/*
 * Time_Table.c
 *
 *  Created on: ??�/??�/????
 *      Author: medoa
 */
#include "Time_Table.h"
#include "EEPROM.h"
#include <util/delay.h>

void Clock_Set_Hour(u8 H_data1, u8 M_data2)
{
    EEPROM_Write_Byte(0b10100000, 0b00000000, 4);
}
void Clock_Set_Min(u8 H_data1, u8 M_data2)
{
    EEPROM_Write_Byte(0b10100000, Clock_Min_add1, H_data1);
}

void Clock_Set_Fajr(u8 H_data1, u8 M_data2)
{
    EEPROM_Write_Byte(0b10100000, Clock_Fajr_add1, H_data1);
    _delay_ms(100);
    EEPROM_Write_Byte(0b10100000, Clock_Fajr_add2, M_data2);
}
void Clock_Set_Dhuhr(u8 H_data1, u8 M_data2)
{
    EEPROM_Write_Byte(0b10100000, Clock_Dhuhr_add1, H_data1);
    _delay_ms(100);
    EEPROM_Write_Byte(0b10100000, Clock_Dhuhr_add2, M_data2);
}
void Clock_Set_Asr(u8 H_data1, u8 M_data2)
{
    EEPROM_Write_Byte(0b10100000, Clock_Asr_add1, H_data1);
    _delay_ms(100);
    EEPROM_Write_Byte(0b10100000, Clock_Asr_add2, M_data2);
}
void Clock_Set_Maghrib(u8 H_data1, u8 M_data2)
{
    EEPROM_Write_Byte(0b10100000, Clock_Maghrib_add1, H_data1);
    _delay_ms(100);
    EEPROM_Write_Byte(0b10100000, Clock_Maghrib_add2, M_data2);
}
void Clock_Set_Isha(u8 H_data1, u8 M_data2)
{
    EEPROM_Write_Byte(0b10100000, Clock_Isha_add1, H_data1);
    _delay_ms(100);
    EEPROM_Write_Byte(0b10100000, Clock_Isha_add2, M_data2);
}

u16 Clock_Get_Hour()
{
    u8 x = EEPROM_Read_Byte(0b10100000, Clock_Hour_add1);
    _delay_ms(100);
    u8 y = EEPROM_Read_Byte(0b10100000, Clock_Hour_add2);
    return (x * 100 + y);
}
u16 Clock_Get_Min()
{
    u8 x = EEPROM_Read_Byte(0b10100000, Clock_Min_add1);
    _delay_ms(100);
    u8 y = EEPROM_Read_Byte(0b10100000, Clock_Min_add2);
    return (x * 100 + y);
}
u16 Clock_Get_Fajr()
{
    u8 x = EEPROM_Read_Byte(0b10100000, Clock_Fajr_add1);
    _delay_ms(100);
    u8 y = EEPROM_Read_Byte(0b10100000, Clock_Fajr_add2);
    return (x * 100 + y);
}
u16 Clock_Get_Dhuhr()
{
    u8 x = EEPROM_Read_Byte(0b10100000, Clock_Dhuhr_add1);
    _delay_ms(100);
    u8 y = EEPROM_Read_Byte(0b10100000, Clock_Dhuhr_add2);
    return (x * 100 + y);
}
u16 Clock_Get_Asr()
{
    u8 x = EEPROM_Read_Byte(0b10100000, Clock_Asr_add1);
    _delay_ms(100);
    u8 y = EEPROM_Read_Byte(0b10100000, Clock_Asr_add2);
    return (x * 100 + y);
}
u16 Clock_Get_Maghrib()
{
    u8 x = EEPROM_Read_Byte(0b10100000, Clock_Maghrib_add1);
    _delay_ms(100);
    u8 y = EEPROM_Read_Byte(0b10100000, Clock_Maghrib_add2);
    return (x * 100 + y);
}
u16 Clock_Get_Isha()
{
    u8 x = EEPROM_Read_Byte(0b10100000, Clock_Isha_add1);
    _delay_ms(100);
    u8 y = EEPROM_Read_Byte(0b10100000, Clock_Isha_add2);
    return (x * 100 + y);
}