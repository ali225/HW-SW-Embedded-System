/*
 * main.c
 *
 *  Created on: Dec 12, 2018
 *      Author: Eng Ali Gamal
 */

#include <avr/io.h>
#include <util/delay.h>
#ifndef F_CPU
#define F_CPU 8000000UL
#endif

int main(void) {

	DDRC = 0xff;
	PORTC = 0xff;

	int i, j, co;
	while (1) {
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
	}
}
