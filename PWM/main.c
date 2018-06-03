/*
 * PWM.c
 *
 * Created: 2018/6/3 11:35:20
 * Author : geneLocated
 */ 

#include <avr/io.h>
#include <util/delay.h>

#define PWM_0A_ENABLE
#define PWM_0B_ENABLE
#include "HAL_PWM.h"

int main(void)
{
	PWM_Init();
    while (1)
    {
		unsigned char bright = 0;
		for (; bright < 255; bright++)
		{
			PWM_0A(bright);
			_delay_ms(10);
		}
		for (; bright > 0; bright--)
		{
			PWM_0A(bright);
			_delay_ms(10);
		}
    }
}

