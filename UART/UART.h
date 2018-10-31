/*
 * UART.h
 *
 *  Created on: Oct 30, 2018
 *      Author: Eng Ali Gamal
 */

#ifndef UART_H_
#define UART_H_

//prototype init_UART
void UART_VidInit();
//prototype send UART
void UART_Send(u8 Data);
//prototype Receive UART
u8 UART_Receive();

#endif /* UART_H_ */
