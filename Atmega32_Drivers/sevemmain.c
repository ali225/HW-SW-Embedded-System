/*

 * sevemmain.c
 *
 *  Created on: Jul 24, 2019
 *      Author: Eng Ali Gamal


#include "Atmega32_registers.h"
#include "mydelay.h"
#include "GPIO/GPIO.h"

#ifndef F_CPU
#define F_CPU 8000000UL // 8MHZ
#endif

#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>

//Encoded Number from PCM to 7-segment
int gEncoder[10] =
		{ 0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x67 };

int main(void) {
	int hr = 0, min = 0, sec = 0, i;
	//Initializing Ports
	DDRC = 0xFF;
	DDRB = 0xFF;
	float wait = 2500;

	while (1) {
		for (hr = 0; hr < 12; hr++) { //for loop to change hours
			for (min = 0; min < 60; min++) { //for loop to change minutes
				for (sec = 0; sec < 60; sec++) { //for to change seconds
					for (i = 0; i < 60; i++) { //for loop to multiplex and render with frequency of 30 Hz (the frequency that the eye can see )

						PORTC = ~1;
						PORTB = gEncoder[sec % 10];
						//_delay_ms(5);
						_delay_us(wait);

						PORTC = ~2;
						PORTB = gEncoder[sec / 10];
						//_delay_ms(5);
						_delay_us(wait);

						PORTC = ~4;
						PORTB = gEncoder[min % 10];
						//_delay_ms(5);
						_delay_us(wait);

						PORTC = ~8;
						PORTB = gEncoder[min / 10];
						//_delay_ms(5);
						_delay_us(wait);

						PORTC = ~16;
						PORTB = gEncoder[hr % 10];
						//_delay_ms(5);
						_delay_us(wait);

						PORTC = ~32;
						PORTB = gEncoder[hr / 10];
						//_delay_ms(5);
						_delay_us(wait);
					}
				}
			}
		}
	}
}


*/
