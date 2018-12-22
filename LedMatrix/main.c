/*
 * main.c
 *
 *  Created on: Dec 13, 2018
 *      Author: Eng Ali Gamal
 */


#include "LedMatrix_HAL/ledmatrix_5X7.h"
#define F_CPU 8000000ul

int main(void)
{
	U8 check= 0, i;

	IO_PinDir(C,0,OUTPUT);

	while(1)
	{
		/* drawing A to Z */
		for(i= 'A'; i<= 'Z' ; i++)
		{
			check= LMTRX5x7_DrawAlpha(i,500);
			IO_PinWrite(C,0,check);
		}

		/* drawing 0 to 9 */
		for(i= '0'; i<= '9' ; i++)
		{
			check= LMTRX5x7_DrawDigit(i,500);
			IO_PinWrite(C,0,check);
		}

	}
}
