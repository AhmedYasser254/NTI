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


/*
 * Call Back Function For Toggle the choosing led which is yellow led
 */
//volatile static uint8_t value = 0;
void ahmed(void)
{
	TURN_ON_OFF_LED(GPIOA_BASE, ACTIVE_HIGH, 6);
	_delay_ms(2000);
	TURN_ON_OFF_LED(GPIOA_BASE, ACTIVE_LOW, 6);
	_delay_ms(2000);

}



//void ADC_CALL_BACK(void)
//{
//
//	value = ADC_BASE->ADCL_Reg.Reg;
//}
void YELLOW_LED_Init(void)
{
	TURN_ON_OFF_LED(GPIOA_BASE, ACTIVE_HIGH, 6);



}


void EXTI1_INIT(void)
{

	EXTI_CONFIG_t EXTI_conf ;
	EXTI_conf.external_number = EXTI_NUM_1;
	EXTI_conf.P_IRQ_CallBack = ahmed;
	EXTI_conf.trigger_edge = LOGICAL_CHANGE_MODE;
	MCAL_EXTI_INIT(&EXTI_conf);
}
void ADC_INIT_POT(void)
{
	ADC_Config_t Adc_PinConf;


	Adc_PinConf.AutoTrigger = Disable_AutoTrigger;
	Adc_PinConf.prescaler= F_CPU_128;
	Adc_PinConf.ref_volt = Internal;
	ADC_init(&Adc_PinConf);

}

void INIT_DRIVERS(void)
{
	H_LCD_void_IniT();
	KEYPAD_INIT();
	//YELLOW_LED_Init();
	EXTI1_INIT();
	//Segment_init(0);

	ADC_INIT_POT();
}








int main(void)
{
	INIT_DRIVERS();
	H_LCD_void_sendString("Pot Value: ");

	uint16 key = 0;

	while(1)
	{
		 ADC_getDigitalValueAsynchCallBack( 1,ahmed);

//		key = ADC_getDigitalValueSynchNonBlocking(1);
//		H_LCD_void_gotoXY(0, 15);
//		H_LCD_int_to_string(key);

	}

}

