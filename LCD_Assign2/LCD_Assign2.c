/*
 * LCD_Assign2.c
 *
 *  Created on: Apr 26, 2018
 *      Author: Administrator
 */
#include "Types.h"
#include "LCDc.h"
#include "DIO.h"
#define F_CPU 8000000UL
#include <avr/delay.h>
/*
int main(void)
{

	LCD_VidInit();
	u8 arr[]="Welcome!";
	u8 arr2[]="Enter Password:";
	u8 arr3[]="Try Again:";
	u8 arr4[]="Successful Login";
	u8 arr5[]="Tries Left=";
	u8 flag=0;

	DIO_VidSetPortDirection(3,0);
	DIO_VidSetPortValue(3,255);  //Pull-up resistance

	LCD_VidWriteCommand(0b01000000);//3shan arouh lel cgram

	LCD_VidWriteCharacter(0b00000000);
	LCD_VidWriteCharacter(0b00000000);
	LCD_VidWriteCharacter(0b00011100);
	LCD_VidWriteCharacter(0b00000010);
	LCD_VidWriteCharacter(0b00000011);  //7a2
	LCD_VidWriteCharacter(0b00011100);
	LCD_VidWriteCharacter(0b00000000);
	LCD_VidWriteCharacter(0b00000000);

	LCD_VidWriteCharacter(0b00000000);
	LCD_VidWriteCharacter(0b00000000);
	LCD_VidWriteCharacter(0b00000000);
	LCD_VidWriteCharacter(0b00000000);
	LCD_VidWriteCharacter(0b00000000);  //ra2
	LCD_VidWriteCharacter(0b00000011);
	LCD_VidWriteCharacter(0b00001100);
	LCD_VidWriteCharacter(0b00010000);

	LCD_VidWriteCharacter(0b00000100);
	LCD_VidWriteCharacter(0b00000100);
	LCD_VidWriteCharacter(0b00000100);
	LCD_VidWriteCharacter(0b00000100);
	LCD_VidWriteCharacter(0b00000100);  //alef
	LCD_VidWriteCharacter(0b00000000);
	LCD_VidWriteCharacter(0b00000000);
	LCD_VidWriteCharacter(0b00000000);

	LCD_VidWriteCharacter(0b00000000);
	LCD_VidWriteCharacter(0b00000000);
	LCD_VidWriteCharacter(0b00000000);
	LCD_VidWriteCharacter(0b00011111);
	LCD_VidWriteCharacter(0b00000101);  //meem
	LCD_VidWriteCharacter(0b00000111);
	LCD_VidWriteCharacter(0b00000000);
	LCD_VidWriteCharacter(0b00000000);

	LCD_VidWriteCharacter(0b00000000);
	LCD_VidWriteCharacter(0b00000000);
	LCD_VidWriteCharacter(0b00000000);
	LCD_VidWriteCharacter(0b00000011);
	LCD_VidWriteCharacter(0b00010010);  //ya2
	LCD_VidWriteCharacter(0b00011110);
	LCD_VidWriteCharacter(0b00000000);
	LCD_VidWriteCharacter(0b00001010);

	u8 PW_HSB= 0; //Password Highest Significant Bit
	u8 PW_MSB= 0; //Password Middle Significant Bit
	u8 PW_LSB= 0; //Password Lowest Significant Bit
	u8 Enter = 0; //Enter Password

	u8 Tries=2;

	while(1)
	{
		LCD_VidSetPosition(4,0);
		LCD_VidWriteString(arr);
		_delay_ms(3000);
		LCD_VidWriteCommand(00000001);

		while( Enter != 1)
		{
			LCD_VidSetPosition(0,0);
			LCD_VidWriteString(arr2);

			PW_HSB= DIO_u8GetPinValue(3,5); //Password Highest Significant Bit
			PW_MSB= DIO_u8GetPinValue(3,6); //Password Middle Significant Bit
			PW_LSB= DIO_u8GetPinValue(3,7); //Password Lowest Significant Bit
			Enter = DIO_u8GetPinValue(3,0); //Enter Password

		}


		if(PW_HSB ==1 && PW_MSB==1 && PW_LSB==1)
		{
			LCD_VidWriteCommand(00000001);
			LCD_VidSetPosition(0,0);
			LCD_VidWriteString(arr4);
			_delay_ms(3000);
		}
		else
		{
			_delay_ms(3000);
			Enter = DIO_u8GetPinValue(3,0); //Enter Password

			for(u8 i=0;i<2;i++)
			{
				while( Enter != 1)
				{
					LCD_VidWriteCommand(00000001);
					LCD_VidSetPosition(0,0);
					LCD_VidWriteString(arr3);

					LCD_VidSetPosition(0,1);
					LCD_VidWriteString(arr5);

					LCD_VidSetPosition(15,1);
					LCD_VidWriteNumber(Tries);
					_delay_ms(1000);


					PW_HSB= DIO_u8GetPinValue(3,5); //Password Highest Significant Bit
					PW_MSB= DIO_u8GetPinValue(3,6); //Password Middle Significant Bit
					PW_LSB= DIO_u8GetPinValue(3,7); //Password Lowest Significant Bit
					Enter = DIO_u8GetPinValue(3,0); //Enter Password
				}

				Tries--;
				_delay_ms(3000);
				Enter = DIO_u8GetPinValue(3,0); //Enter Password

				if(PW_HSB ==1 && PW_MSB==1 && PW_LSB==1)
				{
					LCD_VidWriteCommand(00000001);
					LCD_VidSetPosition(0,0);
					LCD_VidWriteString(arr4);
					_delay_ms(3000);
					flag=1;
					break;
				}
			}

			if(flag !=1)
			{
				LCD_VidWriteCommand(00000001);
				LCD_VidSetPosition(5,0);
				LCD_VidWriteCharacter(4);
				LCD_VidWriteCharacter(3);
				LCD_VidWriteCharacter(2);
				LCD_VidWriteCharacter(1);
				LCD_VidWriteCharacter(0);
				_delay_ms(3000);
			}



		}

		LCD_VidWriteCommand(00000001);
		Tries=2;
		Enter=0;
		flag=0;
	}
	return -1;
}
*/

