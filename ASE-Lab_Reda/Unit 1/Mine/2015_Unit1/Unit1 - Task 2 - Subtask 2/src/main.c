#include "api.h"

void showdata(int value);
#pragma inline showdata



void configure_io(void)
{
//Task1
//Please enter the PCR register numbers and initialitation code here 
// LEDs 
   SIU.PCR[9].R = 0x0200;       // D0
   SIU.PCR[42].R = 0x0200;      // D1
   SIU.PCR[13].R = 0x0200;      // D2
   SIU.PCR[12].R = 0x0200;      // D3
   SIU.PCR[62].R = 0x0200;      // D4
   SIU.PCR[61].R = 0x0200;      // D5
   SIU.PCR[59].R = 0x0200;      // D6
   SIU.PCR[11].R = 0x0200;      // D7

//task 3
// Buttons & switches
    //SIU.PCR[].R = ; //BT5
    //SIU.PCR[44].R = 0x0100; //SW1

//task 2 
// Analog inputs configuration
  SIU.PCR[33].R = 0x2500;
  SIU.PCR[34].R = 0x2500;
    
    
}



void main(void)
{
    int value;
    

    init(); // board initialization
    
  
    
    
   for(;;) // inifinite loop
   {
   //task 1 - please enter your code for checking LEDs here
        /*SIU.GPDO[9].R = 0; // D0
		SIU.GPDO[42].R = 0; // D1
		SIU.GPDO[13].R = 0; // D2
		SIU.GPDO[12].R = 0; // D3
		SIU.GPDO[62].R = 0; // D4
		SIU.GPDO[61].R = 0; // D5
		SIU.GPDO[59].R = 0; // D6
		SIU.GPDO[11].R = 0; // D7*/
   
   // task 3/ task 4 - code for checking button press and timer enable/disable goes here 
   
   
   //task2 - subtask 2
   value = ADC_0.CDR[4].B.CDATA; //Potentiometer
   showdata(value);
  
   
   
      
   } // End for loop
    
} // End main




void showdata(int value) // task2
{
        if(value <= 256)
        {
            // task 2 
            // LED status to be shown 
            // D0 - on, D1 - off, D2 - off D3 - off
            SIU.GPDO[9].R = 0; // D0
            SIU.GPDO[42].R = 1; // D1
            SIU.GPDO[13].R = 1; // D2
            SIU.GPDO[12].R = 1; // D3
            SIU.GPDO[62].R = 1; // D4
            SIU.GPDO[61].R = 1; // D5
            SIU.GPDO[59].R = 1; // D6
            SIU.GPDO[11].R = 1; // D7
        }
        else if(value > 256 && value <= 512)
        {
        
            // task 2 
            // LED status to be shown 
            // D0 - on, D1 - on, D2 - off D3 - off
            SIU.GPDO[9].R = 0; // D0
            SIU.GPDO[42].R = 0; // D1
            SIU.GPDO[13].R = 1; // D2
            SIU.GPDO[12].R = 1; // D3
            SIU.GPDO[62].R = 1; // D4
            SIU.GPDO[61].R = 1; // D5
            SIU.GPDO[59].R = 1; // D6
            SIU.GPDO[11].R = 1; // D7
        }
        else if(value > 512 && value <= 768)
        {
            // task 2 
            // LED status to be shown 
            // D0 - on, D1 - on, D2 - on D3 - off
            SIU.GPDO[9].R = 0; // D0
            SIU.GPDO[42].R = 0; // D1
            SIU.GPDO[13].R = 0; // D2
            SIU.GPDO[12].R = 1; // D3
            SIU.GPDO[62].R = 1; // D4
            SIU.GPDO[61].R = 1; // D5
            SIU.GPDO[59].R = 1; // D6
            SIU.GPDO[11].R = 1; // D7
        }    
        else
        {
            // task 2 
            // LED status to be shown 
            // D0 - on, D1 - on, D2 - on, D3 - on
            SIU.GPDO[9].R = 0; // D0
            SIU.GPDO[42].R = 0; // D1
            SIU.GPDO[13].R = 0; // D2
            SIU.GPDO[12].R = 0; // D3
            SIU.GPDO[62].R = 1; // D4
            SIU.GPDO[61].R = 1; // D5
            SIU.GPDO[59].R = 1; // D6
            SIU.GPDO[11].R = 1; // D7
        }     

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






