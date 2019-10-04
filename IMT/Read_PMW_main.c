/*
 * Read_PMW_main.c
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

u64 volatile Counter=0;
u8 volatile flag=0;
u64 volatile Snap1=0;
u64 volatile  Snap2=0;
u64 volatile Snap3=0;


#define __INTR_ATTRS used,externally_visible

void __vector_6(void) __attribute__ ((signal, __INTR_ATTRS));  //external interrupt
void __vector_9(void) __attribute__ ((signal, __INTR_ATTRS));  //timer 1 overflow


void __vector_6(void)
{

	if(flag==0)
	{

		Snap1= ICR1;   		 	// Read_PWM
		Counter=0;				// counter
		Clr_Bit(TCCR1B,6);      // change to config to falling
	}

	else if(flag==1)
	{

		Snap2= (Counter*65536) + Snap1;
		Set_Bit(TCCR1B,6);
	}

	else if(flag==2)
	{

		Snap3= (Counter*65536) + Snap1;
		Clr_Bit(TIMSK,2);
		Clr_Bit(TIMSK,5);
	}

	flag++;
}

 //no presclar
 // overflow mode
void __vector_9(void) //Disable
{
	Counter++;        // Enable
}

/*
int main(void)
{

	DIO_VidSetPinDirection(1,3,1); //output
	DIO_VidSetPinDirection(3,6,0); //input

	Set_Bit(TCCR0,0);
	Clr_Bit(TCCR0,1);
	Set_Bit(TCCR0,2);
	Set_Bit(TCCR0,3);
	Clr_Bit(TCCR0,4);
	Set_Bit(TCCR0,5);
	Set_Bit(TCCR0,6);
	Clr_Bit(TCCR0,7);

	Clr_Bit(TCCR1A,0);
	Clr_Bit(TCCR1A,1);

	Set_Bit(TCCR1B,0);
	Clr_Bit(TCCR1B,1);
	Clr_Bit(TCCR1B,2);
	Clr_Bit(TCCR1B,3);
	Clr_Bit(TCCR1B,4);
	Clr_Bit(TCCR1B,5);
	Set_Bit(TCCR1B,6);

	Set_Bit(TIMSK,2);
	Set_Bit(TIMSK,5);


	Set_Bit(SREG,7);



	LCD_VidInit();
	ADC_Init();

	//OCR0=128;



	u64 Duty=0;
	u64 freq=0;

	u8 freq_string[]="Freq=";
	u8 duty_string[]="Duty=";
	u8 Hertz_String[]="Hz";
	u8 Percent='%';

	while(1)
	{

		OCR0= ADC_GetResult();

		if(flag==3)
		{

			Duty = ((Snap2 - Snap1)*100) / (Snap3 - Snap1);
			freq= 8000000 / (Snap3 - Snap1);
			flag=0;
			Set_Bit(TIMSK,2);
			Set_Bit(TIMSK,5);
			Set_Bit(TIFR,5);

			LCD_VidSetPosition(0,0);
			LCD_VidWriteString(freq_string);
			LCD_VidSetPosition(5,0);
			LCD_VidWriteNumber(freq);
			//LCD_VidSetPosition(7,0);
			//LCD_VidWriteString(Hertz_String);


			LCD_VidSetPosition(0,1);
			LCD_VidWriteString(duty_string);
			LCD_VidSetPosition(5,1);
			LCD_VidWriteNumber(Duty);
			//LCD_VidSetPosition(7,1);
			//LCD_VidWriteCharacter(Percent);
		}




	}



	return -1;
}

*/


