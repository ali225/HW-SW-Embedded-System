/*
 * ADC.c
 *
 *  Created on: Oct 27, 2018
 *      Author: Eng Ali Gamal
 */

#include "Types.h"
#include "Macros.h"
#include "DIO.h"
#include "Registers.h"
#define F_CPU 12000000UL
#include <util/delay.h>

void ADC_Init() {

	ADMUX  = 0b01100000;
	ADCSRA = 0b11000111;

	DIO_vidSetPinDirection(0, 0, 0);
}

u8 ADC_GetResult() {
	Set_Bit(ADCSRA, 6); // start conversion

	while (Get_Bit(ADCSRA,4) == 0) {

	}

	Set_Bit(ADCSRA, 4);
	return ADCH;
}

