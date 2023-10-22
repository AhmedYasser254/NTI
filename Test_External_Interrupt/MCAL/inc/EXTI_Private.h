/******************************************************************************
 *
 * Module: EXTI
 *
 * File Name: EXTI_Private.h
 *
 * Description: Header file for the AVR External interrupt driver ATMEGA32
 *
 * Author: Ahmed Yasser
 *
 *******************************************************************************/

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_
#include "stdint.h"
#include "BIT_MATH.h"


void __vector_1 (void) __attribute__ ((signal));
void __vector_2 (void) __attribute__ ((signal));
void __vector_3 (void) __attribute__ ((signal));

//***********************************************************************************************
//********************************Macros for masking MCUCR Register specific bits for Edges ******************************************
//***********************************************************************************************
#define INT1_MASK				0x11110011
#define INT0_MASK				0x11111100
#define INT2_MASK				0x10111111
//***********************************************************************************************

#endif /* EXTI_PRIVATE_H_ */
