/*
 * Calculator.c
 *
 *  Created on: ??�/??�/????
 *      Author: medoa
 */



#ifndef SRC_CALCULATOR_C_
#define SRC_CALCULATOR_C_

#include "std_types.h"
#include "macros.h"
#include "Keypad.h"
#include "LCD.h"
#include "Calculator.h"

//u8 Calculator_GetRealNumber (Keypad_ButtonType button);

void Calculator_Run(void) {
    s8 num1=0, num2=0, operation=0, result=0;
    u8 num1_flag=0, num2_flag=0, operation_flag=0, result_flag=0;
    Keypad_ButtonType pressed_button;
    while (1)
    {
        /* Wait for user input */
        do {
            pressed_button = Keypad_GetPressedButton();
        }
        while (pressed_button == KEYPAD_BUTTON_INVALID);

        if (pressed_button == CALCULATOR_BUTTON_CLR) {
            num1_flag = 0;
            num2_flag = 0;
            operation_flag = 0;
            result_flag = 0;
            LCD_Clear();
            continue;
        }
        if (num1_flag == 0) {
            num1_flag = 1;
            num1 = Calculator_GetRealNumber(pressed_button);
            LCD_DisplayNumber(num1);
        }
        else if (operation_flag == 0) {
            operation_flag = 1;
            switch (pressed_button)
            {
            case CALCULATOR_BUTTON_PLUS:
                operation = '+';
                break;
            case CALCULATOR_BUTTON_MINUS:
                operation = '-';
                break;
            case CALCULATOR_BUTTON_MUL:
                operation = '*';
                break;
            case CALCULATOR_BUTTON_DIV:
                operation = '/';
                break;
            default:
                break;
            }
            LCD_DisplayCharacter(operation);
        }
        else if (num2_flag == 0) {
            num2_flag = 1;
            num2 = Calculator_GetRealNumber(pressed_button);
            LCD_DisplayNumber(num2);
        }
        else if (result_flag == 0) {
            if (pressed_button == CALCULATOR_BUTTON_EQUAL) {
                result_flag = 1;
                switch (operation)
                {
                case '+':
                    result = num1 + num2;
                    break;
                case '-':
                    result = num1 - num2;
                    break;
                case '*':
                    result = num1 * num2;
                    break;
                case '/':
                    result = num1 / num2;
                    break;
                default:
                    break;
                }
                LCD_DisplayCharacter('=');
                LCD_SetCursorPosition(1,0);
                LCD_DisplayString((u8*)"Result = ");
                LCD_DisplayNumber(result);
            }
        }
    }
}

 u8 Calculator_GetRealNumber (Keypad_ButtonType button) {
    u8 num = 0;
    switch (button)
    {
    case CALCULATOR_BUTTON_NUM0:
        num = 0;
        break;
    case CALCULATOR_BUTTON_NUM1:
        num = 1;
        break;
    case CALCULATOR_BUTTON_NUM2:
        num = 2;
        break;
    case CALCULATOR_BUTTON_NUM3:
        num = 3;
        break;
    case CALCULATOR_BUTTON_NUM4:
        num = 4;
        break;
    case CALCULATOR_BUTTON_NUM5:
        num = 5;
        break;
    case CALCULATOR_BUTTON_NUM6:
        num = 6;
        break;
    case CALCULATOR_BUTTON_NUM7:
        num = 7;
        break;
    case CALCULATOR_BUTTON_NUM8:
        num = 8;
        break;
    case CALCULATOR_BUTTON_NUM9:
        num = 9;
        break;
    default:
        break;
    }
    return num;
}


#endif /* SRC_CALCULATOR_C_ */

