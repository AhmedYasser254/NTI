

#ifndef SWITCH_INTERFACING_H_
#define SWITCH_INTERFACING_H_


#include "Dio.h"

extern Port_Def* PORTA ;
extern Port_Def* PORTB ;
extern Port_Def* PORTC ;
extern Port_Def* PORTD ;


uint8 switch_read (uint8 pin , uint8 * val,Port_Def* ptr);




#endif /* SWITCH_INTERFACING_H_ */
