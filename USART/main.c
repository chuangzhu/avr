/*
 * main.c
 * HAL_USART库测试程序
 * Modified: 2017/10/3
 * Author : geneLocated
 */ 

#include "F_CPU.h"
#include <avr/io.h>
#include <util/delay.h>
#include "HAL_USART.h"

int main(void)
{
	USART_Begin();
	int message=23333;
	while(1)
	{
		USART_Print(message);
		USART_SendLine();
		_delay_ms(500);
	}
}
