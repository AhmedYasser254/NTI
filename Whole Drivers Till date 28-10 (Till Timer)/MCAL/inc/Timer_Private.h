/*
 * Timer_Private.h
 *
 *  Created on: Oct 26, 2023
 *      Author: Ahmed Yasser
 */

#ifndef INC_TIMER_PRIVATE_H_
#define INC_TIMER_PRIVATE_H_



///////////////////////////////////////////////////////////////////////////////
///////////////////////////// DEFINING TCCR0 Reg Bits//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#define				CS00				0
#define				CS01				1
#define				CS02				2
#define				WGM01				3
#define				COM00				4
#define				COM01				5
#define				WGM00				6
#define				FOC0				7





///////////////////////////////////////////////////////////////////////////////
///////////////////////////// DEFINING TIMSK Reg Bits//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#define				TOIE0				0
#define				OCIE0				1






///////////////////////////////////////////////////////////////////////////////
///////////////////////////// DEFINING TIFR Reg Bits//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#define				TOV0				0
#define				OCF0				1



/* TCCR1A */
#define COM1A1  7
#define COM1A0  6
#define COM1B1  5
#define COM1B0  4
#define FOC1A   3
#define FOC1B   2
#define WGM11   1
#define WGM10   0

/* TCCR1B */
#define ICNC1   7
#define ICES1   6
/* bit 5 reserved */
#define WGM13   4
#define WGM12   3
#define CS12    2
#define CS11    1
#define CS10    0

#endif /* INC_TIMER_PRIVATE_H_ */