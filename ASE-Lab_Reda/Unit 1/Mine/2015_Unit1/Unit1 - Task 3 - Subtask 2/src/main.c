#include "api.h"

void showdata(int value);
#pragma inline showdata



void configure_io(void)
{
//Task3 - subtask 2
    SIU.PCR[9].R  = 0x0200; // D0
    SIU.PCR[44].R = 0x0100 ; //SW1
}


void main(void)
{
    SIU.PCR[9].R = 0;

    init(); // board initialization
    for(;;)
    {
        
        conf_timer0(1, 1000);
    }
} // End main





void showdata(int value) // task2
{
}

void conf_timer1(void)
{
// Task 4 
// Timer channel Channel 1

    //PIT.CH[1].LDVAL.B.TSV = ; //Time Start Value Bits     
    //PIT.CH[1].TCTRL.B.TIE = ; // Timer interrupt Enable
    //PIT.CH[1].TCTRL.B.TEN = ; // Timer enable 
    //PIT.CH[1].TFLG.B.TIF = ; // Clear Timer Flag 
}

void timer0_intr(void)
{
// task 3 subtask 2 - LED blink code goes here
    if(SIU.PCR[44].R == 1)
		SIU.GPDO[9].R = SIU.GPDO[9].R;
	else
		SIU.GPDO[9].R = ~SIU.GPDO[9].R;
        
}
void timer1_intr(void)
{
// task 4 - timer 1 interrupt function 

}






