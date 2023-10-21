/******************************************************************************
 *
 * Module: Application
 *
 * File Name: APP.c
 *
 * Description: Source file for Test DIO driver
 *
 * Author: Ahmed Yasser
 *
 *******************************************************************************/

#include "Dio.h"
#include<util/delay.h>

int main(void)
{

	/*Make portA to be output for bliking Yellow,BLUe,Green
	 *
	 */
	DIO_voidSetPortDirection(PORTA, PORT_OUTPUT);

	while(1)
	{

		DIO_voidSetPinValue(PORTA, PIN6_ID, HIGH);
		_delay_ms(500);

		DIO_voidSetPinValue(PORTA, PIN5_ID, HIGH);
		_delay_ms(500);


		DIO_voidSetPinValue(PORTA, PIN4_ID, HIGH);
		_delay_ms(500);


		DIO_voidSetPinValue(PORTA, PIN6_ID, LOW);
		_delay_ms(500);

		DIO_voidSetPinValue(PORTA, PIN5_ID, LOW);
		_delay_ms(500);


		DIO_voidSetPinValue(PORTA, PIN4_ID, LOW);
		_delay_ms(500);


	}
	return 0;
}
