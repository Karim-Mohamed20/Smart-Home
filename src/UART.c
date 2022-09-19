/*
 * UART.c
 *
 *  Created on: ??�/??�/????
 *      Author: medoa
 */


#include"UART.h"
#include "std_types.h"
#include "macros.h"
#include "UART.h"
#include "Registers.h"
#include "DIO.h"

void UART_Init(USART_Mode_Select mode,Parity_Mode pmode,Stop_Bit_Select sbit,Character_Size csize,Baud_Rate_Setting brate)
{
    SET_BIT(UCSRC, UCSRC_URSEL); // 3shan tekhali uart to play
    DIO_SetPinMode(DIO_PORTD, DIO_PIN0, DIO_INPUT_FLOATING);
	DIO_SetPinMode(DIO_PORTD, DIO_PIN1, DIO_OUTPUT);


    if(mode == Asynchronous)
    {
        CLR_BIT(UCSRC,UCSRC_UMSEL);
    }else if(mode == Synchronous)
    {
        SET_BIT(UCSRC,UCSRC_UMSEL);

    }

    switch (pmode)
    {
    case Disabled_parity:
        CLR_BIT(UCSRC,UCSRC_UPM0);
        CLR_BIT(UCSRC,UCSRC_UPM1);
        /* code */
        break;
    case Even_Parity:
        CLR_BIT(UCSRC,UCSRC_UPM0);
        SET_BIT(UCSRC,UCSRC_UPM1);
        /* code */
        break;
    case Odd_Parity:
        SET_BIT(UCSRC,UCSRC_UPM0);
        SET_BIT(UCSRC,UCSRC_UPM1);
        /* code */
        break;
    
    default:
        break;
    }
    if(sbit==one_Stop_bit)
    {
        CLR_BIT(UCSRC,UCSRC_USBS);
    }else if( sbit==two_Stop_bit)
    {
        SET_BIT(UCSRC,UCSRC_USBS);
    }
    switch (csize)
    {
    case _5_bit:
        CLR_BIT(UCSRC,UCSRC_UCSZ0);
        CLR_BIT(UCSRC,UCSRC_UCSZ1);
        CLR_BIT(UCSRC,UCSRB_UCSZ2);
        /* code */
        break;
    case _6_bit:
        CLR_BIT(UCSRC,UCSRC_UCSZ0);
        CLR_BIT(UCSRC,UCSRC_UCSZ1);
        CLR_BIT(UCSRC,UCSRB_UCSZ2);
        /* code */
        break;
    case _7_bit:
        CLR_BIT(UCSRC,UCSRC_UCSZ0);
        SET_BIT(UCSRC,UCSRC_UCSZ1);
        CLR_BIT(UCSRC,UCSRB_UCSZ2);
        /* code */
        break;
    case _8_bit:
        SET_BIT(UCSRC,UCSRC_UCSZ0);
        SET_BIT(UCSRC,UCSRC_UCSZ1);
        CLR_BIT(UCSRC,UCSRB_UCSZ2);
        /* code */
        break;
    case _9_bit:
        SET_BIT(UCSRC,UCSRC_UCSZ0);
        SET_BIT(UCSRC,UCSRC_UCSZ1);
        SET_BIT(UCSRC,UCSRB_UCSZ2);
        /* code */
        break;
    
    default:
        break;
    }
    switch (brate)
    {
    case _2400:
        UBRRL=416;
        /* code */
        break;
    case _4800:
        UBRRL=207;
        /* code */
        break;
    case _9600:
        UBRRL=103;
        /* code */
        break;
    
    default:
        break;
    }
    SET_BIT(UCSRB,UCSRB_RXEN);
    SET_BIT(UCSRB,UCSRB_TXEN);
}


void UART_Send_Data(u8 data){
    
    UDR=data;
    while (GET_BIT(UCSRA,UCSRA_TXC)==0);
}

u8 Recieve_Data(){
    while (GET_BIT(UCSRA,UCSRA_RCX)==0);
    return UDR;
}
