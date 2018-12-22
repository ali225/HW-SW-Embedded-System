/*

 * LCDmain.c
 *
 *  Created on: Dec 13, 2018
 *      Author: Eng Ali Gamal


#include "GPIO/GPIO.h"
#include "LCD/lcd.h"
#include "mydelay.h"
#define output 1
#define input 0

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



 * main.c
 *
 *  Created on: Dec 12, 2018
 *      Author: Eng Ali Gamal

#include "GPIO/GPIO.h"
#include "mydelay.h"
#define output 1
#define input 0

int main ()
{
	GPIO_voidInit();
	GPIO_u8_WritePinDir(5,output,'D') ;
	int toggle_led = 1;
	while(1)
	{
		GPIO_u8_WritePinVal(5,toggle_led,'D') ;
		toggle_led ^= 1 ;
		DELAY_MS(1000);
	}

	return 0 ;
}




*/
