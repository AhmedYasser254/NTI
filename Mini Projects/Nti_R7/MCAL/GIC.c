/******************************************************************************
 *
 * Module: General Interrupt Controller
 *
 * File Name: GIC.c
 *
 * Description: Source file for the AVR General Interrupt Controller driver ATMEGA32
 *
 * Author: Ahmed Yasser
 *
 *******************************************************************************/
#include "GIC.h"


void ENABLE_GIE()
{
	SET_BIT(SREG_t,I);
}

void DISABLE_GIE()
{
	CLR_BIT(SREG_t,I);
}
