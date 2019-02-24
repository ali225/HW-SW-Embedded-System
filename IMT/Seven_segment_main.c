/*
 * Seven_segment_main.c
 *
 *  Created on: Feb 24, 2019
 *      Author: Eng Ali Gamal
 */

#include <avr/io.h>          Defines pins, ports, etc
#include <util/delay.h>		 Functions to waste time
#include "TYPES.h"			 Types data
#include "MACROS.h"			 Function Macros set and clear and togel
#include "REGISTERS.h"	  	 Defines Registers
#include "DIO/DIO.h"		 Functions to Input and output
#define F_CPU 12000000UL


int main(void) {

	DDRD = 0xFF;

	while (1){


		PORTD = 0b00111111; // Number 0
		_delay_ms(1000);
		PORTD = 0b00100000; // Number 1
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


/*
int main (void)
{
	Set_Bit(DDRA,PB0);
	Set_Bit(DDRA,PB1);
	Set_Bit(DDRA,PB2);
	Set_Bit(DDRA,PB3);

	while(1)
	{
		int i;
		for(i=0;i<=9;i++)
		{
			PORTA=i;
			_delay_ms(1000);
		}

		_delay_ms(1000);
		for(i=9;i>=0;i--)
		{
			PORTA=i;
			_delay_ms(1000);
		}

		_delay_ms(1000);

	}
	return 0;
}
*/

/*
int sevenfor_60();
int sevenfor_10();
*/
/*

int main(void)
{
	DDRA = 0xff;
	DDRB = 0xff;
	DDRC = 0b11111111;


	while(1)
	{
		PORTC = 0b00000001;
		_delay_ms(300);
		sevenfor_60();
		PORTC = 0b00000010;
		_delay_ms(300);
		sevenfor_10();
		PORTC = 0b00000100;
		_delay_ms(300);
		sevenfor_60();


	}

}

int sevenfor_60()
{
	char array[]={0b00000100,0b01000000,0b00000000,0b11100100,0b00001000,0b01001000,0b11010000,0b01100000,0b00100010,0b11110100};

	for(int j=5;j<10;j++)
	{
		PORTB = array[j];
		_delay_ms(300);

		for(int i=0;i<10;i++)
		{
			PORTA = array[i];
			_delay_ms(300);
		}
	}
	return 0;
}


int sevenfor_10()
{
	char array[]={0b00000100,0b01000000,0b00000000,0b11100100,0b00001000,0b01001000,0b11010000,0b01100000,0b00100010,0b11110100};

	for(int j=9;j<10;j++)
	{
		PORTB = array[j];
		_delay_ms(300);

		for(int i=0;i<10;i++)
		{
			PORTA = array[i];
			_delay_ms(300);
		}
	}
	return 0;
}

*/
