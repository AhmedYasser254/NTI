/*
 * MCU_HW.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Ahmed Yasser
 */

#ifndef MCU_HW_H_
#define MCU_HW_H_

#include "std_types.h"

#include "BIT_MATH.h"

//***********************************************************************************************
//********************************DEFINING  GICR REG FOR INT0,INT1,INT2 PREPHERAL ENABLE ******************************************
//***********************************************************************************************
#define		SREG					(*((volatile uint8 * ) (0x5F)))
#define		 I						7		// I BIT IN SREG FOR GENERAL INTERRUPT ENABLE


#define		SFIOR					(*((volatile uint8 * ) (0x50)))




typedef union
{
	uint8 Reg;
	struct
	{
		uint8 B0:1;
		uint8 B1:1;
		uint8 B2:1;
		uint8 B3:1;
		uint8 B4:1;
		uint8 B5:1;
		uint8 B6:1;
		uint8 B7:1;
	}Bitfield;
}Reg_Def;


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: GPIO
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	Reg_Def Pin;
	Reg_Def DDR;
	Reg_Def PORT;
}Port_Def;


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: GPIO
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	Reg_Def MCUCSR_Reg;
	Reg_Def MCUCR_Reg;
	Reg_Def RESERVED_Reg[5];
	Reg_Def GICR_Reg;
}EXTI_REG_t;



//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: ADC
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	uint16 ADCL_Reg;
	Reg_Def ADCSRA_Reg;
	Reg_Def ADMUX_Reg;
}ADC_REG_t;






//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: Timer0
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	Reg_Def TCNT0_Reg;
	Reg_Def TCCR0_Reg;
	Reg_Def RESERVED1_Reg[2];
	Reg_Def TWCR_Reg;
	Reg_Def RESERVED2_Reg[1];
	Reg_Def TIFR_Reg;
	Reg_Def TIMSK_Reg;
	Reg_Def RESERVED3_Reg[2];
	Reg_Def OCR0_Reg;

}Timer0_REG_t;


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: Timer1
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	uint16 ICR1_t;
	Reg_Def OCR1BL_t;
	Reg_Def OCR1BH_t;
	uint16 OCR1A_t;
	uint16 TCNT1_t;
	Reg_Def TCCR1B_t;
	Reg_Def TCCR1A_t;

}Timer1_REG_t;





//-*-*-*-*-*-*-*-*-*-*-*-
//GPIO Instants:
//-*-*-*-*-*-*-*-*-*-*-*
#define GPIOA_BASE 			(( Port_Def*) 0x39)
#define GPIOB_BASE			(( Port_Def*) 0x36)
#define GPIOC_BASE 			(( Port_Def*) 0x33)
#define GPIOD_BASE			(( Port_Def*) 0x30)



//-*-*-*-*-*-*-*-*-*-*-*-
//EXTI Instants:
//-*-*-*-*-*-*-*-*-*-*-*
#define EXTI_BASE 			(( EXTI_REG_t*) 0x54)


//-*-*-*-*-*-*-*-*-*-*-*-
//ADC Instants:
//-*-*-*-*-*-*-*-*-*-*-*
#define ADC_BASE 			(( ADC_REG_t*) 0x24)




//-*-*-*-*-*-*-*-*-*-*-*-
//Timer0 Instants:
//-*-*-*-*-*-*-*-*-*-*-*
#define Timer0_BASE 			(( Timer0_REG_t*) 0x52)

//-*-*-*-*-*-*-*-*-*-*-*-
//Timer0 Instants:
//-*-*-*-*-*-*-*-*-*-*-*
#define Timer1_BASE 			(( Timer1_REG_t*) 0x46)


#endif /* MCU_HW_H_ */
