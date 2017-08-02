#include "api.h"

unsigned short speed=0;
int received=1;
void conf_can()
{
    // mask register configuration
    CAN_0.RXIMR[0].R = 0x1FC7FFFF;   //0001 1111 1100 0111 11..11

    // TX pin configuration
    SIU.PCR[16].B.PA = 1;
    SIU.PCR[16].B.OBE = 1;  //enable when PA=0
    SIU.PCR[16].B.IBE = 0;  //disable
    SIU.PCR[16].B.APC = 0;  //disable analog input

    //RX pin configuration
    SIU.PCR[17].B.PA = 1;
    SIU.PCR[17].B.IBE = 1;   //enable
    SIU.PCR[17].B.OBE = 0;   //enable when PA=1
    SIU.PCR[17].B.APC = 0;   //disable analog input

}

void main(void)
{
     int i=0,value=0;
     conf_can();
  
     init();
     CAN_0.BUF[0].ID.B.STD_ID= 0x081;
     conf_timer0(1,200);       
}


void timer0_intr()
{
    // timer interrupt implementation. LED blink code goes here
    static int flag=0;
    SIU.GPDO[9].R=~SIU.GPDO[9].R;
    if(0==SIU.GPDI[2].R)
    {
     if(flag==0 && speed<300)
     {
      speed+=5; 
     }
     else
     {
      flag=1;
      speed-=5;
      if(speed==0) flag=0; 
     }
     can_send();
    }      
}

void can_send()
{
    // send function
    int i=0;
    CAN_0.BUF[4].ID.B.STD_ID = 0x20;
    CAN_0.BUF[4].CS.B.IDE = 0;
    CAN_0.BUF[4].CS.B.RTR = 0;

    CAN_0.BUF[4].DATA.B[0]=speed;
    CAN_0.BUF[4].DATA.B[1]=speed>>8;
    for(i=2;i<8;i++){    
	CAN_0.BUF[4].DATA.B[i]=0;
    }

    CAN_0.BUF[4].CS.B.LENGTH = 2;
    CAN_0.BUF[4].CS.B.CODE = 0xC; //for 1100 in binary   
}

void can_receive()
{
    CAN_0.BUF[0].CS.B.CODE=0x4; //for 0100
    SIU.GPDO[42].R=0;
}