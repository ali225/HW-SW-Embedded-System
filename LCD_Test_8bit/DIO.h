/*
 * DIO.h
 *
 *  Created on: Oct 15, 2018
 *      Author: Eng Ali Gamal
 */

#ifndef DIO_H_
#define DIO_H_
void DIO_vidSetPortDirection(u8 port, u8 value);
void DIO_vidSetPortValue(u8 port, u8 value);
void DIO_vidSetPinDirection(u8 port, u8 pin, u8 value);
void DIO_vidSetPinValue(u8 port, u8 pin, u8 value);
u8 DIO_u8ReadPort(u8 port);
#endif /* DIO_H_ */
