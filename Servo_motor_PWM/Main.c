/*
 * Main.c
 *
 *  Created on: Oct 28, 2018
 *      Author: Eng Ali Gamal
 */

#include "Types.h"
#include "REGISTERS.h"
#include "Macros.h"
#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 12000000UL

int main(void) {

	DDRC = 0x01;
	PORTC = 0x00;

	while (1)
	{
		// Rotate Motor to 0 degree
		PORTC |= 1<<0;
		_delay_us(1000);	//1ms
		PORTC &= ~1<<0;

		_delay_ms(1000);	// 1 s

		// Rotate Motor to 90 degree
		PORTC |= 1<<0;
		_delay_us(1500);   //1.5 ms
		PORTC &= ~1<<0;

		_delay_ms(1000);	// 1 s


		// Rotate Motor to 180 degree
		PORTC |= 1<<0;
		_delay_us(2000);   //2ms
		PORTC &= ~1<<0;

		_delay_ms(1000);	// 1 s

	}

}
