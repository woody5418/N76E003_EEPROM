//********************************************************************
//
//      ���빦�ܣ�EEPROM����
//      4DClass
//      Copyright(C)  2017
//      All rights reserved
//  Dataflash use APROM area, please ALWAYS care the address of you code
//	APROM 0x3800~0x38FF demo as dataflash
// 	Please use Memory window key in C:0x3800 to check earse result
//***********************************************************************
#include "includes.h"

/**
 * ��ȡ�洢��APROM������
 * ģ��EEPROMʹ��
 * ��ַ��0X3801��ʼ��ȡ
 */
uint8_t read_APROM_BYTE(uint16_t code *u16_addr)
{
    uint8_t rdata;
    rdata = *u16_addr>>8;
    return rdata;
}
/**
 * д���ݵ�APROM
 * ģ��EEPROMʹ��
 * ��ַ��0X3801��ʼд��
 */
void write_DATAFLASH_BYTE(uint16_t u16_addr,uint8_t u8_data)
{
    uint8_t looptmp=0,u8_addrl_r;
    unsigned char code *cd_longaddr;
    unsigned char xdata *xd_tmp;

	//���ҳ��ʼ��ַ
    u8_addrl_r = u16_addr;
    if (u8_addrl_r<0x80)
    {
        u8_addrl_r = 0;
    }
    else
    {
        u8_addrl_r = 0x80;
    }
	//���� APROM ���ݵ� XRAM
    xd_tmp = 0x80;
    cd_longaddr = (u16_addr&0xff00)+u8_addrl_r;
    while (xd_tmp !=0x100)
    {
        *xd_tmp = *cd_longaddr;
        looptmp++;
        xd_tmp++;
        cd_longaddr++;
    }
	//�� XRAM ���޸�����
    u8_addrl_r = u16_addr;
    if (u8_addrl_r<0x80)
    {
        xd_tmp = u8_addrl_r+0x80;
    }
    else
    {
        xd_tmp = u8_addrl_r+0;
    }
    *xd_tmp = u8_data;
	//���� APROM DATAFLASH ҳ
    IAPAL = u16_addr;
    IAPAH = u16_addr>>8;
    IAPFD = 0xFF;
    set_IAPEN;
    set_APUEN;
    IAPCN = 0x22;
    set_IAPGO;
	//�����޸ĵ� RAM ���ݵ� APROM DATAFLASH
    u8_addrl_r = u16_addr;
    if (u8_addrl_r<0x80)
    {
        u8_addrl_r =0;
    }
    else
    {
        u8_addrl_r = 0x80;
    }
    xd_tmp = 0x80;
    IAPAL = u8_addrl_r;
    IAPAH = u16_addr>>8;
    set_IAPEN;
    set_APUEN;
    IAPCN = 0x21;
    while (xd_tmp !=0xFF)
    {
        IAPFD = *xd_tmp; //д���ݵ�IAPFD
        set_IAPGO;
        IAPAL++;
        xd_tmp++;
    }
    clr_APUEN;
    clr_IAPEN;
}
/************************************************************/


