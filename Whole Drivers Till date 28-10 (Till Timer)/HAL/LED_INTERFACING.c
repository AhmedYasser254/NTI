/*
 * LED_INTERFACING.c
 *
 *  Created on: Oct 22, 2023
 *      Author: Ahmed Yasser
 */


#include "LED_INTERFACING.h"

void TURN_ON_OFF_LED(Port_Def* GPIOx ,LED_Status_t state,Pin_ID_t pin )
{
	DIO_voidSetPinDirection(GPIOx, pin, Pin_OUTPUT);

	switch(state)
	{
	case ACTIVE_HIGH:
		DIO_voidSetPinValue(GPIOx, pin, HIGH);
		break;
	case ACTIVE_LOW:
		DIO_voidSetPinValue(GPIOx, pin, LOW);
		break;

	}
}


