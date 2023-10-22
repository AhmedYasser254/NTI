/*
 * Keypad.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Ahmed Yasser
 */

#include "stdint.h"
#include "Keypad.h"
#include "util/delay.h"
//uint8_t arr [4][4] = 		{{'1','2','3','+'},	//keypad layout design for calculator app
//							{'4','5','6','-'},
//							{'7','8','9','*'},
//		{					'0','=','c','/' } };
void KEYPAD_INIT()
{
	/* do nothing */
	DIO_voidSetPinDirection(GPIOD_BASE, PIN7_ID, PIN_INPUT);
	DIO_voidSetPinDirection(GPIOD_BASE, PIN6_ID, PIN_INPUT);
	DIO_voidSetPinDirection(GPIOD_BASE, PIN5_ID, PIN_INPUT);

	DIO_voidSetPinDirection(GPIOD_BASE, PIN3_ID, PIN_INPUT);


	DIO_voidSetPinDirection(GPIOC_BASE, PIN5_ID, Pin_OUTPUT);
	DIO_voidSetPinDirection(GPIOC_BASE, PIN4_ID, Pin_OUTPUT);
	DIO_voidSetPinDirection(GPIOC_BASE, PIN3_ID, Pin_OUTPUT);

	DIO_voidSetPinDirection(GPIOC_BASE, PIN2_ID, Pin_OUTPUT);


}


uint8_t KEYPAD_Get_Pressed_Key(void)
{
	uint8_t  i,j;
	uint8_t rows[]={5,4,3,2};
	uint8_t cols[]={7,6,5,3};
	while(1)
	{
		for(i = 0; i<3; i++)
		{
			DIO_voidSetPinValue(GPIOC_BASE, rows[i], LOW);

			for(j = 0; j<3; j++)
			{
				if(DIO_voidGetPinValue(GPIOD_BASE, cols[j]) == LOW)
				{

					return ((i*3) + (j+1));
				}
			}
			DIO_voidSetPinValue(GPIOC_BASE, rows[i], HIGH);
			_delay_ms(5);
		}
	}


}

