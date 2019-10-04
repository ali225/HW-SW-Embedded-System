/*
 * main.c
 *
 *  Created on: Dec 24, 2018
 *      Author: Eng Ali Gamal
 */


/// master Tx
#undef F_CPU
#define F_CPU 8000000UL
#define prescaler 1 // 1 4 16 64
#include <avr/io.h>
#include <util/delay.h>

void I2C_Init(unsigned long SCL_Clock){
	TWBR = (unsigned char) (((F_CPU / SCL_Clock) - 16) / (2 * prescaler));

	if (prescaler == 0 )
		TWSR = 0;
	else if (prescaler == 4)
		TWSR = 1;
	else if(prescaler == 16)
		TWSR = 2;
	else if (prescaler == 64)
		TWSR = 3;

}

void I2C_Start(void){
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTA);
	while(((TWCR & (1<<7)) == 0 )); // wait to finish
	while ((TWSR) != 0x08); // start condition has transmitted
}

void I2C_write(unsigned char cByte){
	TWDR =cByte;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while((TWCR & 0x80) == 0); // wait to finish
}
void I2C_Stop(){
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);

}
int main()
{
	unsigned char ch=0;
	I2C_Init(0x48);
	while(1)
	{
		_delay_ms(500);
		I2C_Start();  // transmit start condition
		I2C_write(0b11010000+0); // transmit sla + w(0)
		while((TWSR) != 0x18); // SLA + w(0) has been transmitted and ack has been received
		I2C_write(ch++); // transmit data
		while((TWSR) != 0x28); // data has been transmitted and ack has been received
		I2C_Stop(); // transmit stop condition
	}
	return 0;
	}
