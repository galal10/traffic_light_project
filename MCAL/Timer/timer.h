#ifndef TIMER_H_
#define TIMER_H_


#include "../STD_TYPES.h"
#include "../BITS.h"
#include "../AVR_REG.h"

#define FiveSec 39062
#define half_Sec 1

/*________________________________________________________________*/
/******************************************************************/
/*                    Struct Function Input                       */
/******************************************************************/
typedef struct
{
  u8 Timer_Channel; /*Timer Channel (Timer0 or Timer1 or Timer2*/
  u8 Timer_Psc;     /*Timer Prescaler Based on DataSheet No prescaler or /8 or /64 or .....*/
  u8 Ticks_Mode;    /* normal Mode or CTC Mode*/
}Str_TimerConfiguration_t;

/*_______________________________________________________________________________________________________________________________*/
/*________________________________________________________________*/
/******************************************************************/
/*                        MACROS                                  */
/******************************************************************/
#define NO_OF_CHANNELS 3

/*________________________________________________________________*/
/******************************************************************/
/*                        TIMER_CHANNELS                          */
/******************************************************************/
#define TIMER0 0
#define TIMER1 1
#define TIMER2 2
/*________________________________________________________________*/
/******************************************************************/
// TIMER_CHANNELS OverFlow //

#define TIMER0_OVERFLOW 255
#define TIMER1_OVERFLOW 65536
#define TIMER2_OVERFLOW 255

// Normal MODE or CTC Mode //
#define NORMAL_MODE 0
#define CTC_MODE 1

// PreScaler //

// Timer0 //
#define NO_CLOCK_TIMER_0     					0
#define F_CPU_CLOCK_TIMER_0   					1
#define F_CPU_CLOCK_8_TIMER_0 					2
#define F_CPU_CLOCK_64_TIMER_0					3
#define F_CPU_CLOCK_256_TIMER_0					4
#define F_CPU_CLOCK_1024_TIMER_0				5
#define F_EXTERNAL_CLOCK_FALLING_TIMER_0		6
#define F_EXTERNAL_CLOCK_RISING_TIMER_0			7

// Timer1 //
#define NO_CLOCK_TIMER_1     					0
#define F_CPU_CLOCK_TIMER_1   					1
#define F_CPU_CLOCK_8_TIMER_1 					2
#define F_CPU_CLOCK_64_TIMER_1					3
#define F_CPU_CLOCK_256_TIMER_1					4
#define F_CPU_CLOCK_1024_TIMER_1				5
#define F_EXTERNAL_CLOCK_FALLING_TIMER_1		6
#define F_EXTERNAL_CLOCK_RISING_TIMER_1			7

// Timer2 //
#define NO_CLOCK_TIMER_2     					0
#define F_CPU_CLOCK_TIMER_2   					1
#define F_CPU_CLOCK_8_TIMER_2 					2
#define F_CPU_CLOCK_32_TIMER_2					3
#define F_CPU_CLOCK_64_TIMER_2					4
#define F_CPU_CLOCK_128_TIMER_2					5
#define F_CPU_CLOCK_256_TIMER_2		 			6
#define F_CPU_CLOCK_1024_TIMER_2				7

// ERROR STATUS //
#define ERROR_OK     0
#define ERROR_NOK    1

/*Description: Timer/Counter Initialization
 * Input     : Timer_Configuration_S* Confg_S (Struct contain : Timer Channel, Prescaler, Timer mode)
 * Output    : Error Checking
 *_______________________________________________________________________________________________________________________________*/
extern u8 Timer_Init(Str_TimerConfiguration_t* Confg_S);
/*_______________________________________________________________________________________________________________________________*/


/*________________________________________V_______________________________________________________________________________________*/
/*Description: Timer/Counter Start
 * Input     :  Timer Channel(Timer Channel (Timer0 or Timer1 or Timer2), Tick Counting (Counts given by user)
 * Output    : Error Checking
 *_______________________________________________________________________________________________________________________________*/
extern u8 Timer_Start(Str_TimerConfiguration_t* Confg_S,u32 Copy_u32_tickCounts);
/*_______________________________________________________________________________________________________________________________*/


/*_______________________________________________________________________________________________________________________________*/
/*Description: Timer/Counter Stop
 * Input     :  Timer Channel(Timer Channel (Timer0 or Timer1 or Timer2)
 * Output    : Error Checking
 *_______________________________________________________________________________________________________________________________*/
extern u8 Timer_Stop(u8 Copy_u8_timerChannel);
/*_______________________________________________________________________________________________________________________________*/

/*_______________________________________________________________________________________________________________________________*/
/*Description: Timer Reset
 * Input     :  Timer Channel(Timer Channel (Timer0 or Timer1 or Timer2)
 * Output    : Error Checking
 *_______________________________________________________________________________________________________________________________*/
extern u8 Timer_Reset(u8 Copy_u8_timerChannel);
/*_______________________________________________________________________________________________________________________________*/

/*_______________________________________________________________________________________________________________________________*/
/*Description: Get Timer Flag Status
 * Input     : Timer Channel(Timer Channel (Timer0 or Timer1 or Timer2), *FlagStatus (Pointer to Flag)
 * Output    : Error Checking
 *_______________________________________________________________________________________________________________________________*/
extern u8 Timer_Get_FlagStatus(Str_TimerConfiguration_t* Confg_S, u8 *Copy_uint8Ptr_FlagStatus);

extern u8 delay_5sec();
extern u8 delay_half_sec();

#endif /* TIMER_H_ */
