/*
 * firstmain.c
 *
 *  Created on: Jun 23, 2019
 *      Author: Eng Ali Gamal
 */

#include "Atmega32_registers.h"
//#include <avr/io.h>
//#include <avr/delay.h>
#include "GPIO/GPIO.h"
#include "mydelay.h"
#ifndef F_CPU
#define F_CPU 8000000UL // 8MHZ
#endif
#define input 0
#define output 1

/*int main() {
	GPIO_voidInit();
	GPIO_u8_WritePinDir(5, output, 'D');
	int Togel_led = 1;

	while (1) {
		GPIO_u8_WritePinVal(5, Togel_led, 'D');
		Togel_led ^= 1;
		DELAY_MS(1000);
	}
	return 0;
}*/
/*
 int main(void) {
 DDRC = 0xFF;
 PORTC = 0xFF;

 int i, j, co;

 for (i = 0; i < 10; i++) {
 for (j = 0; j < 10; j++) {
 for (co = 0; co < 100; co++) {
 PORTC = (0b1011 | (i << 4));
 _delay_ms(50);
 PORTC = (0b0111 | (j << 4));
 _delay_ms(50);
 }
 }

 }
 }*/

/*void mydelay(unsigned long time);

 int main(void) {
 //used for loop
 unsigned char i;
 // configeur PORT D pin 5, 6, 7 (LED)
 // port D pin 4 (buzzer)
 myDDRD |= (1 << 4 | 1 << 5 | 1 << 6 | 1 << 7);

 // this is the programing cod function that
 while (1) {
 for (i = 5; i < 8; i++) {
 mydelay(30);          // delay that need befor run cod
 myPORTD &= ~(1 << 4);   // stop run buzzer
 myPORTD = (1 << i);  // shift on led
 }
 myPORTD |= 1 << 4;        // start buzzer
 }

 }
 void mydelay(unsigned long time) {
 while (time > 0) {
 volatile int i = 13333;

 while (i > 0) {
 i--;
 }
 time--;
 }

 }*/
/*

 int main(int argc, char **argv) {

 DDRD |= 1 << 5 | 1 << 6 | 1 << 7;
 PORTD |= 1 << 5 | 1 << 6 | 1 << 7;
 while (1) {

 uint8_t i;
 // --------Inits --------//
 DDRD = 0xff; //Data Direction Register D : writing a one to the bit enables output

 // ------ Event Loop ------ //

 while (1) {
 for (i = 7; i > 0; i--) {

 PORTD = (1 << i);
 _delay_ms(1000); // wait

 }
 PORTD |= 1<<5;
 _delay_ms(250);
 PORTD &= ~(1<<5);
 PORTD |= 1<<6;
 _delay_ms(250);
 PORTD &= ~(1<<6);
 PORTD |= 1<<7;
 _delay_ms(250);
 PORTD &= ~(1<<7);

 }
 return 1;

 }
 */
