/*
 * main.c
 *
 *  Created on: Oct 7, 2018
 *      Author: Eng Ali Gamal
 */
#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 12000000UL



int main(void)
{
	DDRD = 0b11111111; // set out put DDRD

	while(1)
	{
		PORTD = 0b11111111; // Led on
		_delay_ms(500); 	// delay
		PORTD = 0b00000000;	// led off
		_delay_ms(500);
		PORTD = 0b11111111;
		_delay_ms(500);
		PORTD = 0b010000000;
		_delay_ms(500);
		PORTD = 0b11111111;
		_delay_ms(500);


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
