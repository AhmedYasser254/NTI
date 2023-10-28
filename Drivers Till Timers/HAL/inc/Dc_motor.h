/*
 * Dc_motor.h
 *
 *  Created on: Oct 28, 2023
 *      Author: Ahmed Yasser
 */

#ifndef INC_DC_MOTOR_H_
#define INC_DC_MOTOR_H_
#include "Dio_INTERFACE.h"
#include "MCU_HW.h"
#include "Config.h"


/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/

typedef enum {
	Stop,CW,CCW
}DcMotor_State;

#define DC_MOTOR_PORT_ID   GPIOB_BASE
#define DC_MOTOR_PIN		  PIN7_ID



void DcMotor_Init(void);
void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif /* INC_DC_MOTOR_H_ */
