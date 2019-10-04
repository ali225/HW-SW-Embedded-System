/*
 * mian.c
 *
 *  Created on: Dec 24, 2018
 *      Author: Eng Ali Gamal
 */

#define F_CPU 8000000UL
#include <avr/io.h>   // stander avr header
#include <util/delay.h>
#define MOSI 5
#define SCK  7
#define SS   4

void execute(unsigned char cmd, unsigned char data) {
	// initializing the packet by pulling ss low
	PORTB &= ~(1 << SS);
	SPDR = cmd;     //start cmd transmission
	// wait cmd transfer to finsh
	while (!(SPSR & (1 << SPIF)))
		;
	// start data transmission
	SPDR = data;
	// wait data transfer to finish
	while (!(SPSR & (1 << SPIF)))
		;
	// terminate the packe by pulling ss high
	PORTB |= 1 << SS;

}

int main(void){
	unsigned char counter = 0 ;
	unsigned char index_dispaly = 1;
	// MOSI SCK and ss are output
	DDRB = (1<<MOSI) |(1<<SCK) |(1<<SS);
	// enable SPI as master , sck = Fosc/16
	SPCR = (1<SPE)|(1<<MSTR)|(1<<SPR0);
	execute(0x09,0xFF); // decod all dispaly 111111
	execute(0x0B,0x07); // set scan limit (digit0 to digit 7)
	execute(0x0A,0x0F); // max intensity
	execute(0x0C,0x01); // turn on display

	while(1)
	{
		for(index_dispaly = 1; index_dispaly<9;index_dispaly++)
			execute(index_dispaly,counter++);
		_delay_ms(1000);
	}
	return 0;
}
