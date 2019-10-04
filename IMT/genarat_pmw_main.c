/*
 * genarat_pmw_main.c
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


/*
int main(void)
{

	DIO_VidSetPinDirection(3,5,1);

	Clr_Bit(TCCR1A,0);
	Set_Bit(TCCR1A,1);
	Clr_Bit(TCCR1A,6);
	Set_Bit(TCCR1A,7);

	Clr_Bit(TCCR1B,0);
	Clr_Bit(TCCR1B,1);
	Set_Bit(TCCR1B,2);
	Set_Bit(TCCR1B,3);
	Set_Bit(TCCR1B,4);
	Clr_Bit(TCCR1B,5);

	ICR1H=2;
	ICR1L=113;


	while(1)
	{
		OCR1AH=0;
		OCR1AL=20;
		_delay_ms(1000);

		OCR1AH=0;
		OCR1AL=100;
		_delay_ms(1000);
	}



	return -1;
}
*/


