/*
 * LED_INTERFACING.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Ahmed Yasser
 */

#ifndef INC_LED_INTERFACING_H_
#define INC_LED_INTERFACING_H_

#include "Dio.h"

typedef enum
{
	ACTIVE_LOW,
	ACTIVE_HIGH
}LED_Status_t;



void TURN_ON_LED(Port_Def* GPIOx  ,LED_Status_t state,Pin_ID_t pin );
void TURN_OFF_LED(Pin_ID_t pin ,LED_Status_t state,Port_Def* GPIOx  );
#endif /* INC_LED_INTERFACING_H_ */
