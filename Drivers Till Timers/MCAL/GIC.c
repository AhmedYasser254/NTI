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


void ENABLE_GIC()
{
	SET_BIT(SREG,I);
}

void DISABLE_GIC()
{
	CLR_BIT(SREG,I);
}
