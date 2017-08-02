#include <init.h>

int8_t lowBeam_HeadlightSwitch_Status = 1;
int8_t highBeam_HeadlightSwitch_Status = 1;
int8_t parkingLight_HeadlightSwitch_Status = 1;
int8_t ECU0_aliveSignal = 1;
int8_t errorSignal = 1;
int8_t Gear = 0;
int8_t timer0Flag_100ms = 0;
int8_t timer1Flag_200ms = 0;

int16_t engineCoolantTemperature = 0;
int16_t RPM = 0;
int16_t speedValue = 0;
int16_t RPM_Temp = 0;

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
		engineCoolantTemperature = POT; //Reading Engine Coolant Temperature from Potentiometer

		if(SW1 == 0) //if Switch 1 is ON
			parkingLight_HeadlightSwitch_Status = 0; //Switching the Parking Light to ON status
		else
			parkingLight_HeadlightSwitch_Status = 1; //Switching the Parking Light to OFF status
		
		if(SW3 == 0) //if Switch 3 is ON
			lowBeam_HeadlightSwitch_Status = 0; //Switching the Low Beam Headlight to ON status
		else
			lowBeam_HeadlightSwitch_Status = 1; //Switching the Low Beam Headlight to OFF status
			
		if(SW4 == 0) //if Switch 4 is ON
			highBeam_HeadlightSwitch_Status = 0; //Switching the High Beam Headlight to ON status
		else
			highBeam_HeadlightSwitch_Status = 1; //Switching the High Beam Headlight to OFF status

		switch(gear) {
			//Case where the Gear Box is at the Reverse Gear
			case 0b00000001:
				speedValue = (7842 * RPM) / 100000;
				break;
			
			//Case where the Gear Box is at the Neutral Gear
			case 0b00000010:
				speedValue = (0 * RPM) / 100000;
				break;
			
			//Case where the Gear Box is at the 1st Gear
			case 0b00000100:
				speedValue = (7842 * RPM) / 100000;
				break;
			
			//Case where the Gear Box is at the 2nd Gear
			case 0b00001000:
				speedValue = (13112 * RPM) / 100000;
				break;
			
			//Case where the Gear Box is at the 3rd Gear
			case 0b00010000:
				speedValue = (19861 * RPM) / 100000;
				break;
			
			//Case where the Gear Box is at the 4th Gear
			case 0b00100000:
				speedValue = (27038 * RPM) / 100000;
				break;
			
			//Case where the Gear Box is at the 5th Gear
			case 0b01000000:
				speedValue = (33149 * RPM) / 100000;
				break;
			
			//Case where the Gear Box is at the 6th Gear
			case 0b10000000:
				speedValue = (40035 * RPM) / 100000;
				break;
			
			default:
				break;
		}
		
		if(ECU0_aliveSignal == 1) { //if ECU0 is not present
			errorSignal = 0; //Setting the Error Signal to TRUE status
			LED7 = ~LED7; //Blinking LED7
		}
		else if(ECU0_aliveSignal == 0) { //if ECU0 is present
			LED7 = 1; //LED7 is OFF
		}

		if(timer0Flag_100ms == 1) {
			CAN_Send_100ms_Interrupt(); //Sending the messages through CAN-Bus
			timer0Flag_100ms = 0; //Reseting the Timer0 Flag to 0
		}

		if(timer1Flag_200ms == 1) {
			CAN_Send_200ms_Interrupt(); //Sending the messages through CAN-Bus
			timer1Flag_200ms = 0; //Reseting the Timer1 Flag to 0
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
	//Buffer 0 used to receive Gears Message from ECU1
    CAN_0.BUF[0].CS.B.IDE = 0;
    CAN_0.BUF[0].CS.B.SRR = 0;
    CAN_0.BUF[0].CS.B.RTR = 0;
    CAN_0.BUF[0].CS.B.LENGTH = 0x1; //1 byte
    CAN_0.BUF[0].ID.B.STD_ID = 0x202;
    CAN_0.BUF[0].CS.B.CODE = 0x4; //0b0100
    //Individual mask register
    CAN_0.RXIMR[0].R = 0x01FFFFFF;
    
    //Buffer 1 used to receive RPM Message from ECU1
    CAN_0.BUF[1].CS.B.IDE = 0;
    CAN_0.BUF[1].CS.B.SRR = 0;
    CAN_0.BUF[1].CS.B.RTR = 0;
    CAN_0.BUF[1].CS.B.LENGTH = 0x2; //2 bytes
    CAN_0.BUF[1].ID.B.STD_ID = 0x201;
    CAN_0.BUF[1].CS.B.CODE = 0x4; //0b0100
    //Individual mask register
    CAN_0.RXIMR[1].R = 0x01FFFFFF;
    
    //Buffer 2 used to receive Alive Signal from ECU0
    CAN_0.BUF[2].CS.B.IDE = 0;
    CAN_0.BUF[2].CS.B.SRR = 0;
    CAN_0.BUF[2].CS.B.RTR = 0;
    CAN_0.BUF[2].CS.B.LENGTH = 0x0; //0 bits
    CAN_0.BUF[2].ID.B.STD_ID = 0x105;
    CAN_0.BUF[2].CS.B.CODE = 0x4; //0b0100
    //Individual mask register
    CAN_0.RXIMR[2].R = 0x01FFFFFF;
    
    //Buffer 8 used to send Engine Coolant Temperature Message
    CAN_0.BUF[8].CS.B.IDE = 0;
    CAN_0.BUF[8].CS.B.SRR = 0;
    CAN_0.BUF[8].CS.B.RTR = 0;
    CAN_0.BUF[8].CS.B.LENGTH = 0x2; //2 bytes
    CAN_0.BUF[8].ID.B.STD_ID = 0x501;
    CAN_0.BUF[8].CS.B.CODE = 0xC; //0b1100
    //Individual mask register
    CAN_0.RXIMR[8].R = 0x01FFFFFF;
    
    //Buffer 9 used to send Speed Message
    CAN_0.BUF[9].CS.B.IDE = 0;
    CAN_0.BUF[9].CS.B.SRR = 0;
    CAN_0.BUF[9].CS.B.RTR = 0;
    CAN_0.BUF[9].CS.B.LENGTH = 0x2; //2 bytes
    CAN_0.BUF[9].ID.B.STD_ID = 0x502;
    CAN_0.BUF[9].CS.B.CODE = 0xC; //0b1100
    //Individual mask register
    CAN_0.RXIMR[9].R = 0x01FFFFFF;
    
    //Buffer 10 used to send Headlight Switch Message
    CAN_0.BUF[10].CS.B.IDE = 0;
    CAN_0.BUF[10].CS.B.SRR = 0;
    CAN_0.BUF[10].CS.B.RTR = 0;
    CAN_0.BUF[10].CS.B.LENGTH = 0x1; //1 byte
    CAN_0.BUF[10].ID.B.STD_ID = 0x503;
    CAN_0.BUF[10].CS.B.CODE = 0xC; //0b1100
    //Individual mask register
    CAN_0.RXIMR[10].R = 0x01FFFFFF;
    
    //Buffer 11 used to send Alive Signal Message
    CAN_0.BUF[11].CS.B.IDE = 0;
    CAN_0.BUF[11].CS.B.SRR = 0;
    CAN_0.BUF[11].CS.B.RTR = 0;
    CAN_0.BUF[11].CS.B.LENGTH = 0x0; //0 bits
    CAN_0.BUF[11].ID.B.STD_ID = 0x504;
    CAN_0.BUF[11].CS.B.CODE = 0xC; //0b1100
    //Individual mask register
    CAN_0.RXIMR[11].R = 0x01FFFFFF;
    
    //Buffer 12 used to send Error Message
    CAN_0.BUF[12].CS.B.IDE = 0;
    CAN_0.BUF[12].CS.B.SRR = 0;
    CAN_0.BUF[12].CS.B.RTR = 0;
    CAN_0.BUF[12].CS.B.LENGTH = 0x0; //0 bits
    CAN_0.BUF[12].ID.B.STD_ID = 0x505;
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
    
    //Sending Speed (M_ID = 0x502) through Buffer 9
    CAN_0.BUF[9].DATA.B[0] = speedValue;
    CAN_0.BUF[9].DATA.B[1] = (speedValue >> 8);
    for(i = 2; i < 8; i++)
		CAN_0.BUF[9].DATA.B[i] = 0;
    CAN_0.BUF[9].CS.B.CODE = 0xC; //0b1100
}

void CAN_Send_200ms_Interrupt(void) {
    int i;
    
    //Sending Engine Coolant Temperature (M_ID = 0x501) through Buffer 8
    CAN_0.BUF[8].DATA.B[0] = engineCoolantTemperature;
    CAN_0.BUF[8].DATA.B[1] = (engineCoolantTemperature >> 8);
    for(i = 2; i < 8; i++)
		CAN_0.BUF[8].DATA.B[i] = 0;
    CAN_0.BUF[8].CS.B.CODE = 0xC; //0b1100
    
    //Sending Headlight Switch (M_ID = 0x503) through Buffer 10
    CAN_0.BUF[10].DATA.B[0] = (parkingLight_HeadlightSwitch_Status << 2) | (lowBeam_HeadlightSwitch_Status << 1) | (highBeam_HeadlightSwitch_Status);
    for(i = 1; i < 8; i++)
		CAN_0.BUF[10].DATA.B[i] = 0;
    CAN_0.BUF[10].CS.B.CODE = 0xC; //0b1100
    
    //Sending Alive Signal (M_ID = 0x504) through Buffer 11
    CAN_0.BUF[11].DATA.B[0] = 0x00;
    for(i = 1; i < 8; i++)
		CAN_0.BUF[11].DATA.B[i] = 0;
    CAN_0.BUF[11].CS.B.CODE = 0xC; //0b1100
    
    //Sending Error Message (M_ID = 0x505) through Buffer 12 if ECU0 is not present
    CAN_0.BUF[12].DATA.B[0] = errorSignal;
    for(i = 1; i < 8; i++)
		CAN_0.BUF[12].DATA.B[i] = 0;
    CAN_0.BUF[12].CS.B.CODE = 0xC; //0b1100
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
	//Buffer 0 used to receive the Gear from ECU1
    Gear = CAN_0.BUF[0].DATA.B[0]; //Receiving the current gear of the car
    CAN_0.BUF[0].CS.B.CODE = 0x4; //0b0100
    
    //Buffer 1 used to receive the RPM value from ECU1
    RPM_Temp = CAN_0.BUF[1].DATA.B[1];
    RPM_Temp <<= 8;
    RPM = CAN_0.BUF[1].DATA.B[0] | RPM_Temp; //Value = LSB + (MSB << 8)
    CAN_0.BUF[1].CS.B.CODE = 0x4; //0b0100
    
    //Buffer 2 used to receive the Alive Signal from ECU0
    ECU0_aliveSignal = CAN_0.BUF[2].DATA.B[0]; //Receiving ECU0 Alive Signal
    CAN_0.BUF[2].CS.B.CODE = 0x4; //0b0100
    
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
    timer1Flag_200ms = 1; //Setting a Flag when the timer is 200ms
    
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
