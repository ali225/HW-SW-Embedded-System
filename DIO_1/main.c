/*
 * main.c
 *
 *  Created on: Dec 11, 2018
 *      Author: Eng Ali Gamal
 */

#include <avr/io.h>

int main(int argc,char **argv){

	DDRD |= 1<<5 | 1<<6 | 1<<7;
	PORTD = 1<<5 | 1<<6 | 1<<7;

	while(1)
	{

	}
	return 1;
}
