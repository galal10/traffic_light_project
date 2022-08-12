#ifndef APP_H_
#define APP_H_

#include "../MCAL/Timer/timer.h"
#include "../MCAL/Interrupt/INTERRUPT.h"
#include "../MCAL/DIO/DIO.h"


#define CAR 0

#define RED_CAR 	0
#define YELLOW_CAR 	1
#define GREEN_CAR 	2

#define RED_PERSON 		16
#define YELLOW_PERSON 	17
#define GREEN_PERSON 	18

#define switch 26

#define FiveSec 39052

Str_TimerConfiguration_t TIMERS = {TIMER1, F_CPU_CLOCK_1024_TIMER_1, NORMAL_MODE};
u8 *RED_Reading,*YELLOW_Reading;

void delay_5sec();

void init();

#endif /* APP_H_ */