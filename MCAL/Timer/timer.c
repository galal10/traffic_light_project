/*
 * timer.c
 *
 *  Created on: Jul 25, 2022
 *      Author: galal
 */
#include "Timer.h"


extern u8 Timer_Init(Str_TimerConfiguration_t* Confg_S)
{
	if(Confg_S->Ticks_Mode == NORMAL_MODE)
	{
		if(Confg_S->Timer_Channel == TIMER0)
		{
				if(Confg_S->Timer_Psc == F_CPU_CLOCK_TIMER_0)
				{
					// WGM00 (6), WGM01(3) -->>00  for normal mode && CS00(0), CS01 (1),CS02(2) -->>001 for no prescaling
					// 00000001
					TCCR0 = 0x01;
				}

				else if(Confg_S->Timer_Psc == F_CPU_CLOCK_8_TIMER_0)
				{
					// WGM00 (6), WGM01(3) -->>00  for normal mode && CS00(0), CS01 (1),CS02(2) -->>010 for 8/ prescaling
					// 00000010
					TCCR0 = 0x02;
				}

				else if(Confg_S->Timer_Psc == F_CPU_CLOCK_64_TIMER_0)
				{
					// WGM00 (6), WGM01(3) -->>00  for normal mode && CS00(0), CS01 (1),CS02(2) -->>011 for 64/ prescaling
					// 00000011
					TCCR0 = 0x03;
				}

				else if(Confg_S->Timer_Psc == F_CPU_CLOCK_256_TIMER_0)
				{
					// WGM00 (6), WGM01(3) -->>00  for normal mode && CS00(0), CS01 (1),CS02(2) -->>100 for 256/ prescaling
					// 00000100
					TCCR0 = 0x04;
				}

				else if(Confg_S->Timer_Psc == F_CPU_CLOCK_1024_TIMER_0)
				{
					// WGM00 (6), WGM01(3) -->>00  for normal mode && CS00(0), CS01 (1),CS02(2) -->>101 for 256/ prescaling
					// 00000101
					TCCR0 = 0x05;
				}

		}

		else if(Confg_S->Timer_Channel == TIMER1)
		{

				if(Confg_S->Timer_Psc == F_CPU_CLOCK_TIMER_1)
				{
					// clear bits
					TCCR1A &= ~(1<<WGM10) & ~(1<<WGM11);
					TCCR1B &= ~(1<<WGM12) & ~(1<<WGM13) & ~(1<<CS11) & ~(1<<CS12);

					// set bits
					TCCR1B |= (1<<CS10);


				}

				else if(Confg_S->Timer_Psc == F_CPU_CLOCK_8_TIMER_1)
				{
					// clear bits
					TCCR1A &= ~(1<<WGM10) & ~(1<<WGM11);
					TCCR1B &= ~(1<<WGM12) & ~(1<<WGM13) & ~(1<<CS10) & ~(1<<CS12);

					// set bits
					TCCR1B |= (1<<CS11);
				}

				else if(Confg_S->Timer_Psc == F_CPU_CLOCK_64_TIMER_1)
				{
					// clear bits
					TCCR1A &= ~(1<<WGM10) & ~(1<<WGM11);
					TCCR1B &= ~(1<<WGM12) & ~(1<<WGM13) & ~(1<<CS12);

					// set bits
					TCCR1B |= (1<<CS10) | (1<<CS11);
				}

				else if(Confg_S->Timer_Psc == F_CPU_CLOCK_256_TIMER_1)
				{
					// clear bits
					TCCR1A &= ~(1<<WGM10) & ~(1<<WGM11);
					TCCR1B &= ~(1<<WGM12) & ~(1<<WGM13) & ~(1<<CS10) & ~(1<<CS11);

					// set bits
					TCCR1B |= (1<<CS12);
				}

				else if(Confg_S->Timer_Psc == F_CPU_CLOCK_1024_TIMER_1)
				{
					// clear bits
					TCCR1A &= ~(1<<WGM10) & ~(1<<WGM11);
					TCCR1B &= ~(1<<WGM12) & ~(1<<WGM13) & ~(1<<CS11);

					// set bits

					TCCR1B |= (1<<CS10) | (1<<CS12);
				}

		}

		else if(Confg_S->Timer_Channel == TIMER2)
		{

				if(Confg_S->Timer_Psc == F_CPU_CLOCK_TIMER_2)
				{
					// WGM20 (6), WGM21(3) -->>00  for normal mode && CS20(0), CS21 (1),CS22(2) -->>001 for no prescaling
					// 00000001
					TCCR2 = 0x01;
				}

				else if(Confg_S->Timer_Psc == F_CPU_CLOCK_8_TIMER_2)
				{
					// WGM20 (6), WGM21(3) -->>00  for normal mode && CS20(0), CS21 (1),CS22(2) -->>010 for 8/ prescaling
					// 00000010
					TCCR2 = 0x02;
				}

				else if(Confg_S->Timer_Psc == F_CPU_CLOCK_32_TIMER_2)
				{
					// WGM20 (6), WGM21(3) -->>00  for normal mode && CS20(0), CS21 (1),CS22(2) -->>011 for 32/ prescaling
					// 00000011
					TCCR2 = 0x03;
				}

				else if(Confg_S->Timer_Psc == F_CPU_CLOCK_64_TIMER_2)
				{
					// WGM20 (6), WGM21(3) -->>00  for normal mode && CS20(0), CS21 (1),CS22(2) -->>100 for 64/ prescaling
					// 00000100
					TCCR2 = 0x04;
				}
				else if(Confg_S->Timer_Psc == F_CPU_CLOCK_128_TIMER_2)
				{
					// WGM20 (6), WGM21(3) -->>00  for normal mode && CS20(0), CS21 (1),CS22(2) -->>101 for 128/ prescaling
					// 00000101
					TCCR2 = 0x05;
				}

				else if(Confg_S->Timer_Psc == F_CPU_CLOCK_256_TIMER_2)
				{
					// WGM20 (6), WGM21(3) -->>00  for normal mode && CS20(0), CS21 (1),CS22(2) -->>110 for 256/ prescaling
					// 00000110
					TCCR2 = 0x06;
				}

				else if(Confg_S->Timer_Psc == F_CPU_CLOCK_1024_TIMER_2)
				{
					// WGM20 (6), WGM21(3) -->>00  for normal mode && CS20(0), CS21 (1),CS22(2) -->>111 for 1024/ prescaling
					// 00000111
					TCCR2 = 0x07;
				}


		}
	}

	else if(Confg_S->Ticks_Mode == CTC_MODE)
	{
		if(Confg_S->Timer_Channel == TIMER0)
		{
				if(Confg_S->Timer_Psc == F_CPU_CLOCK_TIMER_0)
				{
					// WGM00 (6), WGM01(3) -->>01  for CTC mode && CS00(0), CS01 (1),CS02(2) -->>001 for no prescaling
					// 00001001
					TCCR0 = 0x09;
				}

				else if(Confg_S->Timer_Psc == F_CPU_CLOCK_8_TIMER_0)
				{
					// WGM00 (6), WGM01(3) -->>01  for CTC mode && CS00(0), CS01 (1),CS02(2) -->>010 for 8/ prescaling
					// 00001010
					TCCR0 = 0x0A;
				}

				else if(Confg_S->Timer_Psc == F_CPU_CLOCK_64_TIMER_0)
				{
					// WGM00 (6), WGM01(3) -->>01  for CTC mode && CS00(0), CS01 (1),CS02(2) -->>011 for 64/ prescaling
					// 00001011
					TCCR0 = 0x0B;
				}

				else if(Confg_S->Timer_Psc == F_CPU_CLOCK_256_TIMER_0)
				{
					// WGM00 (6), WGM01(3) -->>01  for CTC mode && CS00(0), CS01 (1),CS02(2) -->>100 for 256/ prescaling
					// 00001100
					TCCR0 = 0x0C;
				}

				else if(Confg_S->Timer_Psc == F_CPU_CLOCK_1024_TIMER_0)
				{
					// WGM00 (6), WGM01(3) -->>01  for CTC mode && CS00(0), CS01 (1),CS02(2) -->>101 for 256/ prescaling
					// 00001101
					TCCR0 = 0x0D;
				}

		}

		else if(Confg_S->Timer_Channel == TIMER1)
		{
				if(Confg_S->Timer_Psc == F_CPU_CLOCK_TIMER_1)
				{
					// clear bits
					TCCR1A &= ~(1<<WGM10) & ~(1<<WGM11);
					TCCR1B &= ~(1<<WGM13) & ~(1<<CS11) & ~(1<<CS12);

					//set bits
					TCCR1B |= (1<<WGM12) | (1<<CS10);

				}

				else if(Confg_S->Timer_Psc == F_CPU_CLOCK_8_TIMER_1)
				{
					// clear bits 
					TCCR1A &= ~(1<<WGM10) & ~(1<<WGM11);
					TCCR1B &= ~(1<<WGM13) & ~(1<<CS10) & ~(1<<CS12);

					// set bits 
					TCCR1B |= (1<<WGM12) | (1<<CS11);
				}

				else if(Confg_S->Timer_Psc == F_CPU_CLOCK_64_TIMER_1)
				{
					// clear bits
					TCCR1A &= ~(1<<WGM10) & ~(1<<WGM11);
					TCCR1B &= ~(1<<WGM13) & ~(1<<CS12);

					// set bits
					TCCR1B |= (1<<WGM12) | (1<<CS10) | (1<<CS11);

				}

				else if(Confg_S->Timer_Psc == F_CPU_CLOCK_256_TIMER_1)
				{
					// clear bits
					TCCR1A &= ~(1<<WGM10) & ~(1<<WGM11);
					TCCR1B &= ~(1<<WGM13) & ~(1<<CS10) & ~(1<<CS11);

					//set bits
					TCCR1B |= (1<<WGM12) | (1<<CS12);

				}

				else if(Confg_S->Timer_Psc == F_CPU_CLOCK_1024_TIMER_1)
				{
					// clear bits
					TCCR1A &= ~(1<<WGM10) & ~(1<<WGM11);
					TCCR1B &= ~(1<<WGM13) & ~(1<<CS11);

					// set bits
					TCCR1B |= (1<<WGM12) | (1<<CS10) | (1<<CS12);
				}

		}

		else if(Confg_S->Timer_Channel == TIMER2)
		{
				if(Confg_S->Timer_Psc == F_CPU_CLOCK_TIMER_2)
				{
					// WGM20 (6), WGM21(3) -->>01  for CTC mode && CS20(0), CS21 (1),CS22(2) -->>001 for no prescaling
					// 00001001
					TCCR2 = 0x09;
				}

				else if(Confg_S->Timer_Psc == F_CPU_CLOCK_8_TIMER_2)
				{
					// WGM20 (6), WGM21(3) -->>01  for CTC mode && CS20(0), CS21 (1),CS22(2) -->>010 for 8/ prescaling
					// 00001010
					TCCR2 = 0x0A;
				}

				else if(Confg_S->Timer_Psc == F_CPU_CLOCK_32_TIMER_2)
				{
					// WGM20 (6), WGM21(3) -->>01  for CTC mode && CS20(0), CS21 (1),CS22(2) -->>011 for 32/ prescaling
					// 00001011
					TCCR2 = 0x0B;
				}

				else if(Confg_S->Timer_Psc == F_CPU_CLOCK_64_TIMER_2)
				{
					// WGM20 (6), WGM21(3) -->>01  for CTC mode && CS20(0), CS21 (1),CS22(2) -->>100 for 64/ prescaling
					// 00001100
					TCCR2 = 0x0C;
				}

				else if(Confg_S->Timer_Psc == F_CPU_CLOCK_128_TIMER_2)
				{
					// WGM20 (6), WGM21(3) -->>01  for CTC mode && CS20(0), CS21 (1),CS22(2) -->>101 for 128/ prescaling
					// 00001101
					TCCR2 = 0x0D;
				}

				else if(Confg_S->Timer_Psc == F_CPU_CLOCK_256_TIMER_2)
				{
					// WGM20 (6), WGM21(3) -->>01  for CTC mode && CS20(0), CS21 (1),CS22(2) -->>110 for 128/ prescaling
					// 00001110
					TCCR2 = 0x0E;
				}

				else if(Confg_S->Timer_Psc == F_CPU_CLOCK_1024_TIMER_2)
				{
					// WGM20 (6), WGM21(3) -->>01  for CTC mode && CS20(0), CS21 (1),CS22(2) -->>111 for 1024/ prescaling
					// 00001111
					TCCR2 = 0x0F;
				}

		}
	}

	else
	{
		return ERROR_NOK;
	}

	return ERROR_OK;
}


extern u8 Timer_Start(Str_TimerConfiguration_t* Confg_S,u32 Copy_u32_tickCounts)
{
	if(Confg_S->Ticks_Mode == NORMAL_MODE)
	{

		if(Confg_S->Timer_Channel == TIMER0)
		{
			TCNT0=256-Copy_u32_tickCounts;
		}

		else if(Confg_S->Timer_Channel == TIMER1)
		{
			if(Copy_u32_tickCounts >255)
			{
				Copy_u32_tickCounts = 0xFFFF- Copy_u32_tickCounts;
				TCNT1H = (Copy_u32_tickCounts >>8);
				TCNT1L = Copy_u32_tickCounts & (0x00FF);
			}
			else
			{
				TCNT1L = 256 - Copy_u32_tickCounts;
			}
		}

		else if(Confg_S->Timer_Channel == TIMER2)
		{
			TCNT2=256-Copy_u32_tickCounts;
		}
	}

	else if(Confg_S->Ticks_Mode == CTC_MODE)
	{
		if(Confg_S->Timer_Channel == TIMER0)
		{
			TCNT0 = 0x00;
			OCR0 = Copy_u32_tickCounts;
		}

		else if(Confg_S->Timer_Channel == TIMER1)
		{
			TCNT1H = 0x00;
			TCNT1L = 0x00;

			if(Copy_u32_tickCounts > 255)
			{
				OCR1AH = (Copy_u32_tickCounts>>8);
				OCR1AL = Copy_u32_tickCounts & (0x00FF);
			}

			else if(Copy_u32_tickCounts>=255)
				OCR1AL = Copy_u32_tickCounts;
		}

		else if(Confg_S->Timer_Channel == TIMER2)
		{
			TCNT2 = 0x00;
			OCR2 = Copy_u32_tickCounts;
		}
	}

	else
	{
		return ERROR_NOK;
	}

	return ERROR_OK;
}


extern u8 Timer_Stop(u8 Copy_u8_timerChannel)
{
	if(Copy_u8_timerChannel == TIMER0)
	{
		// clear bits
		TCCR0 &= ~(1<<CS00) & ~(1<<CS01) & ~(1<<CS02);
	}

	else if(Copy_u8_timerChannel == TIMER1)
	{
		TCCR1B &= ~(1<<CS10) & ~(1<<CS11) & ~(1<<CS12);
	}
	else if(Copy_u8_timerChannel == TIMER2)
	{
		TCCR2 &= ~(1<<CS20) & ~(1<<CS21) & ~(1<<CS22);
	}
	else
	{
		return ERROR_NOK;
	}

	return ERROR_OK;
}

extern u8 Timer_Reset(u8 Copy_u8_timerChannel)
{
	if(Copy_u8_timerChannel == TIMER0)
	{
		TCNT0=0x00;
		TIFR |= (1<<TOV0);
	}

	else if(Copy_u8_timerChannel == TIMER1)
	{
		TCNT1H = 0x00;
		TCNT1L = 0x00;
		TIFR |= (1<<TOV1);
	}

	else if(Copy_u8_timerChannel == TIMER2)
	{
		TCNT2=0x00;
		TIFR |= (1<<TOV2);
	}
	else
	{
		return ERROR_NOK;
	}

	return ERROR_OK;
}


extern u8 Timer_Get_FlagStatus(Str_TimerConfiguration_t* Confg_S, u8 *Copy_uint8Ptr_FlagStatus)
{
	if(Confg_S->Ticks_Mode == NORMAL_MODE)
	{
		if(Confg_S->Timer_Channel == TIMER0)
		{
			*Copy_uint8Ptr_FlagStatus = READ_BIT(TIFR,TOV0);
		}

		else if(Confg_S->Timer_Channel == TIMER1)
		{
			*Copy_uint8Ptr_FlagStatus = READ_BIT(TIFR,TOV1);
		}

		else if(Confg_S->Timer_Channel == TIMER2)
		{
			*Copy_uint8Ptr_FlagStatus = READ_BIT(TIFR,TOV2);
		}
	}

	else if(Confg_S->Ticks_Mode == CTC_MODE)
	{
		if(Confg_S->Timer_Channel == TIMER0)
		{
			*Copy_uint8Ptr_FlagStatus = READ_BIT(TIFR,OCF0);
		}

		else if(Confg_S->Timer_Channel == TIMER1)
		{
			*Copy_uint8Ptr_FlagStatus = READ_BIT(TIFR,OCF1A);
		}

		else if(Confg_S->Timer_Channel == TIMER2)
		{
			*Copy_uint8Ptr_FlagStatus = READ_BIT(TIFR,OCF2);
		}
	}

	else
	{
		return ERROR_NOK;
	}

	return ERROR_OK;
}


extern u8 delay_5sec()
{
	Str_TimerConfiguration_t TIMERS1 = {TIMER1, F_CPU_CLOCK_1024_TIMER_1, NORMAL_MODE};

	Timer_Init(&TIMERS1);		/* Timer0, normal mode, no pre-scalar */
	Timer_Start(&TIMERS1,FiveSec);

	while(READ_BIT(TIFR,TOV1)==0);/* Wait for TOV0 to roll over */
	Timer_Reset(TIMER1);
	Timer_Stop(TIMER1);

	return ERROR_OK;
}

extern u8 delay_half_sec()
{
	Str_TimerConfiguration_t TIMERS0 = {TIMER0, F_CPU_CLOCK_1024_TIMER_0, NORMAL_MODE};
	int counter = 0;
	while(counter <15)
	{
		Timer_Init(&TIMERS0);		/* Timer0, normal mode, no pre-scalar */
		Timer_Start(&TIMERS0,half_Sec);

		while(READ_BIT(TIFR,TOV0)==0);/* Wait for TOV0 to roll over */
		TIFR|= 1 <<TOV0;
		counter++;
		Timer_Reset(TIMER0);
		Timer_Stop(TIMER0);
	}
	return ERROR_OK;
}
