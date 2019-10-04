/*
 * main.c
 *
 *  Created on: Dec 24, 2018
 *      Author: Eng Ali Gamal
 */

#include <avr/io.h>

void I2C_Set_Address(unsigned char address) {
	TWAR = address;
}

void I2C_Read(unsigned char ack) {
	TWCR = (1 << TWINT) | (1 << TWEN) | (ack << TWEA);
	while ((TWCR & 0x80) == 0)
		;
}

void I2C_write(unsigned char cByte) {
	TWDR = cByte;
	TWCR = (1 << TWINT) | (1 << TWEN);
	while ((TWCR & 0x80) == 0)
		; // wait to finish
}
int main() {
	unsigned char ch = 0;
	I2C_Set_Address(0b11010000); // set slave at address 01101000 and do not accept general call
	while (1) {
		I2C_Read(1); // read byte send Ack
		I2C_write(ch++); // SLA(1001100)+R(1)
	}
	return 0;
}
