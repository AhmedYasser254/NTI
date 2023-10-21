/*
 * gpio.h
 *
 *  Created on: Oct 20, 2023
 *      Author: Ahmed Yasser
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "stdint.h"


#define  MAX_PIN_NUMBER		31
#define  MIN_PIN_NUMBER		0
#define  MAX_PORT_NUMBER	4
#define  MIN_PORT_NUMBER	0


typedef enum {
	PORT_A_ID,
	PORT_B_ID,
	PORT_C_ID,
	PORT_D_ID

}PORT_ID;


typedef enum {
	PIN_0,
	PIN_1,
	PIN_2,
	PIN_3,
	PIN_4,
	PIN_5,
	PIN_6,
	PIN_7,
}PIN_ID;

typedef union
{
	uint8_t REG;
	struct {
		uint8_t bit0:1;
		uint8_t bit1:1;
		uint8_t bit2:1;
		uint8_t bit3:1;
		uint8_t bit4:1;
		uint8_t bit5:1;
		uint8_t bit6:1;
		uint8_t bit7:1;

	}bits;
}DIO_Typedef;

typedef struct
{
	DIO_Typedef PIN ;
	DIO_Typedef DDR;
	DIO_Typedef PORT;
}DIOReg_Typedef;

typedef enum
{
	PIN_INPUT,PIN_OUTPUT
}GPIO_Direction_Typedef;


typedef struct
{
	GPIO_Direction_Typedef dir;
	PORT_ID port;
	PIN_ID pin;

}GPIO_PinCOnffig;

typedef enum
{
	LOGIC_LOW,LOGIC_HIGH
}Pin_Value_t;


//extern DIOReg_Typedef* GPIOA = ((DIOReg_Typedef*)0x39);
//extern DIOReg_Typedef* GPIOB  = ((DIOReg_Typedef*)0x16);
//#define GPIOC ((DIOReg_Typedef*)0x33)
//#define GPIOD ((DIOReg_Typedef*)0x30)


void DIO_voidSetPinDirection(DIOReg_Typedef*GPIOx , GPIO_PinCOnffig* PinConf);

void DIO_setPinValue(DIOReg_Typedef*GPIOx,GPIO_PinCOnffig* PinConf, Pin_Value_t value );

Pin_Value_t DIO_voidGetPinValue(DIOReg_Typedef*GPIOx , GPIO_PinCOnffig* PinConf);
void DIO_voidSetPortDirection(DIOReg_Typedef*GPIOx , GPIO_PinCOnffig* PinConf);

void DIO_voidSetPortValue (DIOReg_Typedef*GPIOx,Pin_Value_t value);
uint8_t DIO_voidGetPortValue (DIOReg_Typedef*GPIOx);






#endif /* GPIO_H_ */
