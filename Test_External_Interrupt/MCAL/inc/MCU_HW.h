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
//GPIO Instants:
//-*-*-*-*-*-*-*-*-*-*-*
#define GPIOA_BASE 			(( Port_Def*) 0x39)
#define GPIOB_BASE			(( Port_Def*) 0x36)
#define GPIOC_BASE 			(( Port_Def*) 0x33)
#define GPIOD_BASE			(( Port_Def*) 0x39)



//-*-*-*-*-*-*-*-*-*-*-*-
//EXTI Instants:
//-*-*-*-*-*-*-*-*-*-*-*
#define EXTI_BASE 			(( EXTI_REG_t*) 0x54)




#endif /* MCU_HW_H_ */
