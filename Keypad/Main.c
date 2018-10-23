/*
 * Main.c
 *
 *  Created on: Oct 21, 2018
 *      Author: Eng Ali Gamal
 */
#include "Types.h"
#include "REGISTERS.h"
#include "Macros.h"
#include "LCDc.h"
#include "Keypad.h"
#define F_CPU 12000000UL
#include <util/delay.h>


int main(void)
{
	LCD_vidInit();
	Keybad_Vid_Init();

	u8 flags [16] = {0};

	while(1)
	{
		for(u8 i=0; i<16; i++)
		{
			if(Keybad_u8_GetButtonStatus(i)==1 && flags[i] == 0)
			{
				LCD_vidsetposition(0,0);
				LCD_vidWritnumber(i);
				flags[i] = 1;
			}
			else if (Keybad_u8_GetButtonStatus(i)==0)
			{
				flags[i] = 0;
			}
		}
	}

	return -1;
}
/*int main(void)
{
	LCD_vidInit();
	Keybad_Vid_Init();



	while(1)
	{
		for(u8 i=0; i<16; i++)
		{
			if(Keybad_u8_GetButtonStatus(i)==1)
			{
				LCD_vidsetposition(0,0);
				LCD_vidWritnumber(i);
			}
		}
	}

	return -1;
}*/
