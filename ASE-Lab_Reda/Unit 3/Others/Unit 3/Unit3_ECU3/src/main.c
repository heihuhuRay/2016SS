#include <init.h>

#define ON 0
#define OFF 1

int16_t Fuel_Level=0;
int8_t Left_Indicator_Status=OFF;
int16_t Right_Indicator_Status=OFF;
int16_t Hazard_Light_Status=OFF;
int16_t Speed_Value=0;
int8_t Left_Door=1;
int8_t Right_Door=1;
int8_t Door_Status=1;

int8_t Timer0_Flag_200ms=0;
int8_t Timer0_Flag_400ms=0;
int8_t Interrupt_Flag_03=0;
int8_t Error_Flag=1;

/********************************************************************
 *                              main                                *
 ********************************************************************/
void main(void)
{
	 /* board initialization */
		    Init();

		/*Receive Message IDs*/
		    /*
		     * 0x502 = 0 101 0000 0010   Speed
		     * 0x102 = 0 001 0000 0010   Door Status
		     * 0x504 = 0 101 0000 0100   ECU4 Alive
		     * -------------------------
		     * MASK  - 1 011 1111 1001
		     * ACCP  - 0 *01 0000 0**0
		     *
		     * MASK REG- 000 01111111001 11
		     *           111 11111111111 11
		     */
		 CAN_0.RXIMR[0].R =0x0FE7FFFF;
		 CAN_0.BUF[0].ID.B.STD_ID=0x100;
		 CAN_0.BUF[0].CS.B.CODE = 0x04;

		 PIT_ConfigureTimer(0,200); /*Configure timer0 for 200 msec*/
		 PIT_StartTimer(0); /*start timer0 */

    /* forever */
    for(;;)
    {
/********************************************************************
 *                    _____  ___  ___   ___                         *
 *                   |_   _|/ _ \|   \ / _ \                        *
 *                     | | | (_) | |) | (_) |                       *
 *                     |_|  \___/|___/ \___/                        *
 *                                                                  *
 * Write down your logic here.                                      *
 ********************************************************************/  

ADC_StartConversion();
Fuel_Level=POT; /* Read Fuel Value*/


		if (SW1==0) /* SW1 is ON*/
		{
			Left_Indicator_Status=ON;/*Left Indicator ON*/
		}
		else
		{
			Left_Indicator_Status=OFF;/*Left Indicator OFF*/
		}


		if (SW3==0) /* SW3 is ON*/
		{
			Right_Indicator_Status=ON;/*Right Indicator ON*/
		}
		else
		{
			Right_Indicator_Status=OFF;/*Right Indicator OFF*/
		}

		if (SW4==0) /* SW4 is ON*/
		{
			Hazard_Light_Status=ON;/*Hazard Light ON*/
		}
		else
		{
			Hazard_Light_Status=OFF;/*Hazard Light OFF*/
		}

		if (Timer0_Flag_200ms == 1) /* 200 ms task*/
		{
			CAN_Send_Fuel_Level_Status();
			CAN_Send_Indicator_Status();
			CAN_MessageBufferInit();

			if (Timer0_Flag_400ms == 1) /*400 ms task*/
			{
				CAN_Send_Door_Status();
				Timer0_Flag_400ms = 0;
			}
			else
			{
				Timer0_Flag_400ms = 1;
			}

			if (Error_Flag == 1) {
				LED7=~LED7;
				CAN_Send_ECU4_Error_Message();
			}
			else
			 {
			 Error_Flag = 1; /* This Part should be enable after testing*/
			 }

			Timer0_Flag_200ms = 0;
		}

	  	if(Interrupt_Flag_03==1)
		{
			LED0=~LED0;

				if(CAN_0.BUF[0].ID.B.STD_ID==0x502)
				{
					LED1=~LED1;
					Speed_Value= CAN_0.BUF[0].DATA.B[1];
					Speed_Value= Speed_Value<<8;
					Speed_Value|= CAN_0.BUF[0].DATA.B[0];
   		     	}

				if(CAN_0.BUF[1].ID.B.STD_ID==0x102)
				{
					LED2=~LED2;
					Left_Door = (CAN_0.BUF[0].DATA.B[0]& 0b00000001);
					Right_Door= (CAN_0.BUF[0].DATA.B[0]& 0b00000010);
				}

				if(CAN_0.BUF[0].ID.B.STD_ID== 0x504)
				{
					LED3=~LED3;
					Error_Flag = 0; /*stop sending error message*/
				}

				if(Speed_Value >5 && (Left_Door==0||Right_Door==0))
				{
					Door_Status= 0; /* Warning ON */
				}
				else
				{
					Door_Status= 1; /* Warning OFF */
				}

			Interrupt_Flag_03=0;
		}

   }

}

/********************************************************************
 *             initialization of CAN message buffers                *
 ********************************************************************/
void CAN_MessageBufferInit(void)
{
/********************************************************************
 *                    _____  ___  ___   ___                         *
 *                   |_   _|/ _ \|   \ / _ \                        *
 *                     | | | (_) | |) | (_) |                       *
 *                     |_|  \___/|___/ \___/                        *
 *                                                                  *
 * The message buffers must be defined here.                        *
 * Buffers 0-7 can be used as receive buffers.                      *
 * Buffers 8-15 can be used as send buffers.                        *
 * This function is called only once! Don't care about the call.    *
 * It's done by the Init() function.                                *
 ********************************************************************/ 

    CAN_0.BUF[8].CS.B.CODE = 0xC;  
    CAN_0.BUF[8].CS.B.IDE = 0;
    CAN_0.BUF[8].CS.B.SRR = 0;
    CAN_0.BUF[8].CS.B.RTR = 0; /*Data Frame*/
    CAN_0.BUF[8].CS.B.LENGTH = 0x00;
    CAN_0.BUF[8].ID.B.STD_ID =0x404 ;
    CAN_0.BUF[8].DATA.B[0] =0;
    CAN_0.BUF[8].DATA.B[1] =0;
    CAN_0.BUF[8].DATA.B[2] =0;
    CAN_0.BUF[8].DATA.B[3] =0;
    CAN_0.BUF[8].DATA.B[4] =0;
    CAN_0.BUF[8].DATA.B[5] =0;
    CAN_0.BUF[8].DATA.B[6] =0;
    CAN_0.BUF[8].DATA.B[7] =0;		
	// individual mask register
    CAN_0.RXIMR[8].R = 0;

 }

/********************************************************************
 *             CAN Indicator Status Send buffer                *
 ********************************************************************/
void CAN_Send_Indicator_Status(void)
{
	    CAN_0.BUF[9].CS.B.CODE = 0xC;
	    CAN_0.BUF[9].CS.B.IDE = 0;
	    CAN_0.BUF[9].CS.B.SRR = 0;
	    CAN_0.BUF[9].CS.B.RTR = 0; /*Data Frame*/
	    CAN_0.BUF[9].CS.B.LENGTH = 0x01;
	    CAN_0.BUF[9].ID.B.STD_ID = 0x402 ; /* Indicator Msg ID*/
	    CAN_0.BUF[9].DATA.B[0] =(Left_Indicator_Status|(Right_Indicator_Status<<1)| (Hazard_Light_Status<<2));
	    CAN_0.BUF[9].DATA.B[1] =0;
	    CAN_0.BUF[9].DATA.B[2] =0;
	    CAN_0.BUF[9].DATA.B[3] =0;
	    CAN_0.BUF[9].DATA.B[4] =0;
	    CAN_0.BUF[9].DATA.B[5] =0;
	    CAN_0.BUF[9].DATA.B[6] =0;
	    CAN_0.BUF[9].DATA.B[7] =0;
		// individual mask register
	    CAN_0.RXIMR[9].R = 0;
}
/********************************************************************
 *             CAN_Send_Fuel_Level_Status                *
 ********************************************************************/
void CAN_Send_Fuel_Level_Status(void)
{
	    CAN_0.BUF[10].CS.B.CODE = 0xC;
	    CAN_0.BUF[10].CS.B.IDE = 0;
	    CAN_0.BUF[10].CS.B.SRR = 0;
	    CAN_0.BUF[10].CS.B.RTR = 0; /*Data Frame*/
	    CAN_0.BUF[10].CS.B.LENGTH = 0x02;
	    CAN_0.BUF[10].ID.B.STD_ID = 0x401 ; /* Indicator Msg ID*/
	    CAN_0.BUF[10].DATA.B[0] =(int8_t)Fuel_Level;
	    CAN_0.BUF[10].DATA.B[1] =(int8_t)(Fuel_Level>>8);
	    CAN_0.BUF[10].DATA.B[2] =0;
	    CAN_0.BUF[10].DATA.B[3] =0;
	    CAN_0.BUF[10].DATA.B[4] =0;
	    CAN_0.BUF[10].DATA.B[5] =0;
	    CAN_0.BUF[10].DATA.B[6] =0;
	    CAN_0.BUF[10].DATA.B[7] =0;
		// individual mask register
	    CAN_0.RXIMR[10].R = 0;
}


/********************************************************************
 *             CAN Light Door Warning Send buffer                *
 ********************************************************************/
void CAN_Send_Door_Status(void)
{
	    CAN_0.BUF[12].CS.B.CODE = 0xC;
	    CAN_0.BUF[12].CS.B.IDE = 0;
	    CAN_0.BUF[12].CS.B.SRR = 0;
	    CAN_0.BUF[12].CS.B.RTR = 0; /*Data Frame*/
	    CAN_0.BUF[12].CS.B.LENGTH = 0x01;
	    CAN_0.BUF[12].ID.B.STD_ID = 0x403 ; /* Door Message ID*/
	    CAN_0.BUF[12].DATA.B[0] = (Door_Status|(Left_Door<<1)|(Right_Door<<2)); /* Warning */
	    CAN_0.BUF[12].DATA.B[1] =0;
	    CAN_0.BUF[12].DATA.B[2] =0;
	    CAN_0.BUF[12].DATA.B[3] =0;
	    CAN_0.BUF[12].DATA.B[4] =0;
	    CAN_0.BUF[12].DATA.B[5] =0;
	    CAN_0.BUF[12].DATA.B[6] =0;
	    CAN_0.BUF[12].DATA.B[7] =0;
		// individual mask register
	    CAN_0.RXIMR[12].R = 0;
}


/********************************************************************
 *             CAN ECU1 Error Message                *
 ********************************************************************/
void CAN_Send_ECU4_Error_Message()
{
	    CAN_0.BUF[13].CS.B.CODE = 0xC;
	    CAN_0.BUF[13].CS.B.IDE = 0;
	    CAN_0.BUF[13].CS.B.SRR = 0;
	    CAN_0.BUF[13].CS.B.RTR = 0; /*Data Frame*/
	    CAN_0.BUF[13].CS.B.LENGTH = 0x00;
	    CAN_0.BUF[13].ID.B.STD_ID = 0x405 ; /* ECU4 Message ID*/
	    CAN_0.BUF[13].DATA.B[0] =0;
	    CAN_0.BUF[13].DATA.B[1] =0;
	    CAN_0.BUF[13].DATA.B[2] =0;
	    CAN_0.BUF[13].DATA.B[3] =0;
	    CAN_0.BUF[13].DATA.B[4] =0;
	    CAN_0.BUF[13].DATA.B[5] =0;
	    CAN_0.BUF[13].DATA.B[6] =0;
	    CAN_0.BUF[13].DATA.B[7] =0;
		// individual mask register
	    CAN_0.RXIMR[13].R = 0;
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
    /* clear flags */
	Interrupt_Flag_03=1;
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
	Timer0_Flag_200ms=1;
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
