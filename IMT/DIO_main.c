/*
 * main.c
 *
 *  Created on: Feb 5, 2019
 *      Author: Eng Ali Gamal
 */
/*

#include <avr/io.h>          Defines pins, ports, etc
#include <util/delay.h>		 Functions to waste time
#include "TYPES.h"			 Types data
#include "MACROS.h"			 Function Macros set and clear and togel
#include "REGISTERS.h"	  	 Defines Registers
#include "DIO/DIO.h"		 Functions to Input and output
#define F_CPU 12000000UL

// pleas write the code int main here bucase dont matche code anther

     {

	DDRD = 0xFF;
	PORTD = 0xAA;

	while (1)

		PORTD =  PORTD ^ 0xff;

	return 0;

}

int main(void) {

 // -------- Initis --------//
 while (1) {
 DIO_VidSetPinDirection(3, 1, 1);
 DIO_VidSetPinDirection(3, 2, 1);

 //	DIO_VidSetPinValue(3,1,1);

 DIO_VidSetPinValue(3, 1, 0);
 _delay_ms(5000);
 DIO_VidSetPinValue(3, 1, 1);
 _delay_ms(5000);
 DIO_VidSetPinValue(3, 2, 0);
 _delay_ms(100);
 DIO_VidSetPinValue(3, 2, 1);
 _delay_ms(100);

 }

 return 0;
 }


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


 int main(void)
 {
 DDRD = 0xff;

 while(1)
 {
 PORTD = PORTD + 1;
 }

 return 0;
 }


 int main(void) {

 // --------Inits --------//

 DDRD = 0b11111111; Data Direction Register D : writing a one to the bit enables output

 // ------ Event Loop ------ //
 while (1) {
 PORTD = 0b11111111; 	 Turn on all led in port D
 _delay_ms(500); 		 wait
 PORTD = 0b00000000; 	Turn off all Led in port D
 _delay_ms(500); 		wait

 }
 return 0;
 }

int main(void)
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
 }

int main(void)
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
 }

*/
