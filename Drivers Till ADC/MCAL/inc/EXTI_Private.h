/*
 * EXTI_Private.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Ahmed Yasser
 */

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#include "stdint.h"
#include "BIT_MATH.h"
//#include <avr/interrupt.h>

void __vector_1 (void) __attribute__ ((signal)); //INT0
void __vector_2 (void) __attribute__ ((signal)); //INT1

void __vector_3 (void) __attribute__ ((signal)); //IN2

//***********************************************************************************************
//********************************Macros for masking MCUCR Register specific bits for Edges ******************************************
//***********************************************************************************************
#define INT1_MASK				0x11110011
#define INT0_MASK				0x11111100
#define INT2_MASK				0x10111111
//***********************************************************************************************

#endif /* EXTI_PRIVATE_H_ */
