/******************************************************************************
 *
 * Module: Application
 *
 * File Name: APP.c
 *
 * Description: Source file
 *
 * Author: Ahmed Yasser
 *
 *******************************************************************************/

#include <Dio_INTERFACE.h>
#include <Seven_Segment_INTERFACE.h>
#include "Lcd.h"
#include "Keypad.h"
#include "EXTI_INTERACE.h"

#include "BIT_MATH.h"
#include "LED_INTERFACING.h"
#include <util/delay.h>
#include "Button.h"
#include "ADC_INTERFACE.h"
#include "Timer_INTERFACE.h"

static uint8 flag = 0;
unsigned char seconds=0,minutes=0; // Variables For counting Time
void timer_callBack(void)
{
	flag ++;
	if (flag == 1)
	{
		DIO_voidSetPinValue(GPIOC_BASE, PIN6_ID, HIGH);
		_delay_ms(3000);
		flag =0;
	}
}

void timer1_int()
{
	Timer_Config time;
	time.Timer_ID = Timer1;
	time.mode = TIMER1_NORMAL;
	time.reload_value = 0;
	time.prescalar = F_CPU_1024_;
	Timer_Init(&time);
	EnableInt(&time, timer_callBack);
}

int main(void)
{
	DIO_voidSetPinDirection(GPIOC_BASE, PIN6_ID, 1);
	timer1_int();
	KEYPAD_INIT();
	H_LCD_void_IniT();
	Segment_init(FIRST_SEG);

	while(1)
	{
		DIO_voidSetPinValue(GPIOC_BASE, PIN6_ID, LOW);
	}
}

