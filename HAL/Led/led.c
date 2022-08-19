#include "led.h"

void CAR_init(u8 port)
{
	DIO_Port_Direction(port,OUTPUT);
}

void PERSON_init(u8 port)
{
	DIO_Port_Direction(port,OUTPUT);
}

void LED_on(u8 pin)
{
	DIO_Pin_Write(pin,HIGH);
}

void LED_off(u8 pin)
{
	DIO_Pin_Write(pin,LOW);
}

void LED_blink(u8 pin1,u8 pin2)
{
	LED_on(pin1);
	LED_on(pin2);
	delay_half_sec();
	LED_off(pin1);
	LED_off(pin2);
	delay_half_sec();
}

void Traffic_init()
{
	CAR_init(CAR_port);
	PERSON_init(PERSON_port);
}

void CAR_start()
{
	LED_on(GREEN_CAR);
	LED_off(YELLOW_CAR);
	LED_off(RED_CAR);

	LED_on(RED_PERSON);
	LED_off(YELLOW_PERSON);
	LED_off(GREEN_PERSON);
}

void PERSON_start()
{
	LED_on(GREEN_PERSON);
	LED_off(YELLOW_PERSON);
	LED_off(RED_PERSON);

	LED_on(RED_CAR);
	LED_off(YELLOW_CAR);
	LED_off(GREEN_CAR);
}

void changing_cycle()
{
	LED_off(GREEN_CAR);
	LED_off(RED_CAR);

	LED_off(GREEN_PERSON);
	LED_off(RED_PERSON);

	LED_blink(YELLOW_CAR,YELLOW_PERSON);

}
