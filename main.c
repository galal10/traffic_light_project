/*
 * main.c
 *
 *  Created on: Aug 11, 2022
 *      Author: galal
 */



#include "Application/app.h"

//extern u8 flag;
int main(void)
{
	DIO_Port_Direction(2,OUTPUT);
	app_init();
	while(1)
	{
		app_start();
	}
}
ISR(EXT_INT_0)
{

	Disable_INT();
	u8 red_reading,yellow_reading,green_reading;
	DIO_Pin_Read(RED_CAR,&red_reading);
	DIO_Pin_Read(YELLOW_CAR,&yellow_reading);
	DIO_Pin_Read(GREEN_CAR,&green_reading);

	if(red_reading) 	//flag == 0
	{
		G_To_Y();
	}

	else if(yellow_reading) 	//flag == 1
	{

		Y_To_G();
	}

	else if(green_reading) 		//flag == 2
	{
		R_To_Y();
	}
	Enable_INT0(RISING);


}
