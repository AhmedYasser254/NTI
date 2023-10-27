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

#include <Dio_INTERFACE.h>
#include <Seven_Segment_INTERFACE.h>
#include "Lcd.h"
#include "Keypad.h"
#include "EXTI_INTERACE.h"

#include "BIT_MATH.h"
#include "LED_INTERFACING.h"
#include <util/delay.h>
#include "Button.h"
#include "ADC_INTERFACE.h"
#include "Timer_INTERFACE.h"



#define DATABASE_SIZE 2



// Define the database of users
const char* usernames[DATABASE_SIZE] = {"Ahmed Ali", "Sara Omar"};
const uint16_t userIDs[DATABASE_SIZE] = {1234, 5678};
const uint16_t passwords[DATABASE_SIZE] = {5060, 1020};

uint8 g_inputID  [4];
uint8 g_inputPass  [4];


void getID(uint8 * arrayName)
{
	H_LCD_void_gotoXY(1, 0);
	uint8 i = 0;
	uint8 key;

	while(i != 4)
	{
		key = KEYPAD_Get_Pressed_Key();
		if (key >= 0 && key <= 9)
		{
			H_LCD_int_to_string(key);
			*(arrayName + i) = key;
			i++;
		}

	}
	key = 0;

	/* stay till user pushes Enter */
	while(KEYPAD_Get_Pressed_Key() != 'A');
}

 ;
uint8 compareEnteredID(const uint8_t* enteredID) {
	uint16_t enteredIDValue = 0;
	for (uint8_t i = 0; i < 4; i++) {
		enteredIDValue = enteredIDValue * 10 + enteredID[i];
	}

	for ( uint8_t j = 0; j < DATABASE_SIZE; j++) {
		if (enteredIDValue == userIDs[j]) {
			return j+1; // Return the index of the matched element
		}
	}

	return -1; // No match found
}


uint8 compareEnteredPass(const uint8_t* enteredID) {
	uint16_t enteredIDValue = 0;
	for (uint8_t i = 0; i < 4; i++) {
		enteredIDValue = enteredIDValue * 10 + enteredID[i];
	}

	for (uint8_t i = 0; i < DATABASE_SIZE; i++) {
		if (enteredIDValue == passwords[i]) {
			return i+1; // Return the index of the matched element
		}
	}

	return -1; // No match found
}


int main(void)
{
	KEYPAD_INIT();
	H_LCD_void_IniT();

	H_LCD_void_sendString("'A' to continue..");
	uint8 key = 0;
	while (1)
	{
		//H_LCD_void_sendString("'A' to continue..");

		key = KEYPAD_Get_Pressed_Key();
		if(key == 'A')
		{
			H_Lcd_Void_Clear();

			H_LCD_void_sendString("Enter ID : ");
			getID(g_inputID);

			uint8 n = compareEnteredID(g_inputID);
			if( n== 1 || n == 2 )
			{
				H_Lcd_Void_Clear();
				H_LCD_void_sendString("Enter Password: ");
			}
			else
			{
				H_Lcd_Void_Clear();
				H_LCD_void_sendString("Wrong ID");
				continue;
			}

			getID(g_inputPass);
			uint8 m = compareEnteredPass(g_inputPass);


			if( m == 1 || m == 2 )

			{


				if((m == n) && (m ==1))
				{

					H_Lcd_Void_Clear();
					H_LCD_void_sendString("Welcome Ahmed !!");
					continue;
				}
				else if ((m == n) && (m==2))
				{
					H_Lcd_Void_Clear();
					H_LCD_void_sendString("Welcome Sara !!");
					continue;
				}
				else
					H_Lcd_Void_Clear();
				H_LCD_void_sendString("Wrong Pass!!");
				continue;

			}
			else
			{
				H_Lcd_Void_Clear();
				H_LCD_void_sendString("Wrong Pass!!");
				continue;
			}
		}





	}
}

