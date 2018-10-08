/*
 * main.c
 *
 *  Created on: Sep 26, 2018
 *      Author: My ALi Gamal Aziz
 */

#include <avr/delay.h>
#include "Types.h"
#include "Macros.h"
#include "REGISTERS.h"
#define F_CPU 1200000UL
#include "DIO.h"

int main(void)
{
	DIO_VidSetPortDirection(3,255);
	DIO_VidSetPortValue(3,128);

	  while(1){


	     PORTA =0b10000001; //0b10101010
	     _delay_ms(1000);
	     PORTA =0b01000010;
	     _delay_ms(1000);
	     PORTA =0b00100100;
	     _delay_ms(1000);
	     PORTA =0b00011000;
	     _delay_ms(1000);
	     PORTA =0b00100100;
	     _delay_ms(1000);
	     PORTA =0b01000010;
	     _delay_ms(1000);
	     PORTA =0b10000001;
	     _delay_ms(1000);

	   }

	    // return 0;
 }







