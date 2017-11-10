/*
 * main.c
 * TWI��������Գ���
 * PB5��������һ��LED
 * Slave: ADXL345
 * Modified: 2017/10/3
 * Author : geneLocated
 */ 

#define F_CPU 7372800
#include <avr/io.h>
#include <util/delay.h>
#include "HAL_TWI_MST.h"

#define set(Reg, Bit)	Reg|=(1<<Bit)	//��λReg�Ĵ�����Bitλ
#define clr(Reg, Bit)	Reg&=~(1<<Bit)	//����Reg�Ĵ�����Bitλ

#define	slave 0x53

int main(void)
{
	set(DDRB, 5);
	clr(PORTB, 5);
	TWI_Init();
	unsigned char DEVID;
	while(1)
	{
		DEVID=TWI_Query((slave<<1),0x00);
		if(DEVID==0XE5) set(PORTB,5);
		else clr(PORTB,5);
		_delay_ms(500);
	}
}