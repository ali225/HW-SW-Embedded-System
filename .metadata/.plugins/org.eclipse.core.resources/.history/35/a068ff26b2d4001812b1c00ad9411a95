/*
 * LCD.h
 *
 *  Created on: Oct 15, 2018
 *      Author: Eng Ali Gamal
 */
# include "Types.h"
# include "REGISTERS.h"
# include "DIO.h"
# include"LCD_Cfg.h"
# include<avr/delay.h>
# include "LCDc.h"

void LCD_vidwriteCharacter(u8 data) {
	DIO_vidSetPortValue(LCD_Port, data);
	DIO_vidSetPinValue(LCD_Control, RS, 1);
	DIO_vidSetPinValue(LCD_Control, RW, 0);
	DIO_vidSetPinValue(LCD_Control, E, 1);
	_delay_ms(1);
	DIO_vidSetPinValue(LCD_Control, E, 0);
	_delay_ms(2);

}
void LCD_vidwriteCommand(u8 comm) {
	DIO_vidSetPortValue(LCD_Port, comm);
	DIO_vidSetPinValue(LCD_Control, RS, 0);
	DIO_vidSetPinValue(LCD_Control, RW, 0);
	DIO_vidSetPinValue(LCD_Control, E, 1);
	_delay_ms(1);
	DIO_vidSetPinValue(LCD_Control, E, 0);
	_delay_ms(2);

}
void LCD_vidInit(void) {
	DIO_vidSetPortDirection(LCD_Port, 0XFF);
	DIO_vidSetPinDirection(LCD_Control, RS, 1);
	DIO_vidSetPinDirection(LCD_Control, RW, 1);
	DIO_vidSetPinDirection(LCD_Control, E, 1);
	_delay_ms(50);
	LCD_vidwriteCommand(0b00111000);
	_delay_ms(1);
	LCD_vidwriteCommand(0b00001100);
	_delay_ms(1);
	LCD_vidwriteCommand(0b00000001);
	_delay_ms(2);
}
void LCD_vidwriteString(u8 *arr) {
	u8 i = 0;
	while (arr[i] != '\0') {
		LCD_vidwriteCharacter(arr[i]);
		i++;
	}
}
void LCD_vidsetposition(u8 row, u8 col) {

	if (row == 1) {
		LCD_vidwriteCommand(128 + col);
	} else if (row == 2) {
		LCD_vidwriteCommand(128 + 64 + col);
	}

}
void LCD_vidWritnumber(u64 number) {

	u64 temp = 1;
	if (number == 0)
		LCD_vidwriteCharacter('0');

	while (number != 0) {
		u8 reminder = number % 10;
		number = number / 10;
		temp = temp * 10 + reminder;
	}
	while (temp != 1) {
		u8 reminder = temp % 10;
		temp = temp / 10;
		LCD_vidwriteCharacter(reminder + 48);
	}

}

void LCD_vidClear(u8 Clr)

{
	DIO_vidSetPortValue(LCD_Port, Clr);
	DIO_vidSetPinValue(LCD_Control, RS, 0);
	LCD_vidwriteCommand(0x1);
	_delay_ms(2);
}
