/*
 * App.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Ahmed Yasser
 */



#include "sev_seg.h"
#include <util/delay.h>
//DIOReg_Typedef* GPIOA = ((DIOReg_Typedef*)0x39);
//DIOReg_Typedef* GPIOB  = ((DIOReg_Typedef*)0x16);
//

//int main(void)
//{
//	GPIO_PinCOnffig PinCfg;
//		PinCfg.dir = PIN_OUTPUT;
//		PinCfg.pin = PIN_5;
//	//	DIO_voidSetPinDirection(GPIOA,&PinCfg);
//DIO_voidSetPortDirection(GPIOA, &PinCfg);
//	while(1)
//	{
//		//DIO_setPinValue(GPIOA, &PinCfg, LOGIC_HIGH);
//		DIO_voidSetPortValue(GPIOA, LOGIC_HIGH);
//	}
//return 0;
//}


int main(void)
{
	Segment_init();

	while(1)
	{
		for(int i=0; i<=9; i++)
		{
			 SevenSeg_Num(i);
					 _delay_ms(1000);
		}
	}
return 0;
}
