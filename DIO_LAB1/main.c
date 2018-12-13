/*
 * main.c
 *
 *  Created on: Dec 12, 2018
 *      Author: Eng Ali Gamal
 */

#define F_CPU 8000000UL //8 MHZ
#include "ATMEGA32_registers.h"

void mydelay(unsigned long time);


int main(void) {
	unsigned char i;
	//configure port D output led
	//port D pin 4 buzzer
	myDDRD |= (1 << 5 | 1 << 6 | 1 << 7 | 1 << 4);

	while (1) {
		for (i = 5; i < 8; i++) {
			mydelay(30);
			myPORTD &= ~(1 << 4); // stop buzzer
			myPORTD = (1 << i);   //shift led on
		}
		myPORTD |= 1 << 4; // start buzzer
	}
}

// implement delay
void mydelay(unsigned long time)
{
		while (time > 0)
		{
			volatile int i = 13333; // volatile is manatory here
			while (i > 0)
			{
				i--;
			}
			time--;
		}
}

