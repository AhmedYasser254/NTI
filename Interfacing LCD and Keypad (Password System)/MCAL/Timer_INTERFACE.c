/*
 * Timer_INTERFACE.c
 *
 *  Created on: Oct 26, 2023
 *      Author: Ahmed Yasser
 */

#include "Timer_INTERFACE.h"
#include "Timer_Private.h"
#include <avr/interrupt.h>

void (* gTimer0_Call_BackPOINTER) (void) ;

ISR(TIMER0_OVF_vect)
{
	CLR_BIT(SREG,I);
	gTimer0_Call_BackPOINTER();
}



void Timer_Init(Timer_Config *Config_ptr)
{
	switch(Config_ptr->mode)
	{
	case NORMAL:

		SET_BIT(Timer0_BASE->TCCR0_Reg.Reg,FOC0);
		//Timer0_BASE->TCCR0_Reg.Reg = 0;

		/* Inserting Clock Sourc */
		Timer0_BASE->TCCR0_Reg.Reg |= Config_ptr->prescalar;

		Timer0_BASE->TCNT0_Reg.Reg =Config_ptr -> reload_value;

		break;

	case CTC:
		SET_BIT(Timer0_BASE->TCCR0_Reg.Reg,FOC0);

		SET_BIT(Timer0_BASE->TCCR0_Reg.Reg,WGM01);
		/* Inserting Clock Sourc */
		Timer0_BASE->TCCR0_Reg.Reg |= Config_ptr->prescalar;

		Timer0_BASE->TCCR0_Reg.Reg |= ((Config_ptr->signal_output.ctc) )<< COM00;
		Timer0_BASE->OCR0_Reg.Reg = Config_ptr->compare_value;
		break;

	case PWM:
		SET_BIT(Timer0_BASE->TCCR0_Reg.Reg,WGM00);

		/* Inserting Clock Sourc */
		Timer0_BASE->TCCR0_Reg.Reg |= Config_ptr->prescalar;

		Timer0_BASE->TCCR0_Reg.Reg |= ((Config_ptr->signal_output.phase_correct) )<< COM00;
		break;




	case FAST_PWM:

		SET_BIT(Timer0_BASE->TCCR0_Reg.Reg,WGM01);
		SET_BIT(Timer0_BASE->TCCR0_Reg.Reg,WGM00);

		/* Inserting Clock Sourc */
		Timer0_BASE->TCCR0_Reg.Reg |= Config_ptr->prescalar;

		Timer0_BASE->TCCR0_Reg.Reg |= ((Config_ptr->signal_output.fast_pwm) )<< COM00;
		break;

	}

}


void Timer_start(Timer_Config *Config_ptr)
{
	Timer0_BASE->TCCR0_Reg.Reg |= Config_ptr->prescalar;

}


void Timer_stop()
{
	Timer0_BASE->TCCR0_Reg.Reg &= 0xF8;

}


void setCallBack(void(*a_ptr)(void))
{
	gTimer0_Call_BackPOINTER = a_ptr;
}


void EnableInt(	Timer_Config *Config_ptr,void(*fnptr)(void))
{
	switch(Config_ptr->mode)
	{
	case NORMAL:

		SET_BIT(Timer0_BASE->TIMSK_Reg.Reg,TOIE0); /* enable interrupts for overflow mode */
		//SET_BIT(Timer0_BASE->TIFR_Reg.Reg,TOV0); /* enable overflow flag */
		SET_BIT(SREG,I);
		setCallBack(fnptr);
	break;

	case CTC:


		SET_BIT(Timer0_BASE->TIMSK_Reg.Reg,OCIE0); /* enable interrupts for overflow mode */
	//	SET_BIT(Timer0_BASE->TIFR_Reg.Reg,OCF0); /* enable overflow flag */
		SET_BIT(SREG,I);
		setCallBack(fnptr);
	break;



	}

}

void DisableInt(Timer_Config *Config_ptr,void(*fnptr)(void))
{


}

void setFastPWM(duty)
{


	Timer0_BASE->OCR0_Reg.Reg  = duty;


}


void setphaseCorrectPWM(frequency , duty)
{

}



