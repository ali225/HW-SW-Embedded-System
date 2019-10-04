/*

 * Seven_segment_main.c
 *
 *  Created on: Feb 24, 2019
 *      Author: Eng Ali Gamal


#include <avr/io.h>         // Defines pins, ports, etc
#include <util/delay.h>		// Functions to waste time
#include "TYPES.h"			// Types data
#include "MACROS.h"			// Function Macros set and clear and togeal
#include "REGISTERS.h"	  	// Defines Registers
#include "DIO/DIO.h"		// Functions to Input and output
#define F_CPU 12000000UL

 main(void) {

	DDRD = 0xFF; // out put port "D"

	// counter display seven segment from 0 to 9
	while (1) {

		PORTD = 0b00100000;  // Number 0
		_delay_ms(1000);
		PORTD = 0b10010000; // Number 9
		_delay_ms(1000);
		PORTD = 0b00000000; // Number 8
		_delay_ms(1000);
		PORTD = 0b11111000; // Number 7
		_delay_ms(1000);
		PORTD = 0b10000010; // Number 6
		_delay_ms(1000);
		PORTD = 0b10010010; // Number 5
		_delay_ms(1000);
		PORTD = 0b10011001; // Number 4
		_delay_ms(1000);
		PORTD = 0b01010000; // Number 3
		_delay_ms(1000);
		PORTD = 0b01000100; // Number 2
		_delay_ms(1000);
		PORTD = 0b11111001; // Number 1
		_delay_ms(1000);
	}
	return 0;

}


 int main (void)
 {
 Set_Bit(DDRA,PB0);
 Set_Bit(DDRA,PB1);
 Set_Bit(DDRA,PB2);
 Set_Bit(DDRA,PB3);

 while(1)
 {
 int i;
 for(i=0;i<=9;i++)
 {
 PORTA=i;
 _delay_ms(1000);
 }

 _delay_ms(1000);
 for(i=9;i>=0;i--)
 {
 PORTA=i;
 _delay_ms(1000);
 }

 _delay_ms(1000);

 }
 return 0;
 }



 int sevenfor_60();
 int sevenfor_10();



 int main(void)
 {
 DDRA = 0xff;
 DDRB = 0xff;
 DDRC = 0b11111111;


 while(1)
 {
 PORTC = 0b00000001;
 _delay_ms(300);
 sevenfor_60();
 PORTC = 0b00000010;
 _delay_ms(300);
 sevenfor_10();
 PORTC = 0b00000100;
 _delay_ms(300);
 sevenfor_60();


 }

 }

 int sevenfor_60()
 {
 char array[]={0b00000100,0b01000000,0b00000000,0b11100100,0b00001000,0b01001000,0b11010000,0b01100000,0b00100010,0b11110100};

 for(int j=5;j<10;j++)
 {
 PORTB = array[j];
 _delay_ms(300);

 for(int i=0;i<10;i++)
 {
 PORTA = array[i];
 _delay_ms(300);
 }
 }
 return 0;
 }


 int sevenfor_10()
 {
 char array[]={0b00000100,0b01000000,0b00000000,0b11100100,0b00001000,0b01001000,0b11010000,0b01100000,0b00100010,0b11110100};

 for(int j=9;j<10;j++)
 {
 PORTB = array[j];
 _delay_ms(300);

 for(int i=0;i<10;i++)
 {
 PORTA = array[i];
 _delay_ms(300);
 }
 }
 return 0;
 }


*/
// counter nine seven segment
/*
int main(void)
{
	u8 Seven_Segment[10]={0b10100000,0b11111001,0b11000100,0b11010000,0b10011001,0b10010010,
	0b10000010,0b11111000,0b10000000,0b10010000};

	DIO_VidSetPortDirection(0,255);

	DIO_VidSetPinDirection(2,0,1);  //  Left Seven Segment
    DIO_VidSetPinDirection(2,1,1);  // Right Seven Segment

    DIO_VidSetPinValue(2,0,0);  //  Left Seven Segment Disabled
    DIO_VidSetPinValue(2,1,0);  // Right Seven Segment Disabled

    while(1)
    {
    	for(int i=0; i<6; i++)
    	{
			for(int j=0;j<10;j++)
			{
				for (int k=0; k<40;k++)
				{
					DIO_VidSetPinValue(2,0,1);  //  Left Seven Segment Enabled
					DIO_VidSetPinValue(2,1,0);  // Right Seven Segment Disabled
					DIO_VidSetPortValue(0,Seven_Segment[i]);
					_delay_ms(5);

					DIO_VidSetPinValue(2,0,0);  //  Left Seven Segment Disabled
					DIO_VidSetPinValue(2,1,1);  // Right Seven Segment Enabled
					DIO_VidSetPortValue(0,Seven_Segment[j]);
					_delay_ms(5);
				}

			}

    	}





    }







	return -1;
}
*/

// TrafficLights
/*
int main(void)
{
	u8 Seven_Segment[10]={0b10100000,0b11111001,0b11000100,0b11010000,0b10011001,0b10010010,
	0b10000010,0b11111000,0b10000000,0b10010000};

	DIO_VidSetPortDirection(0,255);  // Left Seven Segment
	DIO_VidSetPortDirection(1,255);  // Right Seven Segment

	DIO_VidSetPinDirection(2,0,1);  //Red
	DIO_VidSetPinDirection(2,1,1);  //Yellow
	DIO_VidSetPinDirection(2,2,1);  //Green

	DIO_VidSetPinValue(2,0,0);  //Red
	DIO_VidSetPinValue(2,1,0);  //Yellow
	DIO_VidSetPinValue(2,2,0);  //Green


	while(1)
	{
		DIO_VidSetPinValue(2,0,1);  //Red
		DIO_VidSetPinValue(2,2,0);  //Green
		DIO_VidSetPortValue(0,0b10000010); // Left Seven Segment=6
		DIO_VidSetPortValue(1,0b10100000); // Right Seven Segment=0
		_delay_ms(500);

		for(int i=0;i<6;i++)
		{
			DIO_VidSetPortValue(0,Seven_Segment[5-i]); // Left Seven Segment
			for(int j=0;j<10;j++)
						{
							DIO_VidSetPortValue(1,Seven_Segment[9-j]); // Right Seven Segment
							_delay_ms(500);
						}
		}

		DIO_VidSetPinValue(2,0,0);  //Red
		DIO_VidSetPinValue(2,1,1);  //Yellow
		DIO_VidSetPortValue(0,0b11111001); // Left Seven Segment=1
		DIO_VidSetPortValue(1,0b10100000); // Right Seven Segment=0
		_delay_ms(500);

		DIO_VidSetPortValue(0,0b10100000); // Left Seven Segment=0

		for(int j=0;j<10;j++)
					{
						DIO_VidSetPortValue(1,Seven_Segment[9-j]); // Right Seven Segment
						_delay_ms(500);
					}

		DIO_VidSetPinValue(2,1,0);  //Yellow
		DIO_VidSetPinValue(2,2,1);  //Green
		DIO_VidSetPortValue(0,0b10000010); // Left Seven Segment=6
		DIO_VidSetPortValue(1,0b10100000); // Right Seven Segment=0
		_delay_ms(500);

		for(int i=0;i<6;i++)
				{
					DIO_VidSetPortValue(0,Seven_Segment[5-i]); // Left Seven Segment
					for(int j=0;j<10;j++)
								{
									DIO_VidSetPortValue(1,Seven_Segment[9-j]); // Right Seven Segment
									_delay_ms(500);
								}
				}



	}





	return 1;
}
*/


