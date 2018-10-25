/*
 * Main.c
 *
 *  Created on: Oct 24, 2018
 *      Author: Eng Ali Gamal
 */
#include "Types.h"
#include "REGISTERS.h"
#include "Macros.h"
#define F_CPU 12000000UL
#include <util/delay.h>


int main(void)
{
	DDRA = 0b00000011; // set Led to output

		while(1)
		{
			PORTA =	0b00000011;		 //Motor or led or bizo  on
			_delay_ms(1000);
			PORTA = 0b00000000;
			_delay_ms(10000);		// Motor or led or bizo off
		}
		return 0;
}
