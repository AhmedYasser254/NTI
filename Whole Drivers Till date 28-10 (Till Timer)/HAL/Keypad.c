/*
 * Keypad.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Ahmed Yasser
 */

#include "stdint.h"
#include "Keypad.h"
#include "util/delay.h"
#include "Button.h"

void KEYPAD_INIT()
{
	/* do nothing */
	DIO_voidSetPinDirection(COL_PORT, C1_PIN, PIN_INPUT);
	DIO_voidSetPinDirection(COL_PORT, C2_PIN, PIN_INPUT);
	DIO_voidSetPinDirection(COL_PORT, C3_PIN, PIN_INPUT);

	DIO_voidSetPinDirection(COL_PORT, C4_PIN, PIN_INPUT);


	DIO_voidSetPinDirection(ROW_PORT, R4_PIN, Pin_OUTPUT);
	DIO_voidSetPinDirection(ROW_PORT, R3_PIN, Pin_OUTPUT);
	DIO_voidSetPinDirection(ROW_PORT, R2_PIN, Pin_OUTPUT);

	DIO_voidSetPinDirection(ROW_PORT, R1_PIN, Pin_OUTPUT);




}


uint8_t KEYPAD_Get_Pressed_Key(void)
{
	uint8_t  i,j;
	uint8_t rows[]={R1_PIN,R2_PIN,R3_PIN,R4_PIN};
	uint8_t cols[]={C1_PIN,C2_PIN,C3_PIN,C4_PIN};
	uint8_t KEYPAD_ARR[4][4] = KEYPAD;
	uint8_t key ;

	uint8_t flag;
	while(1)
	{
		for(i = 0; i<=4; i++)
		{
			DIO_voidSetPinValue(ROW_PORT, rows[i], LOW);

			for(j = 0; j<=4; j++)
			{
				flag = Single_press(COL_PORT, cols[j]);
				if(flag == pressed)
				{
					key = KEYPAD_ARR[i][j];
					return key;

				}

			}
			DIO_voidSetPinValue(ROW_PORT, rows[i], HIGH);
			_delay_ms(10);

		}
	}
}

