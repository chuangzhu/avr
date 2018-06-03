/*
 * main.c
 * 时间应用库测试程序
 * Created: 2017/10/3 16:31:55
 * Author : geneLocated
 */

 #include <avr/io.h>
#include <util/delay.h>
#include "APP_Clock.h"
#include "../USART/HAL_USART.h"


int main(void)
{
	Clock_Init();
	USART_Begin();
	sei();
    while (1) 
    {
		for (unsigned char i=0; i<3; i++)
		{
			USART_Print(time[2-i]);
			USART_SendByte('\t');
		}
		USART_SendLine();
		_delay_ms(500);
	}
}

