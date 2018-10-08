/*
 * main.c
 *
 *  Created on: Oct 7, 2018
 *      Author: Eng Ali Gamal
 */

#include <util/delay.h>I
#define F_CPU 12000000UL
#include <avr/io.h>


int main(void)
{
	DDRD = 0b11111111;

	while(1)
	{
		PORTD = 0b00000011;
		_delay_ms(500);
		PORTD = 0b00000111;
		_delay_ms(500);
		PORTD = 0b00001111;
		_delay_ms(500);
		PORTD = 0b01001111;
		_delay_ms(500);
		PORTD = 0b01101111;

	}
	return 0;
}

/*int main(void)
{
	DDRD = 0b00000011; // set Led to output

	while(1)
	{
		PORTD =	0b00000011; //LED on
		_delay_ms(100);
		PORTD = 0b00000000;
		_delay_ms(100);		// LED off
	}
	return 0;
}*/

/*int main(void)
{
	DDRD |= 1<<PD1; // set PB6 to output

	while (1)
	{
		PORTD &= ~(1<<PD1); // LED on
		_delay_ms(1000);
		PORTD |= 1<<PD1; // LED off
		_delay_ms(1000);
	}
	return 0;
}*/
