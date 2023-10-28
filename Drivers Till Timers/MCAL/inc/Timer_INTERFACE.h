/*
 * Timer_INTERFACE.h
 *
 *  Created on: Oct 26, 2023
 *      Author: Ahmed Yasser
 */

#ifndef INC_TIMER_INTERFACE_H_
#define INC_TIMER_INTERFACE_H_


#include "MCU_HW.h"

typedef enum{
    TIMER0_NORMAL = 0,
    TIMER0_PWM_PHASE_CORRECT = 1,
    TIMER0_CTC = 2,
    TIMER0_FAST_PWM = 3,
    TIMER1_NORMAL = 0,
    TIMER1_PWM_PHASE_CORRECT_8BIT = 1,
    TIMER1_PWM_PHASE_CORRECT_9BIT = 2,
    TIMER1_PWM_PHASE_CORRECT_10BIT = 3,
    TIMER1_CTC_OCR = 4,
    TIMER1_FAST_PWM_8BIT = 5,
    TIMER1_FAST_PWM_9BIT = 6,
    TIMER1_FAST_PWM_10BIT = 7,
    TIMER1_PWM_PHASE_FREQUENCY_CORRECT_ICR = 8,
    TIMER1_PWM_PHASE_FREQUENCY_CORRECT_OCR = 9,
    TIMER1_PWM_PHASE_CORRECT_ICR = 10,
    TIMER1_PWM_PHASE_CORRECT_OCR = 11,
    TIMER1_CTC_ICR = 12,
    TIMER1_FAST_PWM_ICR = 14,
    TIMER1_FAST_PWM_OCR = 15
}Timer_ModeType;







typedef enum
{
    NO_CLK_, F_CPU_1_, F_CPU_8_, F_CPU_64_, F_CPU_256_, F_CPU_1024_
}TIMER_CLK_SELECT;






typedef enum{
	Timer0, Timer1, Timer2
}TIMER_ID;


typedef enum
{
	Normal_OC_Disconnected,
	Toggle_OCx,
	Clear_OCx,
	Non_inverting=2,
	Set_OCx,
	Inverting=3,

}Compare_Output_Mode_t;
typedef enum
{
	ChannelA,ChannelB
}Channel;

typedef enum
{
	FALLING,RISING
}Icu_EdgeType;

typedef struct
{
	Icu_EdgeType edge;
}Icu_ConfigType;

typedef struct
{
	Timer_ModeType mode;
	TIMER_CLK_SELECT prescalar;
	Compare_Output_Mode_t signal_output;
	uint16 reload_value;
	uint16 compare_value;
	TIMER_ID Timer_ID;
	Channel Channels;

}Timer_Config;






/* Function ProtoType */
void Timer_Init(Timer_Config *Config_ptr);
void Icu_init(const Icu_ConfigType * Config_Ptr);

void Timer_start(Timer_Config *Config_ptr);
void Timer_stop();
void EnableInt(	Timer_Config *Config_ptr,void(*fnptr)(void));
void setFastPWM(uint8 duty,Compare_Output_Mode_t SignalOutput);

void setphaseCorrectPWM(uint8 duty);
void Timer1_setCallBack(void(*a_ptr)(void));
void Timer0_setCallBack(void(*a_ptr)(void));

void Timer_setDelayTimeMilliSec(uint16 milliseconds,Timer_Config *Config_ptr);

#endif /* INC_TIMER_INTERFACE_H_ */
