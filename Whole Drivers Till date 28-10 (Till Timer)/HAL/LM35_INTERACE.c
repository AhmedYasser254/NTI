/*
 * LM35_INTERACE.c
 *
 *  Created on: Oct 26, 2023
 *      Author: Ahmed Yasser
 */

#include "LM35_INTERFACE.h"

uint16 LM35_read_temperature() {

    // Read the ADC result.
	uint16 raw_adc = ADC_getDigitalValueSynchNonBlocking(ADC2);

    // Calculate temperature in Celsius.
    // LM35 has a sensitivity of 10 mV per degree Celsius.
    float temperature = (raw_adc * 100.0) / 10.0;

    return (uint16)temperature;
}
