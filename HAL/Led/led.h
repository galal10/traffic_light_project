#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/STD_TYPES.h"
#include "../../MCAL/BITS.h"

#define A 0
#define B 1
// port
#define CAR_port 	A
#define PERSON_port B

// pins for car
#define RED_CAR 	0
#define YELLOW_CAR 	1
#define GREEN_CAR 	2

// pins for  person
#define RED_PERSON 		8
#define YELLOW_PERSON 	9
#define GREEN_PERSON 	10


void CAR_init(u8 port);
void PERSON_init(u8 port);
void LED_on(u8 pin);
void LED_off(u8 pin);
void LED_blink(u8 pin1,u8 pin2);
void Traffic_init();
void CAR_start();
void PERSON_start();
void changing_cycle();

#endif /* LED_H_ */
