/*
 * Keypad.h
 *
 *  Created on: Oct 21, 2023
 *      Author: Ahmed Yasser
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_
#include <Dio_INTERFACE.h>

#include "Config.h"

void KEYPAD_INIT();
uint8_t KEYPAD_Get_Pressed_Key(void);


#endif /* KEYPAD_H_ */
