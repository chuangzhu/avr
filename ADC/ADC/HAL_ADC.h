/*
 * HAL_ADC.h
 * �˿�ֻ������Atmega48/88/168/328��Ƭ��
 * ��Ӧ���������ͺ�һЩ�Ĵ�����ֵ��Ҫ�޸�
 * Modified: 2017/10/3
 * Author : geneLocated
 */ 

#ifndef _HAL_ADC_H_
#define _HAL_ADC_H_

#include <avr/io.h>

void ADC_Init(void);
unsigned int ADConvert(unsigned char Channel);

#endif
