#include "app.h"


void init()
{
	DIO_Port_Direction(CAR,OUTPUT);

	Enable_INT();	
}



void delay_5sec()
{
	Timer_Init(&TIMERS);		/* Timer0, normal mode, no pre-scalar */
	Timer_Start(&TIMERS,FiveSec);

	while((TIFR&0x01)==0);/* Wait for TOV0 to roll over */
	Timer_Stop(TIMER1);
	Timer_Reset(TIMER1);
	TIFR |= (1<<TOV1) ;  		/* Clear TOV0 flag*/
}

void car_light()
{
		DIO_Pin_Write(YELLOW_CAR,LOW);
		DIO_Pin_Write(GREEN_CAR,HIGH);
		delay_5sec();
		DIO_Pin_Write(GREEN_CAR,LOW);
		DIO_Pin_Write(YELLOW_CAR,HIGH);
		delay_5sec();
		DIO_Pin_Write(YELLOW_CAR,LOW);
		DIO_Pin_Write(RED_CAR,HIGH);
		delay_5sec();
		DIO_Pin_Write(RED_CAR,LOW);
		DIO_Pin_Write(YELLOW_CAR,HIGH);
		delay_5sec();

}

void person_light()
{
	DIO_Pin_Read(GREEN_CAR,RED_Reading);

	if((*RED_Reading) == HIGH)
	{
		DIO_Pin_Write(YELLOW_CAR,HIGH);
		delay_5sec();
		DIO_Pin_Write(GREEN_CAR,LOW);
		DIO_Pin_Write(RED_CAR,HIGH);
		delay_5sec();
		DIO_Pin_Write(GREEN_PERSON,HIGH);
		delay_5sec();
		delay_5sec();
		DIO_Pin_Write(YELLOW_PERSON,HIGH);
		DIO_Pin_Write(GREEN_PERSON,LOW);
		delay_5sec();
		DIO_Pin_Write(RED_PERSON,HIGH);

	}

	else if(((*YELLOW_Reading) == HIGH) && ((*RED_Reading) == LOW))
	{
		delay_5sec();
		DIO_Pin_Write(YELLOW_CAR,LOW);
		DIO_Pin_Write(RED_CAR,HIGH);
		delay_5sec();
		DIO_Pin_Write(GREEN_PERSON,HIGH);
		delay_5sec();
		delay_5sec();
		DIO_Pin_Write(YELLOW_PERSON,HIGH);
		DIO_Pin_Write(GREEN_PERSON,LOW);
		delay_5sec();
		DIO_Pin_Write(RED_PERSON,HIGH)
	}

	else
	{
		DIO_Pin_Write(GREEN_PERSON,HIGH);
		delay_5sec();
		delay_5sec();
		DIO_Pin_Write(YELLOW_PERSON,HIGH);
		DIO_Pin_Write(GREEN_PERSON,LOW);
		delay_5sec();
		DIO_Pin_Write(RED_PERSON,HIGH)
	}
}