/*
 * GIC.c
 *
 *  Created on: Oct 22, 2023
 *      Author: Ahmed Yasser
 */


#include "GIC.h"


void ENABLE_GIC()
{
	SET_BIT(SREG,I);
}
void DISABLE_GIC()
{
	CLR_BIT(SREG,I);
}
