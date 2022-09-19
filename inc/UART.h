/*
 * UART.h
 *
 *  Created on: ??�/??�/????
 *      Author: medoa
 */

#ifndef INC_UART_H_
#define INC_UART_H_
#include "Registers.h"
#include "std_types.h"
#include "macros.h"

#define UCSRA_RCX 7
#define UCSRA_TXC 6 
#define UCSRC_UMSEL 6
#define UCSRC_UPM0 4
#define UCSRC_UPM1 5
#define UCSRC_USBS 3
#define UCSRC_UCSZ0 1
#define UCSRC_UCSZ1 2
#define UCSRB_UCSZ2 2

#define UCSRB_RXEN 		4
#define UCSRB_TXEN 		3

#define UCSRC_URSEL 	7


typedef enum {
    Asynchronous,
    Synchronous
}USART_Mode_Select;

typedef enum {
    Disabled_parity,
    Even_Parity,
    Odd_Parity


}Parity_Mode;

typedef enum {
    one_Stop_bit,
    two_Stop_bit

}Stop_Bit_Select;

typedef enum {
    _5_bit,
    _6_bit,
    _7_bit,
    _8_bit,
    _9_bit
}Character_Size;

typedef enum {
    _2400,
    _4800,
    _9600

}Baud_Rate_Setting;
void UART_Init(USART_Mode_Select mode,Parity_Mode pmode,Stop_Bit_Select sbit,Character_Size csize,Baud_Rate_Setting brate);
void UART_Send_Data(u8 data);
u8 Recieve_Data();
#endif /* INC_UART_H_ */
