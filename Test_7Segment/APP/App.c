/******************************************************************************
 *
 * Module: Application
 *
 * File Name: APP.c
 *
 * Description: Source file for Test 7 segment Module driver
 *
 * Author: Ahmed Yasser
 *
 *******************************************************************************/

#include "Dio.h"
#include "sev_seg.h"
#include<util/delay.h>

int main(void)
{
	/*
	 * Initilaztion of the segment
	 */
	Segment_init();
	while(1)
	{
		for(int i=0; i<9; i++)
		{
			SevenSeg_Num(i);
			_delay_ms(1000);
		}
	}
	return 0;
}
