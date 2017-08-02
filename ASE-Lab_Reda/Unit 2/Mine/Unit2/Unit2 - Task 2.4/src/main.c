#include "api.h"

int speedValue = 0;

void conf_can()
{
    // mask register configuration
    CAN_0.RXIMR[0].R = 0x1FC7FFFF;

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
    conf_can();
  
    init();
    CAN_0.BUF[0].ID.B.STD_ID = 0x081;
    conf_timer0(1, 200);       
}

void timer0_intr()
{
    // timer interrupt implementation
    static int flag = 0;
    //LED0 = ~LED0;
    if(flag == 0 && speedValue < 300)
        speedValue += 5;
    else 
    {
        flag = 1;
        speedValue -= 5;
        if(speedValue == 0)
            flag = 0;
	}
    can_send();

}

void can_send(void)
{
    // send function
    CAN_0.BUF[4].ID.B.STD_ID = 151;
    CAN_0.BUF[4].CS.B.IDE = 0;
    CAN_0.BUF[4].CS.B.RTR = 0;

    CAN_0.BUF[4].DATA.B[0] = (speedValue & 0xFF);
    CAN_0.BUF[4].DATA.B[1] = (speedValue >> 8);

    CAN_0.BUF[4].DATA.B[2] = 0;
    CAN_0.BUF[4].DATA.B[3] = 0;
    CAN_0.BUF[4].DATA.B[4] = 0;
    CAN_0.BUF[4].DATA.B[5] = 0;
    CAN_0.BUF[4].DATA.B[6] = 0;
    CAN_0.BUF[4].DATA.B[7] = 0;

    CAN_0.BUF[4].CS.B.LENGTH = 2;
    CAN_0.BUF[4].CS.B.CODE = 0b1100;
}

void can_receive()
{
    CAN_0.BUF[0].CS.B.CODE = 0b0100;
    LED0 = ~LED0;
}
