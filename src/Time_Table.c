/*
 * Time_Table.c
 *
 *  Created on: ??�/??�/????
 *      Author: medoa
 */
#include "Time_Table.h"
#include "EEPROM.h"

void Clock_Set_Hour(u8 H_data1,u8 M_data2){
   EEPROM_Write_Byte(0b10100000,0b00000000,4);
}
void Clock_Set_Min(u8 H_data1,u8 M_data2){
    EEPROM_Write_Byte(0b10100000,Clock_Min_add1,H_data1);

}

void Clock_Set_Fajr(u8 H_data1,u8 M_data2){
    EEPROM_Write_Byte(0b10100000,Clock_Fajr_add1,H_data1);
    EEPROM_Write_Byte(0b10100000,Clock_Fajr_add2,M_data2);
}
void Clock_Set_Dhuhr(u8 H_data1,u8 M_data2){
    EEPROM_Write_Byte(0b10100000,Clock_Dhuhr_add1,H_data1);
    EEPROM_Write_Byte(0b10100000,Clock_Dhuhr_add2,M_data2);
}
void Clock_Set_Asr(u8 H_data1,u8 M_data2){
    EEPROM_Write_Byte(0b10100000,Clock_Asr_add1,H_data1);
    EEPROM_Write_Byte(0b10100000,Clock_Asr_add2,M_data2);
}
void Clock_Set_Maghrib(u8 H_data1,u8 M_data2){
    EEPROM_Write_Byte(0b10100000,Clock_Maghrib_add1,H_data1);
    EEPROM_Write_Byte(0b10100000,Clock_Maghrib_add2,M_data2);
}
void Clock_Set_Isha(u8 H_data1,u8 M_data2){
    EEPROM_Write_Byte(0b10100000,Clock_Isha_add1,H_data1);
    EEPROM_Write_Byte(0b10100000,Clock_Isha_add1,M_data2);
}

u8 Clock_Get_Hour(){
    return EEPROM_Read_Byte(0b10100000,Clock_Hour_add1);
}
u8 Clock_Get_Min(){
    return EEPROM_Read_Byte(0b10100000,Clock_Min_add1);
}
u8 Clock_Get_Fajr(){
    return EEPROM_Read_Byte(0b10100000,Clock_Fajr_add1);
}
u8 Clock_Get_Dhuhr(){
    return EEPROM_Read_Byte(0b10100000,Clock_Dhuhr_add1);
}
u8 Clock_Get_Asr(){
    return EEPROM_Read_Byte(0b10100000,Clock_Asr_add1);
}
u8 Clock_Get_Maghrib(){
    return EEPROM_Read_Byte(0b10100000,Clock_Maghrib_add1);
}
u8 Clock_Get_Isha(){
    return EEPROM_Read_Byte(0b10100000,Clock_Isha_add1);
}

