/*
 * UART.c
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


void UART_VidInit() {

	DIO_vidSetPinDirection(3, 0, 0);
	DIO_vidSetPinDirection(3, 1, 1);

	//Set_Bit(UBRRH,7);

	//Set_Bit(UBRRH,1);
	//Set_Bit(UBRRH,2);
	//Clr_Bit(UBRRH,3);
	//Clr_Bit(UBRRH,4);
	//Clr_Bit(UBRRH,5);
	//Clr_Bit(UBRRH,6);

	UBRRH = 0b10000110;
	Clr_Bit(UCSRA, 1);

	//Clr_Bit(UBRRH,7);

	//Clr_Bit(UBRRH,0);
	//Clr_Bit(UBRRH,1);
	//Clr_Bit(UBRRH,2);
	//Clr_Bit(UBRRH,3);

	UBRRH = 0;
	UBRRL = 51;

	Clr_Bit(UCSRB, 2);
	Set_Bit(UCSRB, 3);
	Set_Bit(UCSRB, 4);
}

void UART_Send(u8 Data) {

	// Put data into buffer, sends the data
	UDR = Data;
	// Wait for empty transmit buffer
	while (Get_Bit(UCSRA,5) == 0) {

	}
}

u8 UART_Receive() {

	// Wait for data to be received
	while (Get_Bit(UCSRA,7) == 0) {

	}
	// Get and return received data from buffer
	return UDR;
}

