/*

 * LCDmain.c
 *
 *  Created on: Dec 13, 2018
 *      Author: Eng Ali Gamal

*/
/*
#include <avr/io.h>
#include <util/delay.h>

#include "GPIO/GPIO.h"
#include "LCD/lcd.h"
#include "mydelay.h"
#define output 1
#define input 0
*/

/*int main()
{
   char seg_code[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
   int cnt=0;

//  Configure the ports as output
 DDRC = 0xff;

   while(1)
    {
	    for(cnt=0x00;cnt<=0x0f;cnt++)	 // loop to display 0-F
		 {
			PORTB = seg_code[cnt];	 // Send the segment_code of number to be displayed
			_delay_ms(1000);
		 }
	}
}*/
/*
int main()
{
	LCD_lcd_init();

	while(1)
	{
		LCD_Send_A_String("Hello on embedded system Diploma by: Ali gamal");
		LCD_clear_screen();
		LCD_Send_A_String("Number Examples");
		LCD_display_real_number(30.127);
		LCD_Send_A_String("   ");
		LCD_display_number(12);
		LCD_clear_screen();
		DELAY_MS(1000);

	}
	return 0;
}



*/
