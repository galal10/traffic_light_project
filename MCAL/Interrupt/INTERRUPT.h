
#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "REG.h"
#include "../BITS.h"
#include "../STD_TYPES.h"

#ifndef _VECTOR
#define _VECTOR(N) __vector_ ## N
#endif

#ifdef __cplusplus
#  define ISR(vector, ...)            \
    extern "C" void vector (void) __attribute__ ((signal,__INTR_ATTRS)) __VA_ARGS__; \
    void vector (void)
#else
#  define ISR(vector, ...)            \
    void vector (void) __attribute__ ((signal,__INTR_ATTRS)) __VA_ARGS__; \
    void vector (void)
#endif


/* Interrupt vectors */

/* External Interrupt Request 0 */
#define INT0_vect			_VECTOR(1)
#define SIG_INTERRUPT0			_VECTOR(1)

/* External Interrupt Request 1 */
#define INT1_vect			_VECTOR(2)
#define SIG_INTERRUPT1			_VECTOR(2)

/* External Interrupt Request 2 */
#define INT2_vect			_VECTOR(3)
#define SIG_INTERRUPT2			_VECTOR(3)


#define _VECTORS_SIZE 84


/* Brief : Using this function to enable Interrupt
 * INTUPT : //
 * RETURN OK OR ERROR OF EXCUTE */
Error Enable_INT(void);

/* Brief : Using this function to enable Interrupt 1
 * INTUPT : u8 --> FAILING OR RISING
 * RETURN OK OR ERROR OF EXCUTE */
Error Enable_INT0 (u8 INT_STATE);

/* Brief : Using this function to enable Interrupt 1
 * INTUPT : u8 --> FAILING OR RISING
 * RETURN OK OR ERROR OF EXCUTE */
Error Enable_INT1 (u8 INT_STATE);

/* Brief : Using this function to enable Interrupt 1
 * INTUPT : u8 --> FAILING OR RISING
 * RETURN OK OR ERROR OF EXCUTE */
Error Enable_INT2 (u8 INT_STATE);



#endif /* INTERRUPT_H_ */

