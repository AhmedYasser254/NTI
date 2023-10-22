/******************************************************************************
 *
 * Module: Application
 *
 * File Name: APP.c
 *
 * Description: Source file for Test 7 segment Module driver
 *
 * Author: Ahmed Yasser
 *
 *******************************************************************************/

#include "Dio.h"
#include "sev_seg.h"

#include "Lcd.h"
#include "Keypad.h"
#include "EXTI_INTERACE.h"

#include "BIT_MATH.h"
#include "LED_INTERFACING.h"

/*
 * Call Back Function For Toggle the choosing led which is yellow led
 */
void EXT1_Call_Back(void)
{
	TOGGLE_BIT(GPIOA_BASE->PORT.Reg,PIN6_ID);
}

void YELLOW_LED_Init(void)
{
	TURN_OFF_LED(PIN6_ID, HIGH, GPIOA_BASE);

}



void EXTI1_INIT(void)
{

	EXTI_CONFIG_t* EXTI_conf;
	EXTI_conf->P_IRQ_CallBack = EXT1_Call_Back;
	EXTI_conf->external_number = EXTI_NUM_1;
	EXTI_conf->trigger_edge = FALLING_EDGE_MODE;

}

void INIT_DRIVERS(void)
{
	LCD_INT();
	KEYPAD_INIT();
	YELLOW_LED_Init();
	EXTI1_INIT();
	Segment_init();

}

int main(void)
{


	INIT_DRIVERS();


	while(1)
	{




	}
	return 0;
}
