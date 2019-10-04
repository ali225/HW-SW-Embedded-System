/*
 * main.c
 *
 *  Created on: Dec 24, 2018
 *      Author: Eng Ali Gamal
 */
#define F_CPU 1000000UL    // define crystal frequency for delay.h
#include <avr/io.h>
#include <util/delay.h>
#define SS 4   // slave select   is bit no.4
#define MOSI 5 // master out slave in is bit no.5
#define MISO 6 // master in slave out is bit no.6
#define SCK 7  // shift clock

void SPI_MasterInit(void) {
	// set MOST , SCK and SS as Output pins
	DDRB |= (1 << MOSI) | (1 << SCK) | (1 << SS);
	DDRB &= ~(1 << MISO);   // Set MISO as an Input Pin
	//Enable SPI , master mode , shift clock = clk / 16
	SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);
}

///////// SPI master transmtter program page 2/2  //////

unsigned char SPI_MasterTransmit(unsigned char cData) {
	SPDR = cData;      // start transmission
	while (!(SPCR & (1 << SPIF)));  // wait for transmission complete

	return SPCR;
}

int main() {
	unsigned char ch = 0;  // data to send
	DDRA = 0xFF;          // port is output port
	SPI_MasterInit();     // Run as SPI Master
	for (ch = 0; ch <= 255; ch++) {
		_delay_ms(1000);
		// send and receive data and show received at porta
		PORTA = SPI_MasterTransmit(ch);      // call one sec delay
	}
	return 0;
}

