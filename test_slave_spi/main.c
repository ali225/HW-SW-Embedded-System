/*
 * main.c
 *
 *  Created on: Dec 24, 2018
 *      Author: Eng Ali Gamal
 */

#define F_CPU 1000000UL  // this frquancy
#include <avr/io.h>
#include <util/delay.h>
#define SS 4   // slave select   is bit no.4
#define MOSI 5 // master out slave in is bit no.5
#define MISO 6 // master in slave out is bit no.6
#define SCK 7  // shift clock

void SPI_SlaveInit(void) {
	// set MOST , SCK and SS as Output pins
	DDRB |= (1 << MISO);

	DDRB &= ~(1 << MOSI) & ~(1 << SCK) & ~(1 << SS); // Set MISO as an Input Pin
	//Enable SPI , master mode , shift clock = clk / 16
	SPCR = (1 << SPE);
}

///////// SPI master transmtter program page 2/2  //////

unsigned char SPI_SlaveReceive(unsigned char cData) {
	SPDR = cData;      // start transmission
	while (!(SPCR & (1 << SPIF)))
		;
	// wait for transmission complete
	return SPCR;
}

int main() {
	unsigned char x = 255;  // data to send
	DDRA = 0xFF;          // port is output port
	SPI_SlaveInit();     // Run as SPI Master

	while (1) {
		for (x = 255; x > 0; x--) {

			// send and receive data and show received at porta
			PORTA = SPI_SlaveReceive(x);      // call one sec delay
		}
	}
	return 0;
}

