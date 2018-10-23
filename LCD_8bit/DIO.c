/*
 * DIO.c
 *
 *  Created on: Oct 15, 2018
 *      Author: Eng Ali Gamal
 */



#include"Types.h"
#include"Registers.h"
#include"Macros.h"
#include"DIO.h"

void DIO_vidSetPortDirection(u8 port,u8 value)
{
	switch(port)
	{
	case 0:DDRA=value;break;
	case 1:DDRB=value;break;
	case 2:DDRC=value;break;
	case 3:DDRD=value;break;

	}
}
void DIO_vidSetPortValue(u8 port,u8 value)
{
	switch(port)
	{
		case 0:PORTA=value;break;
		case 1:PORTB=value;break;
		case 2:PORTC=value;break;
		case 3:PORTD=value;break;

	}
}
void DIO_vidSetPinDirection(u8 port,u8 pin,u8 value)
{
switch(port)
{
case 0:
	if(value==1)
{
	Set_Bit(DDRA,pin);
}
else
{
	Clr_Bit(DDRA,pin);
}
break;
case 1:
if(value==1){
	Set_Bit(DDRB,pin);
}
else{
	Clr_Bit(DDRB,pin);
}
break;
case 2:
if(value==1){
	Set_Bit(DDRC,pin);
}
else{
	Clr_Bit(DDRC,pin);
}
break;
case 3:
if(value==1){
	Set_Bit(DDRD,pin);
}
else{
	Clr_Bit(DDRD,pin);
}
break;
}
}

void DIO_vidSetPinValue(u8 port,u8 pin,u8 value){
switch(port){
case 0:
if(value==1){
			Set_Bit(PORTD,pin);
}
else{
	Clr_Bit(PORTA,pin);
}
break;
case 1:
if(value==1){
	Set_Bit(PORTB,pin);
}
else{
	Clr_Bit(PORTB,pin);
}
break;
case 2:
if(value==1){
	Set_Bit(PORTC,pin);
}
else{
	Clr_Bit(PORTC,pin);
}
break;
case 3:
if(value==1){
	Set_Bit(PORTD,pin);
}
else{
	Clr_Bit(PORTD,pin);
}
break;
}
}

u8 DIO_u8ReadPort(u8 port){
	u8 value;
	switch(port){
	case 0:value=PINA;break;
	case 1:value=PINB;break;
	case 2:value=PINC;break;
	case 3:value = PIND;
		break;
	}
	return value;
}

u8 DIO_u8GetPortValue(u8 Port)
{
	u8 Value;
	switch(Port)
	{
	case 0:Value=PINA;break;
	case 1:Value=PINB;break;
	case 2:Value=PINC;break;
	case 3:Value=PIND;break;
	}
	return Value;
}

u8 DIO_u8GetPinValue(u8 Port,u8 Pin)
{
	u8 Value;
	switch(Port)
	{
	case 0:Value=Get_Bit(PINA,Pin);break;
	case 1:Value=Get_Bit(PINB,Pin);break;
	case 2:Value=Get_Bit(PINC,Pin);break;
	case 3:Value=Get_Bit(PIND,Pin);break;
	}
	return Value;
}


