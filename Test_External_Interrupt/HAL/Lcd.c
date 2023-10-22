/*
 * Lcd.c
 *
 *  Created on: Oct 22, 2023
 *      Author: Ahmed Yasser
 */
#include "Lcd.h"

#define GET_BIT(register_name,bit_no)  			((register_name & (1<<bit_no)) >>bit_no)



void LCD_INT (void)
{
	DIO_voidSetPinDirection(GPIOA_BASE, LCD_RS_PIN, Pin_OUTPUT);
	DIO_voidSetPinDirection(GPIOA_BASE, LCD_EN_PIN, Pin_OUTPUT);

	DIO_voidSetPinDirection(GPIOB_BASE, LCD_D4_PIN, Pin_OUTPUT);
	DIO_voidSetPinDirection(GPIOB_BASE, LCD_D5_PIN, Pin_OUTPUT);
	DIO_voidSetPinDirection(GPIOB_BASE, LCD_D6_PIN, Pin_OUTPUT);
	DIO_voidSetPinDirection(GPIOB_BASE, LCD_D7_PIN, Pin_OUTPUT);


	_delay_ms(200);
	LCD_WRITE_COMMAND(LCD_4_BIT_MODE_COMMAND_1);

	_delay_ms(20);
	LCD_WRITE_COMMAND(LCD_4_BIT_MODE_COMMAND_2);
	_delay_ms(20);
	LCD_WRITE_COMMAND(LCD_4_BIT_MODE_COMMAND_3);
	_delay_ms(20);
	LCD_WRITE_COMMAND(LCD_DISPLAY_ON_COMMAND);
	_delay_ms(20);
	LCD_WRITE_COMMAND(LCD_RETURN_HOME_COMMAND);
	_delay_ms(20);
	LCD_WRITE_COMMAND(LCD_CLEAR);
	_delay_ms(20);





}

void LCD_WRITE_COMMAND (uint8_t command)
{
	DIO_voidSetPinValue(GPIOA_BASE, LCD_RS_PIN, LOW);
	DIO_voidSetPinValue(GPIOA_BASE, LCD_EN_PIN, LOW);

	_delay_ms(10);
	DIO_voidSetPinValue(GPIOB_BASE, LCD_D4_PIN, GET_BIT(command,4));
	DIO_voidSetPinValue(GPIOB_BASE, LCD_D5_PIN, GET_BIT(command,5));
	DIO_voidSetPinValue(GPIOB_BASE, LCD_D6_PIN, GET_BIT(command,6));
	DIO_voidSetPinValue(GPIOB_BASE, LCD_D7_PIN, GET_BIT(command,7));
	DIO_voidSetPinValue(GPIOA_BASE, LCD_EN_PIN, HIGH);
	_delay_ms(10);
	DIO_voidSetPinValue(GPIOA_BASE, LCD_EN_PIN, LOW);
	_delay_ms(10);
	DIO_voidSetPinValue(GPIOB_BASE, LCD_D4_PIN, GET_BIT(command,0));
	DIO_voidSetPinValue(GPIOB_BASE, LCD_D5_PIN, GET_BIT(command,1));
	DIO_voidSetPinValue(GPIOB_BASE, LCD_D6_PIN, GET_BIT(command,2));
	DIO_voidSetPinValue(GPIOB_BASE, LCD_D7_PIN, GET_BIT(command,3));
	DIO_voidSetPinValue(GPIOA_BASE, LCD_EN_PIN, HIGH);
	_delay_ms(10);
	DIO_voidSetPinValue(GPIOA_BASE, LCD_EN_PIN, LOW);
	_delay_ms(50);

}



void LCD_WRITE_CHAR(uint8_t c)
{
	DIO_voidSetPinValue(GPIOA_BASE, LCD_RS_PIN, HIGH);
	DIO_voidSetPinValue(GPIOA_BASE, LCD_EN_PIN, LOW);
	_delay_ms(10);


	DIO_voidSetPinValue(GPIOB_BASE, LCD_D4_PIN, GET_BIT(c,4));
	DIO_voidSetPinValue(GPIOB_BASE, LCD_D5_PIN, GET_BIT(c,5));
	DIO_voidSetPinValue(GPIOB_BASE, LCD_D6_PIN, GET_BIT(c,6));
	DIO_voidSetPinValue(GPIOB_BASE, LCD_D7_PIN, GET_BIT(c,7));
	DIO_voidSetPinValue(GPIOA_BASE, LCD_EN_PIN, HIGH);
	_delay_ms(10);
	DIO_voidSetPinValue(GPIOA_BASE, LCD_EN_PIN, LOW);
	_delay_ms(10);
	_delay_ms(10);
	DIO_voidSetPinValue(GPIOB_BASE, LCD_D4_PIN, GET_BIT(c,0));
	DIO_voidSetPinValue(GPIOB_BASE, LCD_D5_PIN, GET_BIT(c,1));
	DIO_voidSetPinValue(GPIOB_BASE, LCD_D6_PIN, GET_BIT(c,2));
	DIO_voidSetPinValue(GPIOB_BASE, LCD_D7_PIN, GET_BIT(c,3));
	DIO_voidSetPinValue(GPIOA_BASE, LCD_EN_PIN, HIGH);
	_delay_ms(10);
	DIO_voidSetPinValue(GPIOA_BASE, LCD_EN_PIN, LOW);
	_delay_ms(50);

}
void LCD_WRITE_STRING(const uint8_t *c)
{
	while (*(c)!= NULL)
	{
		LCD_WRITE_CHAR(*c);
		c++;
	}
}

void Lcd_Void_LCDGoTo(uint8_t Copy_U8_Row, uint8_t Copy_U8_Col)
{
	uint8_t Local_U8_Arr [4] = {LCD_R0_COMMAND , LCD_R1_COMMAND , LCD_R2_COMMAND , LCD_R3_COMMAND};
	LCD_WRITE_COMMAND(Local_U8_Arr[Copy_U8_Row] + Copy_U8_Col);
}


void Lcd_Void_LCDClear()
{
	LCD_WRITE_COMMAND(LCD_CLEAR);
}
