/*
 * SPI_main.c
 *
 *  Created on: Mar 13, 2019
 *      Author: Eng Ali Gamal
 */

#include <avr/io.h>          // Defines pins, ports, etc
#include <util/delay.h>		 // Functions to waste time
#include "TYPES.h"        // Types data
#include "MACROS.h"		 // Function Macros set and clear and togel
#include "REGISTERS.h"    // Defines Registers
#include "DIO/DIO.h"      // Functions to Input and output
#include "LCD/LCD.h"         // the functions the liber Lcd
#define F_CPU 12000000UL
#include "SPI/SPI.h"

/*
int main(void)
{

	//Operating as Master

	LCD_VidInit();
	SPI_vidMasterInit();

	DIO_VidSetPinValue(1,4,0);


	while(1)
	{
		SPI_Transceiver(5);
		_delay_ms(1000);
		SPI_Transceiver(6);
		_delay_ms(1000);
	}



	//Operating as Slave


	LCD_VidInit();
	SPI_vidSlaveInit();

	while(1)
	{


		u8 x= SPI_Transceiver(60);
		LCD_VidSetPosition(0,0);
		LCD_VidWriteNumber(x);
	}



	return -1;
}

*/




