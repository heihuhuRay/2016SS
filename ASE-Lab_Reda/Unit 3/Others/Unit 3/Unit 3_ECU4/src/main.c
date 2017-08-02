#include <init.h>

unsigned short int speed, alive, HeadLight, ECTemp, error=0;
unsigned short int RPM, gear;

void calcSpeed();
void ReceiveFunction();
void SendFunction();

void main(void)
{
  Init();
  PIT_ConfigureTimer(0, 200);
  PIT_ConfigureTimer(1, 100);
  PIT_StartTimer(0);
  PIT_StartTimer(1);
  for(;;)
   {
     ReceiveFunction();
     SendFunction();
   }
}

void ReceiveFunction()
{
    unsigned short int trpm;
    int count=6, temp=0, i=0;
    int hightbeam=0, lowbeam=0, parking=0;
    // Receive Alive signal from ECU 0
    if(CAN_0.BUF[0].ID.B.STD_ID==0x105){
      if(CAN_0.BUF[0].DATA.B[0]!=1){
        LED7=~LED7;
        error=1;
      }
      else{
	LED7=1;
	error=0;
      }
    }
    // Receive RPM from ECU 1
    if(CAN_0.BUF[1].ID.B.STD_ID==0x201){
      RPM=CAN_0.BUF[1].DATA.B[0];
      trpm=CAN_0.BUF[1].DATA.B[1];
      trpm>>=8;
      RPM+=trpm;
    }
    // Receive Gear from ECU 1
    if(CAN_0.BUF[2].ID.B.STD_ID==0x202){
      temp=CAN_0.BUF[2].DATA.B[0];
      for(i=0;i<8;i++){
        if((temp>>i)==1)
          break;
        else count--;
      }
      if(count==-1)
       gear=9;
      else gear=count;
      count=6;
    }
}

void SendFunction()
{

    // Send Engine Coolant Temperature
    ADC_StartConversion();
    ECTemp=POT;
    
    // Send Light Value
    highbeam=SW4;
    lowbeam=SW3;
    parking=SW1;
    switch(highbeam){
      case 0: if(lowbeam==0 && parking==0)
	       HeadLight=0;
	      else if(lowbeam==1 && parking==0)
	       HeadLight=2;
              else if(lowbeam==0 && parking==1)
	       HeadLight=4;
	      else HeadLight=6;
	      break;
      case 1: if(lowbeam==0 && parking==0)
	       HeadLight=1;
	      else if(lowbeam==1 && parking==0)
	       HeadLight=3;
              else if(lowbeam==0 && parking==1)
	       HeadLight=5;
	      else HeadLight=7;
	      break;
      default: break;
    }
    
    // Send Alive Signal
	alive=1;

    // Send Error Signal


    // Send Speed Value
    calcSpeed();

}

void calcSpeed()
{
 long int temp;
 switch(gear)
 {
   case 0: temp=0; break;
   case 1: temp=7842; break;
   case 2: temp=13112; break;
   case 3: temp=19861; break;
   case 4: temp=27038; break;
   case 5: temp=33149; break;
   case 6: temp=40035; break;
   case 9: temp=7842; break;
   default: break;
 }
 temp=(temp*RPM)/100000;
 speed=temp; 
}

void CAN_MessageBufferInit(void)
{
    int i=0;

    CAN_0.BUF[8].CS.B.CODE = 0xC;  
    CAN_0.BUF[8].CS.B.IDE = 0;
    CAN_0.BUF[8].CS.B.SRR = 0;
    CAN_0.BUF[8].CS.B.RTR = 0;
    CAN_0.BUF[8].CS.B.LENGTH = 2;
    CAN_0.BUF[8].ID.B.STD_ID = 0x501;
    CAN_0.BUF[8].DATA.B[0] = ECTemp;
    CAN_0.BUF[8].DATA.B[1] = (ECTemp >> 8);
    for(i=2;i<8;i++) {
	CAN_0.BUF[8].DATA.B[i] = 0;
    }

    CAN_0.BUF[9].CS.B.CODE = 0xC;  
    CAN_0.BUF[9].CS.B.IDE = 0;
    CAN_0.BUF[9].CS.B.SRR = 0;
    CAN_0.BUF[9].CS.B.RTR = 0;
    CAN_0.BUF[9].CS.B.LENGTH = 1;
    CAN_0.BUF[9].ID.B.STD_ID = 0x503;
    CAN_0.BUF[9].DATA.B[0] = HeadLight;
    for(i=1;i<8;i++) {
	CAN_0.BUF[9].DATA.B[i] = 0;
    }

    CAN_0.BUF[10].CS.B.CODE = 0xC;  
    CAN_0.BUF[10].CS.B.IDE = 0;
    CAN_0.BUF[10].CS.B.SRR = 0;
    CAN_0.BUF[10].CS.B.RTR = 0;
    CAN_0.BUF[10].CS.B.LENGTH = 1;
    CAN_0.BUF[10].ID.B.STD_ID = 0x504;
    CAN_0.BUF[10].DATA.B[0] = alive;
    for(i=1;i<8;i++) {
	CAN_0.BUF[10].DATA.B[i] = 0;
    }

    CAN_0.BUF[11].CS.B.CODE = 0xC;  
    CAN_0.BUF[11].CS.B.IDE = 0;
    CAN_0.BUF[11].CS.B.SRR = 0;
    CAN_0.BUF[11].CS.B.RTR = 0;
    CAN_0.BUF[11].CS.B.LENGTH = 1;
    CAN_0.BUF[11].ID.B.STD_ID = 0x505;
    CAN_0.BUF[11].DATA.B[0] = error;
    for(i=1;i<8;i++) {
	CAN_0.BUF[11].DATA.B[i] = 0;
    }

    CAN_0.BUF[12].CS.B.CODE = 0xC;  
    CAN_0.BUF[12].CS.B.IDE = 0;
    CAN_0.BUF[12].CS.B.SRR = 0;
    CAN_0.BUF[12].CS.B.RTR = 0;
    CAN_0.BUF[12].CS.B.LENGTH = 2;
    CAN_0.BUF[12].ID.B.STD_ID = 0x502;
    CAN_0.BUF[12].DATA.B[0] = speed;
    CAN_0.BUF[12].DATA.B[1] = (speed >> 8);
    for(i=2;i<8;i++) {
	CAN_0.BUF[12].DATA.B[i] = 0;
    }
    // individual mask register

    CAN_0.RXIMR[0].R = 0x1FFFFFFF;  //For 105 signal from ECU0 0000 0001 1010 0111 1111 1111
    CAN_0.RXIMR[1].R = 0x1FFFFFFF;  //For 201 signal from ECU1
    CAN_0.RXIMR[2].R = 0x1FFFFFFF;  //For 202 signal from ECU1

}

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
    CANSEND0();
    PIT.CH[0].TFLG.B.TIF = 1;
}

void PITCHANNEL1() {
    /* clear flag */
    CANSEND1();
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
            //CANSEND0();
            break;
        case 71:
            /* CAN Interrupt for message buffers 12-15 */
            //CANSEND1();
            break;
        default:
            break;
    }
    /* End of Interrupt Request */
    INTC.EOIR.R = 0x00000000;
}
