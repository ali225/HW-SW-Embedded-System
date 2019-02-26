/*
 * KeyPad_main.c
 *
 *  Created on: Feb 26, 2019
 *      Author: Eng Ali Gamal
 */


#include <avr/io.h>         // Defines pins, ports, etc
#include <util/delay.h>		// Functions to waste time
#include "TYPES.h"			// Types data
#include "MACROS.h"			// Function Macros set and clear and togel
#include "REGISTERS.h"	  	// Defines Registers
#include "DIO/DIO.h"		// Functions to Input and output
#include "LCD/LCD.h"		// the functions the liber Lcd
#define F_CPU 12000000UL

int main(void)
{
	LCD_VidInit();
	Keypad_vidInit();



	while(1)
	{
		for(u8 i=0; i<16; i++)
		{
			if(Keypad_u8GetButtonStatus(i)==1)
			{
				LCD_VidSetPosition(0,0);
				LCD_VidWriteNumber(i);
			}
		}
	}

	return -1;
}
