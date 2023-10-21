/*
 * sev_seg.h
 *
 *  Created on: Oct 21, 2023
 *      Author: Ahmed Yasser
 */

#ifndef SEV_SEG_H_
#define SEV_SEG_H_


#include "dio.h"
void Segment_init(void);
void SevenSeg_Num(uint8 num);


extern Port_Def* PORTA ;
extern Port_Def* PORTB ;
extern Port_Def* PORTC ;
extern Port_Def* PORTD ;


#endif /* SEV_SEG_H_ */
