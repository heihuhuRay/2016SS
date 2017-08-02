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
     uint8_t arr[7];
     conf_can();
  
     init();
     CAN_0.BUF[0].ID.B.STD_ID= 0x081;

     for(;;)
     {
      if(0==SIU.GPDI[7].R)   //Button 5
       arr[0]=1;
      else arr[0]=0;
      if(0==SIU.GPDI[8].R)   //Button 6
       arr[1]=1;
      else arr[1]=0;
      if(0==SIU.GPDI[1].R)   //Switch 1
       arr[2]=1;
      else arr[2]=0;
      if(0==SIU.GPDI[2].R)   //Switch 2
       arr[3]=1;
      else arr[3]=0;
      if(0==SIU.GPDI[3].R)   //Switch 3
       arr[4]=1;
      else arr[4]=0;
      if(0==SIU.GPDI[4].R)   //Switch 4
       arr[5]=1;
      else arr[5]=0;
     }

}


void timer0_intr()
{
    // timer interrupt implementation. LED blink code goes here
    SIU.GPDO[9].R=~SIU.GPDO[9].R;      
}

void can_send()
{
    // send function
    int i=0;
    CAN_0.BUF[4].ID.B.STD_ID = 0x20;
    CAN_0.BUF[4].CS.B.IDE = 0;
    CAN_0.BUF[4].CS.B.RTR = 0;

    for(i=2;i<8;i++){    
	CAN_0.BUF[4].DATA.B[i]=arr[i];
    }

    CAN_0.BUF[4].CS.B.LENGTH = 6;
    CAN_0.BUF[4].CS.B.CODE = 0xC; //for 1100 in binary
    conf_timer0(1,500);    
}

void can_receive()
{
    CAN_0.BUF[0].CS.B.CODE=0x4; //for 0100
    SIU.GPDO[42].R=0;
}