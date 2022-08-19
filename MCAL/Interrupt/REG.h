/*
 * interrupt.h
 *
 *  Created on: Jul 24, 2022
 *      Author: galal
 */

#ifndef REG_H_
#define REG_H_


#define SREG    (*(volatile unsigned char*)0x5F)
#define GICR    (*(volatile unsigned char*)0x5B)
#define MCUCR   (*(volatile unsigned char*)0x55)
#define MCUCSR  (*(volatile unsigned char*)0x54)
#define GIFR	(*(volatile unsigned char*)0x5A)

#define INT0 	6
#define INT1 	7
#define INT2 	5

/* GIFR bits */
#define INTF1 7
#define INTF0 6
#define INTF2 5

// MCUCR
#define INTF0 6
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3

// MCUCSR
#define ISC2 6

// pin SREG enable interrupt
#define enable 7


// interrupt states
#define FAILING 0
#define RISING  1

typedef enum IN_error
{
	OK,
	ERROR
}ERROR_int;

#endif /* REG_H_ */
