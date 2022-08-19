
#ifndef AVR_REG_H_
#define AVR_REG_H_


/** DDR**/
#define DDRA (*(volatile unsigned char*)0x3A)
#define DDRB (*(volatile unsigned char*)0x37)
#define DDRC (*(volatile unsigned char*)0x34)
#define DDRD (*(volatile unsigned char*)0x31)

/** PORT **/

#define PORTA (*(volatile unsigned char*)0x3B)
#define PORTB (*(volatile unsigned char*)0x38)
#define PORTC (*(volatile unsigned char*)0x35)
#define PORTD (*(volatile unsigned char*)0x32)

/** PIN **/

#define PINA (*(volatile unsigned char*)0x39)
#define PINB (*(volatile unsigned char*)0x36)
#define PINC (*(volatile unsigned char*)0x33)
#define PIND (*(volatile unsigned char*)0x30)

/** timers regs time0 **/
#define TCNT0 (*(volatile unsigned char*)0x52)
#define TCCR0 (*(volatile unsigned char*)0x53)
#define TIFR (*(volatile unsigned char*)0x58) /** for all timers pins **/
#define OCR0 (*(volatile unsigned char*)0x5C)

/** time1 **/
#define TCCR1A (*(volatile unsigned char*)0x4F)
#define TCCR1B (*(volatile unsigned char*)0x4E)
#define TCNT1H (*(volatile unsigned char*)0x4D)
#define TCNT1L (*(volatile unsigned char*)0x4C)
#define OCR1AH (*(volatile unsigned char*)0x4B)
#define OCR1AL (*(volatile unsigned char*)0x4A)

/** time2 **/
#define TCNT2 (*(volatile unsigned char*)0x44)
#define TCCR2 (*(volatile unsigned char*)0x45)
#define OCR2 (*(volatile unsigned char*)0x43)


/** The three Clock Select bits select the clock source to be used by the Timer0 **/
#define CS00 0
#define CS01 1
#define CS02 2
#define WGM01 3
#define WGM00 6


/** The three Clock Select bits select the clock source to be used by the Timer2 **/
#define CS20 0
#define CS21 1
#define CS22 2
#define WGM21 3
#define WGM20 6


/** reset timer to count from zero bit make it 1 **/
/** timer 0 **/
#define TOV0 0
#define OCF0 1

/** timer 1 **/
#define WGM10 0
#define WGM11 1
#define WGM12 3
#define WGM13 4
#define CS10 0
#define CS11 1
#define CS12 2
#define TOV1 2
#define OCF1A 4
#define OCF1B 3
#define ICF1 5

/** timer 2 **/
#define TOV2 6
#define OCF2 7

/** enum **/
typedef enum EN_Error 
{
	ok,
	error
}Error;

#endif /* AVR_REG_H_ */
