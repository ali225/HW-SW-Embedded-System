/*
 * LCD_main.c
 *
 *  Created on: Feb 26, 2019
 *      Author: Eng Ali Gamal
 */


#include <avr/io.h>         // Defines pins, ports, etc
#include <util/delay.h>		// Functions to waste time
#include "TYPES.h"			// Types data
#include "MACROS.h"			// Function Macros set and clear and togel
#include "REGISTERS.h"	  	// Defines Registers
#include "DIO/DIO.h"		// Functions to Input and output
#include "LCD/LCD.h"		// the functions the liber Lcd
#define F_CPU 12000000UL


/*
int main(void)
{
	LCD_VidInit();


		LCD_VidWriteCharacter('A');
		LCD_VidWriteCharacter('L');
		LCD_VidWriteCharacter('i');
}
*/

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
}*/

//	LCD_VidInit();
//	u8 arr[]="ALiGamalAziz";
//	LCD_VidWriteCharacter('A');
//	LCD_VidWriteCharacter('h');
//	LCD_VidWriteCharacter('m');
//	LCD_VidWriteCharacter('e');
//	LCD_VidWriteCharacter('d');

//	LCD_VidSetPosition(4,1);
//	u8 arr2[]="ALi";
//	LCD_VidWriteString(arr2);

//	long long Num=1245656787;
//	LCD_VidWriteNumber(Num);


/*
	while(1)
	{
		for(int i=0;i<6;i++)
		{
			LCD_VidSetPosition(i,0);
			LCD_VidWriteString(arr);
			_delay_ms(1000);
			LCD_VidWriteCommand(00000001);
		}

		for(int i=4;i>0;i--)
		{
			LCD_VidSetPosition(i,0);
			LCD_VidWriteString(arr);
			_delay_ms(1000);
			LCD_VidWriteCommand(00000001);
		}
	}
}*/

/*

	while(1)
	{
		for(int i=0;i<6;i++)
		{
			LCD_VidSetPosition(i,0);
			LCD_VidWriteString(arr);
			_delay_ms(1000);
			LCD_VidWriteCommand(00000001);
		}

		for(int i=0;i<6;i++)
		{
			LCD_VidSetPosition(i,1);
			LCD_VidWriteString(arr);
			_delay_ms(1000);
			LCD_VidWriteCommand(00000001);
		}
	}
}

*/


/*

//	LCD_VidInit();
//	u8 arr[]="Abdel-Malik";
	int size;
	size=sizeof(arr);
	int difference;
	difference= 16 - size +1;
	u8 Space;
	Space=' ';
	int Reverse;


	while(1)
	{
		for(int i=0;i<17;i++)
		{
			Reverse= i-difference;

			if(i>0)
			{
				LCD_VidSetPosition(i-1,0);
				LCD_VidWriteCharacter(Space);
			}

			for(int j=0;j<size-1;j++)
			{
				LCD_VidSetPosition(i+j,0);
				LCD_VidWriteCharacter(arr[j]);
			}



			if(i > difference)
			{
				for(int k=Reverse; k>0;k--)
				{
					LCD_VidSetPosition(k-1,0);
					LCD_VidWriteCharacter(arr[size-2-Reverse+k]);
				}

			}

			if(i != 16)
			{
				_delay_ms(1000);
			}

		}
	}

}
*/


/*

	while(1)
	{
		  LCD_VidWriteCommand(0b01000000);//3shan arouh lel cgram

		  LCD_VidWriteCharacter(0b00000000);
		  LCD_VidWriteCharacter(0b00000000);
		  LCD_VidWriteCharacter(0b00000111);
		  LCD_VidWriteCharacter(0b00000100);
		  LCD_VidWriteCharacter(0b00011111);  //3en
		  LCD_VidWriteCharacter(0b00000000);
		  LCD_VidWriteCharacter(0b00000000);
		  LCD_VidWriteCharacter(0b00000000);


		  LCD_VidWriteCharacter(0b00000000);
		  LCD_VidWriteCharacter(0b00000000);
		  LCD_VidWriteCharacter(0b00000001);
		  LCD_VidWriteCharacter(0b00000001);
		  LCD_VidWriteCharacter(0b00011111); //ba2
		  LCD_VidWriteCharacter(0b00000000);
		  LCD_VidWriteCharacter(0b00000100);
		  LCD_VidWriteCharacter(0b00000000);


		  LCD_VidWriteCharacter(0b00000000);
		  LCD_VidWriteCharacter(0b00000000);
		  LCD_VidWriteCharacter(0b00000001);
		  LCD_VidWriteCharacter(0b00000001);
		  LCD_VidWriteCharacter(0b00000111); //dal
		  LCD_VidWriteCharacter(0b00000000);
		  LCD_VidWriteCharacter(0b00000000);
		  LCD_VidWriteCharacter(0b00000000);

		  LCD_VidWriteCharacter(0b00010000);
		  LCD_VidWriteCharacter(0b00010000);
		  LCD_VidWriteCharacter(0b00010000);
		  LCD_VidWriteCharacter(0b00010000);
		  LCD_VidWriteCharacter(0b00010000); //alef
		  LCD_VidWriteCharacter(0b00000000);
		  LCD_VidWriteCharacter(0b00000000);
		  LCD_VidWriteCharacter(0b00000000);

		  LCD_VidWriteCharacter(0b00000001);
		  LCD_VidWriteCharacter(0b00000001);
		  LCD_VidWriteCharacter(0b00000001);
		  LCD_VidWriteCharacter(0b00000001);
		  LCD_VidWriteCharacter(0b00011111); //lam
		  LCD_VidWriteCharacter(0b00000000);
		  LCD_VidWriteCharacter(0b00000000);
		  LCD_VidWriteCharacter(0b00000000);

		  LCD_VidWriteCharacter(0b00000000);
		  LCD_VidWriteCharacter(0b00000000);
		  LCD_VidWriteCharacter(0b00000000);
		  LCD_VidWriteCharacter(0b00000000);
		  LCD_VidWriteCharacter(0b00011111); //meem
		  LCD_VidWriteCharacter(0b00000101);
		  LCD_VidWriteCharacter(0b00000111);
		  LCD_VidWriteCharacter(0b00000000);

		  LCD_VidWriteCharacter(0b00000001);
		  LCD_VidWriteCharacter(0b00000001);
		  LCD_VidWriteCharacter(0b00000001);
		  LCD_VidWriteCharacter(0b00000001);
		  LCD_VidWriteCharacter(0b00011111); //lam
		  LCD_VidWriteCharacter(0b00000000);
		  LCD_VidWriteCharacter(0b00000000);
		  LCD_VidWriteCharacter(0b00000000);

		  LCD_VidWriteCharacter(0b00001101);
		  LCD_VidWriteCharacter(0b00001001);
		  LCD_VidWriteCharacter(0b00011101);
		  LCD_VidWriteCharacter(0b00000001);
		  LCD_VidWriteCharacter(0b00011111); //kaf
		  LCD_VidWriteCharacter(0b00000000);
		  LCD_VidWriteCharacter(0b00000000);
		  LCD_VidWriteCharacter(0b00000000);

		  LCD_VidSetPosition(8,1);
		  LCD_VidWriteCharacter(7);
		  LCD_VidWriteCharacter(6);
		  LCD_VidWriteCharacter(5);
		  LCD_VidWriteCharacter(4);
		  LCD_VidWriteCharacter(3);
		  LCD_VidWriteCharacter(2);
		  LCD_VidWriteCharacter(1);
		  LCD_VidWriteCharacter(0);

	}

	return -1;
}

*/
/*

	while(1)
	{
			Init LCD
			LCD_VidInit();

			writ CGRAM this order
			LCD_VidWriteCommand(0x40);

			the draw Arabic A
			LCD_VidWriteCharacter(0x00);
			LCD_VidWriteCharacter(0xFF);
			LCD_VidWriteCharacter(0x10);
			LCD_VidWriteCharacter(0x10);
			LCD_VidWriteCharacter(0x10);
			LCD_VidWriteCharacter(0xFF);
			LCD_VidWriteCharacter(0x00);
			LCD_VidWriteCharacter(0x00);

			the draw Arabic L

			LCD_VidWriteCharacter(0x04);
			LCD_VidWriteCharacter(0x04);
			LCD_VidWriteCharacter(0x04);
			LCD_VidWriteCharacter(0x04);
			LCD_VidWriteCharacter(0x04);
			LCD_VidWriteCharacter(0x1F);
			LCD_VidWriteCharacter(0x00);
			LCD_VidWriteCharacter(0x00);

			the draw Arabic i
			LCD_VidWriteCharacter(0x00);
			LCD_VidWriteCharacter(0x00);
			LCD_VidWriteCharacter(0x00);
			LCD_VidWriteCharacter(0x00);
			LCD_VidWriteCharacter(0x00);
			LCD_VidWriteCharacter(0x11);
			LCD_VidWriteCharacter(0x11);
			LCD_VidWriteCharacter(0xFF);

			the draw Smail ^_^
			LCD_VidWriteCharacter(0x00);
			LCD_VidWriteCharacter(0x00);
			LCD_VidWriteCharacter(0x0A);
			LCD_VidWriteCharacter(0x00);
			LCD_VidWriteCharacter(0x11);
			LCD_VidWriteCharacter(0x0E);
			LCD_VidWriteCharacter(0x00);
			LCD_VidWriteCharacter(0x00);

			//	LCD_vidwriteCharacter('a');
			//  LCD_vidWritnumber(100);


			char array[]={12,11,10,9,8,7,6,5,4,3,2,1,0};

			for (int j= 0 ; j < 12; j++){
				LCD_VidSetPosition(1,array[j]);

				print smail
				LCD_VidWriteCharacter(3);
				print i
				LCD_VidWriteCharacter(2);
				print ل
				LCD_VidWriteCharacter(1);
				print ع
				LCD_VidWriteCharacter(0);

				write the row two and start 0
				LCD_VidSetPosition(2,j);
				print array that
				u8 arr[]="ALi";
				LCD_VidWriteString(arr);
				LCD_VidWriteCharacter(3);
				_delay_ms(1000);

				lcd_clrScreen(0xFF);
				_delay_ms(1);
			}

			for (int i=12;i>0;i--){

				LCD_VidSetPosition(1,array[i]);

				print smail
				LCD_VidWriteCharacter(3);
				print i
				LCD_VidWriteCharacter(2);
				print ل
				LCD_VidWriteCharacter(1);
				print ع
				LCD_VidWriteCharacter(0);

				write the row two and start 0
				LCD_VidSetPosition(2,i);
				print array that
				u8 arr[]="ALi";
				LCD_VidWriteString(arr);
				LCD_VidWriteCharacter(3);
				_delay_ms(1000);

				lcd_clrScreen(0xFF);
				_delay_ms(1);
			}

		}

	}
*/
