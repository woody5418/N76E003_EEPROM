/****************************************************************************
*       Copyright (C), 北京四维拓智教育科技有限公司
*
*       N76E003
*       V0.1
*       2017-12-04
*       Woody  QQ:2490006131
*Description
*两组标准16位定时器/计数器：
      定时器0及1
*一组带有3路管脚输入捕获模式的16位定时器：
      定时器
*一组看门狗定时器（WDT）
*一组自唤醒定时器（WKT）
*一组带自动重装载功能，可用于产生标准波特率的定时器：
      定时器3
*两组标准串行口（UART），这两组串行口具有帧错误侦测及自动地址识别功能
*一组SPI
*一组IIC
*6通道增强型PWM输出
*8路12位ADC
* 上述功能对应产生18个中断源，具有4级中断优先级配置
*****************************************************************************/

/****************************************************************************
*< N76E003 >
			FLASH SIZE:18Kbytes (APROM)
			SRAM SIZE:256bytes
			XRAM SIZE:768bytes
			Package:TSSOP20
* 已用
			FLASH:Kbytes
			RAM:  Kbytes
*****************************************************************************/
#include "includes.h"  //库文件添加旅路径 

/******************************************************************************
The main C function.  Program execution starts
here after stack initialization.
******************************************************************************/
void main (void)
{
	uint8_t datatemp=0;
	
    InitialUART0_Timer1(115200);
	
    write_DATAFLASH_BYTE (0x3801,0x55);
    write_DATAFLASH_BYTE (0x3802,0x56);
    write_DATAFLASH_BYTE (0x3805,0xaa);
    write_DATAFLASH_BYTE (0x3806,0x66);
	
	datatemp = read_APROM_BYTE(0x3801);
	printf("data is :%bx",datatemp);
    while(1)
    {
    }
}




