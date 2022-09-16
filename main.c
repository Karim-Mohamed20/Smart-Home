/*
 * main.c
 *
 *  Created on: ??�/??�/????
 *      Author: ascom
 */

#include <util/delay.h>
#include "macros.h"
#include "std_types.h"
#include "DIO.h"
#include "SSD.h"
#include "LCD.h"
#include "Keypad.h"
#include "ExtInterrupt.h"
#include "Adc.h"
#include "Gpt.h"
#include "GlobalInterrupt.h"
#include "Spt.h"
#include "UART.h"
#include "SPI_cfg.h"
#include "SPI.h"
#include "WDT.h"
#include "I2C.h"
#include "I2C_cfg.h"
#include "EEPROM.h"
#include "EEPROM_cfg.h"
#include "Calculator.h"
#include "Time_Table.h"

u8 Check_IS_Anumber(Keypad_ButtonType pressed_button);
u8 Check_For_PassWord();
void dispaly_prayer();
int main(void)
{
	DIO_SetPinMode(DIO_PORTC, DIO_PIN0, DIO_OUTPUT);
	DIO_SetPinLevel(DIO_PORTC, DIO_PIN0, DIO_HIGH);
	LCD_Init();
	EEPROM_Init();
	LCD_Clear();

	// EEPROM_Write_Byte(0b10100000,0b00000000,4);
	Clock_Set_Fajr(04);
	_delay_ms(1000);
	Clock_Set_Dhuhr(12);
	_delay_ms(1000);
	LCD_DisplayString("Fajr is");
	LCD_DisplayNumber(Clock_Get_Fajr());
	_delay_ms(1000);
	LCD_Clear();
	LCD_DisplayString("dhuhr is");
	LCD_DisplayNumber(Clock_Get_Dhuhr());
	_delay_ms(1000);

	while (1)
	{

		/* code */
		LCD_DisplayString("CLOCK::");
		Keypad_ButtonType pressed_button;
		Keypad_Init();
		do
		{
			pressed_button = Keypad_GetPressedButton();
		} while (pressed_button == KEYPAD_BUTTON_INVALID);
		if (pressed_button == CALCULATOR_BUTTON_CLR)
		{
			Check_For_PassWord();
		}
	}
}
void dispaly_prayer()
{
	LCD_Clear();
	LCD_DisplayString("Prayers clock settings");
	_delay_ms(500);

	Keypad_ButtonType pressed_button;
	u8 arr[20] = {0};
	u8 c = 0;
	u8 n = 0;
	while (1)
	{
		do
		{
			pressed_button = Keypad_GetPressedButton();
		} while (pressed_button == KEYPAD_BUTTON_INVALID);
		if (pressed_button != KEYPAD_BUTTON_INVALID)
		{
			if (Check_IS_Anumber(pressed_button))
			{
					LCD_DisplayString("Fjr:")
					u8 x = Calculator_GetRealNumber(pressed_button); //1
					LCD_DisplayNumber(x);
					do
					{
						pressed_button = Keypad_GetPressedButton();
					} while (pressed_button == KEYPAD_BUTTON_INVALID); //12
					u8 x1 = Calculator_GetRealNumber(pressed_button);
					LCD_DisplayNumber(x1);
					LCD_DisplayString(":");//12:
					do
					{
						pressed_button = Keypad_GetPressedButton();
					} while (pressed_button == KEYPAD_BUTTON_INVALID); 
					u8 x2 = Calculator_GetRealNumber(pressed_button);
					LCD_DisplayNumber(x2);
					do
					{
						pressed_button = Keypad_GetPressedButton();
					} while (pressed_button == KEYPAD_BUTTON_INVALID);
					u8 x3 = Calculator_GetRealNumber(pressed_button);
					LCD_DisplayNumber(x3);
					LCD_DisplayString("|");
					Clock_Set_Fajr((u8)(x*10+x1),(u8)(x2*10+x3));
					// arr[c] = x;

					LCD_DisplayString("Dhr:")
					u8 x = Calculator_GetRealNumber(pressed_button); //1
					LCD_DisplayNumber(x);
					do
					{
						pressed_button = Keypad_GetPressedButton();
					} while (pressed_button == KEYPAD_BUTTON_INVALID); //12
					u8 x1 = Calculator_GetRealNumber(pressed_button);
					LCD_DisplayNumber(x1);
					LCD_DisplayString(":");//12:
					do
					{
						pressed_button = Keypad_GetPressedButton();
					} while (pressed_button == KEYPAD_BUTTON_INVALID); 
					u8 x2 = Calculator_GetRealNumber(pressed_button);
					LCD_DisplayNumber(x2);
					do
					{
						pressed_button = Keypad_GetPressedButton();
					} while (pressed_button == KEYPAD_BUTTON_INVALID);
					u8 x3 = Calculator_GetRealNumber(pressed_button);
					LCD_DisplayNumber(x3);
					LCD_DisplayString("|");
					Clock_Set_Dhuhr((u8)(x*10+x1),(u8)(x2*10+x3));
					// arr[c] = x;

					LCD_DisplayString("Asr:")
					u8 x = Calculator_GetRealNumber(pressed_button); //1
					LCD_DisplayNumber(x);
					do
					{
						pressed_button = Keypad_GetPressedButton();
					} while (pressed_button == KEYPAD_BUTTON_INVALID); //12
					u8 x1 = Calculator_GetRealNumber(pressed_button);
					LCD_DisplayNumber(x1);
					LCD_DisplayString(":");//12:
					do
					{
						pressed_button = Keypad_GetPressedButton();
					} while (pressed_button == KEYPAD_BUTTON_INVALID); 
					u8 x2 = Calculator_GetRealNumber(pressed_button);
					LCD_DisplayNumber(x2);
					do
					{
						pressed_button = Keypad_GetPressedButton();
					} while (pressed_button == KEYPAD_BUTTON_INVALID);
					u8 x3 = Calculator_GetRealNumber(pressed_button);
					LCD_DisplayNumber(x3);
					LCD_DisplayString("|");
					Clock_Set_Asr((u8)(x*10+x1),(u8)(x2*10+x3));
					// arr[c] = x;

					LCD_DisplayString("Magh:")
					u8 x = Calculator_GetRealNumber(pressed_button); //1
					LCD_DisplayNumber(x);
					do
					{
						pressed_button = Keypad_GetPressedButton();
					} while (pressed_button == KEYPAD_BUTTON_INVALID); //12
					u8 x1 = Calculator_GetRealNumber(pressed_button);
					LCD_DisplayNumber(x1);
					LCD_DisplayString(":");//12:
					do
					{
						pressed_button = Keypad_GetPressedButton();
					} while (pressed_button == KEYPAD_BUTTON_INVALID); 
					u8 x2 = Calculator_GetRealNumber(pressed_button);
					LCD_DisplayNumber(x2);
					do
					{
						pressed_button = Keypad_GetPressedButton();
					} while (pressed_button == KEYPAD_BUTTON_INVALID);
					u8 x3 = Calculator_GetRealNumber(pressed_button);
					LCD_DisplayNumber(x3);
					LCD_DisplayString("|");
					Clock_Set_Maghrib((u8)(x*10+x1),(u8)(x2*10+x3));
					// arr[c] = x;

					LCD_DisplayString("Isha:")
					u8 x = Calculator_GetRealNumber(pressed_button); //1
					LCD_DisplayNumber(x);
					do
					{
						pressed_button = Keypad_GetPressedButton();
					} while (pressed_button == KEYPAD_BUTTON_INVALID); //12
					u8 x1 = Calculator_GetRealNumber(pressed_button);
					LCD_DisplayNumber(x1);
					LCD_DisplayString(":");//12:
					do
					{
						pressed_button = Keypad_GetPressedButton();
					} while (pressed_button == KEYPAD_BUTTON_INVALID); 
					u8 x2 = Calculator_GetRealNumber(pressed_button);
					LCD_DisplayNumber(x2);
					do
					{
						pressed_button = Keypad_GetPressedButton();
					} while (pressed_button == KEYPAD_BUTTON_INVALID);
					u8 x3 = Calculator_GetRealNumber(pressed_button);
					LCD_DisplayNumber(x3);
					LCD_DisplayString("|");
					Clock_Set_Isha((u8)(x*10+x1),(u8)(x2*10+x3));
					// arr[c] = x;
			}
			else if (pressed_button == CALCULATOR_BUTTON_EQUAL)
			{
			}
		}
	}
}
u8 Check_For_PassWord()
{
	LCD_Clear();
	Keypad_ButtonType pressed_button;
	u8 arr[20] = {0};
	u8 c = 0;
	u8 n = 0;
	while (1)
	{
		do
		{
			pressed_button = Keypad_GetPressedButton();
		} while (pressed_button == KEYPAD_BUTTON_INVALID);
		if (pressed_button != KEYPAD_BUTTON_INVALID)
		{
			if (Check_IS_Anumber(pressed_button))
			{
				u8 x = Calculator_GetRealNumber(pressed_button);
				LCD_DisplayNumber(x);
				arr[c] = x;
				c++;
			}
			else if (pressed_button == CALCULATOR_BUTTON_EQUAL)
			{
				if (1 && n < 5) // will check on the password
				{
					LCD_Clear();
					u8 *chr = "Correct Password";
					LCD_DisplayString(chr);
					_delay_ms(500);
					LCD_Clear();
					u8 *chr2 = " Welcome ";
					LCD_DisplayString(chr2);
					_delay_ms(500);
					LCD_Clear();
					return 1;
				}
				else if (n < 5)
				{ // enter an invalid password
					LCD_Clear();
					u8 *chr = "Wrong Password";
					LCD_DisplayString(chr);
					n++;
					LCD_Clear();
				}
				else
				{
					LCD_Clear();
					u8 *chr = "you entered Wrong Password 5 times";
					LCD_DisplayString(chr);
					_delay_ms(500);
					LCD_Clear();
					u8 *chr2 = "please wait 20 seconds then tryagain";
					LCD_DisplayString(chr2);
					LCD_Clear();
					return 0;
				}
			}
		}
	}
}

u8 Check_IS_Anumber(Keypad_ButtonType pressed_button)
{
	if (pressed_button != CALCULATOR_BUTTON_CLR && pressed_button != CALCULATOR_BUTTON_PLUS && pressed_button != CALCULATOR_BUTTON_MINUS && pressed_button != CALCULATOR_BUTTON_MUL && pressed_button != CALCULATOR_BUTTON_DIV && pressed_button != CALCULATOR_BUTTON_EQUAL)
		return 1;
	return 0;
}
