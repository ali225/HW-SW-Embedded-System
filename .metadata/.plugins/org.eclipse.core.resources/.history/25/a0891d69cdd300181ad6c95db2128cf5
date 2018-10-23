/*
 * Main.c
 *
 *  Created on: Oct 15, 2018
 *      Author: Eng Ali Gamal
 */

#include <avr/io.h>
#include<avr/delay.h>
#include "Types.h"
#include"LCDc.h"

int main(void) {

	while (1) {
		/*Init LCD */
		LCD_vidInit();

		/*writ CGRAM this order writ data on CGRAM*/
		LCD_vidwriteCommand(0x40);

		/*the draw Arabic A */
		LCD_vidwriteCharacter(0x00);
		LCD_vidwriteCharacter(0xFF);
		LCD_vidwriteCharacter(0x10);
		LCD_vidwriteCharacter(0x10);
		LCD_vidwriteCharacter(0x10);
		LCD_vidwriteCharacter(0xFF);
		LCD_vidwriteCharacter(0x00);
		LCD_vidwriteCharacter(0x00);

		/*the draw Arabic L */

		LCD_vidwriteCharacter(0x04);
		LCD_vidwriteCharacter(0x04);
		LCD_vidwriteCharacter(0x04);
		LCD_vidwriteCharacter(0x04);
		LCD_vidwriteCharacter(0x04);
		LCD_vidwriteCharacter(0x1F);
		LCD_vidwriteCharacter(0x00);
		LCD_vidwriteCharacter(0x00);

		/*the draw Arabic i */
		LCD_vidwriteCharacter(0x00);
		LCD_vidwriteCharacter(0x00);
		LCD_vidwriteCharacter(0x00);
		LCD_vidwriteCharacter(0x00);
		LCD_vidwriteCharacter(0x00);
		LCD_vidwriteCharacter(0x11);
		LCD_vidwriteCharacter(0x11);
		LCD_vidwriteCharacter(0xFF);

		/*the draw Smail ^_^  */
		LCD_vidwriteCharacter(0x00);
		LCD_vidwriteCharacter(0x00);
		LCD_vidwriteCharacter(0x0A);
		LCD_vidwriteCharacter(0x00);
		LCD_vidwriteCharacter(0x11);
		LCD_vidwriteCharacter(0x0E);
		LCD_vidwriteCharacter(0x00);
		LCD_vidwriteCharacter(0x00);

		/*the draw Arabic R  */
		LCD_vidwriteCharacter(0x00);
		LCD_vidwriteCharacter(0x01);
		LCD_vidwriteCharacter(0x01);
		LCD_vidwriteCharacter(0x03);
		LCD_vidwriteCharacter(0x06);
		LCD_vidwriteCharacter(0x0c);
		LCD_vidwriteCharacter(0x18);
		LCD_vidwriteCharacter(0x00);

		/*the draw Arabic dad arbic */
		LCD_vidwriteCharacter(0x00);
		LCD_vidwriteCharacter(0x10);
		LCD_vidwriteCharacter(0x00);
		LCD_vidwriteCharacter(0x0f);
		LCD_vidwriteCharacter(0x09);
		LCD_vidwriteCharacter(0x1f);
		LCD_vidwriteCharacter(0x00);
		LCD_vidwriteCharacter(0x00);

		/*the draw Arabic L  */
		LCD_vidwriteCharacter(0x10);
		LCD_vidwriteCharacter(0x10);
		LCD_vidwriteCharacter(0x10);
		LCD_vidwriteCharacter(0x10);
		LCD_vidwriteCharacter(0x10);
		LCD_vidwriteCharacter(0x1f);
		LCD_vidwriteCharacter(0x00);
		LCD_vidwriteCharacter(0x00);

		//	LCD_vidwriteCharacter('a');
		//  LCD_vidWritnumber(100);

		char array[] = { 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };

		for (int j = 0; j < 12; j++) {
			LCD_vidsetposition(1, array[j]);

			/*print L arbic */
			LCD_vidwriteCharacter(6);
			/*print dada arbic */
			LCD_vidwriteCharacter(5);
			/* print R */
			LCD_vidwriteCharacter(4);
			/*print smail*/
			LCD_vidwriteCharacter(3);
			/*print i to Arbic*/
			LCD_vidwriteCharacter(2);
			/*print L to Arbic */
			LCD_vidwriteCharacter(1);
			/*print A to Arbic */
			LCD_vidwriteCharacter(0);

			/*write the row two and start 0  */
			LCD_vidsetposition(2, j);
			/*print array that */
			u8 arr[] = "ALi";
			/* write character to LCD ALi */
			LCD_vidwriteString(arr);
			/* number arr of word ali  */
			LCD_vidwriteCharacter(3);
			_delay_ms(1000);

			/*clear all LCD  */
			LCD_vidClear(0xFF);
			_delay_ms(1);
		}

		for (int i = 12; i > 0; i--) {

			LCD_vidsetposition(1, array[i]);

			/*print L arbic */
			LCD_vidwriteCharacter(6);
			/*print dada arbic */
			LCD_vidwriteCharacter(5);
			/* print R */
			LCD_vidwriteCharacter(4);
			/*print smail*/
			LCD_vidwriteCharacter(3);
			/*print i*/
			LCD_vidwriteCharacter(2);
			/*print  L to Arbic*/
			LCD_vidwriteCharacter(1);
			/*print  A to Arbic*/
			LCD_vidwriteCharacter(0);

			/*write the row two and start 0  */
			LCD_vidsetposition(2, i);
			/*print array that */
			u8 arr[] = "ALi";
			LCD_vidwriteString(arr);
			LCD_vidwriteCharacter(3);
			_delay_ms(1000);

			LCD_vidClear(0xFF);
			_delay_ms(1);
		}

	}

}

