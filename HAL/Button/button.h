#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/Interrupt/INTERRUPT.h"
#include "../../MCAL/STD_TYPES.h"

//switch_pin 
#define button 26

void button_init(u8 pin);
void button_status(u8 pin,u8 *reading);
void init_interrupt_traffic();
#endif /* BUTTON_H_ */
