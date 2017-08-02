#include <init.h>

unsigned short int NDWheels, alive, Light, error=0;
unsigned short int flag=1;

void ReceiveFunction();
void SendFunction();

void main(void)
{
  Init();
  PIT_ConfigureTimer(0, 100);
  PIT_ConfigureTimer(1, 400);
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
    unsigned short int indi, hlight, vlight, ulight;

    // Receive Alive signal from ECU 3
    if(CAN_0.BUF[0].ID.B.STD_ID==0x404){
      if(CAN_0.BUF[0].DATA.B[0]!=1){
        LED7=~LED7;
        error=1;
      }
      else{
	LED7=1;
	error=0;
      }
    }
    // Receive Indicator Switch from ECU 3
    if(CAN_0.BUF[1].ID.B.STD_ID==0x402){
      indi=CAN_0.BUF[1].DATA.B[0];
    }
    // Receive Headlights from ECU 4
    if(CAN_0.BUF[2].ID.B.STD_ID==0x503){
      hlight=CAN_0.BUF[2].DATA.B[0];
      hlight*=8;
    }
    // Receive light value from ECU 0
    if(CAN_0.BUF[3].ID.B.STD_ID==0x101){
      vlight=CAN_0.BUF[3].DATA.B[0];
      ulight=CAN_0.BUF[3].DATA.B[1];
      vlight=vlight+(ulight >> 8);
    }
}

void SendFunction()
{
      unsigned int temp, ltemp;
    // Send Light value
      ltemp=SW1;
      //Automatic Mode
      if(ltemp==0)
      {
       if(vlight<512)
       {
        hlight-=48;
       }
      }
      //Manual Mode
       Light=indi+hlight;
    
    // Send non-driven wheels
      ADC_StartConversion();
      temp=POT;
      temp=temp*(300/1024);
      NDWheels=temp; 
    
    // Send Alive Signal
	alive=1;

    // Send Error Signal
}

void CAN_MessageBufferInit(void)
{
    int i=0;

    CAN_0.BUF[12].CS.B.CODE = 0xC;  
    CAN_0.BUF[12].CS.B.IDE = 0;
    CAN_0.BUF[12].CS.B.SRR = 0;
    CAN_0.BUF[12].CS.B.RTR = 0;
    CAN_0.BUF[12].CS.B.LENGTH = 1;
    CAN_0.BUF[12].ID.B.STD_ID = 0x301;
    CAN_0.BUF[12].DATA.B[0] = Light;
    for(i=1;i<8;i++) {
	CAN_0.BUF[12].DATA.B[i] = 0;
    }

    CAN_0.BUF[9].CS.B.CODE = 0xC;  
    CAN_0.BUF[9].CS.B.IDE = 0;
    CAN_0.BUF[9].CS.B.SRR = 0;
    CAN_0.BUF[9].CS.B.RTR = 0;
    CAN_0.BUF[9].CS.B.LENGTH = 2;
    CAN_0.BUF[9].ID.B.STD_ID = 0x302;
    CAN_0.BUF[9].DATA.B[0] = NDWheels;
    CAN_0.BUF[9].DATA.B[1] = (NDWheels >> 8);
    for(i=2;i<8;i++) {
	CAN_0.BUF[9].DATA.B[i] = 0;
    }

    CAN_0.BUF[10].CS.B.CODE = 0xC;  
    CAN_0.BUF[10].CS.B.IDE = 0;
    CAN_0.BUF[10].CS.B.SRR = 0;
    CAN_0.BUF[10].CS.B.RTR = 0;
    CAN_0.BUF[10].CS.B.LENGTH = 1;
    CAN_0.BUF[10].ID.B.STD_ID = 0x303;
    CAN_0.BUF[10].DATA.B[0] = alive;
    for(i=1;i<8;i++) {
	CAN_0.BUF[10].DATA.B[i] = 0;
    }

    CAN_0.BUF[11].CS.B.CODE = 0xC;  
    CAN_0.BUF[11].CS.B.IDE = 0;
    CAN_0.BUF[11].CS.B.SRR = 0;
    CAN_0.BUF[11].CS.B.RTR = 0;
    CAN_0.BUF[11].CS.B.LENGTH = 1;
    CAN_0.BUF[11].ID.B.STD_ID = 0x304;
    CAN_0.BUF[11].DATA.B[0] = error;
    for(i=1;i<8;i++) {
	CAN_0.BUF[11].DATA.B[i] = 0;
    }


    // individual mask register

    CAN_0.RXIMR[0].R = 0x1FFFFFFF;  //For 404 signal from ECU3
    CAN_0.RXIMR[1].R = 0x1FFFFFFF;  //For 402 signal from ECU3
    CAN_0.RXIMR[2].R = 0x1FFFFFFF;  //For 503 signal from ECU4
    CAN_0.RXIMR[3].R = 0x1FFFFFFF;  //For 101 signal from ECU0

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
    if(flag==1)
    {
     flag=0;
    }
    else
    {
     CAN_0.IFRL.B.BUF10I = 1;
     CAN_0.IFRL.B.BUF11I = 1;
     flag=1;
    }
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
    CANSEND1();  //for 400ms light function
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
