/*
 * Lcd.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Ahmed Yasser
 */

#ifndef LCD_H_
#define LCD_H_
#include "Dio.h"
#include "util/delay.h"
//////////////////////////////////////////////////////////////////////
///////////////////////// DEFINING LCD PINS////////////////////////////////
//////////////////////////////////////////////////////////////////////
#define		LCD_RS_PIN	PIN3_ID
#define		LCD_EN_PIN	PIN2_ID
#define		LCD_D4_PIN	PIN0_ID
#define		LCD_D5_PIN	PIN1_ID
#define		LCD_D6_PIN	PIN2_ID
#define		LCD_D7_PIN	PIN4_ID




#define		CLEAR_DISPLAY_COMMAND	 0x01
#define		RETURN_HOME_COMMAND		 0x02
#define		COMMAND_NUMBER_1		 0x0F  // DISPLAY ON , CURSOR ON , BLINKING ON
#define		COMMAND_NUMBER_2		 0x0C // DISPLAY ON , CURSOR OFF , BLINKING OFF
#define		LCD_FONT_BOLD            0x04         // 5 x 10 font
#define		LCD_FONT_NOT_BOLD        0x00         // 5 x 8 font
#define		LCD_2_LINE               0x08         // 2-line display
#define		LCD_1_LINE               0x00         // 1-line display
#define		FOUR_BIT_MODE            0x20    // 1 line, 4-bit mode
#define		EIGHT_BIT_MODE           0x30    // 1 line, 4-bit mode
#define		CONTROL_MODE   (LCD_FONT_NOT_BOLD | LCD_2_LINE | FOUR_BIT_MODE) // 2 lines, 5x8 matrix,4-bit mode (you can make your own mode
#define		LCD_CURSOR_RETURN        0x02  // return cursor to first position on first line
#define		SHIFT_CURSOR_RIGHT       0x06  // make you write from left to right
#define		LCD_CLEAR_CMD  			 0x01
#define		SHIFT_CURSOR_TO_1_LINE   0x80  // to write in first line
#define		SHIFT_CURSOR_TO_2_LINE   0xC0  // to write in second line

//////////////////////////////////////////////
#define _8_BIT_MODE                   8
#define _4_BIT_MODE                   4
#define LCD_8_BIT_MODE_COMMAND        0x38
#define LCD_DISPLAY_ON_COMMAND        0x0C
#define LCD_RETURN_HOME_COMMAND       0x02
#define LCD_4_BIT_MODE_COMMAND_1      0x33	// enabling LCD and choosing DISPLAY ON  CURSOR OFF
#define LCD_4_BIT_MODE_COMMAND_2      0x32	// return cursor to first position on first line
#define LCD_4_BIT_MODE_COMMAND_3      0x28	// mode control
#define LCD_CLEAR                     0x01
#define LCD_R0_COMMAND                0x80
#define LCD_R1_COMMAND                0xC0
#define LCD_R2_COMMAND                0x94
#define LCD_R3_COMMAND                0xD4
#define NULL                          '\0'
////////////////////////////////////////////////////////

void LCD_INT (void);
void LCD_WRITE_COMMAND (uint8_t command);
void LCD_WRITE_CHAR(uint8_t c);
void LCD_WRITE_STRING(const uint8_t *c);
void Lcd_Void_LCDGoTo(uint8_t Copy_U8_Row, uint8_t Copy_U8_Col) ;
void Lcd_Void_LCDClear(void) ;

extern Port_Def* PORTA ;
extern Port_Def* PORTB ;
extern Port_Def* PORTC ;
extern Port_Def* PORTD ;


#endif /* LCD_H_ */
