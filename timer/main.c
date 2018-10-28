/*
 * main.c
 * 计时器库检验程序
 * Created: 2017/10/3 16:22:52
 * Author : geneLocated
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "HAL_TIMER.h"

#define set(Reg, Bit)	Reg|=(1<<Bit)	//置位Reg寄存器的Bit位
#define clr(Reg, Bit)	Reg&=~(1<<Bit)	//清零Reg寄存器的Bit位
#define not(Reg, Bit)	Reg^=(1<<Bit)	//取反Reg寄存器的Bit位

int main(void)
{
	set(DDRD, 6);
	set(DDRD, 7);
	set(PORTD, 6);
	set(PORTD, 7);
	TIMER0_Init();
	sei();
    while (1) 
    {
		;
    }
}

ISR(TIMER0_OVF_vect)
{
	TCNT0=TCNT0_Init;
	{
		not(PORTD, 6);
	}
}
