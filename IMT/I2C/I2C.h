/*
 * I2C.h
 *
 *  Created on: Mar 13, 2019
 *      Author: Eng Ali Gamal
 */

#ifndef I2C_I2C_H_
#define I2C_I2C_H_

void I2C_Inint(u64 SCL_Clock);
void I2C_Start(void);
void I2C_Write(u8 cByte);
void I2C_Stop();
void I2C_Set_Address(u8 address);
u8 I2C_Read(u8 ack);

#endif /* I2C_I2C_H_ */
