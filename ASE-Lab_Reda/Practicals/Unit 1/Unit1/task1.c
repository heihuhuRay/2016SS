#include "api.h"
void showdata(int value);
void showdataChanged(int value);
void showdataButton(int value, int value2);
void conf_timer0(int mode,int value);
#pragma inline showdata


int j[8]={9,42,13,12,62,61,59,11};
int k=0;
int i=0;
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
  // SIU.PCR[61].R = 0x0200;      // D5
  // SIU.PCR[59].R = 0x0200;      // D6
  // SIU.PCR[11].R = 0x0200;      // D7 

  /* 
 //task 1
  for(i=0;i<8;i++) 
   {
     k=j[i];
     SIU.PCR[k].R = 0x0200;    
   }

 //task2 subtask 1 and 3
    SIU.PCR[33].R = 0x2500;  //light sensor
 //task2 subtask 2
    SIU.PCR[65].R = 0x2500;    //potentiometer
    
    */
    
    //task 3
// Buttons & switches
    SIU.PCR[1].R = 0x0100; //BT5
    //SIU.PCR[0].R = 0x0100; //BT6
    SIU.PCR[2].R = 0x0100; //SW4
   // SIU.PCR[3].R = 0x0100; //SW3
   // SIU.PCR[4].R = 0x0100; //SW2
   // SIU.PCR[44].R = 0x0100; //SW1

}



void main(void)
{
    int value,value2;
    i=0;
    configure_io();
    init(); // board initialization
  
    
  //  k=0;
  /*
   for(i=0;i<8;i++) 
   {
   //task 1 - please enter your code for checking LEDs here
     k=j[i];
     SIU.GPDO[k].R = 0;    
   }
 */ 
   
  /* //task 2 subtask 1
   for(;;)
     {
       value = ADC_0.CDR[2].B.CDATA;
       showdata(value);
      }
      
    
   //task 2 subtask 2
   for(;;)
     {
       value = ADC_0.CDR[4].B.CDATA;
       showdata(value);
      }
   
   //task 2 subtask 3
    for(;;)
     {
       value = ADC_0.CDR[2].B.CDATA;
       showdataChanged(value);
      }
    
   // task 3/ task 4 - code for checking button press and timer enable/disable goes here  
    for(;;)
     {
      value=SIU.GPDI[1].R;
      value2=SIU.GPDI[2].R;
      showdataButton(value,value2);
     }
     */
     for(;;)
     {
      value=SIU.GPDI[2].R;
      if(value==0) 
        conf_timer0(1,500);
      else conf_timer0(0,0);
     } 
} // End main


void showdataButton(int value,int value2) //task 3
{
   if(value==0 && value2==0){
       SIU.GPDO[9].R = 0;       // D0
       SIU.GPDO[42].R = 0;       // D1
   }else if(value==0 && value2==1){
       SIU.GPDO[9].R = 0;       // D0
       SIU.GPDO[42].R = 1;       // D1
   }else if(value==1 && value2==0){
        SIU.GPDO[9].R = 1;       // D0
        SIU.GPDO[42].R = 0;       // D1
   }else if(value==1 && value2==1){
        SIU.GPDO[9].R = 1;       // D0
        SIU.GPDO[42].R = 1;       // D1
   }
}

void showdata(int value) // task2
{
        if(value <= 256)
        {
        
            SIU.GPDO[9].R = 0;       // D0
            SIU.GPDO[42].R = 1;      // D1
            SIU.GPDO[13].R = 1;      // D2
            SIU.GPDO[12].R = 1;      // D3
            // D0 - on, D1 - off, D2 - off D3 - off
        }
        else if(value > 256 && value <= 512)
        {
        
            SIU.GPDO[9].R = 0;       // D0
            SIU.GPDO[42].R = 0;      // D1
            SIU.GPDO[13].R = 1;      // D2
            SIU.GPDO[12].R = 1;      // D3
            // D0 - on, D1 - on, D2 - off D3 - off
        }
        else if(value > 512 && value <= 768)
        {
        
            SIU.GPDO[9].R = 0;       // D0
            SIU.GPDO[42].R = 0;      // D1
            SIU.GPDO[13].R = 0;      // D2
            SIU.GPDO[12].R = 1;      // D3
            // D0 - on, D1 - on, D2 - on D3 - off
        }    
        else
        {
            SIU.GPDO[9].R = 0;       // D0
            SIU.GPDO[42].R = 0;      // D1
            SIU.GPDO[13].R = 0;      // D2
            SIU.GPDO[12].R =0;      // D3
            // D0 - on, D1 - on, D2 - on, D3 - on
            
        }     

}
void showdataChanged(int value) // task2
{
        if(value <= 205)
        {
        
            SIU.GPDO[9].R = 0;       // D0
            SIU.GPDO[42].R = 0;      // D1
            SIU.GPDO[13].R = 0;      // D2
            SIU.GPDO[12].R = 0;      // D3
            SIU.GPDO[62].R = 0;      // D4
            // D0 - on, D1 - on, D2 - on D3 - on D4 - on
        }
        else if(value > 205 && value <= 410)
        {
        
            SIU.GPDO[9].R = 0;       // D0
            SIU.GPDO[42].R = 0;      // D1
            SIU.GPDO[13].R = 0;      // D2
            SIU.GPDO[12].R = 0;      // D3
            SIU.GPDO[62].R = 1;      // D4
            // D0 - on, D1 - on, D2 - on D3 - on D4 - off
        }
        else if(value > 410 && value <= 615)
        {
        
            SIU.GPDO[9].R = 0;       // D0
            SIU.GPDO[42].R = 0;      // D1
            SIU.GPDO[13].R = 0;      // D2
            SIU.GPDO[12].R = 1;      // D3
            SIU.GPDO[62].R = 1;      // D4
            // D0 - on, D1 - on, D2 - on D3 - off D4 - off
        }    
        else if(value > 615 && value <= 820)
        {
        
            SIU.GPDO[9].R = 0;       // D0
            SIU.GPDO[42].R = 0;      // D1
            SIU.GPDO[13].R = 1;      // D2
            SIU.GPDO[12].R = 1;      // D3
            SIU.GPDO[62].R = 1;      // D4
            // D0 - on, D1 - on, D2 - off D3 - off D4 - off
        } 
        else
        {
            SIU.GPDO[9].R = 1;       // D0
            SIU.GPDO[42].R = 1;      // D1
            SIU.GPDO[13].R = 1;      // D2
            SIU.GPDO[12].R =1;      // D3
            SIU.GPDO[62].R = 1;      // D4
            // D0 - off, D1 - off, D2 - off D3 - off D4 - off
            
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
   SIU.GPDO[9].R=~SIU.GPDO[9].R;
        
}
void timer1_intr(void)
{
// task 4 - timer 1 interrupt function 

}






