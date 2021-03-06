/*
 * main.c
 *
 *  Created on: Oct 8, 2018
 *      Author: Eng Ali Gamal
 */
/*

 #include <avr/io.h>
 #include <util/delay.h>
 #define F_CPU 12000000UL


 int main(void)
 {
 DDRD = 0b11111111; // set out put DDRD

 while(1)
 {
 PORTD = 0b00111111; // Number 0
 _delay_ms(1000);
 PORTD = 0b00110000; // Number 1
 _delay_ms(1000);
 PORTD = 0b01011011; // Number 2
 _delay_ms(1000);
 PORTD = 0b01001111; // Number 3
 _delay_ms(1000);
 PORTD = 0b01100110; // Number 4
 _delay_ms(1000);
 PORTD = 0b01101101; // Number 5
 _delay_ms(1000);
 PORTD = 0b01111101; // Number 6
 _delay_ms(1000);
 PORTD = 0b00000111; // Number 7
 _delay_ms(1000);
 PORTD = 0b11111111; // Number 8
 _delay_ms(1000);
 PORTD = 0b01101111; // Number 9
 _delay_ms(1000);
 }

 return 0;

 }
 */

/*
 #include <avr/io.h>

 #include <avr/delay.h>
 #define F_CPU 12000000UL
 #include "Types.h"
 #include "Macros.h"
 #include "REGISTERS.h"
 #include "DIO.h"

 int main(void)
 {
 DDRA = 0xff;
 DDRB = 0xff;
 DDRD = 0xff;


 char array[]={0b00000100,0b01000000,0b00000000,0b11100100,0b00001000,0b01001000,0b11010000,0b01100000,0b00100010,0b11110100};
 write hex value for CA display from 0 to 9

 while(1)
 {

 for(int i=0;i<3;i++)
 {
 PORTA = (1 << i);
 _delay_ms(300);

 for(int j=4;j<10;j++)
 {
 PORTC = array[j];  write data on to the LED port
 _delay_ms(300);  wait for 1 second

 for(int i=9;i>0;i--)
 {
 PORTD = array[i];  write data on to the LED port
 _delay_ms(900);  wait for 1 second
 }
 }

 }
 }
 }
 */

#define F_CPU 12000000UL
#include <avr/io.h>
#include <avr/delay.h>
#include"Types.h"
#include "Macros.h"
#include "REGISTERS.h"
#include "DIO.h"

int main(void) {

 DDRD = 0b11111111; // out put port "D"

 // counter display seven segment from 0 to 9
 while (1) {


 PORTD = 0b00100000;  // Number 0
 _delay_ms(1000);
 PORTD = 0b10010000; // Number 9
 _delay_ms(1000);
 PORTD = 0b00000000; // Number 8
 _delay_ms(1000);
 PORTD = 0b11111000; // Number 7
 _delay_ms(1000);
 PORTD = 0b10000010; // Number 6
 _delay_ms(1000);
 PORTD = 0b10010010; // Number 5
 _delay_ms(1000);
 PORTD = 0b10011001; // Number 4
 _delay_ms(1000);
 PORTD = 0b01010000; // Number 3
 _delay_ms(1000);
 PORTD = 0b01000100; // Number 2
 _delay_ms(1000);
 PORTD = 0b11111001; // Number 1
 _delay_ms(1000);

 }

 }


