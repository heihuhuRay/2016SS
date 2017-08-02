#include "api.h"


void conf_can()
{
    // mask register configuration
    CAN_0.RXIMR[0].R = 0x00000000;

    // TX pin configuration
    //SIU.PCR[].B.PA = ;
    //SIU.PCR[].B.OBE = ;
    //SIU.PCR[].B.IBE = ;
    //SIU.PCR[].B.APC = ;

    //RX pin configuration
    //SIU.PCR[].B.PA = ;
    //SIU.PCR[].B.IBE = ; 
    //SIU.PCR[].B.OBE = ;
    //SIU.PCR[].B.APC = ;
}

void main(void)
{
    init();
    // timer initialization

    // task 4 initialization code for the message buffer
    //CAN_0.BUF[].ID.B.STD_ID= ;

    for(;;)
    {                 
        
    }
}


void timer0_intr()
{
    // timer interrupt implementation
}

void can_send(void)
{
    // send function
    /*
    CAN_0.BUF[].ID.B.STD_ID = ;
    CAN_0.BUF[].CS.B.IDE = 0;
    CAN_0.BUF[].CS.B.RTR = 0;

    CAN_0.BUF[].DATA.B[0]=;
    CAN_0.BUF[].DATA.B[1]=;
    CAN_0.BUF[].DATA.B[2]=;
    CAN_0.BUF[].DATA.B[3]=;
    CAN_0.BUF[].DATA.B[4]=;
    CAN_0.BUF[].DATA.B[5]=;
    CAN_0.BUF[].DATA.B[6]=;
    CAN_0.BUF[].DATA.B[7]=;

    CAN_0.BUF[].CS.B.LENGTH = ;
    CAN_0.BUF[].CS.B.CODE = ;
    */
}

void can_receive()
{
    //CAN_0.BUF[0].CS.B.CODE;
    //CAN_0.BUF[0].ID.B.STD_ID;

    //CAN_0.BUF[0].DATA.B[];
    //CAN_0.BUF[0].DATA.B[];
    //CAN_0.TIMER.R;

    //CAN_0.BUF[0].ID.B.STD_ID=;
}

