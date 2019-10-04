/*
 * main.c
 *
 *  Created on: Dec 24, 2018
 *      Author: Eng Ali Gamal
 */

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
unsigned char I2C_Read(unsigned char ack){
	TWCR = (1<<TWINT) | (1<<TWEN)|(ack<<TWEA);
	while((TWCR & 0x80) == 0 );
    return TWDR;
}

void I2C_Stop(){
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);

}
int main()
{
	unsigned char ch;
	DDRA = 0xFF;   // PORTA is output
	I2C_Init(0x48); // initialize TWI for master mode

	while(1)
	{
		_delay_ms(500);
		I2C_Start();  // transmit start condition
		I2C_write(0b11010000+1); // transmit sla + R(1)
		ch = I2C_Read(0); // read last byte send nack
		I2C_Stop(); // transmit stop condition
		PORTA = ch;
	}
	return 0;
	}

