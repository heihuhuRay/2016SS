#include "jdp.h" 
#include "names.h"

void main(void);
void init(void);
void PITCHANNEL0(void);
void init_mode(void);
void init_peripherals();
void init_timer(void);
void init_flexcan(void);
void conf_timer0(int mode, int time);
void conf_timer1(int mode, int time);


extern void can_send(void);
extern void can_receive();
extern void conf_can();
extern void timer0_intr(void);
extern void timer1_intr(void);



