/*
 * LED_INTERFACING.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Ahmed Yasser
 */

#ifndef INC_LED_INTERFACING_H_
#define INC_LED_INTERFACING_H_

/*-----------------------------------------INCLUDES-----------------------------------------------------*/

#include <Dio_INTERFACE.h>




/*-------------------------------------------ENUMS-----------------------------------------------------*/

typedef enum
{
	ACTIVE_LOW,
	ACTIVE_HIGH
}LED_Status_t;




/*-------------------------------------------Functions Declaration-----------------------------------*/
void TURN_ON_OFF_LED(Port_Def* GPIOx ,LED_Status_t state,Pin_ID_t pin );

#endif /* INC_LED_INTERFACING_H_ */
