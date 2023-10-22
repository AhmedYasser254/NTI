/******************************************************************************
 *
 * Module: EXTI
 *
 * File Name: EXTI_INTERFACE.c
 *
 * Description: Source file for the AVR External interrupt driver ATMEGA32
 *
 * Author: Ahmed Yasser
 *
 *******************************************************************************/
#include "EXTI_Private.h"

#include "EXTI_INTERACE.h"
#include "GIC.h"

void (* EXT_INT_POINTERS [3]) (void) ;

void MCAL_EXTI_INIT(EXTI_CONFIG_t* EXTI_Config)
{
	ENABLE_GIC();

	SET_BIT(EXTI_BASE->GICR_Reg.Reg, EXTI_Config->external_number);

	switch (EXTI_Config->external_number)
	{
	case EXTI_NUM_0:
		EXTI_BASE->MCUCR_Reg.Reg &= ~(INT0_MASK);
		EXTI_BASE->MCUCR_Reg.Reg |= EXTI_Config->trigger_edge;
		break;
	case EXTI_NUM_1:
		EXTI_BASE->MCUCR_Reg.Reg &= ~(INT1_MASK);
		EXTI_BASE->MCUCR_Reg.Reg |= (EXTI_Config->trigger_edge)<<2 ;
		break;
	case EXTI_NUM_2:
		EXTI_BASE->MCUCSR_Reg.Reg &= ~(INT2_MASK);
		EXTI_BASE->MCUCSR_Reg.Reg |= (EXTI_Config->trigger_edge - 2)<<6;
		break;

	}
	if(EXTI_Config->external_number == EXTI_NUM_0 || EXTI_Config->external_number == EXTI_NUM_1)
		EXT_INT_POINTERS[EXTI_Config->external_number - 6] = EXTI_Config->P_IRQ_CallBack;

	else
		EXT_INT_POINTERS[EXTI_Config->external_number - 3] = EXTI_Config->P_IRQ_CallBack;



}


void MCAL_EXTI_GPIO_DeInit (EXTI_CONFIG_t* EXTI_Config)
{
	switch(EXTI_Config->external_number)
	{
	case EXTI_NUM_0:

		CLR_BIT(EXTI_BASE->GICR_Reg.Reg,EXTI_Config->external_number);
		break;
	case EXTI_NUM_1:

		CLR_BIT(EXTI_BASE->GICR_Reg.Reg,EXTI_Config->external_number);
		break;

	case EXTI_NUM_2:

		CLR_BIT(EXTI_BASE->GICR_Reg.Reg,EXTI_Config->external_number);
		break;


	}
}

void __vector_1 (void)
{
	DISABLE_GIC();
	EXT_INT_POINTERS[0]();
}

void __vector_2 (void)
{
	DISABLE_GIC();
	EXT_INT_POINTERS[1]();
}

void __vector_3 (void)
{
	DISABLE_GIC();
	EXT_INT_POINTERS[2]();
}

