/*
 * LED_INTERFACING.c
 *
 *  Created on: Oct 22, 2023
 *      Author: Ahmed Yasser
 */


#include "LED_INTERFACING.h"

void TURN_ON_LED(Port_Def* GPIOx ,LED_Status_t state,Pin_ID_t pin )
{
	switch(state)
	{
	case ACTIVE_HIGH:
		DIO_voidSetPinDirection(GPIOx, pin, Pin_OUTPUT);
		DIO_voidSetPinValue(GPIOx, pin, HIGH);
		break;
	case ACTIVE_LOW:
		DIO_voidSetPinDirection(GPIOx, pin, Pin_OUTPUT);
		DIO_voidSetPinValue(GPIOx, pin, LOW);
		break;

	}
}



void TURN_OFF_LED(Pin_ID_t pin ,LED_Status_t state,Port_Def* GPIOx  )
{
	switch (state)
	{

	case ACTIVE_HIGH:
		DIO_voidSetPinDirection(GPIOx, pin, Pin_OUTPUT);
		DIO_voidSetPinValue(GPIOx, pin, LOW);
		break;
	case ACTIVE_LOW:
		DIO_voidSetPinDirection(GPIOx, pin, Pin_OUTPUT);
		DIO_voidSetPinValue(GPIOx, pin, HIGH);
		break;
	}

}
