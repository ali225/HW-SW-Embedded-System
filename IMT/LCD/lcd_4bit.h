/*
 * lcd_4bit.h
 *
 *  Created on: Feb 24, 2019
 *      Author: Eng Ali Gamal
 */

#ifndef LCD_LCD_4BIT_H_
#define LCD_LCD_4BIT_H_

void lcd_sendCommand(unsigned char cmd);
void lcd_displayChar(unsigned char data);
void lcd_init(void);
void lcd_gotoxy(unsigned char x, unsigned char y);
void lcd_clrScreen(void);
void lcd_dispString(char * ptr);
void lcd_disp_string_xy(char * ptr, int y, int x);



#endif /* LCD_LCD_4BIT_H_ */
