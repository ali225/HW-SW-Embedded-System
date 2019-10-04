/*
 * Keypad.h
 *
 *  Created on: Oct 21, 2018
 *      Author: Eng Ali Gamal
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

enum button_status
{
	KeyNOTPressed=0,
	KeyPressed
};
enum key_Operation
{
	NUM_1=0,
	NUM_2,
	NUM_3,
	PLUS,
	NUM_4,
	NUM_5,
	NUM_6,
	MINUS,
	NUM_7,
	NUM_8,
	NUM_9,
	MULT,
	CLEAR,
	NUM_0,
	EQUEL,
	ENTER,
};
enum Pressed
{
	NUMB=0,
	Operation,
	Clr

};
u8 Keybad_u8_GetButtonStatus(u8 button);
void Keybad_Vid_Init();


#endif /* KEYPAD_H_ */
