/*
 * main.c
 *
 *  Created on: Dec 24, 2018
 *      Author: Eng Ali Gamal
 */
#undef F_CPU
#define F_CPU 8000000UL
#include <avr/io.h>

void I2C_Set_Address(unsigned char address){
		TWAR = address;}

unsigned char I2C_Read(unsigned char ack){
		unsigned char x = 0;
		TWCR = (1<<TWINT)|(1<<TWEN)|(ack<<TWEA);
		while((TWCR & 1<<7)==0);
		while((TWSR) !=0x60) x = TWSR; // own SLA + W(0) has been transmitted and ack has been returned
		TWCR = (1<<TWINT)|(1<<TWEN)|(ack<<TWEA);
		while((TWCR & 1<<7)==0);
		while((TWSR) !=0x80) x = TWSR; // Data  has been transmitted and ack has been returned

		return TWDR;
}
int main()
{
	DDRA = 0xFF; // PortA is oitput
	I2C_Set_Address(0b11010000); // enable slave at address 01101000 and do not accept general call
	while(1){
		PORTA = I2C_Read(1); // receive byte and send Ack
	}
	return 0;
	}
