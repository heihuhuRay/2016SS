#include <init.h>,

int8_t currentGear = 0;
int8_t ECU2_aliveSignal = 1;
int8_t errorSignal = 1;
int8_t timer0Flag_100ms = 0;
int8_t timer1Flag_200ms_400ms = 0;
int8_t nbrOfTimer1Iterations = 0;

int16_t RPM = 0;
int16_t speedValue = 0;
int16_t nonDrivenWheels_SpeedValue = 0;


/********************************************************************
 *                              main                                *
 ********************************************************************/
void main(void)
{
    /* board initialization */
    Init();
    
    PIT_ConfigureTimer(0, 100); //Configuring Timer0 for 100ms
    PIT_StartTimer(0); //Starting Timer0
    
    PIT_ConfigureTimer(1, 200); //Configuring Timer1 for 200ms
    PIT_StartTimer(1); //Starting Timer1

    /* forever */
    for(;;)
    {
		ADC_StartConversion(); //Calling the ADC Conversion function before the analog POT value
		RPM = POT * 10; //Reading RPM Value from Potentiometer
		
		if(BT5 == 0) { //if Button 5 is pressed = Gear is shifted up
			if(currentGear >= -1 || currentGear <= 5) //if the Gear Box is at a position between the Reverse and the 5th Gear
				currentGear++; //shift the Gear up
		}
		
		else if(BT6 == 0) { //if Button 6 is pressed = Gear is shifted down
			if(currentGear >= 0) //if the Gear Box is not at the Reverse Gear position 
				currentGear--; //shift the Gear down
		}
		
		if(((speedValue - nonDrivenWheels_SpeedValue) > 15) || ((nonDrivenWheels_SpeedValue - speedValue) > 15)) //if the difference between the driven wheels speed and the non-driven wheels speed is larger than 15 km/h
			ASR_Warning = 0; //Switching the ASR Warning to ON status
		
		if(ECU2_aliveSignal == 1) { //if ECU2 is not present
			errorSignal = 0; //Setting the Error Signal to TRUE status
			LED7 = ~LED7; //Blinking LED7
		}

		if(timer0Flag_100ms == 1) {
			CAN_Send_100ms_Interrupt(); //Sending the messages through CAN-Bus
			timer0Flag_100ms = 0; //Reseting the Timer0 Flag to 0
		}

		if(timer1Flag_200ms_400ms == 1) {
			CAN_Send_200ms_400ms_Interrupt(); //Sending the messages through CAN-Bus
			timer1Flag_200ms_400ms = 0; //Reseting the Timer1 Flag to 0
		}
    }
}

/********************************************************************
 *             initialization of CAN message buffers                *
 ********************************************************************/
/********************************************************************
* The message buffers must be defined here.                        *
 * Buffers 0-7 can be used as receive buffers.                      *
 * Buffers 8-15 can be used as send buffers.                        *
 * This function is called only once! Don't care about the call.    *
 * It's done by the Init() function.                                *
 ********************************************************************/ 
void CAN_MessageBufferInit(void)
{
	 //Buffer 0 used to receive Speed Message from ECU4
    CAN_0.BUF[0].CS.B.IDE = 0;
    CAN_0.BUF[0].CS.B.SRR = 0;
    CAN_0.BUF[0].CS.B.RTR = 0;
    CAN_0.BUF[0].CS.B.LENGTH = 0x2; //2 bytes
    CAN_0.BUF[0].ID.B.STD_ID = 0x502;
    CAN_0.BUF[0].CS.B.CODE = 0x4; //0b0100
    //Individual mask register
    CAN_0.RXIMR[0].R = 0x01FFFFFF;
    
    //Buffer 1 used to receive Non-Driven Wheels Speed Message from ECU2
    CAN_0.BUF[1].CS.B.IDE = 0;
    CAN_0.BUF[1].CS.B.SRR = 0;
    CAN_0.BUF[1].CS.B.RTR = 0;
    CAN_0.BUF[1].CS.B.LENGTH = 0x2; //2 bytes
    CAN_0.BUF[1].ID.B.STD_ID = 0x302;
    CAN_0.BUF[1].CS.B.CODE = 0x4; //0b0100
    //Individual mask register
    CAN_0.RXIMR[1].R = 0x01FFFFFF;
    
    //Buffer 2 used to receive Alive Signal from ECU2
    CAN_0.BUF[2].CS.B.IDE = 0;
    CAN_0.BUF[2].CS.B.SRR = 0;
    CAN_0.BUF[2].CS.B.RTR = 0;
    CAN_0.BUF[2].CS.B.LENGTH = 0x0; //0 bits
    CAN_0.BUF[2].ID.B.STD_ID = 0x303;
    CAN_0.BUF[2].CS.B.CODE = 0x4; //0b0100
    //Individual mask register
    CAN_0.RXIMR[2].R = 0x01FFFFFF;
    
    //Buffer 8 used to send RPM Message
    CAN_0.BUF[8].CS.B.IDE = 0;
    CAN_0.BUF[8].CS.B.SRR = 0;
    CAN_0.BUF[8].CS.B.RTR = 0;
    CAN_0.BUF[8].CS.B.LENGTH = 0x2; //2 bytes
    CAN_0.BUF[8].ID.B.STD_ID = 0x201;
    CAN_0.BUF[8].CS.B.CODE = 0xC; //0b1100
    //Individual mask register
    CAN_0.RXIMR[8].R = 0x01FFFFFF;
    
    //Buffer 9 used to send Gears Message
    CAN_0.BUF[9].CS.B.IDE = 0;
    CAN_0.BUF[9].CS.B.SRR = 0;
    CAN_0.BUF[9].CS.B.RTR = 0;
    CAN_0.BUF[9].CS.B.LENGTH = 0x1; //1 byte
    CAN_0.BUF[9].ID.B.STD_ID = 0x202;
    CAN_0.BUF[9].CS.B.CODE = 0xC; //0b1100
    //Individual mask register
    CAN_0.RXIMR[9].R = 0x01FFFFFF;
    
    //Buffer 10 used to send ASR Warning Message
    CAN_0.BUF[10].CS.B.IDE = 0;
    CAN_0.BUF[10].CS.B.SRR = 0;
    CAN_0.BUF[10].CS.B.RTR = 0;
    CAN_0.BUF[10].CS.B.LENGTH = 0x1; //1 byte
    CAN_0.BUF[10].ID.B.STD_ID = 0x203;
    CAN_0.BUF[10].CS.B.CODE = 0xC; //0b1100
    //Individual mask register
    CAN_0.RXIMR[10].R = 0x01FFFFFF;
    
    //Buffer 11 used to send Alive Signal Message
    CAN_0.BUF[11].CS.B.IDE = 0;
    CAN_0.BUF[11].CS.B.SRR = 0;
    CAN_0.BUF[11].CS.B.RTR = 0;
    CAN_0.BUF[11].CS.B.LENGTH = 0x0; //0 bits
    CAN_0.BUF[11].ID.B.STD_ID = 0x204;
    CAN_0.BUF[11].CS.B.CODE = 0xC; //0b1100
    //Individual mask register
    CAN_0.RXIMR[11].R = 0x01FFFFFF;
    
    //Buffer 12 used to send Error Message
    CAN_0.BUF[12].CS.B.IDE = 0;
    CAN_0.BUF[12].CS.B.SRR = 0;
    CAN_0.BUF[12].CS.B.RTR = 0;
    CAN_0.BUF[12].CS.B.LENGTH = 0x0; //0 bits
    CAN_0.BUF[12].ID.B.STD_ID = 0x205;
    CAN_0.BUF[12].CS.B.CODE = 0xC; //0b1100
    //Individual mask register
    CAN_0.RXIMR[12].R = 0x01FFFFFF;
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

void CAN_Send_100ms_Interrupt(void) {
	 int i;
    
    //Sending RPM (M_ID = 0x201) through Buffer 8
    CAN_0.BUF[8].DATA.B[0] = RPM;
    CAN_0.BUF[8].DATA.B[1] = (RPM >> 8);
    for(i = 2; i < 8; i++)
		CAN_0.BUF[8].DATA.B[i] = 0;
    CAN_0.BUF[8].CS.B.CODE = 0xC; //0b1100
}

void CAN_Send_200ms_400ms_Interrupt(void) {
	int i;

	if(((nbrOfTimer1Iterations % 2)) == 0 && ())
	switch(currentGear) {
		//Case when the Gear Box is at the Reverse Gear
		case -1:
			
			break;
				
		//Case when the Gear Box is at the Neutral Gear
		case 0:
			
			break;
				
		//Case when the Gear Box is at the 1st Gear
		case 1:
			
			break;
				
		//Case when the Gear Box is at the 2nd Gear
		case 2:
			
			break;
				
		//Case when the Gear Box is at the 3rd Gear
		case 3:
			
			break;
				
		//Case when the Gear Box is at the 4th Gear
		case 4:
			
			break;
				
		//Case when the Gear Box is at the 5th Gear
		case 5:
				
			break;
				
		//Case when the Gear Box is at the 6th Gear
		case 6:
			
			break;
				
		default:
			break;
	}
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

void PITCHANNEL0() { //Timer0 interrupt = 100ms
    timer0Flag_100ms = 1; //Setting a Flag when the timer is 100ms
    
    /* clear flag */
    PIT.CH[0].TFLG.B.TIF = 1;
}

void PITCHANNEL1() { //Timer1 interrupt = 200ms
	 timer0Flag_200ms_400ms = 1; //Setting a Flag when the timer is 200ms
    nbrOfTimer1Iterations++;
    
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
