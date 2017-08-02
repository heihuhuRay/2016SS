#include "api.h"
#include "jdp.h"


int counter;

void init(void)
{
    //clear the soft lock bit of the SWT watchdog, just in case
	SWT.SR.B.WSC = 0xc520;
	SWT.SR.B.WSC = 0xd928;	
    //disable the SWT watchdog and configure it for not interfering with the debugger
	SWT.CR.R = 0x8000010A;
	
    init_mode(); // mode initialisation

    // vector table entry size = 8 bytes (1) 4 bytes (0)
    INTC.MCR.B.VTES = 0;
    // software vector mode enable
    INTC.MCR.B.HVEN = 0;
    // vector table base adress
    INTC.IACKR.B.VTBA = 0x12000;
	
    // interrupt priority register
    INTC.PSR[59].B.PRI = 0x6; // PIT channel 0
	INTC.PSR[60].B.PRI = 0x5; // PIT channel 1
    INTC.PSR[70].B.PRI = 0xF;
    INTC.PSR[71].B.PRI = 0x8;
	INTC.PSR[66].B.PRI = 0xD;
	INTC.PSR[67].B.PRI = 0x9;
	INTC.PSR[68].B.PRI = 0xA;
	INTC.PSR[69].B.PRI = 0xE;
	INTC.PSR[57].B.PRI = 0x7;  // XOSC counter expired
    INTC.PSR[127].B.PRI = 0x7;
  
  
    // enable interrupts

    /*
    asm("lis r31, 0x1200");
    asm("mtspr 63, r31");*/
 
    init_peripherals();
    ADC_0.MCR.B.NSTART = 1;
    init_timer();
	
    
	 // ADC conversion start
    
       // while(ADC_0.MSR.B.NSTART); // wait for one shot mode 
    
    
   
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


void init_timer(void)
{
	PIT.PITMCR.B.MDIS = 0; // Module Enable
    PIT.PITMCR.B.FRZ = 0;  // Timers continue to run in debug mode
      

}

void conf_timer0(int mode, int time)
{      
    // Channel 0 
    PIT.CH[0].LDVAL.B.TSV = time*16000;    
    PIT.CH[0].TCTRL.B.TIE = 1; 
    PIT.CH[0].TCTRL.B.TEN = mode; 
    
    PIT.CH[0].TFLG.B.TIF = 1; 
    
    
}



void init_peripherals(void)
{
    
    ME.PCTL[32].R = 0; // ADC0 Activate
    //ME.PCTL[33].R = 0; // ADC1 Activate
    //ME.PCTL[38].R = 0; // ETIMER0 Activate
    ME.PCTL[92].R = 0; // PIT activate
    //ME.PCTL[39].R = 0; // ETIMER1 
    ME.PCTL[16].R = 0; // FLEXCAN0 
    //ME.PCTL[].R = 0;  // 

    
    SIU.PCR[66].B.PA = 0b01;
    SIU.PCR[66].B.APC = 1;
    SIU.PCR[66].B.IBE = 1;
    
    
    

  
    
    // ANA IN 2 analog input enable
    SIU.PCR[34].B.PA = 0b01;
    SIU.PCR[34].B.APC = 1;
    SIU.PCR[34].B.IBE = 1;
   
    
	 ADC_0.MCR.B.MODE = 1; // 0- one shot mode 1- scan Mode
    
    // disable Power Down Mode
    ADC_0.MCR.B.PWDN = 0;
    
   // Overwrite Enable
    ADC_0.MCR.B.OWREN = 1;
  
    //ADC_0.IMR.B.MSKEOC = 1; // interrupt enable for End of channel converison
    //ADC_0.ISR.B.MSKEOC bit is set when interrupt occurs 
    ADC_0.NCMR[0].B.CH4 = 1; // Channel 4 Potentiometer
    //ADC_0.NCMR[0].B.CH5 = 1; // Channel 5 Temprature Sensor
    ADC_0.NCMR[0].B.CH2 = 1; // Channel 2 ANA IN 1
    //ADC_0.NCMR[0].B.CH3 = 1; // Channel 3 ANA IN 2
   
        
  
    //SIU.PCR[4].R = 0x0100;       // SW2 input Enable  // config check
   
 
    configure_io();
    
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





#pragma interrupt Ext_Isr
#pragma section IrqSect RX address=0x040
#pragma use_section IrqSect Ext_Isr



void Ext_Isr()
{

    switch(INTC.IACKR.B.INTVEC )
    {
    
    case 59 : timer0_intr();
			  PIT.CH[0].TFLG.B.TIF = 1;
             break;
    case 60 : 
			timer1_intr();
			PIT.CH[1].TFLG.B.TIF = 1;
             break;
  
    case 61: //PITimer channel 2
        PIT.CH[2].TFLG.B.TIF = 1;
             break;
    case 127: // PITimer Channel 3    
        PIT.CH[3].TFLG.B.TIF = 1; 
             break;       
    }         
    INTC.EOIR.R = 0x00000000;


}
