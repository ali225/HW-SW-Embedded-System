/*
 * LCD.c
 *
 *  Created on: Feb 24, 2019
 *      Author: Eng Ali Gamal
 */
#include <avr/io.h>         // Defines pins, ports, etc
#include <util/delay.h>		// Functions to waste time
#include "../TYPES.h"  // Types data
#include "../MACROS.h"
#include "../REGISTERS.h"
#include "../DIO/DIO.h"
#include "LCD.h"
#include "LCD_Cfg.h"
#define F_CPU 12000000UL


void LCD_VidWriteCharacter(u8 data)
{
	DIO_VidSetPinValue(LCD_Control_Port,Rs,1);
	DIO_VidSetPinValue(LCD_Control_Port,Rw,0);
	DIO_VidSetPortValue(LCD_Port,data);
	DIO_VidSetPinValue(LCD_Control_Port,E,1);
	_delay_ms(1);
	DIO_VidSetPinValue(LCD_Control_Port,E,0);
	_delay_ms(1);
}

void LCD_VidWriteCommand(u8 data)
{
	DIO_VidSetPinValue(LCD_Control_Port,Rs,0);
	DIO_VidSetPinValue(LCD_Control_Port,Rw,0);
	DIO_VidSetPortValue(LCD_Port,data);
	DIO_VidSetPinValue(LCD_Control_Port,E,1);
	_delay_ms(1);
	DIO_VidSetPinValue(LCD_Control_Port,E,0);
	_delay_ms(1);
}


void LCD_VidInit()
{
	DIO_VidSetPortDirection(LCD_Port,255);
	DIO_VidSetPinDirection(LCD_Control_Port,Rw,1);
	DIO_VidSetPinDirection(LCD_Control_Port,Rs,1);
	DIO_VidSetPinDirection(LCD_Control_Port,E,1);

	_delay_ms(50);
	LCD_VidWriteCommand(0b00111000);

	_delay_ms(10);
	LCD_VidWriteCommand(0b00001100);

	_delay_ms(10);
	LCD_VidWriteCommand(0b00000001);

	_delay_ms(10);

}

void LCD_VidWriteString(u8 * arr)
{
	u8 i=0;
	while(arr[i] != '\0')
	{
		LCD_VidWriteCharacter(arr[i]);
		i++;
	}
}

void LCD_VidSetPosition(u8 X, u8 Y)
{
	if(Y==0)
	{
		LCD_VidWriteCommand(128+X);
	}

	else if(Y ==1)
	{
		LCD_VidWriteCommand(128+64+X);
	}
}

void LCD_VidWriteNumber(u64 Number)
{
	u64 temp=1;

	if(Number==0)
	{
		LCD_VidWriteCharacter('0');
	}
	while(Number != 0)
	{
		u8 rem= Number %10;
		Number /=10;
		temp= temp *10 + rem;
	}

	while(temp != 1)
		{
			u8 rem2= temp %10;
			LCD_VidWriteCharacter(rem2 + 48);
			temp/=10;
		}
}




