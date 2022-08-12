#include "DIO.h"


extern Error DIO_Pin_Write(u8 u8Pin_number , u8 u8Value)
{
	// set bit ports

	if(u8Pin_number >32 || u8Pin_number<0)
		return error;

	else
	{
		if(u8Value == HIGH)
		{
			if(u8Pin_number<=7 && u8Pin_number>=0)	
			{
				switch(u8Pin_number)
				{
				case 0:
					BIT_SET(PORTA,0);
					break;

				case 1:
					BIT_SET(PORTA,1);
					break;

				case 2:
					BIT_SET(PORTA,2);
					break;

				case 3:
					BIT_SET(PORTA,3);
					break;

				case 4:
					BIT_SET(PORTA,4);
					break;

				case 5:
					BIT_SET(PORTA,5);
					break;

				case 6:
					BIT_SET(PORTA,6);
					break;

				case 7:
					BIT_SET(PORTA,7);
					break;
				
				}
			}

			else if(u8Pin_number>=8 && u8Pin_number<=15)
			{
				switch(u8Pin_number)
				{

				case 8:
					BIT_SET(PORTB,0);
					break;

				case 9:
					BIT_SET(PORTB,1);
					break;

				case 10:
					BIT_SET(PORTB,2);
					break;

				case 11:
					BIT_SET(PORTB,3);
					break;

				case 12:
					BIT_SET(PORTB,4);
					break;

				case 13:
					BIT_SET(PORTB,5);
					break;

				case 14:
					BIT_SET(PORTB,6);
					break;

				case 15:
					BIT_SET(PORTB,7);
					break;
				}
			}
			else if(u8Pin_number>=16 && u8Pin_number<=23)
			{
				switch(u8Pin_number)
				{

				case 16:
					BIT_SET(PORTC,0);
					break;

				case 17:
					BIT_SET(PORTC,1);
					break;

				case 18:
					BIT_SET(PORTC,2);
					break;

				case 19:
					BIT_SET(PORTC,3);
					break;

				case 20:
					BIT_SET(PORTC,4);
					break;

				case 21:
					BIT_SET(PORTC,5);
					break;

				case 22:
					BIT_SET(PORTC,6);
					break;

				case 23:
					BIT_SET(PORTC,7);
					break;
				}
			}
			else if(u8Pin_number>=24 && u8Pin_number<=31)
			{
				switch(u8Pin_number)
				{

				case 24:
					BIT_SET(PORTD,0);
					break;

				case 25:
					BIT_SET(PORTD,1);
					break;

				case 26:
					BIT_SET(PORTD,2);
					break;

				case 27:
					BIT_SET(PORTD,3);
					break;

				case 28:
					BIT_SET(PORTD,4);
					break;

				case 29:
					BIT_SET(PORTD,5);
					break;

				case 30:
					BIT_SET(PORTD,6);
					break;

				case 31:
					BIT_SET(PORTD,7);
					break;
				}
			}
		}

		if(u8Value == LOW)
		{
			if(u8Pin_number<=7 && u8Pin_number>=0)	
			{
				switch(u8Pin_number)
				{

				case 0:
					BIT_CLEAR(PORTA,0);
					break;

				case 1:
					BIT_CLEAR(PORTA,1);
					break;

				case 2:
					BIT_CLEAR(PORTA,2);
					break;

				case 3:
					BIT_CLEAR(PORTA,3);
					break;

				case 4:
					BIT_CLEAR(PORTA,4);
					break;

				case 5:
					BIT_CLEAR(PORTA,5);
					break;

				case 6:
					BIT_CLEAR(PORTA,6);
					break;

				case 7:
					BIT_CLEAR(PORTA,7);
					break;
				}
			}

			else if(u8Pin_number>=8 && u8Pin_number<=15)
			{
				switch(u8Pin_number)
				{

				case 8:
					BIT_CLEAR(PORTB,0);
					break;

				case 9:
					BIT_CLEAR(PORTB,1);
					break;

				case 10:
					BIT_CLEAR(PORTB,2);
					break;

				case 11:
					BIT_CLEAR(PORTB,3);
					break;

				case 12:
					BIT_CLEAR(PORTB,4);
					break;

				case 13:
					BIT_CLEAR(PORTB,5);
					break;

				case 14:
					BIT_CLEAR(PORTB,6);
					break;

				case 15:
					BIT_CLEAR(PORTB,7);
					break;
				}
			}

			else if(u8Pin_number>=16 && u8Pin_number<=23)
			{
				switch(u8Pin_number)
				{

				case 16:
					BIT_CLEAR(PORTC,0);
					break;

				case 17:
					BIT_CLEAR(PORTC,1);
					break;

				case 18:
					BIT_CLEAR(PORTC,2);
					break;

				case 19:
					BIT_CLEAR(PORTC,3);
					break;

				case 20:
					BIT_CLEAR(PORTC,4);
					break;

				case 21:
					BIT_CLEAR(PORTC,5);
					break;

				case 22:
					BIT_CLEAR(PORTC,6);
					break;

				case 23:
					BIT_CLEAR(PORTC,7);
					break;
				}
			}

			else if(u8Pin_number>=24 && u8Pin_number<=31)
			{
				switch(u8Pin_number)
				{

				case 24:
					BIT_CLEAR(PORTD,0);
					break;

				case 25:
					BIT_CLEAR(PORTD,1);
					break;

				case 26:
					BIT_CLEAR(PORTD,2);
					break;

				case 27:
					BIT_CLEAR(PORTD,3);
					break;

				case 28:
					BIT_CLEAR(PORTD,4);
					break;

				case 29:
					BIT_CLEAR(PORTD,5);
					break;

				case 30:
					BIT_CLEAR(PORTD,6);
					break;

				case 31:
					BIT_CLEAR(PORTD,7);
					break;
				}
			}
		}
		return ok;
	}

}


extern Error DIO_Pin_Read(u8 u8Pin_number , u8 *pu8Reading)
{
	// read from pins
	if(u8Pin_number>0 && u8Pin_number<=7)
	{
		*pu8Reading = READ_BIT(PINA,u8Pin_number);
	}

	else if(u8Pin_number>=8 && u8Pin_number <=15)
	{
		*pu8Reading = READ_BIT(PINB,8 - u8Pin_number);
	}

	else if(u8Pin_number>=16 && u8Pin_number<=23)
	{
		*pu8Reading = READ_BIT(PINC, 16 - u8Pin_number);
	}

	else if(u8Pin_number>=24 && u8Pin_number<=31)
	{
		*pu8Reading = READ_BIT(PIND,24 - u8Pin_number);
	}

	else
		return error;

	return ok;
}

extern Error DIO_Pin_Init(u8 u8Pin_number , u8 u8State)
{
	// set for ddr
	if(u8Pin_number >32 || u8Pin_number<0)
		return error;

	else
	{
		if(u8State == OUTPUT)
		{
			if(u8Pin_number<=7 && u8Pin_number>=0)
			{
				switch(u8Pin_number)
				{
				case 0:
					BIT_SET(DDRA,0);
					break;

				case 1:
					BIT_SET(DDRA,1);
					break;
				case 2:
					BIT_SET(DDRA,2);
					break;

				case 3:
					BIT_SET(DDRA,3);
					break;

				case 4:
					BIT_SET(DDRA,4);
					break;

				case 5:
					BIT_SET(DDRA,5);
					break;

				case 6:
					BIT_SET(DDRA,6);
					break;

				case 7:
					BIT_SET(DDRA,7);
					break;
				}
			}

			else if(u8Pin_number>=8 && u8Pin_number<=15)
			{
				switch(u8Pin_number)
				{

				case 8:
					BIT_SET(DDRB,0);
					break;

				case 9:
					BIT_SET(DDRB,1);
					break;

				case 10:
					BIT_SET(DDRB,2);
					break;

				case 11:
					BIT_SET(DDRB,3);
					break;

				case 12:
					BIT_SET(DDRB,4);
					break;

				case 13:
					BIT_SET(DDRB,5);
					break;

				case 14:
					BIT_SET(DDRB,6);
					break;

				case 15:
					BIT_SET(DDRB,7);
					break;
				}
			}

			else if(u8Pin_number>=16 && u8Pin_number<=23)
			{
				switch(u8Pin_number)
				{

				case 16:
					BIT_SET(DDRC,0);
					break;

				case 17:
					BIT_SET(DDRC,1);
					break;

				case 18:
					BIT_SET(DDRC,2);
					break;

				case 19:
					BIT_SET(DDRC,3);
					break;

				case 20:
					BIT_SET(DDRC,4);
					break;

				case 21:
					BIT_SET(DDRC,5);
					break;

				case 22:
					BIT_SET(DDRC,6);
					break;

				case 23:
					BIT_SET(DDRC,7);
					break;
				}
			}

			else if(u8Pin_number>=24 && u8Pin_number<=31)
			{
				switch(u8Pin_number)
				{

				case 24:
					BIT_SET(DDRD,0);
					break;

				case 25:
					BIT_SET(DDRD,1);
					break;

				case 26:
					BIT_SET(DDRD,2);
					break;

				case 27:
					BIT_SET(DDRD,3);
					break;

				case 28:
					BIT_SET(DDRD,4);
					break;

				case 29:
					BIT_SET(DDRD,5);
					break;

				case 30:
					BIT_SET(DDRD,6);
					break;

				case 31:
					BIT_SET(DDRD,7);
					break;
				}
			}
		}

		if(u8State == INPUT)
		{
			if(u8Pin_number<=7 && u8Pin_number>=0)
			{
				switch(u8Pin_number)
				{

				case 0:
					BIT_CLEAR(DDRA,0);
					break;

				case 1:
					BIT_CLEAR(DDRA,1);
					break;

				case 2:
					BIT_CLEAR(DDRA,2);
					break;

				case 3:
					BIT_CLEAR(DDRA,3);
					break;

				case 4:
					BIT_CLEAR(DDRA,4);
					break;

				case 5:
					BIT_CLEAR(DDRA,5);
					break;

				case 6:
					BIT_CLEAR(DDRA,6);
					break;

				case 7:
					BIT_CLEAR(DDRA,7);
					break;
				}
			}
			else if(u8Pin_number>=8 && u8Pin_number<=15)
			{
				switch(u8Pin_number)
				{

				case 8:
					BIT_CLEAR(DDRB,0);
					break;

				case 9:
					BIT_CLEAR(DDRB,1);
					break;

				case 10:
					BIT_CLEAR(DDRB,2);
					break;

				case 11:
					BIT_CLEAR(DDRB,3);
					break;

				case 12:
					BIT_CLEAR(DDRB,4);
					break;

				case 13:
					BIT_CLEAR(DDRB,5);
					break;

				case 14:
					BIT_CLEAR(DDRB,6);
					break;

				case 15:
					BIT_CLEAR(DDRB,7);
					break;
				}
			}

			else if(u8Pin_number>=16 && u8Pin_number<=23)
			{
				switch(u8Pin_number)
				{

				case 16:
					BIT_CLEAR(DDRC,0);
					break;

				case 17:
					BIT_CLEAR(DDRC,1);
					break;

				case 18:
					BIT_CLEAR(DDRC,2);
					break;

				case 19:
					BIT_CLEAR(DDRC,3);
					break;

				case 20:
					BIT_CLEAR(DDRC,4);
					break;

				case 21:
					BIT_CLEAR(DDRC,5);
					break;

				case 22:
					BIT_CLEAR(DDRC,6);
					break;

				case 23:
					BIT_CLEAR(DDRC,7);
					break;
				}
			}

			else if(u8Pin_number>=24 && u8Pin_number<=31)
			{
				switch(u8Pin_number)
				{

				case 24:
					BIT_CLEAR(DDRD,0);
					break;

				case 25:
					BIT_CLEAR(DDRD,1);
					break;

				case 26:
					BIT_CLEAR(DDRD,2);
					break;

				case 27:
					BIT_CLEAR(DDRD,3);
					break;

				case 28:
					BIT_CLEAR(DDRD,4);
					break;

				case 29:
					BIT_CLEAR(DDRD,5);
					break;

				case 30:
					BIT_CLEAR(DDRD,6);
					break;

				case 31:
					BIT_CLEAR(DDRD,7);
					break;
				}
			}
		}	
		return ok;
	}

}

extern Error DIO_Port_Write(u8 u8Port_index , u8 u8Value)
{
	if(u8Port_index >3 && u8Port_index <0)
		return error;
	else
	{
		if(u8Value == HIGH)
		{
			switch(u8Port_index)
			{

			case 0:
				PORTA = 0xFF;
				break;

			case 1:
				PORTB = 0xFF;
				break;

			case 2:
				PORTC = 0xFF;
				break;

			case 3:
				PORTD = 0xFF;
				break;
			}
		}

		else if(u8Value == LOW)
		{
			switch(u8Port_index)
			{

			case 0:
				PORTA = 0x00;
				break;

			case 1:
				PORTB = 0x00;
				break;

			case 2:
				PORTC = 0x00;
				break;

			case 3:
				PORTD = 0x00;
				break;
			}
		}

		return ok;
	}
}

extern Error DIO_Port_Read(u8 u8Port_index , u8 *pu8Reading)
{
	if(u8Port_index == 0)
		*pu8Reading = PINA;

	else if(u8Port_index == 1)
		*pu8Reading = PINB;

	else if(u8Port_index == 2)
		*pu8Reading = PINC;

	else if(u8Port_index == 3)
		*pu8Reading = PIND;

	else
		return error;

	return ok;
}

extern Error DIO_Port_Direction(u8 u8Port_index , u8 u8State)
{
	if(u8Port_index >3 && u8Port_index <0)
		return error;
	else
	{
		if(u8State == OUTPUT)
		{
			switch(u8Port_index)
			{

			case 0:
				DDRA = 0xFF;
				break;

			case 1:
				DDRB = 0xFF;
				break;

			case 2:
				DDRC = 0xFF;
				break;

			case 3:
				DDRD = 0xFF;
				break;

			}
		}

		else if(u8State == INPUT)
		{
			switch(u8Port_index)
			{
			case 0:
				DDRA = 0x00;
				break;

			case 1:
				DDRB = 0x00;
				break;

			case 2:
				DDRC = 0x00;
				break;

			case 3:
				DDRD = 0x00;
				break;
			}
		}

		return ok;
	}
}

