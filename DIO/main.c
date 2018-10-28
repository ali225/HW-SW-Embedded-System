/*
 * main.c
 *
 *  Created on: Oct 7, 2018
 *      Author: Eng Ali Gamal
 */

#include <avr/io.h>          /* Defines pins, ports, etc */
#include <util/delay.h>		/* Functions to waste time */
#include "Types.h"
#include "Macros.h"
#include "REGISTERS.h"
#include "DIO.h"
#define F_CPU 12000000UL

/*int main(void)
 {

// --------Inits --------//
 while(1)
 {
 DIO_VidSetPinDirection(3,1,1);
 DIO_VidSetPinDirection(3,2,1);

 //	DIO_VidSetPinValue(3,1,1);

 DIO_VidSetPinValue(3,1,0);
 _delay_ms(5000);
 DIO_VidSetPinValue(3,1,1);
 _delay_ms(5000);
 DIO_VidSetPinValue(3,2,0);
 _delay_ms(100);
 DIO_VidSetPinValue(3,2,1);
 _delay_ms(100);

 }


 return 0;
 }*/

int main(void) {
	uint8_t i;
	// --------Inits --------//
	DDRD = 0xff;    //Data Direction Register D : writing a one to the bit enables output

	// ------ Event Loop ------ //

	while (1) {
		for (i = 7; i > 0; i--) {

			PORTD = (1 << i);
			_delay_ms(1000); // wait

		}

	}
	return 0;
}
