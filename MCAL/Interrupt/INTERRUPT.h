
#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "REG.h"
#include "../BITS.h"
#include "../STD_TYPES.h"


/* External Interrupt Request 0 */
#define EXT_INT_0 __vector_1
/* External Interrupt Request 1 */
#define EXT_INT_1 __vector_2
/* External Interrupt Request 2 */
#define EXT_INT_2 __vector_3

/* Timer Interrupt Vector */

/* Set Global Interrupt, Set the I-bit in status register to 1 */
#define sei() __asm__ __volatile__ ("sei" ::: "memory")

/* Clear Global Interrupt, Set the I-bit in status register to 0 */
#define cli() __asm__ __volatile__ ("cli" ::: "memory")

/* ISR definition */
#define ISR(INT_VECT)void INT_VECT(void) __attribute__((signal,used));\
void INT_VECT(void)




/* Function Prototypes */
/* Using this function to enable Interrupt 0
 * INPUT : uint8_t --> FAILING OR RISING
 * RETURN OK OR ERROR OF EXCUTE */

/* Brief : Using this function to enable Interrupt
 * INTUPT : //
 * RETURN OK OR ERROR OF EXCUTE */
ERROR_int Enable_INT(void);

/* Brief : Using this function to enable Interrupt 0
 * INTUPT : u8 --> FAILING OR RISING
 * RETURN OK OR ERROR OF EXCUTE */
ERROR_int Enable_INT0 (u8 INT_STATE);

/* Brief : Using this function to enable Interrupt 1
 * INTUPT : u8 --> FAILING OR RISING
 * RETURN OK OR ERROR OF EXCUTE */
ERROR_int Enable_INT1 (u8 INT_STATE);

/* Brief : Using this function to disable Interrupt 2
 * INTUPT : u8 --> FAILING OR RISING
 * RETURN OK OR ERROR OF EXCUTE */
ERROR_int Enable_INT2 (u8 INT_STATE);

/* Brief : Using this function to disable Interrupt 0
 * INTUPT : //
 * RETURN OK OR ERROR OF EXCUTE */
ERROR_int Disable_INT(void);

#endif /* INTERRUPT_H_ */
