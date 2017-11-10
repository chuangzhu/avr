/*
 * HAL_TWI_MST.h
 * TWI/IIC/I2C������
 * �˿�ֻ������Atmega48/88/168/328��Ƭ��
 * ��Ӧ���������ͺ�һЩ�Ĵ�����ֵ��Ҫ�޸�
 * Modified: 2017/10/3
 * Author : geneLocated
 */ 

#ifndef _HAL_TWI_MST_H_
#define _HAL_TWI_MST_H_

#include <avr/io.h>
#include <util/twi.h>

#define	SDApin	4
#define SCLpin	5
#define	TWBR_Init	0X73

void TWI_Init(void);
void TWI_Write(unsigned char SlaveAddress, unsigned char RegisterAddress, unsigned char data);
void TWI_MultiWrite(unsigned char SlaveAddress, unsigned char RegisterAddress, unsigned char data[], unsigned char leng);
unsigned char TWI_Query(unsigned char SlaveAddress, unsigned char RegisterAddress);
void TWI_MultiQuery(unsigned char SlaveAddress, unsigned char RegisterAddress, unsigned char Result[], unsigned char leng);

#endif
