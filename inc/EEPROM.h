/*
 * EEPROM.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: medoa
 */

#ifndef INC_EEPROM_H_
#define INC_EEPROM_H_


/*Initialize EEPROM*/
void EEPROM_Init(void);
/*Send byte to EEPROM*/
void EEPROM_Write_Byte(u8 AddressSlave ,u8 AddressLocation,u8 Data);
/*Read byte to EEPROM*/
u8 EEPROM_Read_Byte(u8 AddressSlave ,u8 AddressLocation);


#endif /* INC_EEPROM_H_ */
