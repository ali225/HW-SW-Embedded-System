/*
 * LCD.h
 *
 *  Created on: Feb 24, 2019
 *      Author: Eng Ali Gamal
 */

#ifndef LCD_LCD_H_
#define LCD_LCD_H_

void LCD_VidWriteCharacter(u8 data);
void LCD_VidWriteCommand(u8 data);
void LCD_VidInit();
void LCD_VidWriteString(u8 * arr);
void LCD_VidSetPosition(u8 X, u8 Y);
void LCD_VidWriteNumber(u64 Number);

#endif /* LCD_LCD_H_ */
