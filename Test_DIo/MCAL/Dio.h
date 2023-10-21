/******************************************************************************
 *
 * Module: DIO
 *
 * File Name: Dio.h
 *
 * Description: Header file for the AVR GPIO driver ATMEGA32
 *
 * Author: Ahmed Yasser
 *
 *******************************************************************************/

#ifndef DIO_H_
#define DIO_H_

#include "std_types.h"
/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/


typedef enum
{
	PIN0_ID,
	PIN1_ID,
	PIN2_ID,
	PIN3_ID,
	PIN4_ID,
	PIN5_ID,
	PIN6_ID,
	PIN7_ID,
}Pin_ID_t;


typedef enum
{
	PORT_INPUT = 0x00,
	PORT_OUTPUT = 0xFF,

}Port_Direction_t;


typedef enum
{
	PIN_INPUT,
	Pin_OUTPUT

}Pin_Direction_t;

typedef enum
{
	LOW,
	HIGH
}PIN_VALUE_t;


typedef enum
{
	PORT_LOW=0x00,
	PORT_HIGH=0xFF
}PORT_VALUE_t;


typedef union
{
	uint8 Reg;
	struct
	{
		uint8 B0:1;
		uint8 B1:1;
		uint8 B2:1;
		uint8 B3:1;
		uint8 B4:1;
		uint8 B5:1;
		uint8 B6:1;
		uint8 B7:1;
	}Bitfield;
}Reg_Def;

typedef struct
{
	Reg_Def Pin;
	Reg_Def DDR;
	Reg_Def PORT;
}Port_Def;



extern Port_Def* PORTA ;
extern Port_Def* PORTB ;
extern Port_Def* PORTC ;
extern Port_Def* PORTD ;



/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

void DIO_voidSetPinDirection(Port_Def* ptr,Pin_ID_t Copy_u8PinId,Pin_Direction_t Copy_u8Direction);

void DIO_voidSetPinValue(Port_Def* ptr,Pin_ID_t Copy_u8PinId,PIN_VALUE_t Copy_u8Value);

uint8 DIO_voidGetPinValue(Port_Def* ptr,Pin_ID_t Copy_u8PinId);

void DIO_voidSetPortDirection(Port_Def* ptr,Port_Direction_t Copy_u8Direction);

void DIO_voidSetPortValue(Port_Def* ptr,PORT_VALUE_t Copy_u8Value);

uint8 DIO_voidGetPortValue(Port_Def* ptr);



#endif /* DIO_H_ */
