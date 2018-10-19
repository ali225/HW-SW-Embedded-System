/*
 * LCDh.h
 *
 *  Created on: Oct 15, 2018
 *      Author: Eng Ali Gamal
 */

#ifndef LCDC_H_
#define LCDC_H_

	
void LCD_vidwriteCharacter(u8 data);
void LCD_vidwriteCommand(u8 comm);
void LCD_vidInit(void);
void LCD_vidwriteString(u8 *arr);
void LCD_vidsetposition(u8 row , u8 col);
void LCD_vidWritnumber(u64 number);
void LCD_vidClear(u8 Clr);



#endif /* LCDC_H_ */
