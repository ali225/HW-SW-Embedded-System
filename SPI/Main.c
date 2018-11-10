/*
 * Main.c
 *
 *  Created on: Nov 1, 2018
 *      Author: Eng Ali Gamal
 */


#include "Types.h"
#include "LCDc.h"
#include "Macros.h"
#include "DIO.h"
#include "Registers.h"
#include "SPI.h"
#define F_CPU 12000000UL
#include <avr/delay.h>

int main(void)
{

	//Operating as Master

	LCD_vidInit();
	SPI_vidMasterInit();

	DIO_vidSetPinValue(1,4,0);


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





