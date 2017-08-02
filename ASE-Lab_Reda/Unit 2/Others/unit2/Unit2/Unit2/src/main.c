#include "api.h"

int kmh = 0;
int upOrDown = 0;


void conf_can()
{
    int i=0;

    // mask register configuration
    CAN_0.RXIMR[0].R = 0x1FC7FFFF; // task 4

    for(i=0; i<16; i++)
       CAN_0.BUF[i].ID.B.STD_ID = 0x0;

    CAN_0.BUF[0].ID.B.STD_ID = 0x81;

 

    // TX pin configuration
    SIU.PCR[16].B.PA = 1;
    SIU.PCR[16].B.OBE = 1;
    SIU.PCR[16].B.IBE = 0;
    SIU.PCR[16].B.APC = 0;

    //RX pin configuration
    SIU.PCR[17].B.PA = 1;
    SIU.PCR[17].B.IBE = 1;
    SIU.PCR[17].B.OBE = 0;
    SIU.PCR[17].B.APC = 0;
}

void main(void)
{
    init();
    conf_timer0(1,200);
    // timer initialization

    // task 4 initialization code for the message buffer
    //CAN_0.BUF[].ID.B.STD_ID= ;
    for(;;)
       {
        

       }
}


void timer0_intr()
{
    // increment some

    // send new kmh value to cokcpit

        if(upOrDown == 0)
            {
               kmh+=5;
            }
        else
            {
            kmh -=5;
            }

            
        if(kmh >= 300 )
        {
        upOrDown = 1;
        }
        else if (kmh <= 0)
        {
        upOrDown = 0;
        }
    


        can_send(kmh);

}

/*
int x;
int y;


    
    
        for (x =0; x < 60; x ++)
{
            kmh +=5;
            can_send(kmh);
}

        for (y =60; y < 0; y --)
{
            kmh -=5;
            can_send(kmh);
}


}*/

void can_send(int zahl)
{
    // send function
    int lsb = zahl & 0xFF;
    int msb = zahl & 0x100;
    msb = msb >> 8;

    CAN_0.BUF[4].ID.B.STD_ID = 163;// Kann sich noch ändern

    CAN_0.BUF[4].CS.B.IDE = 0;
    CAN_0.BUF[4].CS.B.RTR = 0;

    CAN_0.BUF[4].DATA.B[0]=lsb;
    CAN_0.BUF[4].DATA.B[1]=msb;
    CAN_0.BUF[4].DATA.B[2]=0;
    CAN_0.BUF[4].DATA.B[3]=0;
    CAN_0.BUF[4].DATA.B[4]=0;
    CAN_0.BUF[4].DATA.B[5]=0;
    CAN_0.BUF[4].DATA.B[6]=0;
    CAN_0.BUF[4].DATA.B[7]=0;

    CAN_0.BUF[4].CS.B.LENGTH = 2;
    CAN_0.BUF[4].CS.B.CODE = 0b1100;

    // clearing the interrupt flag here?
    // after sending?
    

}

int can_receive()
{
    LED0 = ~LED0;

    if(CAN_0.BUF[0].CS.B.CODE == 0b0010) //&& CAN_0.BUF[0].ID.B.STD_ID == 0x81)
        {

        //LED0 = 0;
        CAN_0.BUF[0].CS.B.CODE = 0b0100;
        }


   // CAN_0.BUF[0].DATA.B[];
    //CAN_0.BUF[0].DATA.B[];
    //CAN_0.TIMER.R;

  //  CAN_0.BUF[0].ID.B.STD_ID= 163; // Kann sich noch ändern

}

