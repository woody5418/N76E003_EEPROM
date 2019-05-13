
/********************************************************************
 *@file        Common.h
 *@author      Woody      QQ£º2490006131
 *@version     V1.0
 *@date        2017-07-26
 *@brief       
 *******************************************************************/
#ifndef __EEPROM_H__
#define __EEPROM_H__

#define  StartEEPROMAddress   0X3801

void write_DATAFLASH_BYTE(uint16_t u16_addr,uint8_t u8_data);
uint8_t read_APROM_BYTE(uint16_t code *u16_addr);

#endif





