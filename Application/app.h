#ifndef APP_H_
#define APP_H_

#include "../MCAL/Interrupt/INTERRUPT.h"
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/Timer/Timer.h"
#include "../HAL/Led/led.h"
#include "../HAL/Button/button.h"

//#define FiveSec 39062

void app_init();
void blinking_cycle();
void app_start();
void normal_cycle();
void G_To_Y();
void Y_To_G();
void R_To_Y();

#endif /* APP_H_ */
