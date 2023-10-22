
#include "SWITCH_INTERFACING.h"

uint8 switch_read (uint8 pin , uint8 * val,Port_Def* ptr)
{
	uint8 error = 0;
	uint8 u = * val ;
	//error = DIO_voidGetPinValue(ptr, (uint8*)val);

	//_delay_ms(50);
	if (*val == u)
	error =0;
	else 
	error= 1;
	return error ;
}
