#include <init.h>

int8_t leftIndicatorSwitchStatus = 1;
int8_t rightIndicatorSwitchStatus = 1;
int8_t hazardLightStatus = 1;
int8_t leftDoorStatus = 1;
int8_t rightDoorStatus = 1;
int8_t openedDoorsWarning = 1;
int8_t ECU4_aliveSignal = 1;
int8_t errorSignal = 1;
int8_t timer0Flag_200ms = 0;
int8_t timer1Flag_400ms = 0;

int16_t fuelLevel = 0;
int16_t speedValue = 0;
int16_t speedValue_Temp = 0;

/********************************************************************
 *                              main                                *
 ********************************************************************/
void main(void)
{
    /* board initialization */
    Init();
    
    PIT_ConfigureTimer(0, 200); //Configuring Timer0 for 200ms
    PIT_StartTimer(0); //Starting Timer0
    
    PIT_ConfigureTimer(1, 400); //Configuring Timer1 for 400ms
    PIT_StartTimer(1); //Starting Timer1

    /* forever */
    for(;;)
    {
		ADC_StartConversion(); //Calling the ADC Conversion function before the analog POT value
		fuelLevel = POT; //Reading Fuel Level from Potentiometer

		if(SW3 == 0) //if Switch 3 is ON
			leftIndicatorSwitchStatus = 0; //Switching the left indicator to ON status
		else
			leftIndicatorSwitchStatus = 1; //Switching the left indicator to OFF status

		if(SW4 == 0) //if Switch 4 is ON
			rightIndicatorSwitchStatus = 0; //Switching the right indicator to ON status
		else
			rightIndicatorSwitchStatus = 1; //Switching the right indicator to OFF status

		if(SW1 == 0) //if Switch 1 is ON
			hazardLightStatus = 0; //Switching the hazard light indicator to ON status
		else
			hazardLightStatus = 1; //Switching the hazard light indicator to OFF status

		if(speedValue > 5 && ((leftDoorStatus == 0) || (rightDoorStatus == 0)))
			openedDoorsWarning = 0; //Switching the Doors' Status Warning to ON status

		if(ECU4_aliveSignal == 1) { //if ECU4 is not present
			errorSignal = 0; //Setting the Error Signal to TRUE status
			LED7 = ~LED7; //Blinking LED7
		}
		else if(ECU4_aliveSignal == 0) { //if ECU4 is present
			LED7 = 1; //LED7 is OFF
			ECU4_aliveSignal = 1;
		}

		if(timer0Flag_200ms == 1) {
			CAN_Send_200ms_Interrupt(); //Sending the messages through CAN-Bus
			timer0Flag_200ms = 0; //Reseting the Timer0 Flag to 0
		}

		if(timer1Flag_400ms == 1) {
			CAN_Send_400ms_Interrupt(); //Sending the messages through CAN-Bus
			timer1Flag_400ms = 0; //Reseting the Timer1 Flag to 0
		}
    }
}

/********************************************************************
 *             initialization of CAN message buffers                *
 ********************************************************************
 ********************************************************************
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
    
    //Buffer 1 used to receive Doors Message from ECU0
    CAN_0.BUF[1].CS.B.IDE = 0;
    CAN_0.BUF[1].CS.B.SRR = 0;
    CAN_0.BUF[1].CS.B.RTR = 0;
    CAN_0.BUF[1].CS.B.LENGTH = 0x1; //1 byte
    CAN_0.BUF[1].ID.B.STD_ID = 0x102;
    CAN_0.BUF[1].CS.B.CODE = 0x4; //0b0100
    //Individual mask register
    CAN_0.RXIMR[1].R = 0x01FFFFFF;
    
    //Buffer 2 used to receive Alive Signal from ECU4
    CAN_0.BUF[2].CS.B.IDE = 0;
    CAN_0.BUF[2].CS.B.SRR = 0;
    CAN_0.BUF[2].CS.B.RTR = 0;
    CAN_0.BUF[2].CS.B.LENGTH = 0x0; //0 bits
    CAN_0.BUF[2].ID.B.STD_ID = 0x504;
    CAN_0.BUF[2].CS.B.CODE = 0x4; //0b0100
    //Individual mask register
    CAN_0.RXIMR[2].R = 0x01FFFFFF;
    
    //Buffer 8 used to send Fuel Level Message
    CAN_0.BUF[8].CS.B.IDE = 0;
    CAN_0.BUF[8].CS.B.SRR = 0;
    CAN_0.BUF[8].CS.B.RTR = 0;
    CAN_0.BUF[8].CS.B.LENGTH = 0x2; //2 bytes
    CAN_0.BUF[8].ID.B.STD_ID = 0x401;
    CAN_0.BUF[8].CS.B.CODE = 0xC; //0b1100
    //Individual mask register
    CAN_0.RXIMR[8].R = 0x01FFFFFF;
    
    //Buffer 9 used to send Switch Indicator Message
    CAN_0.BUF[9].CS.B.IDE = 0;
    CAN_0.BUF[9].CS.B.SRR = 0;
    CAN_0.BUF[9].CS.B.RTR = 0;
    CAN_0.BUF[9].CS.B.LENGTH = 0x1; //1 byte
    CAN_0.BUF[9].ID.B.STD_ID = 0x402;
    CAN_0.BUF[9].CS.B.CODE = 0xC; //0b1100
    //Individual mask register
    CAN_0.RXIMR[9].R = 0x01FFFFFF;
    
    //Buffer 10 used to send Door Status Message
    CAN_0.BUF[10].CS.B.IDE = 0;
    CAN_0.BUF[10].CS.B.SRR = 0;
    CAN_0.BUF[10].CS.B.RTR = 0;
    CAN_0.BUF[10].CS.B.LENGTH = 0x1; //1 byte
    CAN_0.BUF[10].ID.B.STD_ID = 0x403;
    CAN_0.BUF[10].CS.B.CODE = 0xC; //0b1100
    //Individual mask register
    CAN_0.RXIMR[10].R = 0x01FFFFFF;
    
    //Buffer 11 used to send Alive Signal Message
    CAN_0.BUF[11].CS.B.IDE = 0;
    CAN_0.BUF[11].CS.B.SRR = 0;
    CAN_0.BUF[11].CS.B.RTR = 0;
    CAN_0.BUF[11].CS.B.LENGTH = 0x0; //0 bits
    CAN_0.BUF[11].ID.B.STD_ID = 0x404;
    CAN_0.BUF[11].CS.B.CODE = 0xC; //0b1100
    //Individual mask register
    CAN_0.RXIMR[11].R = 0x01FFFFFF;
    
    //Buffer 12 used to send Error Message
    CAN_0.BUF[12].CS.B.IDE = 0;
    CAN_0.BUF[12].CS.B.SRR = 0;
    CAN_0.BUF[12].CS.B.RTR = 0;
    CAN_0.BUF[12].CS.B.LENGTH = 0x0; //0 bits
    CAN_0.BUF[12].ID.B.STD_ID = 0x405;
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
    /* clearing flag */
    CAN_0.ESR.B.ERRINT = 1;
}

void CANBOFF(void) {
    /* clearing flag */
    CAN_0.ESR.B.BOFFINT = 1;
}

void CANWAK(void) {
    /* clearing flag */
    CAN_0.ESR.B.WAKINT = 1;
}

void CAN_Send_200ms_Interrupt(void) {
    int i;
    
    //Sending Fuel Level (M_ID = 0x401) through Buffer 8
    CAN_0.BUF[8].DATA.B[0] = fuelLevel;
    CAN_0.BUF[8].DATA.B[1] = (fuelLevel >> 8);
    for(i = 2; i < 8; i++)
		CAN_0.BUF[8].DATA.B[i] = 0;
    CAN_0.BUF[8].CS.B.CODE = 0xC; //0b1100
    
    //Sending Indicator Switch (M_ID = 0x402) through Buffer 9
    CAN_0.BUF[9].DATA.B[0] = (hazardLightStatus << 2) | (rightIndicatorSwitchStatus << 1) | (leftIndicatorSwitchStatus);
    for(i = 1; i < 8; i++)
		CAN_0.BUF[9].DATA.B[i] = 0;
    CAN_0.BUF[9].CS.B.CODE = 0xC; //0b1100
    
    //Sending Alive Signal (M_ID = 0x404) through Buffer 11
    CAN_0.BUF[11].DATA.B[0] = 0x00;
    for(i = 1; i < 8; i++)
		CAN_0.BUF[11].DATA.B[i] = 0;
    CAN_0.BUF[11].CS.B.CODE = 0xC; //0b1100
    
    //Sending Error Message (M_ID = 0x405) through Buffer 12 if ECU4 is not present
    CAN_0.BUF[12].DATA.B[0] = errorSignal;
    for(i = 1; i < 8; i++)
		CAN_0.BUF[12].DATA.B[i] = 0;
    CAN_0.BUF[12].CS.B.CODE = 0xC; //0b1100
}

void CAN_Send_400ms_Interrupt(void) {
    int i;
    
    //Sending Door Status (M_ID = 0x403) through Buffer 10
    CAN_0.BUF[10].DATA.B[0] = ((rightDoorStatus << 1) | (leftDoorStatus << 1) | (openedDoorsWarning));
    for(i = 1; i < 8; i++)
		CAN_0.BUF[10].DATA.B[i] = 0;
    CAN_0.BUF[10].CS.B.CODE = 0xC; //0b1100
}

void CANSEND0(void) {
    /* clearing flags */
    CAN_0.IFRL.B.BUF08I = 1;
    CAN_0.IFRL.B.BUF09I = 1;
    CAN_0.IFRL.B.BUF10I = 1;
    CAN_0.IFRL.B.BUF11I = 1;
}

void CANSEND1(void) {
    /* clearing flags */
    CAN_0.IFRL.B.BUF12I = 1;
    CAN_0.IFRL.B.BUF13I = 1;
    CAN_0.IFRL.B.BUF14I = 1;
    CAN_0.IFRL.B.BUF15I = 1;
}

void CANRCV0(void) {
    //Buffer 0 used to receive the speed value from ECU4
    speedValue_Temp = CAN_0.BUF[0].DATA.B[1];
    speedValue_Temp <<= 8;
    speedValue = CAN_0.BUF[0].DATA.B[0] | speedValue_Temp; //Value = LSB + (MSB << 8)
    CAN_0.BUF[0].CS.B.CODE = 0x4; //0b0100
    
    //Buffer 1 used to receive the doors statuses from ECU0
    leftDoorStatus = CAN_0.BUF[1].DATA.B[0] & 0x1; //Receiving the LSB at the 0th bit from the Data Field
    rightDoorStatus = CAN_0.BUF[1].DATA.B[0] & 0x2; //Receiving the 1st bit from the Data Field
    CAN_0.BUF[1].CS.B.CODE = 0x4; //0b0100
    
    //Buffer 2 used to receive the Alive Signal from ECU4
    if(CAN_0.BUF[2].ID.B.STD_ID == 0x504) //if Alive Signal is received from ECU4
    	ECU4_aliveSignal = 0; //Setting ECU4 Alive Signal to ON
    CAN_0.BUF[2].CS.B.CODE = 0x4; //0b0100

    /* clearing flags */
    CAN_0.IFRL.B.BUF00I = 1;    
    CAN_0.IFRL.B.BUF01I = 1;    
    CAN_0.IFRL.B.BUF02I = 1;    
    CAN_0.IFRL.B.BUF03I = 1;
}

void CANRCV1(void) {
    /* clearing flags */
    CAN_0.IFRL.B.BUF04I = 1;
    CAN_0.IFRL.B.BUF05I = 1;
    CAN_0.IFRL.B.BUF06I = 1;
    CAN_0.IFRL.B.BUF07I = 1;
}

void PITCHANNEL0() { //Timer0 interrupt = 200ms
    timer0Flag_200ms = 1; //Setting a Flag when the timer is 200ms
    
    /* clearing flag */
    PIT.CH[0].TFLG.B.TIF = 1;
}

void PITCHANNEL1() { //Timer1 interrupt = 400ms
    timer1Flag_400ms = 1; //Setting a Flag when the timer is 400ms
    
    /* clearing flag */
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
