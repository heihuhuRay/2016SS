#include "api.h"

void showdata(int value);
#pragma inline showdata



void configure_io(void)
{

//Please enter the PCR register numbers and initialitation code here 
// LEDs 

   // SIU.PCR[].R = ;       // D0
   // SIU.PCR[].R = ;      // D1
   // SIU.PCR[].R = ;      // D2
   // SIU.PCR[].R = ;      // D3
   // SIU.PCR[].R = ;      // D4
   // SIU.PCR[].R = ;      // D5
   // SIU.PCR[].R = ;      // D6
   // SIU.PCR[].R = ;      // D7 

//task 3
// Buttons & switches
    //SIU.PCR[].R = ; //BT5
    //SIU.PCR[].R = ; //SW1

//task 2 
// Analog inputs configuration
  //SIU.PCR[].R = ;
  //SIU.PCR[].R = ;
    
}



void main(void)
{
    int value;
    

    init(); // board initialization
    
  
    
    
   for(;;) // inifinite loop
   {
   //task 1 - please enter your code for checking LEDs here
   
   // task 3/ task 4 - code for checking button press and timer enable/disable goes here 
   
   
   //task2
   //value = ;
   //showdata(value);
  
   
   
      
   } // End for loop
    
} // End main




void showdata(int value) // task2
{
        if(value <= 256)
        {
        
            // task 2 
            // LED status to be shown 
            // D0 - on, D1 - off, D2 - off D3 - off
        }
        else if(value > 256 && value <= 512)
        {
        
            // task 2 
            // LED status to be shown 
            // D0 - on, D1 - on, D2 - off D3 - off
        }
        else if(value > 512 && value <= 768)
        {
        
    
            // task 2 
            // LED status to be shown 
            // D0 - on, D1 - on, D2 - on D3 - off
        }    
        else
        {
        
  
            // task 2 
            // LED status to be shown 
            // D0 - on, D1 - on, D2 - on, D3 - on
            
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






