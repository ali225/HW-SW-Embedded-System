/*
 * DIO.c
 *
 *  Created on: Feb 5, 2019
 *      Author: Eng Ali Gamal
 */


#include "../TYPES.h"
#include "../MACROS.h"
#include "../REGISTERS.h"
#include "DIO.h"



void DIO_VidSetPortDirection(u8 PortNumber, u8 Value)
{
	switch(PortNumber)
	{
	case 0:
		DDRA=Value;
		break;

	case 1:
		DDRB=Value;
		break;

	case 2:
		DDRC=Value;
		break;

	case 3:
		DDRD=Value;
		break;

	default:
		break;

	}
}
void DIO_VidSetPortValue(u8 PortNumber, u8 Value)
{
	switch(PortNumber)
	{
	case 0:
		PORTA=Value;
		break;

	case 1:
		PORTB=Value;
		break;

	case 2:
		PORTC=Value;
		break;

	case 3:
		PORTD=Value;
		break;

	default:
		break;

	}
}

void DIO_VidSetPinDirection(u8 PortNumber,u8 Pin, u8 Value)
{
	switch(PortNumber)
	{
	case 0:
		if (Value==1)
		{
			Set_Bit(DDRA,Pin);
		}
		else if(Value==0)
		{
			Clr_Bit(DDRA,Pin);
		}
		break;
	case 1:
		if (Value==1)
		{
			Set_Bit(DDRB,Pin);
		}
		else if(Value==0)
		{
			Clr_Bit(DDRB,Pin);
		}
		break;

	case 2:
		if (Value==1)
		{
			Set_Bit(DDRC,Pin);
		}
		else if(Value==0)
		{
			Clr_Bit(DDRC,Pin);
		}
		break;

	case 3:
		if (Value==1)
		{
			Set_Bit(DDRD,Pin);
		}
		else if(Value==0)
		{
			Clr_Bit(DDRD,Pin);
		}
		break;
	}
}
void DIO_VidSetPinValue(u8 PortNumber,u8 Pin, u8 Value)
{
	switch(PortNumber)
	{
	case 0:
		if (Value==1)
		{
			Set_Bit(PORTA,Pin);
		}
		else if(Value==0)
		{
			Clr_Bit(PORTA,Pin);
		}
		break;

	case 1:
		if (Value==1)
		{
			Set_Bit(PORTB,Pin);
		}
		else if(Value==0)
		{
			Clr_Bit(PORTB,Pin);
		}
		break;

	case 2:
		if (Value==1)
		{
			Set_Bit(PORTC,Pin);
		}
		else if(Value==0)
		{
			Clr_Bit(PORTC,Pin);
		}
		break;

	case 3:
		if (Value==1)
		{
			Set_Bit(PORTD,Pin);
		}
		else if(Value==0)
		{
			Clr_Bit(PORTD,Pin);
		}
		break;
	}
}

u8 DIO_u8GetPortValue(u8 Port)
{
	u8 Value;
	switch(Port)
	{
	case 0:
		Value=PINA;
		break;

	case 1:
		Value=PINB;
		break;

	case 2:
		Value=PINC;
		break;

	case 3:
		Value=PIND;
		break;

	}

	return Value;
}
u8 DIO_u8GetPinValue(u8 Port,u8 Pin)
{
	u8 Value;
	switch(Port)
	{
	case 0:
		Value=Get_Bit(PINA,Pin);
		break;
	case 1:
		Value=Get_Bit(PINB,Pin);
		break;
	case 2:
		Value=Get_Bit(PINC,Pin);
		break;
	case 3:
		Value=Get_Bit(PIND,Pin);
		break;
	}

	return Value;
}


