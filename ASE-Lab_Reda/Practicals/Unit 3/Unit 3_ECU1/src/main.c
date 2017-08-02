// header file for all registers
#include "jdp.h"
void CANMessageSending(int buffer,int std_id, int data0,int data1);

int gearVal=00000010;
int count=0;
int nonDrivingSpeed=0;
int drivingSpeed=0;

int ECU2Present=0;

void CANMessageSending(int buffer,int std_id, int data0,int data1)
{
/********************************************************************
 *                              TODO                                *
 ********************************************************************/ 
    // here the message buffers must be defined
    // buffers 0-7 can be used as receive buffers
    // buffers 8-15 can be used as send buffers
    CAN_0.BUF[buffer].CS.B.CODE = 0x8;  
    CAN_0.BUF[buffer].CS.B.IDE = 0;
    CAN_0.BUF[buffer].CS.B.SRR = 0;
    CAN_0.BUF[buffer].CS.B.RTR = 0;
    CAN_0.BUF[buffer].CS.B.LENGTH = 2;
    CAN_0.BUF[buffer].ID.B.STD_ID = std_id;
    CAN_0.BUF[buffer].DATA.B[0] = data0;
    CAN_0.BUF[buffer].DATA.B[1] = data1;
    CAN_0.BUF[buffer].DATA.B[2] = 0x0;
    CAN_0.BUF[buffer].DATA.B[3] = 0x0;
    CAN_0.BUF[buffer].DATA.B[4] = 0x0;
    CAN_0.BUF[buffer].DATA.B[5] = 0x0;
    CAN_0.BUF[buffer].DATA.B[6] = 0x0;
    CAN_0.BUF[buffer].DATA.B[7] = 0x0;
}

#define FIRST8(a) (0b0011111111) & a
#define LAST2(a) (0b0000000011) & (a >> 8)
#define COMBINE(a, b) ((b << 8) |  a)

void main(void)
{
    Init();

	
	PIT_ConfigureTimer(0,100);
	PIT_StartTimer(0);
	
	PIT_ConfigureTimer(1,200);
	PIT_StartTimer(1);
    // forever
    for(;;)
    {
/********************************************************************
 *                              TODO                                *
 ********************************************************************/    
    }
}

/********************************************************************
 *                here are the interrupt functions                  *
 ********************************************************************/

void CANERR(void) {
    CAN_0.ESR.B.ERRINT = 1;
}

void CANBOFF(void) {
    CAN_0.ESR.B.BOFFINT = 1;
}

void CANWAK(void) {
    CAN_0.ESR.B.WAKINT = 1;
}

void CANSEND0(void) {
    CAN_0.IFRL.B.BUF08I = 1;
    CAN_0.IFRL.B.BUF09I = 1;
    CAN_0.IFRL.B.BUF10I = 1;
    CAN_0.IFRL.B.BUF11I = 1;
}

void CANSEND1(void) {
    CAN_0.IFRL.B.BUF12I = 1;
    CAN_0.IFRL.B.BUF13I = 1;
    CAN_0.IFRL.B.BUF14I = 1;
    CAN_0.IFRL.B.BUF15I = 1;
}

void CANRCV0(void)
{
    CAN_0.IFRL.B.BUF00I = 1;    
    CAN_0.IFRL.B.BUF01I = 1;    
    CAN_0.IFRL.B.BUF02I = 1;    
    CAN_0.IFRL.B.BUF03I = 1;
	
	switch(CAN_0.BUF[0].ID.B.STD_ID){
	case 0x302:
		nonDrivingSpeed=COMBINE(CAN_0.BUF[0].DATA.B[0],CAN_0.BUF[0].DATA.B[1]);
		break;
		
	case 0x502:
		drivingSpeed=COMBINE(CAN_0.BUF[0].DATA.B[0],CAN_0.BUF[0].DATA.B[1]);
		break;
		
	case 0x303:
		ECU2Present=1;
		break;
	}
	
}

void CANRCV1(void)
{
    CAN_0.IFRL.B.BUF04I = 1;
    CAN_0.IFRL.B.BUF05I = 1;
    CAN_0.IFRL.B.BUF06I = 1;
    CAN_0.IFRL.B.BUF07I = 1;
}

void PITCHANNEL0() 
{
    // clear timer flag
    PIT.CH[0].TFLG.B.TIF = 1;
	
	ADC_StartConversion();
	
	//Alive message
	CANMessageSending(11,0x204,0,0);
	
	//RPM value
	CANMessageSending(8,0x201,FIRST8(POT*10),LAST2(POT*10));
}

void PITCHANNEL1() 
{
    // clear timer flag
    PIT.CH[1].TFLG.B.TIF = 1;
	
	ADC_StartConversion();
	
	if(BT6==0){ //Gear shift up
		if(count<5){
			gearVal>>1;
			count++;
		}
	}else if(BT5==0){//Gear shift down
		if(count>-1){
			gearVal<<1;
			count--;
		}
	}
	CANMessageSending(9,0x202,gearVal,0);
	
	if(ECU2Present==1){
		LED7=1;
	}else{
		//ECU2 not present error
		LED7=~LED7;
		CANMessageSending(10,0x205,0,0);
	}
	
	if(drivingSpeed-nonDrivingSpeed>15){
		//Driving speed error
		CANMessageSending(10,0x203,00000000,0);
	}else{
		CANMessageSending(10,0x203,00000001,0);
	}
}

/********************************************************************
 * When an interrupt is recognized, this function will be executed  *
 * It looks for the interrupt and calls the corresponding interrupt *
 * function                                                         *
 ********************************************************************/

#pragma interrupt Ext_Isr
#pragma section IrqSect RX address=0x040
#pragma use_section IrqSect Ext_Isr

void Ext_Isr() {
    switch(INTC.IACKR.B.INTVEC)
    {
        case 59:
            // Timer Interrupt
            PITCHANNEL0();
            break;
        case 60:
            // Timer Interrupt
            PITCHANNEL1();
            break;            
        case 65:
            // CAN Error Interrupt
            CANERR();
            break;
        case 66:
            // CAN Bus Off Interrupt
            CANBOFF();
            break;
        case 67:
            // CAN Wakeup Interrupt
            CANWAK();
        case 68:
            // CAN Interrupt for MBs 0-3
            CANRCV0();
            break;
        case 69:
            // CAN Interrupt for MBs 4-7
            CANRCV1();
            break;
        case 70:
            // CAN Interrupt for MBs 8-11
            CANSEND0();
            break;
        case 71:
            // CAN Interrupt for MBs 12-15
            CANSEND1();
            break;
        default:
            break;
    }
    // End of Interrupt Request
    INTC.EOIR.R = 0x00000000;
}
