/*
 * Timer_INTERFACE.h
 *
 *  Created on: Oct 26, 2023
 *      Author: Ahmed Yasser
 */

#ifndef INC_TIMER_INTERFACE_H_
#define INC_TIMER_INTERFACE_H_


#include "MCU_HW.h"
typedef enum
{
	NORMAL,
	PWM,
	CTC,
	FAST_PWM
}Timer0_Mode_t;

typedef enum
{
    NO_CLK_, F_CPU_1_, F_CPU_8_, F_CPU_64_, F_CPU_256_, F_CPU_1024_
}TIMER_CLK_SELECT;


typedef enum
{
	Normal__,
	non_inverting = 2,
	inverting
}FAST_PWM_MODE;


typedef enum
{
	Normal_,
	toggle_oc0,
	clear_oc0,
	set_oc0
}CTC_non_PWM;


typedef enum
{
	normal,
	clear_oc,
	set_oc
}Phase;


typedef struct
{
	FAST_PWM_MODE fast_pwm;
	CTC_non_PWM ctc;
	Phase phase_correct;

}Generated_Output;

typedef struct
{
	Timer0_Mode_t mode;
	TIMER_CLK_SELECT prescalar;
	Generated_Output signal_output;
	uint16 reload_value;
	uint8 compare_value;

}Timer_Config;



/* Function ProtoType */
void Timer_Init(Timer_Config *Config_ptr);

void Timer_start(Timer_Config *Config_ptr);
void Timer_stop();
void EnableInt(	Timer_Config *Config_ptr,void(*fnptr)(void));
void setFastPWM(duty);

void setphaseCorrectPWM(frequency , duty);
#endif /* INC_TIMER_INTERFACE_H_ */
