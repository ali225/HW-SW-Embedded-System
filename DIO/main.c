/*
 * main.c
 *
 *  Created on: Oct 7, 2018
 *      Author: Eng Ali Gamal
 */

#include <avr/delay.h>
#include "Types.h"
#include "Macros.h"
#include "REGISTERS.h"
#include "DIO.h"
#define F_CPU 12000000UL


int main(void)
{


	while(1)
		{
			DIO_VidSetPinDirection(3,1,1);
			DIO_VidSetPinDirection(3,2,1);

		//	DIO_VidSetPinValue(3,1,1);

			DIO_VidSetPinValue(3,1,0);
			_delay_ms(5000);
			DIO_VidSetPinValue(3,1,1);
			_delay_ms(5000);
			DIO_VidSetPinValue(3,2,0);
			_delay_ms(100);
			DIO_VidSetPinValue(3,2,1);
			_delay_ms(100);

		}


	return 0;
}
