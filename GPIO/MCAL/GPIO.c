/*
 * GPIO.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Ahmed Yasser
 */




#include "gpio.h"




void DIO_voidSetPinDirection(DIOReg_Typedef*GPIOx , GPIO_PinCOnffig* PinConf)
{

	switch(PinConf->pin)
	{
	case PIN_0:
		if (PinConf->dir == PIN_OUTPUT)
		{
			GPIOx->DDR.bits.bit0 =1;
		}
		else
		{
			GPIOx->DDR.bits.bit0 =0;
		}
		break;
	case PIN_1:
		if (PinConf->dir == PIN_OUTPUT)
		{
			GPIOx->PORT.bits.bit0 =1;
		}
		else
		{
			GPIOx->DDR.bits.bit1 =0;
		}
		break;
	case PIN_2:
		if (PinConf->dir == PIN_OUTPUT)
		{
			GPIOx->DDR.bits.bit2 =1;
		}
		else
		{
			GPIOx->DDR.bits.bit2 =0;
		}
		break;
	case PIN_3:
		if (PinConf->dir == PIN_OUTPUT)
		{
			GPIOx->DDR.bits.bit3 =1;
		}
		else
		{
			GPIOx->DDR.bits.bit3 =0;
		}
		break;
	case PIN_4:
		if (PinConf->dir == PIN_OUTPUT)
		{
			GPIOx->DDR.bits.bit4 =1;
		}
		else
		{
			GPIOx->DDR.bits.bit4 =0;
		}
		break;
	case PIN_5:
		if (PinConf->dir == PIN_OUTPUT)
		{
			GPIOx->DDR.bits.bit5 =1;
		}
		else
		{
			GPIOx->DDR.bits.bit5 =0;
		}
		break;
	case PIN_6:
		if (PinConf->dir == PIN_OUTPUT)
		{
			GPIOx->DDR.bits.bit6 =1;
		}
		else
		{
			GPIOx->DDR.bits.bit6 =0;
		}
		break;
	case PIN_7:
		if (PinConf->dir == PIN_OUTPUT)
		{
			GPIOx->DDR.bits.bit7 =1;
		}
		else
		{
			GPIOx->DDR.bits.bit7 =0;
		}
		break;

	}

}




void DIO_setPinValue(DIOReg_Typedef*GPIOx,GPIO_PinCOnffig* PinConf, Pin_Value_t value )
{
	switch(PinConf->pin){
	case PIN_0:
		if (value == LOGIC_HIGH)
		{
			GPIOx->PORT.bits.bit0 =1;
		}
		else
		{
			GPIOx->PORT.bits.bit0 =0;
		}
		break;
	case PIN_1:
		if (value == LOGIC_HIGH)
		{
			GPIOx->PORT.bits.bit0 =1;
		}
		else
		{
			GPIOx->PORT.bits.bit1 =0;
		}
		break;
	case PIN_2:
		if (value == LOGIC_HIGH)
		{
			GPIOx->PORT.bits.bit2 =1;
		}
		else
		{
			GPIOx->PORT.bits.bit2 =0;
		}
		break;
	case PIN_3:
		if (value == LOGIC_HIGH)
		{
			GPIOx->PORT.bits.bit3 =1;
		}
		else
		{
			GPIOx->PORT.bits.bit3 =0;
		}
		break;
	case PIN_4:
		if (value == LOGIC_HIGH)
		{
			GPIOx->PORT.bits.bit4 =1;
		}
		else
		{
			GPIOx->PORT.bits.bit4 =0;
		}
		break;
	case PIN_5:
		if (value == LOGIC_HIGH)
		{
			GPIOx->PORT.bits.bit5 =1;
		}
		else
		{
			GPIOx->PORT.bits.bit5 =0;
		}
		break;
	case PIN_6:
		if (value == LOGIC_HIGH)
		{
			GPIOx->PORT.bits.bit6 =1;
		}
		else
		{
			GPIOx->PORT.bits.bit6 =0;
		}
		break;
	case PIN_7:
		if (value == LOGIC_HIGH)
		{
			GPIOx->PORT.bits.bit7 =1;
		}
		else
		{
			GPIOx->PORT.bits.bit7 =0;
		}
		break;

	}
}



Pin_Value_t DIO_voidGetPinValue(DIOReg_Typedef*GPIOx , GPIO_PinCOnffig* PinConf)
{
	Pin_Value_t pin_value = LOGIC_LOW;
	switch(PinConf->pin)
	{
	case PIN_0:
		if (GPIOx->PIN.bits.bit0)
		{
			pin_value = LOGIC_HIGH;
		}
		else
		{
			pin_value = LOGIC_LOW;
		}
		break;
	case PIN_1:
		if (GPIOx->PIN.bits.bit1)
		{
			pin_value = LOGIC_HIGH;
		}
		else
		{
			pin_value = LOGIC_LOW;
		}
		break;
	case PIN_2:
		if (GPIOx->PIN.bits.bit2)
		{
			pin_value = LOGIC_HIGH;
		}
		else
		{
			pin_value = LOGIC_LOW;
		}
		break;
	case PIN_3:
		if (GPIOx->PIN.bits.bit3)
		{
			pin_value = LOGIC_HIGH;
		}
		else
		{
			pin_value = LOGIC_LOW;
		}
		break;
	case PIN_4:
		if (GPIOx->PIN.bits.bit4)
		{
			pin_value = LOGIC_HIGH;
		}
		else
		{
			pin_value = LOGIC_LOW;
		}
		break;
	case PIN_5:
		if (GPIOx->PIN.bits.bit5)
		{
			pin_value = LOGIC_HIGH;
		}
		else
		{
			pin_value = LOGIC_LOW;
		}
		break;
	case PIN_6:
		if (GPIOx->PIN.bits.bit6)
		{
			pin_value = LOGIC_HIGH;
		}
		else
		{
			pin_value = LOGIC_LOW;
		}
		break;
	case PIN_7:
		if (GPIOx->PIN.bits.bit7)
		{
			pin_value = LOGIC_HIGH;
		}
		else
		{
			pin_value = LOGIC_LOW;
		}
		break;

	}
	return pin_value;
}



void DIO_voidSetPortDirection(DIOReg_Typedef*GPIOx , GPIO_PinCOnffig* PinConf)
{

	GPIOx->DDR.REG = PinConf->dir;
}



void DIO_voidSetPortValue (DIOReg_Typedef*GPIOx,Pin_Value_t value)
{
	GPIOx->PORT.REG = value;
}



uint8_t DIO_voidGetPortValue (DIOReg_Typedef*GPIOx)
{
	uint8_t port_value = LOGIC_LOW;
	port_value = GPIOx->PIN.REG;
	return port_value;
}
