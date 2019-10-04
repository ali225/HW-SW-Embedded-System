/*

 * keypadmain.c
 *
 *  Created on: Dec 13, 2018
 *      Author: Eng Ali Gamal
 */
#include "Atmega32_registers.h"
#include "GPIO/GPIO.h"
#include "LCD/lcd.h"
#include "mydelay.h"
#include "keypad/keypad.h"

#define output 1
#define input 0

int main() {
	char key_pressed;
	LCD_lcd_init();
	Keypad_init();

	while (1) {
		key_pressed = Keypad_getkey();
		switch (key_pressed) {
		case ('A'):
			break; // do nothing if no key is pressed
		case ('?'):
			LCD_clear_screen();
			break; // do nothing if no key is pressed
		default:
			LCD_Send_A_Character(key_pressed); // send the key pressed to lcd

		}
	}
	return 0;

}

