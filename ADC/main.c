/*
 * ADC.c
 * ADC库的测试程序
 * Created: 2017/10/3 11:36:50
 * Author : geneLocated
 */ 

#include "F_CPU.h"
#include <avr/io.h>
#include <util/delay.h>
#include "HAL_ADC.h"
#include "../USART/HAL_USART.h"

int main(void)
{
	unsigned int CData;
	ADC_Init();
	USART_Begin();
	while(1)
	{
		CData = ADConvert(0);
		USART_Print(CData);
		USART_SendLine();
		_delay_ms(10);
	}
}


