/*
 * PWM.c
 *
 * Created: 2018/6/3 11:35:20
 * Author : geneLocated
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "HAL_PWM.h"

int main(void)
{
	PWM_Init();
    while (1) 
    {
		unsigned char bright = 0;
		for (; bright < 255; bright++)
		{
			OCR0A = bright;
			_delay_ms(10);
		}
		for (; bright > 0; bright--)
		{
			OCR0A = bright;
			_delay_ms(10);
		}
    }
}

