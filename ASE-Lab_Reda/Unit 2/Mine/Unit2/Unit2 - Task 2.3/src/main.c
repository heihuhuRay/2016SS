#include "api.h"

int speedValue = 0;

void conf_can()
{
    //Mask register configuration
    CAN_0.RXIMR[0].R = 0x00000000;

    //TX pin configuration
    SIU.PCR[16].B.PA =  1;
    SIU.PCR[16].B.OBE = 1;
    SIU.PCR[16].B.IBE = 0;
    SIU.PCR[16].B.APC = 0;

    //RX pin configuration
    SIU.PCR[17].B.PA =  1;
    SIU.PCR[17].B.IBE = 1; 
    SIU.PCR[17].B.OBE = 0;
    SIU.PCR[17].B.APC = 0;
}

void main(void)
{
    init();
    
    //Timer initialization
	conf_timer1(1, 1000);
}


void timer0_intr()
{
    //Timer interrupt implementation
    static int flag = 0;
    
    LED0 = ~LED0;
    
    if(flag == 0 && speedValue < 300)
        speedValue += 5;
    else 
    {
        flag = 1;
        speedValue -= 5;
        if (speedValue == 0)
            flag = 0;
	}
	
    can_send();
}

void timer1_intr()
{
    // timer interrupt implementation
    LED0 = 1; //ALL LEDs
    LED1 = 1;
    LED2 = 1;
    LED3 = 1;
    LED4 = 1;
    LED5 = 1;
    LED6 = 1;
    LED7 = 1;
    conf_timer0(1, 200);
}

void can_send(void)
{
    // send function
    CAN_0.BUF[4].ID.B.STD_ID = 151;
    CAN_0.BUF[4].CS.B.IDE = 0;
    CAN_0.BUF[4].CS.B.RTR = 0;

    CAN_0.BUF[4].DATA.B[0]= (speedValue & 0xFF);
    CAN_0.BUF[4].DATA.B[1]= (speedValue >> 8);
    CAN_0.BUF[4].DATA.B[2]= 0;
    CAN_0.BUF[4].DATA.B[3]= 0;
    CAN_0.BUF[4].DATA.B[4]= 0;
    CAN_0.BUF[4].DATA.B[5]= 0;
    CAN_0.BUF[4].DATA.B[6]= 0;
    CAN_0.BUF[4].DATA.B[7]= 0;

    CAN_0.BUF[4].CS.B.LENGTH = 2;
    CAN_0.BUF[4].CS.B.CODE = 0b1100;
}

void can_receive()
{
    CAN_0.BUF[0].CS.B.CODE = 0b0100;
        
	if(CAN_0.BUF[0].ID.B.STD_ID == 0x01)
	{
		LED0 = 0;
		//LED1 = 0;
		//LED2 = 0;
		//LED3 = 0;
		//LED4 = 0;
		//LED5 = 0;
		//LED6 = 0;
		//LED7 = 0;
    }
    
    else
    {
    	LED0 = 1; //ALL LEDs
		LED1 = 1;
		LED2 = 1;
		LED3 = 1;
		LED4 = 1;
		LED5 = 1;
		LED6 = 1;
		LED7 = 1;
	}
}

