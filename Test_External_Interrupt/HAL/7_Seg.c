/******************************************************************************
 *
 * Module: Seven Segment
 *
 * File Name: 7_seg.c
 *
 * Description: Source file for the AVR Seven Segment driver ATMEGA32
 *
 * Author: Ahmed Yasser
 *
 *******************************************************************************/

#include "sev_seg.h"


void Segment_init(void)
{
		DIO_voidSetPinDirection(GPIOB_BASE,PIN0_ID,Pin_OUTPUT);
	 	DIO_voidSetPinDirection(GPIOB_BASE,PIN1_ID,Pin_OUTPUT);
	 	DIO_voidSetPinDirection(GPIOB_BASE,PIN2_ID,Pin_OUTPUT);
	 	DIO_voidSetPinDirection(GPIOB_BASE,PIN4_ID,Pin_OUTPUT);


	 	DIO_voidSetPinValue(GPIOB_BASE,PIN0_ID,LOW);
	 	DIO_voidSetPinValue(GPIOB_BASE,PIN1_ID,LOW);
	 	DIO_voidSetPinValue(GPIOB_BASE,PIN2_ID,LOW);
	 	DIO_voidSetPinValue(GPIOB_BASE,PIN4_ID,LOW);

	 	DIO_voidSetPinDirection(GPIOA_BASE,PIN3_ID,Pin_OUTPUT);
	 	DIO_voidSetPinValue(GPIOA_BASE,PIN3_ID,LOW);


}

void SevenSeg_Num(uint8 num)

{
	switch(num)
	{
	case 0:
		DIO_voidSetPinValue(GPIOB_BASE,PIN0_ID,LOW);
		DIO_voidSetPinValue(GPIOB_BASE,PIN1_ID,LOW);
		DIO_voidSetPinValue(GPIOB_BASE,PIN2_ID,LOW);
		DIO_voidSetPinValue(GPIOB_BASE,PIN4_ID,LOW);
		break;
	case 1 :
		DIO_voidSetPinValue(GPIOB_BASE,PIN0_ID,HIGH);
		DIO_voidSetPinValue(GPIOB_BASE,PIN1_ID,LOW);
		DIO_voidSetPinValue(GPIOB_BASE,PIN2_ID,LOW);
		DIO_voidSetPinValue(GPIOB_BASE,PIN4_ID,LOW);
		break;
	case 2 :
		DIO_voidSetPinValue(GPIOB_BASE,PIN0_ID,LOW);
		DIO_voidSetPinValue(GPIOB_BASE,PIN1_ID,HIGH);
		DIO_voidSetPinValue(GPIOB_BASE,PIN2_ID,LOW);
		DIO_voidSetPinValue(GPIOB_BASE,PIN4_ID,LOW);
		break;
	case 3 :
		DIO_voidSetPinValue(GPIOB_BASE,PIN0_ID,HIGH);
		DIO_voidSetPinValue(GPIOB_BASE,PIN1_ID,HIGH);
		DIO_voidSetPinValue(GPIOB_BASE,PIN2_ID,LOW);
		DIO_voidSetPinValue(GPIOB_BASE,PIN4_ID,LOW);
		break;
	case 4 :
		DIO_voidSetPinValue(GPIOB_BASE,PIN0_ID,LOW);
		DIO_voidSetPinValue(GPIOB_BASE,PIN1_ID,LOW);
		DIO_voidSetPinValue(GPIOB_BASE,PIN2_ID,HIGH);
		DIO_voidSetPinValue(GPIOB_BASE,PIN4_ID,LOW);
		break;
	case 5 :
		DIO_voidSetPinValue(GPIOB_BASE,PIN0_ID,HIGH);
		DIO_voidSetPinValue(GPIOB_BASE,PIN1_ID,LOW);
		DIO_voidSetPinValue(GPIOB_BASE,PIN2_ID,HIGH);
		DIO_voidSetPinValue(GPIOB_BASE,PIN4_ID,LOW);
		break;
	case 6 :
		DIO_voidSetPinValue(GPIOB_BASE,PIN0_ID,LOW);
		DIO_voidSetPinValue(GPIOB_BASE,PIN1_ID,HIGH);
		DIO_voidSetPinValue(GPIOB_BASE,PIN2_ID,HIGH);
		DIO_voidSetPinValue(GPIOB_BASE,PIN4_ID,LOW);
		break;
	case 7 :
		DIO_voidSetPinValue(GPIOB_BASE,PIN0_ID,HIGH);
		DIO_voidSetPinValue(GPIOB_BASE,PIN1_ID,HIGH);
		DIO_voidSetPinValue(GPIOB_BASE,PIN2_ID,HIGH);
		DIO_voidSetPinValue(GPIOB_BASE,PIN4_ID,LOW);
		break;
	case 8 :
		DIO_voidSetPinValue(GPIOB_BASE,PIN0_ID,LOW);
		DIO_voidSetPinValue(GPIOB_BASE,PIN1_ID,LOW);
		DIO_voidSetPinValue(GPIOB_BASE,PIN2_ID,LOW);
		DIO_voidSetPinValue(GPIOB_BASE,PIN4_ID,HIGH);
		break;
	case 9 :
		DIO_voidSetPinValue(GPIOB_BASE,PIN0_ID,HIGH);
		DIO_voidSetPinValue(GPIOB_BASE,PIN1_ID,LOW);
		DIO_voidSetPinValue(GPIOB_BASE,PIN2_ID,LOW);
		DIO_voidSetPinValue(GPIOB_BASE,PIN4_ID,HIGH);
		break;
	}

}
