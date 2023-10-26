/*
 * LM35_INTERFACE.h
 *
 *  Created on: Oct 26, 2023
 *      Author: Ahmed Yasser
 */

#ifndef INC_LM35_INTERFACE_H_
#define INC_LM35_INTERFACE_H_

#include "Dio_INTERFACE.h"
#include "Config.h"
#include "ADC_INTERFACE.h"
#include "std_types.h"

#define LM35_PORT			GPIOA_BASE
#define LM35_PIN			PIN7_ID


uint16 LM35_read_temperature();
#endif /* INC_LM35_INTERFACE_H_ */
