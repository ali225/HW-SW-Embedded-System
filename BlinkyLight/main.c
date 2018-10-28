/*
 * main.c
 *
 *  Created on: Oct 7, 2018
 *      Author: Eng Ali Gamal
 */
#include <avr/io.h>          /* Defines pins, ports, etc */
#include <util/delay.h>		/* Functions to waste time */
#define F_CPU 12000000UL

int main(void) {

	// --------Inits --------//

	DDRD = 0b11111111; /*Data Direction Register D : writing a one to the bit enables output */

	// ------ Event Loop ------ //
	while (1) {
		PORTD = 0b11111111; 	/* Turn on all led in port D */
		_delay_ms(500); 		/* wait */
		PORTD = 0b00000000; 	/*Turn off all Led in port D  */
		_delay_ms(500); 		/*wait */

	}
	return 0;
}

/*int main(void)
 {
 DDRD = 0b00000011; // Data Direction Register D : writing a one to the bit enables output

 while(1)
 {
 PORTD =	0b00000011; //Turn on Two led pin/bit in port D
 _delay_ms(100);		//wait
 PORTD = 0b00000000;	// Turn off all led in port D
 _delay_ms(100);		//wait
 }
 return 0;
 }*/

/*int main(void)
 {
 DDRD |= 1<<PD1; // set PB6 to output

 while (1)
 {
 PORTD &= ~(1<<PD1);  //Turn on all led pin/bit in port D
 _delay_ms(1000);	  //wait
 PORTD |= 1<<PD1;     //Turn off all led in port D
 _delay_ms(1000);	  //wait
 }
 return 0;
 }*/
