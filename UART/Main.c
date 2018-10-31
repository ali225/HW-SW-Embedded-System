/*
 * Main.c
 *
 *  Created on: Oct 30, 2018
 *      Author: Eng Ali Gamal
 */

#include "Types.h"
#include "LCDc.h"
#include "Macros.h"
#include "DIO.h"
#include "Registers.h"
#define F_CPU 12000000UL
#include <util/delay.h>


int main(void)
{

	LCD_vidInit();
	UART_VidInit();

	u8 x;

	UART_Send(48+5);


	while(1)
	{

		x=UART_Receive();
		LCD_vidwriteCharacter(x);
	}





	return -1;
}

