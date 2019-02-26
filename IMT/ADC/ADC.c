/*
 * ADC.c
 *
 *  Created on: Feb 25, 2019
 *      Author: Eng Ali Gamal
 */
#include "../TYPES.h"  // Types data
#include "../MACROS.h"
#include "../REGISTERS.h"
#include "../DIO/DIO.h"
#include "ADC.h"
#define F_CPU 12000000UL


void ADC_Init()
{
	ADMUX=0b01100000;
	ADCSRA=0b11000111;

	DIO_VidSetPinDirection(0,0,0);
}

u8 ADC_GetResult()
{
	Set_Bit(ADCSRA,6);

	while(Get_Bit(ADCSRA,4)==0)
	{

	}

	Set_Bit(ADCSRA,4);
	return ADCH;
}
