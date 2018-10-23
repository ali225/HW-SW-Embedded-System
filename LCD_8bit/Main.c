/*
 * Main.c
 *
 *  Created on: Oct 15, 2018
 *      Author: Eng Ali Gamal
 */

#include <avr/io.h>
#include<util/delay.h>
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
			LCD_vidWritnumber(123);
			_delay_ms(1000);

			LCD_vidClear(0xFF);
			_delay_ms(1);
		}

	}

}


/*
int main(void) {
	LCD_vidInit();
	u8 arr[] = "AbdMalik";
	int size;
	size = sizeof(arr);
	int difference;
	difference = 16 - size + 1;
	u8 Space;
	Space = ' ';

	LCD_vidwriteCommand(0b01000000); //3shan arouh lel cgram

	LCD_vidwriteCharacter(0b00000000);
	LCD_vidwriteCharacter(0b00000000);
	LCD_vidwriteCharacter(0b00000111);
	LCD_vidwriteCharacter(0b00000100);
	LCD_vidwriteCharacter(0b00011111);  //3en
	LCD_vidwriteCharacter(0b00000000);
	LCD_vidwriteCharacter(0b00000000);
	LCD_vidwriteCharacter(0b00000000);

	LCD_vidwriteCharacter(0b00000000);
	LCD_vidwriteCharacter(0b00000000);
	LCD_vidwriteCharacter(0b00000001);
	LCD_vidwriteCharacter(0b00000001);
	LCD_vidwriteCharacter(0b00011111); //ba2
	LCD_vidwriteCharacter(0b00000000);
	LCD_vidwriteCharacter(0b00000100);
	LCD_vidwriteCharacter(0b00000000);

	LCD_vidwriteCharacter(0b00000000);
	LCD_vidwriteCharacter(0b00000000);
	LCD_vidwriteCharacter(0b00000001);
	LCD_vidwriteCharacter(0b00000001);
	LCD_vidwriteCharacter(0b00000111); //dal
	LCD_vidwriteCharacter(0b00000000);
	LCD_vidwriteCharacter(0b00000000);
	LCD_vidwriteCharacter(0b00000000);

	LCD_vidwriteCharacter(0b00010000);
	LCD_vidwriteCharacter(0b00010000);
	LCD_vidwriteCharacter(0b00010000);
	LCD_vidwriteCharacter(0b00010000);
	LCD_vidwriteCharacter(0b00010000); //alef
	LCD_vidwriteCharacter(0b00000000);
	LCD_vidwriteCharacter(0b00000000);
	LCD_vidwriteCharacter(0b00000000);

	LCD_vidwriteCharacter(0b00000001);
	LCD_vidwriteCharacter(0b00000001);
	LCD_vidwriteCharacter(0b00000001);
	LCD_vidwriteCharacter(0b00000001);
	LCD_vidwriteCharacter(0b00011111); //lam
	LCD_vidwriteCharacter(0b00000000);
	LCD_vidwriteCharacter(0b00000000);
	LCD_vidwriteCharacter(0b00000000);

	LCD_vidwriteCharacter(0b00000000);
	LCD_vidwriteCharacter(0b00000000);
	LCD_vidwriteCharacter(0b00000000);
	LCD_vidwriteCharacter(0b00000000);
	LCD_vidwriteCharacter(0b00011111); //meem
	LCD_vidwriteCharacter(0b00000101);
	LCD_vidwriteCharacter(0b00000111);
	LCD_vidwriteCharacter(0b00000000);

	LCD_vidwriteCharacter(0b00000001);
	LCD_vidwriteCharacter(0b00000001);
	LCD_vidwriteCharacter(0b00000001);
	LCD_vidwriteCharacter(0b00000001);
	LCD_vidwriteCharacter(0b00011111); //lam
	LCD_vidwriteCharacter(0b00000000);
	LCD_vidwriteCharacter(0b00000000);
	LCD_vidwriteCharacter(0b00000000);

	LCD_vidwriteCharacter(0b00001101);
	LCD_vidwriteCharacter(0b00001001);
	LCD_vidwriteCharacter(0b00011101);
	LCD_vidwriteCharacter(0b00000001);
	LCD_vidwriteCharacter(0b00011111); //kaf
	LCD_vidwriteCharacter(0b00000000);
	LCD_vidwriteCharacter(0b00000000);
	LCD_vidwriteCharacter(0b00000000);

	//////////////////////////////////////////////////////////////////////////////////////////////////

	while (1) {

		for (int i = 0; i < 17; i++) {

			LCD_vidsetposition(i, 0);
			LCD_vidwriteString(arr);

			if (i < difference) {
				LCD_vidsetposition(difference - i, 1);
			}

			else {
				LCD_vidsetposition(48 - i, 0);
			}

			for (int j = size - 2; j >= 0; j--) {
				LCD_vidwriteCharacter(j);
			}

			if (i > difference) {
				LCD_vidsetposition(33 - size + i, 1);
				LCD_vidwriteString(arr);

				LCD_vidsetposition(15 + size - i, 1);
				for (int j = size - 2; j >= 0; j--) {
					LCD_vidwriteCharacter(j);
				}

			}

			if (i != 16) {
				_delay_ms(1000);
				LCD_vidwriteCommand(00000001);
			}

		}

	}

	return -1;
}

*/
