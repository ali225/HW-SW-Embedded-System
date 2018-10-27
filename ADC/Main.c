/*
 * Main.c
 *
 *  Created on: Oct 27, 2018
 *      Author: Eng Ali Gamal
 */

#include "Types.h"
#include "LCDc.h"
#include "REGISTERS.h"
#include "ADC.h"
#define F_CPU 12000000UL
#include <util/delay.h>

int main(void) {

	ADC_Init();
	LCD_vidInit();
	u8 Space;
	Space =' ';

	while (1) {

		LCD_vidInit();
		ADC_Init();
		u8 x = ADC_GetResult();
		LCD_vidsetposition(0,0);
		LCD_vidWritnumber(x);
		LCD_vidwriteCharacter(Space);

	}

	return -1;
}
