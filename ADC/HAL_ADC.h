/*
 * HAL_ADC.h
 * 此库只适用于Atmega48/88/168/328单片机
 * 若应用于其他型号一些寄存器的值需要修改
 * Modified: 2017/10/3
 * Author : geneLocated
 */ 

#ifndef _HAL_ADC_H_
#define _HAL_ADC_H_

#include <avr/io.h>

#define ADC_Init() {\
	ADCSRA = 0x00;	/*禁用ADC*/ \
	ADMUX = 0x40;	/*设置参考电压为AVCC，右对齐*/ \
	ADCSRA = 0x86;	/*设置分频数为64，使能ADC*/ \
}

#define ADC_Disable() {\
	ADCSRA = 0x00;\
}

unsigned int ADConvert(unsigned char Channel);

#endif
