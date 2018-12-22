/*
 * servomotormain.c
 *
 *  Created on: Dec 21, 2018
 *      Author: Eng Ali Gamal
 */


#include <avr/io.h>
#include <util/delay.h>


#define F_CPU 8000000UL // needed by <util/deley.h>

int main (void)
{
	DDRC = 0x01;
	PORTC = 0x00;

	while(1)
	{
		// Rotate motor to 0 degree
		PORTC |=1<<0;
		_delay_us(1000);  //1ms
		PORTC &=~1<<0;

		_delay_ms(1000);  // 1s

		//Rotate motor to 90 degree
		PORTC |= 1<<0;
		_delay_us(1500); //1.5 ms
		PORTC &=~1<<0;

		_delay_ms(1000); // 1s

		//Rotate motor to 180 degree
		PORTC |= 1<<0;
		_delay_us(2000);  //2ms
		PORTC &=~1<<0;


		_delay_ms(1000);  //1 s
	}

}
