/*
 * Time_Table.h
 *
 *  Created on: ??�/??�/????
 *      Author: medoa
 */

#ifndef INC_TIME_TABLE_H_
#define INC_TIME_TABLE_H_
// #include "EEPROM.h"
#include "std_types.h"

#define Clock_Hour_add1 1
#define Clock_Hour_add2 2

#define Clock_Min_add1  3
#define Clock_Min_add2  4

#define Clock_Fajr_add1 5
#define Clock_Fajr_add2 6
#define Clock_Fajr_add3 7
#define Clock_Fajr_add4 8

#define Clock_Dhuhr_add1 9
#define Clock_Dhuhr_add2 10
#define Clock_Dhuhr_add3 11
#define Clock_Dhuhr_add4 12

#define Clock_Asr_add1 13
#define Clock_Asr_add2 14
#define Clock_Asr_add3 15
#define Clock_Asr_add4 16

#define Clock_Maghrib_add1 17
#define Clock_Maghrib_add2 18
#define Clock_Maghrib_add3 19
#define Clock_Maghrib_add4 20

#define Clock_Isha_add1 19
#define Clock_Isha_add2 20
#define Clock_Isha_add3 21
#define Clock_Isha_add4 22

void Clock_Set_Hour(u8 data);
void Clock_Set_Min(u8 data);

void Clock_Set_Fajr(u8 data);
void Clock_Set_Dhuhr(u8 data);
void Clock_Set_Asr(u8 data);
void Clock_Set_Maghrib(u8 data);
void Clock_Set_Isha(u8 data);

u8 Clock_Get_Hour();
u8 Clock_Get_Min();
u8 Clock_Get_Fajr();
u8 Clock_Get_Dhuhr();
u8 Clock_Get_Asr();
u8 Clock_Get_Maghrib();
u8 Clock_Get_Isha();




#endif /* INC_TIME_TABLE_H_ */
