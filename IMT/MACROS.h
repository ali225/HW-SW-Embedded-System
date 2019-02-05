/*
 * MACROS.h
 *
 *  Created on: Feb 5, 2019
 *      Author: Eng Ali Gamal
 */

#ifndef MACROS_H_
#define MACROS_H_

#define Set_Bit(Var, BitNo) Var=(Var | (1<< BitNo))
#define Clr_Bit(Var, BitNo) Var=(Var &  (~(1 << BitNo)))
#define Toggle_Bit(Var, BitNo) Var=(Var ^ (1<< BitNo))
#define Get_Bit(Var, BitNo) ((Var & (1<<BitNo)) >> BitNo)

#define HIGH_NIBBLE(hVar,var) hVar= (var & 0xf0)    // hVar will hold value of high nibble of var

#define LOW_NIBBLE(lVar,var) lVar= (var<<4)        // lVar will hold the value of low nibble of var

//#define CLR_BIT(var, bit) var &= (~(1<<bit))

//#define SET_BIT(var, bit) var |= (1<<bit)

//#define TOG_BIT(var, bit) var ^= (1<<bit)

#endif /* MACROS_H_ */
