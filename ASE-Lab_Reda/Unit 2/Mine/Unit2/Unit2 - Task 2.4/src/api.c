#include "names.h"
#include "api.h"

void init(void)
{
    //clear the soft lock bit of the SWT watchdog, just in case
	SWT.SR.B.WSC = 0xc520;
	SWT.SR.B.WSC = 0xd928;	
    //disable the SWT watchdog and configure it for not interfering with the debugger
	SWT.CR.R = 0x8000010A;
    init_mode();

    
    INTC.MCR.B.VTES = 0;
    
    INTC.MCR.B.HVEN = 0;
    
    INTC.IACKR.B.VTBA = 0x12000;


    
    INTC.PSR[59].B.PRI = 0x6; 
    INTC.PSR[60].B.PRI = 0xE;  
    INTC.PSR[70].B.PRI = 0xF;
    INTC.PSR[71].B.PRI = 0x8;
	INTC.PSR[66].B.PRI = 0xD;
	INTC.PSR[67].B.PRI = 0x9;
	INTC.PSR[68].B.PRI = 0xA;
	INTC.PSR[69].B.PRI = 0xE;
	INTC.PSR[57].B.PRI = 0x7;  
    INTC.PSR[127].B.PRI = 0x7;
    

    /*
    asm("lis r31, 0x1200");
    asm("mtspr 63, r31");*/
 
    init_peripherals();
    init_timer();
    init_flexcan();
    
   
}

void init_mode(void)
{
    
    ME.MER.B.RUN0 = 1;
    ME.MER.B.RUN1=1;

    ME.DRUN.B.DFLAON = 3;
    ME.DRUN.B.CFLAON = 3;
    ME.DRUN.B.XOSC0ON = 1;
    ME.DRUN.B.SYSCLK = 0x2;

    ME.RUN[1].B.XOSC0ON=1;
    ME.RUN[1].B.SYSCLK=0x2;
    
    ME.RUN[0].B.PDO =0; // No automatic safe gating of I/Os used and pads power sequence driver is enabled.
    ME.RUN[0].B.DFLAON=3; //data flash normal mode
    ME.RUN[0].B.CFLAON=3; //code flash normal mode
    ME.RUN[0].B.XOSC0ON=0; // external oscillator   
    ME.RUN[0].B.SYSCLK =0x2 ;    

    ME.IM.B.M_CONF = 1; // Invalid mode configuration interrupt mask
    ME.IM.B.M_MODE = 1; 
    ME.IM.B.M_AFE = 1;
    ME.IM.B.M_TC = 1;
    

    ME.RUNPC[0].R = 0xFE; // Peripheral Configuration 
    ME.LPPC[0].B.STOP0 = 1;  // Low Power mode configuration
    ME.LPPC[0].B.HALT0 = 1;  // Low power mode configuration
    ME.MCTL.R = 0x40005AF0; // RUN0 mode pg 174 
    ME.MCTL.R = 0x4000A50F;
        
}

void init_flexcan(void)
{
    int i;

    for(i=0; i<32; i++)
    {
        CAN_0.BUF[i].ID.B.STD_ID = 0;
        CAN_0.BUF[i].CS.B.CODE = 0;
        CAN_0.BUF[i].CS.B.SRR = 0;
        CAN_0.BUF[i].CS.B.IDE = 0;
        CAN_0.BUF[i].CS.B.RTR = 0;
        CAN_0.RXIMR[i].R = 0x00000000;
    }

    CAN_0.RXGMASK.R=0x00000000;
    CAN_0.RX14MASK.R=0x00000000;
    CAN_0.RX15MASK.R=0x00000000;

    CAN_0.CR.B.CLKSRC=1; 
    CAN_0.CR.B.BOFFMSK = 1; 
    CAN_0.CR.B.ERRMSK = 1; 
    CAN_0.CR.B.LPB = 0; 
    CAN_0.CR.B.LBUF = 0; 



    CAN_0.CR.B.PRESDIV=15;
    CAN_0.CR.B.RJW =0 ; 
    CAN_0.CR.B.PROPSEG = 2; 
    CAN_0.CR.B.PSEG1 = 1;  
    CAN_0.CR.B.PSEG2 = 1; 


    CAN_0.CR.B.TWRNMSK=1;
    CAN_0.CR.B.RWRNMSK=1;
    CAN_0.IMRL.R = 0xFFFFFFFF; 


    CAN_0.IFRL.R = 0xFFFFFFFF; 
    CAN_0.MCR.B.FRZ = 0;
    CAN_0.MCR.B.FEN = 0;
    CAN_0.MCR.B.AEN = 0;
    CAN_0.MCR.B.LPRIO_EN = 0; 
    CAN_0.MCR.B.SRXDIS = 1; 
    CAN_0.MCR.B.WRNEN = 1; 
    CAN_0.MCR.B.BCC = 1; 
    CAN_0.MCR.B.MAXMB = 20;


    CAN_0.IMRL.R = 0xFFFFFFFF;
    conf_can();

    CAN_0.MCR.B.MDIS = 0; 

    CAN_0.MCR.B.HALT = 0;

    while ((CAN_0.MCR.B.LPMACK == 1));
    while ((CAN_0.MCR.B.FRZACK == 1));
    while((CAN_0.MCR.B.NOTRDY == 1));
        

    CAN_0.BUF[0].CS.B.CODE = 0b0100;


    CAN_0.IFRL.R = 0xFFFFFFFF; 
}

void init_timer(void)
{
	PIT.PITMCR.B.MDIS = 0; 
    PIT.PITMCR.B.FRZ = 0;
}

void conf_timer0(int mode, int time)
{      
    // Channel 0 
    PIT.CH[0].LDVAL.B.TSV = time*16000;    
    PIT.CH[0].TCTRL.B.TIE = 1; 
    PIT.CH[0].TCTRL.B.TEN = mode;  
    PIT.CH[0].TFLG.B.TIF = 1;  
}

void conf_timer1(int mode, int time)
{      
    // Channel 1
    PIT.CH[1].LDVAL.B.TSV = time*16000;    
    PIT.CH[1].TCTRL.B.TIE = 1; 
    PIT.CH[1].TCTRL.B.TEN = mode;     
    PIT.CH[1].TFLG.B.TIF = 1;       
}

void init_peripherals(void)
{
    // module activation    
    ME.PCTL[32].R = 0; // ADC0 Activate
    //ME.PCTL[33].R = 0; // ADC1 Activate
    //ME.PCTL[38].R = 0; // ETIMER0 Activate
    ME.PCTL[92].R = 0; // PIT activate
    //ME.PCTL[39].R = 0; // ETIMER1 
    ME.PCTL[16].R = 0; // FLEXCAN0 
    
        
    //Button & switch inputs  
    SIU.PCR[0].R = 0x100;       // BT6 input Enable 
    SIU.PCR[1].R = 0x100;       // BT5 input Enable 
    SIU.PCR[2].R = 0x100;       // SW4 input Enable 
    SIU.PCR[3].R = 0x100;       // SW3 input Enable 
    SIU.PCR[4].R = 0x100;       // SW2 input Enable 
    SIU.PCR[44].R = 0x100;       // SW1 input Enable 
 
    // LEDs 
    SIU.PCR[9].R = 0x200;       // D0
    SIU.PCR[42].R = 0x200;      // D1
    SIU.PCR[13].R = 0x200;      // D2
    SIU.PCR[12].R = 0x200;      // D3
    SIU.PCR[62].R = 0x200;      // D4
    SIU.PCR[61].R = 0x200;      // D5
    SIU.PCR[59].R = 0x200;      // D6
    SIU.PCR[11].R = 0x200;      // D7
    
    // Turn off LEDs
    SIU.GPDO[9].R = 0x1;
    SIU.GPDO[42].R = 0x1;
    SIU.GPDO[13].R = 0x1;
    SIU.GPDO[12].R = 0x1;
    SIU.GPDO[62].R = 0x1;
    SIU.GPDO[61].R = 0x1;   
    SIU.GPDO[59].R = 0x1;
    SIU.GPDO[11].R = 0x1;

    asm("wrteei 1"); // Enable Interrupts
}



// ----------------Software Interrupt Table--------------- 

#pragma interrupt Ext_Isr
#pragma section IrqSect RX address=0x040
#pragma use_section IrqSect Ext_Isr

void Ext_Isr()
{
    switch(INTC.IACKR.B.INTVEC )
    {
    // please find the respective IRQ numbers from the vector table 
    // and input the functions and flag clearing codes in the respective case numbers 
    case 59 :    
             timer0_intr();
             PIT.CH[0].TFLG.B.TIF = 1;   
             break;
    case 60 : 
             break;
    case 62 : 
             break;
    case 66: 
             break;
    case 67: 
             break;
    case 68: 
             can_receive();
             CAN_0.IFRL.B.BUF00I = 1;
             break;
    case 69:           
             CAN_0.IFRL.B.BUF04I = 1;
             break;
    case 70:            
             break;
    case 71: 
             break;
    case 72: 
             break;
    case 61: 
             break;
    case 127:  
             break;
    default:
             break;
    }         
    INTC.EOIR.R = 0x00000000;
}