/*
 * Timer_INTERFACE.c
 *
 *  Created on: Oct 26, 2023
 *      Author: Ahmed Yasser
 */

#include "Timer_INTERFACE.h"
#include "Timer_Private.h"
#include <avr/interrupt.h>
#include "stdlib.h"

/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/
static  void (* gTimer0_Call_BackPOINTER) (void) = NULL_PTR;
static  void (*g_Timer1CallBackPtr)(void) = NULL_PTR;

static volatile void (*g_callBackPtr)(void) = NULL_PTR;



/* Timer0 overflow*/
ISR(TIMER0_OVF_vect)
{
	CLR_BIT(SREG,I);
	SET_BIT(Timer0_BASE->TIFR_Reg.Reg,TOV0); /* Clear Flag W1C*/

	if (gTimer0_Call_BackPOINTER != NULL_PTR)
	{
		(*gTimer0_Call_BackPOINTER)();
	}
}

/* Timer0 Compare*/
ISR(TIMER0_COMP_vect)
{
	CLR_BIT(SREG,I);
	SET_BIT(Timer0_BASE->TIFR_Reg.Reg,OCF0); /* Clear Flag W1C*/
	if (gTimer0_Call_BackPOINTER != NULL_PTR)
	{
		(*gTimer0_Call_BackPOINTER)();
	}
}


/* Timer1 overflow*/
ISR(TIMER1_OVF_vect)
{
	CLR_BIT(SREG,I);
	SET_BIT(Timer0_BASE->TIFR_Reg.Reg,TOV1); /* enable overflow flag */

	if (g_Timer1CallBackPtr != NULL_PTR)
	{
		(*g_Timer1CallBackPtr)();
	}
}

/* Timer1 compare */
ISR(TIMER1_COMPA_vect)
{
	CLR_BIT(SREG,I);
	SET_BIT(Timer0_BASE->TIFR_Reg.Reg,OCF1A);
	if (g_Timer1CallBackPtr != NULL_PTR)
	{
		(*g_Timer1CallBackPtr)();
	}
}




ISR(TIMER1_CAPT_vect)
{
	if(g_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_callBackPtr)(); /* another method to call the function using pointer to function g_callBackPtr(); */
	}
}

void Timer_Init(Timer_Config *Config_ptr)
{

	if(Config_ptr->Timer_ID == Timer0)
	{
		/* Inserting Clock Sourc */
		Timer0_BASE->TCCR0_Reg.Reg |= Config_ptr->prescalar;

		switch(Config_ptr->mode)
		{
		case TIMER0_NORMAL:

			SET_BIT(Timer0_BASE->TCCR0_Reg.Reg,FOC0);
			//Timer0_BASE->TCCR0_Reg.Reg = 0;

			/* Inserting Clock Sourc */

			Timer0_BASE->TCNT0_Reg.Reg = Config_ptr -> reload_value;

			break;

		case TIMER0_CTC:
			SET_BIT(Timer0_BASE->TCCR0_Reg.Reg,FOC0);

			SET_BIT(Timer0_BASE->TCCR0_Reg.Reg,WGM01);


			Timer0_BASE->TCCR0_Reg.Reg |= ((Config_ptr->signal_output) )<< COM00;
			Timer0_BASE->OCR0_Reg.Reg = Config_ptr->compare_value;
			break;

		case TIMER0_PWM_PHASE_CORRECT:
			SET_BIT(Timer0_BASE->TCCR0_Reg.Reg,WGM00);
			CLR_BIT(Timer0_BASE->TCCR0_Reg.Reg,WGM01);
			/* Inserting Clock Sourc */
			Timer0_BASE->TCCR0_Reg.Reg |= ((Config_ptr->signal_output) )<< COM00;

			if(Config_ptr->signal_output == Clear_OCx)
			{
				Timer0_BASE->TCCR0_Reg.Reg |= (1 << COM01);
			}
			else if(Config_ptr->signal_output == Set_OCx)
			{
				Timer0_BASE->TCCR0_Reg.Reg |= (1 << COM01) | (1<<COM00);

			}
			break;




		case TIMER0_FAST_PWM:

			SET_BIT(Timer0_BASE->TCCR0_Reg.Reg,WGM01);
			SET_BIT(Timer0_BASE->TCCR0_Reg.Reg,WGM00);


			Timer0_BASE->TCCR0_Reg.Reg |= ((Config_ptr->signal_output) )<< COM00;
			if(Config_ptr->signal_output == Non_inverting)
			{
				Timer0_BASE->TCCR0_Reg.Reg |= (1 << COM01);

			}
			else if(Config_ptr->signal_output == Inverting)
			{
				Timer0_BASE->TCCR0_Reg.Reg |= (1 << COM01) | (1<<COM00);

			}

			break;

		}
	}
	else if (Config_ptr -> Timer_ID == Timer1)
	{
		Timer1_BASE->TCCR1A_t.Reg = 0;
		Timer1_BASE->TCCR1B_t.Reg |= Config_ptr->prescalar;

		switch (Config_ptr->mode)
		{

		case TIMER1_NORMAL:
			Timer1_BASE->TCNT1_t = Config_ptr->reload_value;
			CLR_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM10);
			CLR_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM11);
			CLR_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM12);
			CLR_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM13);
			break;

		case TIMER1_PWM_PHASE_CORRECT_8BIT:
			SET_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM10);
			CLR_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM11);
			CLR_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM12);
			CLR_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM13);
			break;

		case TIMER1_PWM_PHASE_CORRECT_9BIT:
			CLR_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM10);
			SET_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM11);
			CLR_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM12);
			CLR_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM13);
			break;

		case TIMER1_PWM_PHASE_CORRECT_10BIT:
			SET_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM10);
			SET_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM11);
			CLR_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM12);
			CLR_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM13);
			break;

		case TIMER1_CTC_OCR:
			Timer1_BASE->OCR1A_t = Config_ptr->compare_value;
			CLR_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM10);
			CLR_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM11);
			SET_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM12);
			CLR_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM13);
			break;

		case TIMER1_FAST_PWM_8BIT:
			SET_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM10);
			CLR_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM11);
			SET_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM12);
			CLR_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM13);
			break;

		case TIMER1_FAST_PWM_9BIT:
			CLR_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM10);
			SET_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM11);
			SET_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM12);
			CLR_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM13);
			break;

		case TIMER1_FAST_PWM_10BIT:
			SET_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM10);
			SET_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM11);
			SET_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM12);
			CLR_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM13);
			break;

		case TIMER1_PWM_PHASE_FREQUENCY_CORRECT_ICR:
			CLR_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM10);
			CLR_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM11);
			CLR_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM12);
			SET_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM13);
			break;

		case TIMER1_PWM_PHASE_FREQUENCY_CORRECT_OCR:
			SET_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM10);
			CLR_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM11);
			CLR_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM12);
			SET_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM13);
			break;

		case TIMER1_PWM_PHASE_CORRECT_ICR:
			CLR_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM10);
			SET_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM11);
			CLR_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM12);
			SET_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM13);
			break;

		case TIMER1_PWM_PHASE_CORRECT_OCR:
			SET_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM10);
			SET_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM11);
			CLR_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM12);
			SET_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM13);
			break;

		case TIMER1_CTC_ICR:
			CLR_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM10);
			CLR_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM11);
			SET_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM12);
			SET_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM13);
			break;

		case TIMER1_FAST_PWM_ICR:
			CLR_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM10);
			SET_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM11);
			SET_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM12);
			SET_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM13);
			break;

		case TIMER1_FAST_PWM_OCR:
			SET_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM10);
			SET_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM11);
			SET_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM12);
			SET_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM13);
			break;

		default:
			break;
		}
		if(Config_ptr->Channels == ChannelB)
		{
			Timer1_BASE->TCCR1B_t.Reg = ((Timer1_BASE->TCCR1B_t.Reg & 0x3F) | (Config_ptr->signal_output) << COM1A0);
		}
		else
		{
			Timer1_BASE->TCCR1A_t.Reg = ((Timer1_BASE->TCCR1A_t.Reg & 0xCF) | (Config_ptr->signal_output) << COM1B0);
		}

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





void EnableInt(	Timer_Config *Config_ptr,void(*fnptr)(void))
{

	if(Config_ptr->Timer_ID == Timer0)
	{
		switch(Config_ptr->mode)
		{
		case TIMER0_NORMAL:

			SET_BIT(Timer0_BASE->TIMSK_Reg.Reg,TOIE0); /* enable interrupts for overflow mode */
			SET_BIT(Timer0_BASE->TIFR_Reg.Reg,TOV0); /* enable overflow flag */
			SET_BIT(SREG,I);
			Timer0_setCallBack(fnptr);
			break;

		case TIMER0_CTC:


			SET_BIT(Timer0_BASE->TIMSK_Reg.Reg,OCIE0); /* enable interrupts for overflow mode */
			SET_BIT(Timer0_BASE->TIFR_Reg.Reg,OCF0); /* enable overflow flag */
			SET_BIT(SREG,I);
			Timer0_setCallBack(fnptr);
			break;



		}
	}

	else if (Config_ptr->Timer_ID == Timer1)
	{
		switch(Config_ptr->mode)
		{
		case TIMER1_NORMAL:

			SET_BIT(Timer0_BASE->TIMSK_Reg.Reg,TOIE1); /* enable interrupts for overflow mode */
			SET_BIT(Timer0_BASE->TIFR_Reg.Reg,TOV1); /* enable overflow flag */
			SET_BIT(SREG,I);
			Timer1_setCallBack(fnptr);
			break;

		case TIMER1_CTC_OCR:


			SET_BIT(Timer0_BASE->TIMSK_Reg.Reg,OCIE1A); /* enable interrupts for overflow mode */
			SET_BIT(Timer0_BASE->TIFR_Reg.Reg,OCF1A); /* enable overflow flag */
			SET_BIT(SREG,I);
			Timer1_setCallBack(fnptr);
			break;



		}
	}
}

void DisableInt(Timer_Config *Config_ptr,void(*fnptr)(void))
{

	CLR_BIT(SREG,I);
}

void setFastPWM(uint8 duty,Compare_Output_Mode_t SignalOutput)
{


	if(SignalOutput == Non_inverting)
	{
		Timer0_BASE->OCR0_Reg.Reg  = abs (((duty*255)/100)-1);
	}
	else if(SignalOutput== Inverting)
	{
		Timer0_BASE->OCR0_Reg.Reg  = abs(255-((duty*256)/100));

	}



}


void setphaseCorrectPWM(uint8 duty)
{


	Timer0_BASE->OCR0_Reg.Reg  = (duty*255)/100;

}


void Timer_setDelayTimeMilliSec(uint16 milliseconds,Timer_Config *Config_ptr)
{
	// Calculate the number of timer counts required for the delay
	uint16 counts = (uint16)((milliseconds * 1000) / Config_ptr->prescalar);

	// Set the compare value
	Timer0_BASE->OCR0_Reg.Reg = counts - 1;

	// Clear the timer counter
	Timer0_BASE->TCNT0_Reg.Reg  = 0;

	// Wait until the compare match flag is set
	while (!(Timer0_BASE->TIFR_Reg.Reg & (1 << OCF0)));

	// Clear the compare match flag by writing a 1 to it
	Timer0_BASE->TIFR_Reg.Reg |= (1 << OCF0);
}


void Icu_init(const Icu_ConfigType * Config_Ptr)
{

	/*
	 * insert the required edge type in ICES1 bit in TCCR1B Register
	 */
	TCCR1B = (TCCR1B & 0xBF) | ((Config_Ptr->edge)<<ICES1);
	/* Initial Value for Timer1 */
	Timer1_BASE->TCNT1_t = 0;

	/* Initial Value for the input capture register */
	Timer1_BASE->ICR1_t = 0;

	/* Enable the Input Capture interrupt to generate an interrupt when edge is detected on ICP1/PD6 pin */
	Timer0_BASE->TIMSK_Reg.Reg |= (1<<TICIE1);

}


uint16 Icu_getInputCaptureValue(void)
{
	return Timer1_BASE->ICR1_t;
}

void Timer1_setCallBack(void(*a_ptr)(void))
{
	g_Timer1CallBackPtr = a_ptr;
}

void Timer0_setCallBack(void(*a_ptr)(void))
{
	gTimer0_Call_BackPOINTER = a_ptr;
}

void Icu_setCallBack(void(*a_ptr)(void))
{
	/* Save the address of the Call back function in a global variable */
	g_callBackPtr = a_ptr;
}
