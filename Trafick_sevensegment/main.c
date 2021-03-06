/*
 * main.c
 *
 *  Created on: Oct 9, 2018
 *      Author: Eng Ali Gamal
 */

/*#define F_CPU 12000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "Types.h"
#include "REGISTERS.h"
#include "Macros.h"

#include "DIO.h"


int main()
{
	DDRD = 0xff;

	char array[]={0b00000100,0b01000000,0b00000000,0b11100100,0b00001000,0b01001000,0b11010000,0b01100000,0b00100010,0b11110100};
		 write hex value for CA display from 0 to 9

	while(1)
	{
		for (int i = 9;i > 0;i--)  for loop from counter 1 to 9
		{
			PORTD = array[i];  write data on to the seven segment from 1 to 0
			_delay_ms(300);    wait for 1 second
		}
	}

}*/

#include <avr/delay.h>
#include"Types.h"
#include "REGISTERS.h"
#include <avr/io.h>


int main(void)
{
	DDRA = 0xff;
	DDRB = 0xff;
	DDRC = 0xff;


	char array[]={0b00000100,0b01000000,0b00000000,0b11100100,0b00001000,0b01001000,0b11010000,0b01100000,0b00100010,0b11110100};
	/* write hex value for CA display from 0 to 9 */

	while(1)
	{

		for(int i=0;i<3;i++)
		{
			PORTC = (1 << i);
			_delay_ms(300);

			for(int j=4;j<10;j++)
			{
				PORTB = array[j]; /* write data on to the LED port */
				_delay_ms(300); /* wait for 1 second */

				for(int i=0;i<10;i++)
				{
					PORTA = array[i]; /* write data on to the LED port */
					_delay_ms(300); /* wait for 1 second */
				}
			}

		}
	}
}
