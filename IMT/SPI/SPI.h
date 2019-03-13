/*
 * SPI.h
 *
 *  Created on: Mar 13, 2019
 *      Author: Eng Ali Gamal
 */

#ifndef SPI_SPI_H_
#define SPI_SPI_H_

void SPI_vidMasterInit();
void SPI_vidSlaveInit();
u8 SPI_Transceiver(u8 Data);

#endif /* SPI_SPI_H_ */
