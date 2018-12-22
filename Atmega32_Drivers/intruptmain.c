/*

 * intruptmain.c
 *
 *  Created on: Dec 14, 2018
 *      Author: Eng Ali Gamal


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define F_CPU 8000000UL

ISR(INT0_vect){

	PORTD |= 1<<5;
	_delay_ms(1000);
}

ISR(INT1_vect){

	PORTD |= 1<<6;
	_delay_ms(1000);

}
ISR(INT2_vect){
	PORTD |= 1<<7;
	_delay_ms(1000);
}

 main()
{

	MCUCR |= (1<<0 | 1<<2 | 1<<3);
	MCUCR &= ~(1<<1);
	MCUCSR &= ~(1<<6);
	GICR |= (1<<5 | 1<<6 | 1<<7);
	sei();
	DDRD |= (1<<5) |(1<<6) |(1<<7);

	while(1)
	{
		PORTD &= ~((1<<5)| (1<<6) | (1<<7));
		_delay_ms(1000);
	}
}
*/
