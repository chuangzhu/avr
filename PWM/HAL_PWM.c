/*
 * HAL_PWM.c
 *
 * Created: 2018/6/3 12:02:50
 *  Author: geneLocated
 */ 

#include "HAL_PWM.h"

void PWM_Init()
{
	DDRD |= (1<<PORTD6)|(1<<PORTD5); //OC0A OCOB
	TCCR0A |= (1<<COM0A1)|(1<<COM0B1)|(1<<WGM00)|(1<<WGM01);
	TCCR0A &= ~((1<<COM0A0)|(1<<COM0B0));
	TCCR0B |= (1<<CS00);
	TCCR0B &= ~((1<<CS02)|(1<<CS01));
}
