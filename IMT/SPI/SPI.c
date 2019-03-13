/*
 * SPI.c
 *
 *  Created on: Mar 13, 2019
 *      Author: Eng Ali Gamal
 */

#include <avr/io.h>          // Defines pins, ports, etc
#include <util/delay.h>		 // Functions to waste time
#include "../TYPES.h"        // Types data
#include "../MACROS.h"		 // Function Macros set and clear and togel
#include "../REGISTERS.h"    // Defines Registers
#include "../DIO/DIO.h"      // Functions to Input and output
#define F_CPU 12000000UL
#include "SPI.h"

void SPI_vidMasterInit()
{

	DIO_VidSetPinDirection(1,4,1);
	DIO_VidSetPinDirection(1,5,1);
	DIO_VidSetPinDirection(1,6,0);
	DIO_VidSetPinDirection(1,7,1);

	Clr_Bit(SPCR,0);
	Set_Bit(SPCR,1);
	Clr_Bit(SPCR,2);
	Clr_Bit(SPCR,3);
	Set_Bit(SPCR,4);    //Master Init
	Clr_Bit(SPCR,5);
	Set_Bit(SPCR,6);
	Clr_Bit(SPCR,7);

	Clr_Bit(SPSR,0);
	Clr_Bit(SPSR,7);

	SPDR=0;
}

void SPI_vidSlaveInit()
{
	DIO_VidSetPinDirection(1,4,0);
	DIO_VidSetPinDirection(1,5,0);
	DIO_VidSetPinDirection(1,6,1);
	DIO_VidSetPinDirection(1,7,0);

	Clr_Bit(SPCR,0);
	Set_Bit(SPCR,1);
	Clr_Bit(SPCR,2);
	Clr_Bit(SPCR,3);
	Clr_Bit(SPCR,4);    //Slave Init
	Clr_Bit(SPCR,5);
	Set_Bit(SPCR,6);
	Clr_Bit(SPCR,7);

	Clr_Bit(SPSR,0);
	Clr_Bit(SPSR,7);

	SPDR=0;
}

u8 SPI_Transceiver(u8 Data)
{
	SPDR=Data;

	while(Get_Bit(SPSR,7)==0)
		{

		}

		return SPDR;

}
