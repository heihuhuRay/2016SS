#include "api.h"

void showdata(int value);
#pragma inline showdata



void configure_io(void)
{
//Task1
//Please enter the PCR register numbers and initialitation code here 
// LEDs 
   SIU.PCR[9].R  = 0x0200; // D0
   SIU.PCR[42].R = 0x0200; // D1
   SIU.PCR[13].R = 0x0200; // D2
   SIU.PCR[12].R = 0x0200; // D3
   SIU.PCR[62].R = 0x0200; // D4
   SIU.PCR[61].R = 0x0200; // D5
   SIU.PCR[59].R = 0x0200; // D6
   SIU.PCR[11].R = 0x0200; // D7

//task 3
// Buttons & switches
    SIU.PCR[0].R = 0x0100 ; //BT5
    SIU.PCR[1].R = 0x0100 ; //BT6
	SIU.PCR[44].R = 0x0100 ; //SW1
	SIU.PCR[4].R = 0x0100 ; //SW2
	SIU.PCR[3].R = 0x0100 ; //SW3
	SIU.PCR[2].R = 0x0100 ; //SW4
    
}



void main(void)
{
    
    init(); // board initialization
    
  
    
    
   for(;;) // inifinite loop
   {
        /*SIU.GPDO[9].R = 1; // D0
        SIU.GPDO[42].R = 1; // D1
        SIU.GPDO[13].R = 1; // D2
        SIU.GPDO[12].R = 1; // D3
        SIU.GPDO[62].R = 1; // D4
        SIU.GPDO[61].R = 1; // D5
        SIU.GPDO[59].R = 1; // D6
        SIU.GPDO[11].R = 1; // D7*/
   
   // task 3/ task 4 - code for checking button press and timer enable/disable goes here 
        if(SIU.GPDI[0].R == 0) // BT5
            SIU.GPDO[9].R = 0; // D0
        else if(SIU.GPDI[1].R == 0) // BT6
            SIU.GPDO[42].R = 0; // D1
        else if(SIU.GPDI[44].R == 0) // SW1
            SIU.GPDO[13].R = 0; // D2
        else if(SIU.GPDI[4].R == 0) // SW2
            SIU.GPDO[12].R = 0; // D3
        else if(SIU.GPDI[3].R == 0) // SW3
            SIU.GPDO[62].R = 0; // D4
        else if(SIU.GPDI[2].R == 0) // SW4
            SIU.GPDO[61].R = 0; // D5
      
        if(SIU.GPDI[0].R == 1) // BT5
            SIU.GPDO[9].R = 1; // D0
        else if(SIU.GPDI[1].R == 1) // BT6
            SIU.GPDO[42].R = 1; // D1
        else if(SIU.GPDI[44].R == 1) // SW1
            SIU.GPDO[13].R = 1; // D2
        else if(SIU.GPDI[4].R == 1) // SW2
            SIU.GPDO[12].R = 1; // D3
        else if(SIU.GPDI[3].R == 1) // SW3
            SIU.GPDO[62].R = 1; // D4
        else if(SIU.GPDI[2].R == 1) // SW4
            SIU.GPDO[61].R = 1; // D5
        
   } // End for loop
    
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

        
}
void timer1_intr(void)
{
// task 4 - timer 1 interrupt function 

}



