/*
 * Counter_Nine_Wires.c
 *
 *  Created on: Apr 12, 2018
 *      Author: Administrator
 */
#include "Types.h"
#include "Macros.h"
#include "DIO.h"
#include <avr/delay.h>
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
