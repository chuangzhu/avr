/*
 * main.c
 * ��ʱ����������
 * Created: 2017/10/3 16:22:52
 * Author : geneLocated
 */ 

#include "F_CPU.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include "HAL_TIMER.h"

#define set(Reg, Bit)	Reg|=(1<<Bit)	//��λReg�Ĵ�����Bitλ
#define clr(Reg, Bit)	Reg&=~(1<<Bit)	//����Reg�Ĵ�����Bitλ
#define not(Reg, Bit)	Reg^=(1<<Bit)	//ȡ��Reg�Ĵ�����Bitλ

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
