/*
 * Timer.c
 *
 *  Created on: Feb 27, 2019
 *      Author: Eng Ali Gamal
 */


#include <avr/io.h>         // Defines pins, ports, etc
#include <util/delay.h>		// Functions to waste time
#include "../TYPES.h"      // Types data
#include "../MACROS.h"
#include "../REGISTERS.h"
#include "../DIO/DIO.h"
#include "Timer.h"

void (*GB)(void);
void TimerVidInt()
{
	TCCR0=0b00000100;
	Set_Bit(TIMSK,0);
	Set_Bit(SREG,7);
	DIO_VidSetPinDirection(0,0,1);

}

void delivery(void(*ptr)(void))
{
	GB=ptr;
}

#define __INTR_ATTRS used, externally_visible

void __vector_11 (void) __attribute__ ((signal,__INTR_ATTRS)) ;
void __vector_11 (void)
{
GB();
}
