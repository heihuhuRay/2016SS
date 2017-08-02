#include <init.h>


unsigned short can_data,ECU3_Fuel,ECU4_Coolant;
unsigned short can_id;
unsigned char can_buffer;
unsigned char ECU1_Counter;
unsigned char Timer_Counter,timer_flag;


/********************************************************************
 *                              main                                *
 ********************************************************************/
void main(void)
{
    /* board initialization */
    Init();
    PIT_ConfigureTimer(0, 200);
	PIT_StartTimer(0);
	ADC_StartConversion();
    /* forever */
    for(;;)
    {

    if(timer_flag ==1) 
	{
		//increment if confirmation from ECU1 not received */
		ECU1_Counter = ECU1_Counter + 1; 
		
		//sending  alive signal
		can_data=0;
		can_buffer=9;
		can_id=0x105;
		CAN_send();
		
		//light signal
		can_data =IN1;
		can_id=0x101;
		can_buffer= 10;
		CAN_send();
		
		//door information
		can_data=0x03;
		if(SW1==0) can_data = can_data & 0x02;
		if(SW2==0) can_data = can_data & 0x01;
		can_id=0x102;
		can_buffer= 11;
		CAN_send();
		//CAN_mode = 0x0C;
		
		if(ECU1_Counter>=5)
		{	
			LED7=~LED7;
			can_data=0;
			can_buffer=8;
			can_id=0x106;
			CAN_send();			
		}
		
			if(Timer_Counter%4==0)
			{   
		        can_data=1;
				if(ECU3_Fuel<=102) can_data=0;
				
				can_buffer=12;
				can_id=0x103;
				CAN_send();	
				
				can_data=1;
				if(ECU4_Coolant>=921) can_data=0;
				
				can_buffer=13;
				can_id=0x104;
				CAN_send();						
			}			
		Timer_Counter=Timer_Counter+1;
		timer_flag=0;
	}
	
	
	
	}
}
void CAN_send(void)
{

    CAN_0.BUF[can_buffer].CS.B.CODE = 0xC;  
    CAN_0.BUF[can_buffer].CS.B.IDE =0 ;
    CAN_0.BUF[can_buffer].CS.B.SRR = 0;
    CAN_0.BUF[can_buffer].CS.B.RTR =0 ;
    CAN_0.BUF[can_buffer].CS.B.LENGTH =2 ;
    CAN_0.BUF[can_buffer].ID.B.STD_ID =can_id ;
    CAN_0.BUF[can_buffer].DATA.B[0] = (signed char)can_data;
    CAN_0.BUF[can_buffer].DATA.B[1] = (signed char)(can_data>>8);
    /*CAN_0.BUF[can_buffer].DATA.B[2] = ;
    CAN_0.BUF[can_buffer].DATA.B[3] = ;
    CAN_0.BUF[can_buffer].DATA.B[4] = ;
    CAN_0.BUF[can_buffer].DATA.B[5] = ;
    CAN_0.BUF[can_buffer].DATA.B[6] = ;
    CAN_0.BUF[can_buffer].DATA.B[7] = ;	*/	
	// individual mask register
   // CAN_0.RXIMR[].R = ;

}


/********************************************************************
 *             initialization of CAN message buffers                *
 ********************************************************************/
void CAN_MessageBufferInit(void)
{



  /*  CAN_0.BUF[].CS.B.CODE = ;  
    CAN_0.BUF[].CS.B.IDE = ;
    CAN_0.BUF[].CS.B.SRR = ;
    CAN_0.BUF[].CS.B.RTR = ;
    CAN_0.BUF[].CS.B.LENGTH = ;
    CAN_0.BUF[].ID.B.STD_ID = ;
    CAN_0.BUF[].DATA.B[0] = ;
    CAN_0.BUF[].DATA.B[1] = ;
    CAN_0.BUF[].DATA.B[2] = ;
    CAN_0.BUF[].DATA.B[3] = ;
    CAN_0.BUF[].DATA.B[4] = ;
    CAN_0.BUF[].DATA.B[5] = ;
    CAN_0.BUF[].DATA.B[6] = ;
    CAN_0.BUF[].DATA.B[7] = ;	*/	
	// individual mask register
    CAN_0.RXIMR[0].R = 0x3EBFFFF;

}

/********************************************************************
 *                       interrupt functions                        *
 ********************************************************************/

/********************************************************************
 *                    _____  ___  ___   ___                         *
 *                   |_   _|/ _ \|   \ / _ \                        *
 *                     | | | (_) | |) | (_) |                       *
 *                     |_|  \___/|___/ \___/                        *
 *                                                                  *
 * Interrupts can be handled here.                                  *
 ********************************************************************/  
 
void CANERR(void) {
    /* clear flag */
    CAN_0.ESR.B.ERRINT = 1;
}

void CANBOFF(void) {
    /* clear flag */
    CAN_0.ESR.B.BOFFINT = 1;
}

void CANWAK(void) {
    /* clear flag */
    CAN_0.ESR.B.WAKINT = 1;
}

void CANSEND0(void) {
    /* clear flags */
    CAN_0.IFRL.B.BUF08I = 1;
    CAN_0.IFRL.B.BUF09I = 1;
    CAN_0.IFRL.B.BUF10I = 1;
    CAN_0.IFRL.B.BUF11I = 1;
}

void CANSEND1(void) {
    /* clear flags */
    CAN_0.IFRL.B.BUF12I = 1;
    CAN_0.IFRL.B.BUF13I = 1;
    CAN_0.IFRL.B.BUF14I = 1;
    CAN_0.IFRL.B.BUF15I = 1;
}

void CANRCV0(void) {
	switch(CAN_0.BUF[0].ID.B.STD_ID)
	{
	case 0x204 : 
		// Confirmation from ECU1
		ECU1_Counter = 0;
        LED7=1;
		break;
	case 0x401; 
		// Fuel level from ECU3
		ECU3_Fuel = CAN_0.BUF[0].DATA.B[0] + (CAN_0.BUF[0].DATA.B[1] * 256);
		break;
	case 0x501:
		// Engine coolant temperature from ECU4
		ECU4_Coolant = CAN_0.BUF[0].DATA.B[0] + (CAN_0.BUF[0].DATA.B[1] * 256);
		break;
	
	}
    /* clear flags */
	
	

    CAN_0.IFRL.B.BUF00I = 1;    
    CAN_0.IFRL.B.BUF01I = 1;    
    CAN_0.IFRL.B.BUF02I = 1;    
    CAN_0.IFRL.B.BUF03I = 1;
}

void CANRCV1(void) {
    /* clear flags */
    CAN_0.IFRL.B.BUF04I = 1;
    CAN_0.IFRL.B.BUF05I = 1;
    CAN_0.IFRL.B.BUF06I = 1;
    CAN_0.IFRL.B.BUF07I = 1;
}

void PITCHANNEL0() {
    /* clear flag */
timer_flag =1;
    PIT.CH[0].TFLG.B.TIF = 1;
}

void PITCHANNEL1() {
    /* clear flag */
    PIT.CH[1].TFLG.B.TIF = 1;
}

/********************************************************************
 *                   interrupt vector table                         *
 ********************************************************************/

#pragma interrupt Ext_Isr
#pragma section IrqSect RX address=0x040
#pragma use_section IrqSect Ext_Isr

void Ext_Isr() {
    switch(INTC.IACKR.B.INTVEC)
    {
        case 59:
            /* Timer Interrupt */
            PITCHANNEL0();
            break;
        case 60:
            /* Timer Interrupt */
            PITCHANNEL1();
            break;            
        case 65:
            /* CAN Error Interrupt */
            CANERR();
            break;
        case 66:
            /* CAN Bus Off Interrupt */
            CANBOFF();
            break;
        case 67:
            /* CAN Wakeup Interrupt */
            CANWAK();
        case 68:
            /* CAN Interrupt for message buffers 0-3 */
            CANRCV0();
            break;
        case 69:
            /* CAN Interrupt for message buffers 4-7 */
            CANRCV1();
            break;
        case 70:
            /* CAN Interrupt for message buffers 8-11 */
            CANSEND0();
            break;
        case 71:
            /* CAN Interrupt for message buffers 12-15 */
            CANSEND1();
            break;
        default:
            break;
    }
    /* End of Interrupt Request */
    INTC.EOIR.R = 0x00000000;
}
