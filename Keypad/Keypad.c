/*
 * Keypad.c
 *
 *  Created on: Oct 21, 2018
 *      Author: Eng Ali Gamal
 */

#include"Types.h"
#include"DIO.h"
#include"Macros.h"
#include"REGISTERS.h"
#include"Keypad_cfg.h"
#include"Keypad.h"
#define F_CPU 12000000UL
#include <util/delay.h>

void Keybad_Vid_Init() {

	DIO_vidSetPinDirection(Keypad_Port, R0, 0);
	DIO_vidSetPinValue(Keypad_Port, R0, 1);

	DIO_vidSetPinDirection(Keypad_Port, R1, 0);
	DIO_vidSetPinValue(Keypad_Port, R1, 1);

	DIO_vidSetPinDirection(Keypad_Port, R2, 0);
	DIO_vidSetPinValue(Keypad_Port, R2, 1);

	DIO_vidSetPinDirection(Keypad_Port, R3, 0);
	DIO_vidSetPinValue(Keypad_Port, R3, 1);

	DIO_vidSetPinDirection(Keypad_Port, C0, 1);
	DIO_vidSetPinDirection(Keypad_Port, C1, 1);
	DIO_vidSetPinDirection(Keypad_Port, C2, 1);
	DIO_vidSetPinDirection(Keypad_Port, C3, 1);

}

u8 Keybad_u8_GetButtonStatus(u8 button) {
	u8 real_col[4] = { C0, C1, C2, C3 };
	u8 real_row[4] = { R0, R1, R2, R3 };
	u8 value = 0;
	u8 row = button / 4;
	u8 col = button % 4;
	DIO_vidSetPinValue(Keypad_Port, C0, 1);
	DIO_vidSetPinValue(Keypad_Port, C1, 1);
	DIO_vidSetPinValue(Keypad_Port, C2, 1);
	DIO_vidSetPinValue(Keypad_Port, C3, 1);
	DIO_vidSetPinValue(Keypad_Port, real_col[col], 0);
	u8 col_value = DIO_u8GetPinValue(Keypad_Port, real_row[row]);

	if (col_value == 0) {
		_delay_ms(5);
		col_value = DIO_u8GetPinValue(Keypad_Port, real_row[row]);
		if (col_value == 0) {
			value = 1;
		}
	}
	return value;
}
