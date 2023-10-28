/*
 * Dc_motor.c
 *
 *  Created on: Oct 28, 2023
 *      Author: Ahmed Yasser
 */

#include "Dc_motor.h"
#include "Timer_INTERFACE.h"
/*******************************************************************************
 *                         Function Definitions                                *
 *******************************************************************************/

void DcMotor_Init(void)
{
	DIO_voidSetPinDirection(DC_MOTOR_PORT_ID ,DC_MOTOR_PIN,1);

}
void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	uint8 duty = ((float)speed/100)*255;

//	switch(state)
//	{
//	case Stop:
//		// Stop the motor
//		GPIO_writePin(DC_MOTOR_PORT_ID,DC_MOTOR_PIN_IN1,LOGIC_LOW);
//		GPIO_writePin(DC_MOTOR_PORT_ID,DC_MOTOR_PIN_IN2,LOGIC_LOW);
//		break;
//	case CW:
//		// Rotate the motor --> clock wise
//		GPIO_writePin(DC_MOTOR_PORT_ID,DC_MOTOR_PIN_IN1,LOGIC_HIGH);
//		GPIO_writePin(DC_MOTOR_PORT_ID,DC_MOTOR_PIN_IN2,LOGIC_LOW);
//		break;
//	case CCW:
//		// Rotate the motor --> anti-clock wise
//		GPIO_writePin(DC_MOTOR_PORT_ID,DC_MOTOR_PIN_IN1,LOGIC_LOW);
//		GPIO_writePin(DC_MOTOR_PORT_ID,DC_MOTOR_PIN_IN2,LOGIC_HIGH);
//		break;
//
//
//
//	}

}
