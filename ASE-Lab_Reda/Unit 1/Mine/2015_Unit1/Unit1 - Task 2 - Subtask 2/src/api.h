#include "jdp.h"


void main(void);
void init(void);
void init_mode(void);
void init_peripherals();
void init_timer(void);
void conf_timer0(int mode, int time);


//external functions
extern void conf_timer1(void);
extern void timer0_intr(void);
extern void timer1_intr(void);
extern void configure_io(void);






