/*
 * App.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Ahmed Yasser
 */


#include "gpio.h"
DIOReg_Typedef* GPIOA = ((DIOReg_Typedef*)0x39);
DIOReg_Typedef* GPIOB  = ((DIOReg_Typedef*)0x16);


int main(void)
{
	GPIO_PinCOnffig PinCfg;
		PinCfg.dir = PIN_OUTPUT;
		PinCfg.pin = PIN_5;
		DIO_voidSetPinDirection(GPIOA,&PinCfg);

	while(1)
	{
		DIO_setPinValue(GPIOA, &PinCfg, LOGIC_HIGH);
	}
return 0;
}
