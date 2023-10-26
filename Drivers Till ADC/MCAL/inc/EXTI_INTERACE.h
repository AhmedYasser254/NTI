/*
 * EXTI_INTERACE.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Ahmed Yasser
 */

#ifndef EXTI_INTERACE_H_
#define EXTI_INTERACE_H_

#include "MCU_HW.h"
typedef enum
{
	EXTI_NUM_0=6,
	EXTI_NUM_1=7,
	EXTI_NUM_2=5,
}EXTI_t;

typedef enum
{
	LOW_LEVEL_MODE=0,
	LOGICAL_CHANGE_MODE=1,
	FALLING_EDGE_MODE=2,
	RISING_EDGE_MODE=3
}Trigger_t;




typedef struct
{
	EXTI_t external_number;
	Trigger_t trigger_edge;
	void (* P_IRQ_CallBack)(void);
}EXTI_CONFIG_t;

void MCAL_EXTI_INIT(EXTI_CONFIG_t* EXTI_Config);

void MCAL_EXTI_GPIO_DeInit (EXTI_CONFIG_t* EXTI_Config);


#endif /* EXTI_INTERACE_H_ */
