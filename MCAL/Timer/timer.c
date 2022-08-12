/*
 * timer.c
 *
 *  Created on: Jul 25, 2022
 *      Author: galal
 */
#include "timer.h"


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
					TCCR1A &= (0<<WGM10) | (0<<WGM11);
					TCCR1B &= (0<<WGM12) | (0<<WGM13) | (1<<CS10) | (0<<CS11) | (0<<CS12);
				}

				else if(Confg_S->Timer_Psc == F_CPU_CLOCK_8_TIMER_1)
				{
					TCCR1A &= (0<<WGM10) | (0<<WGM11);
					TCCR1B &= (0<<WGM12) | (0<<WGM13) | (0<<CS10) | (1<<CS11) | (0<<CS12);
				}

				else if(Confg_S->Timer_Psc == F_CPU_CLOCK_64_TIMER_1)
				{
					TCCR1A &= (0<<WGM10) | (0<<WGM11);
					TCCR1B &= (0<<WGM12) | (0<<WGM13) | (1<<CS10) | (1<<CS11) | (0<<CS12);
				}

				else if(Confg_S->Timer_Psc == F_CPU_CLOCK_256_TIMER_1)
				{
					TCCR1A &= (0<<WGM10) | (0<<WGM11);
					TCCR1B &= (0<<WGM12) | (0<<WGM13) | (0<<CS10) | (0<<CS11) | (1<<CS12);
				}

				else if(Confg_S->Timer_Psc == F_CPU_CLOCK_1024_TIMER_1)
				{
					TCCR1A &= (0<<WGM10) | (0<<WGM11);
					TCCR1B &= (0<<WGM12) | (0<<WGM13) | (1<<CS10) | (0<<CS11) | (1<<CS12);
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
					// WGM00 (6), WGM01(3) -->>10  for CTC mode && CS00(0), CS01 (1),CS02(2) -->>001 for no prescaling
					// 01000001
					TCCR0 = 0x41;
				}

				else if(Confg_S->Timer_Psc == F_CPU_CLOCK_8_TIMER_0)
				{
					// WGM00 (6), WGM01(3) -->>10  for CTC mode && CS00(0), CS01 (1),CS02(2) -->>010 for 8/ prescaling
					// 01000010
					TCCR0 = 0x42;
				}

				else if(Confg_S->Timer_Psc == F_CPU_CLOCK_64_TIMER_0)
				{
					// WGM00 (6), WGM01(3) -->>10  for CTC mode && CS00(0), CS01 (1),CS02(2) -->>011 for 64/ prescaling
					// 01000011
					TCCR0 = 0x43;
				}

				else if(Confg_S->Timer_Psc == F_CPU_CLOCK_256_TIMER_0)
				{
					// WGM00 (6), WGM01(3) -->>10  for CTC mode && CS00(0), CS01 (1),CS02(2) -->>100 for 256/ prescaling
					// 01000100
					TCCR0 = 0x44;
				}

				else if(Confg_S->Timer_Psc == F_CPU_CLOCK_1024_TIMER_0)
				{
					// WGM00 (6), WGM01(3) -->>10  for CTC mode && CS00(0), CS01 (1),CS02(2) -->>101 for 256/ prescaling
					// 01000101
					TCCR0 = 0x45;
				}

		}

		else if(Confg_S->Timer_Channel == TIMER1)
		{
				if(Confg_S->Timer_Psc == F_CPU_CLOCK_TIMER_1)
				{
					TCCR1A &= (0<<WGM10) | (0<<WGM11);
					TCCR1B &= (1<<WGM12) | (0<<WGM13) | (1<<CS10) | (0<<CS11) | (0<<CS12);

					// clear bits
				}

				else if(Confg_S->Timer_Psc == F_CPU_CLOCK_8_TIMER_1)
				{
					TCCR1A &= (0<<WGM10) | (0<<WGM11);
					TCCR1B &= (1<<WGM12) | (0<<WGM13) | (0<<CS10) | (1<<CS11) | (0<<CS12);
				}

				else if(Confg_S->Timer_Psc == F_CPU_CLOCK_64_TIMER_1)
				{
					TCCR1A &= (0<<WGM10) | (0<<WGM11);
					TCCR1B &= (1<<WGM12) | (0<<WGM13) | (1<<CS10) | (1<<CS11) | (0<<CS12);
				}

				else if(Confg_S->Timer_Psc == F_CPU_CLOCK_256_TIMER_1)
				{
					// clear bits
					TCCR1A &= ~(1<<WGM10) & ~(1<<WGM11);
					TCCR1B &= ~(1<<WGM13) & ~(0<<CS10) & ~(0<<CS11);

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
					// WGM20 (6), WGM21(3) -->>10  for CTC mode && CS20(0), CS21 (1),CS22(2) -->>001 for no prescaling
					// 01000001
					TCCR2 = 0x41;
				}

				else if(Confg_S->Timer_Psc == F_CPU_CLOCK_8_TIMER_2)
				{
					// WGM20 (6), WGM21(3) -->>10  for CTC mode && CS20(0), CS21 (1),CS22(2) -->>010 for 8/ prescaling
					// 01000010
					TCCR2 = 0x42;
				}

				else if(Confg_S->Timer_Psc == F_CPU_CLOCK_32_TIMER_2)
				{
					// WGM20 (6), WGM21(3) -->>10  for CTC mode && CS20(0), CS21 (1),CS22(2) -->>011 for 32/ prescaling
					// 01000011
					TCCR2 = 0x43;
				}

				else if(Confg_S->Timer_Psc == F_CPU_CLOCK_64_TIMER_2)
				{
					// WGM20 (6), WGM21(3) -->>10  for CTC mode && CS20(0), CS21 (1),CS22(2) -->>100 for 64/ prescaling
					// 01000100
					TCCR2 = 0x44;
				}

				else if(Confg_S->Timer_Psc == F_CPU_CLOCK_128_TIMER_2)
				{
					// WGM20 (6), WGM21(3) -->>10  for CTC mode && CS20(0), CS21 (1),CS22(2) -->>101 for 128/ prescaling
					// 01000101
					TCCR2 = 0x45;
				}

				else if(Confg_S->Timer_Psc == F_CPU_CLOCK_256_TIMER_2)
				{
					// WGM20 (6), WGM21(3) -->>10  for CTC mode && CS20(0), CS21 (1),CS22(2) -->>110 for 128/ prescaling
					// 01000110
					TCCR2 = 0x46;
				}

				else if(Confg_S->Timer_Psc == F_CPU_CLOCK_1024_TIMER_2)
				{
					// WGM20 (6), WGM21(3) -->>10  for CTC mode && CS20(0), CS21 (1),CS22(2) -->>111 for 1024/ prescaling
					// 01000111
					TCCR2 = 0x47;
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
				Copy_u32_tickCounts = 0xffff- Copy_u32_tickCounts;
				TCNT1L = Copy_u32_tickCounts & (0x00ff);
				TCNT1H = (Copy_u32_tickCounts>>8);
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
				OCR1AL = Copy_u32_tickCounts & (0x00ff);
				OCR1AH = (Copy_u32_tickCounts>>8);
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
		TCCR0 &= ~(0<<CS00) & ~(0<<CS01) & ~(0<<CS02);
	}

	else if(Copy_u8_timerChannel == TIMER1)
	{
		TCCR1B &= ~(0<<CS10) & ~(0<<CS11) & ~(0<<CS12);
	}
	else if(Copy_u8_timerChannel == TIMER0)
	{
		TCCR2 &= ~(0<<CS20) & ~(0<<CS21) & ~(0<<CS22);
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
	}

	else if(Copy_u8_timerChannel == TIMER1)
	{
		TCNT1H = 0x00;
		TCNT1L = 0x00;
	}

	else if(Copy_u8_timerChannel == TIMER2)
	{
		TCNT2=0x00;
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
