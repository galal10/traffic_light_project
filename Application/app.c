#include "app.h"

//u8 *RED_Reading,*YELLOW_Reading;
Str_TimerConfiguration_t TIMER_blink = {TIMER2, F_CPU_CLOCK_1024_TIMER_2, NORMAL_MODE};
//u8 flag=100;

//void blinking_cycle()
//{
//	Timer_Init(&TIMER_blink);
//	Timer_Start(&TIMER_blink,FiveSec);
//
//	while(READ_BIT(TIFR,TOV2)==0)
//	{
//		changing_cycle();
//	}
//	TIFR|= (1<<TOV2);
//	Timer_Reset(TIMER2);
//	Timer_Stop(TIMER2);
//}

void app_init()
{
	Enable_INT0(RISING);
	Traffic_init();
	init_interrupt_traffic();
	//normal_cycle();
}

void app_start()
{
	normal_cycle();
}

void normal_cycle()
{
	CAR_start();
	//flag = 0;
	delay_5sec();
	for(int i=0;i<5;i++)
	{
		changing_cycle();
		//flag = 1;
	}
	PERSON_start();
	//flag=2;
	delay_5sec();
	for(int i=0;i<5;i++)
	{
		changing_cycle();
		//flag=1;
	}
}

void R_To_Y()
{
	delay_5sec();
	for(int i=0;i<5;i++)
		{changing_cycle();}
	PERSON_start();
	delay_5sec();
	for(int i=0;i<5;i++)
		{changing_cycle();}
	normal_cycle();
}

void Y_To_G()
{
	for(int i=0;i<5;i++)
		{changing_cycle();}
	PERSON_start();
	delay_5sec();
	for(int i=0;i<5;i++)
		{changing_cycle();}
	normal_cycle();
}

void G_To_Y()
{
	for(int i=0;i<5;i++)
		{changing_cycle();}
	PERSON_start();
	delay_5sec();
	for(int i=0;i<5;i++)
		{changing_cycle();}
	normal_cycle();
}



