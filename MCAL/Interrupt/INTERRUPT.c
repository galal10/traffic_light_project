#include "INTERRUPT.h"


ERROR_int Enable_INT(void)
{
	BIT_SET(SREG,enable);
	return OK;
}


ERROR_int Enable_INT0(u8 INT_STATE)
{
	Enable_INT();
	BIT_SET(GICR,INT0);
	if(INT_STATE == FAILING)
	{
		BIT_SET(MCUCR,ISC01);
		BIT_CLEAR(MCUCR,ISC00);
	}
	else if(INT_STATE == RISING)
	{
		BIT_SET(MCUCR,ISC00);
		BIT_SET(MCUCR,ISC01);
	}
	else
	{
		return ERROR;
	}
	return OK;

}

ERROR_int Enable_INT1(u8 INT_STATE)
{
	Enable_INT();
	BIT_SET(GICR,INT1);
	if(INT_STATE == FAILING)
	{
		BIT_CLEAR(MCUCR,ISC10);
		BIT_SET(MCUCR,ISC11);
	}
	else if(INT_STATE == RISING)
	{
		BIT_SET(MCUCR,ISC10);
		BIT_SET(MCUCR,ISC11);
	}
	else
	{
		return ERROR;
	}
	return OK;
}

ERROR_int Enable_INT2(u8 INT_STATE)
{
	Enable_INT();
	BIT_SET(GICR,INT2);
	if(INT_STATE == FAILING)
	{
		BIT_CLEAR(MCUCSR,ISC2);
	}
	else if(INT_STATE == RISING)
	{
		BIT_SET(MCUCSR,ISC2);
	}
	else
	{
		return ERROR;
	}
	return OK;
}

ERROR_int Disable_INT(void)
{
	cli();
	return OK;
}
