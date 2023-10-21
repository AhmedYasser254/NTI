/*
 * App.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Ahmed Yasser
 */



#include "sev_seg.h"
#include <util/delay.h>



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
