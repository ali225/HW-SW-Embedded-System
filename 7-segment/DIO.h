/*
 * DIO.h
 *
 *  Created on: Sep 26, 2018
 *      Author: My ALi Gamal Aziz
 */

#ifndef DIO_H_
#define DIO_H_


void DIO_VidSetPortDirection(u8 PortNumber, u8 Value);
void DIO_VidSetPortValue(u8 PortNumber, u8 Value);

void DIO_VidSetPinDirection(u8 PortNumber,u8 Pin, u8 Value);
void DIO_VidSetPinValue(u8 PortNumber,u8 Pin, u8 Value);

u8 DIO_u8GetPortValue(u8 Port);
u8 DIO_u8GetPinValue(u8 Port,u8 Pin);


#endif /* DIO_H_ */
