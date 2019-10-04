/*
 * UART_main.c
 *
 *  Created on: Mar 13, 2019
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
#include "UART/UART.h"

/*
int main(void)
{

	LCD_VidInit();
	UART_VidInit();

	u8 x;

	UART_Send(48+5);


	while(1)
	{

		x=UART_Receive();
		LCD_VidWriteCharacter(x);
	}





	return -1;
}
*/
