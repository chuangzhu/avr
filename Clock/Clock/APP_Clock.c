/*
 * APP_Clock.c
 * ʱ��Ӧ�ÿ�
 * ռ��TIMER1
 * �˿�ֻ������Atmega48/88/168��Ƭ��
 * ��Ӧ���������ͺ�һЩ�Ĵ�����ֵ��Ҫ�޸�
 * Created: 2017/10/3 16:34:30
 *  Author: geneLocated
 */ 

#include "F_CPU.h"	/* ����<F_CPU.h>�ж���ʱ��Ƶ��*/
#include "APP_Clock.h"

#ifndef F_CPU
# warning "F_CPU is not defined for APP_Clock.c"
#define F_CPU 8000000
#endif
#define	TCNT1_Init	(0xFFFF-(F_CPU/256))

unsigned char time[3] = {0, 0, 12};

void Clock_Init(void)
{
	//��ʱ��1
	TCCR1B = _BV(CS12);	//256��Ƶ
	TCNT1 = TCNT1_Init;	//����ʼֵ��ʹ1s�󴥷��ж�
	TIMSK1 |= _BV(TOIE1);	//������ʱ������ж�
}

ISR(TIMER1_OVF_vect)
{
	TCNT1 = TCNT1_Init;	//TCNT1����ʼֵ
	unsigned char* t = time;	//����ָ��tָ������time
	(*t)++;	//���1
	if(*t==60){	//��ﵽ60
		*t=0;	//������
		(*(t+1))++;	//�ּ�һ
	}
	t++;	//ָ���
	if(*t==60){	//�ִﵽ60
		*t=0;	//������
		(*(t+1))++;	//�ּ�һ
	}
	t++;	//ָ��ʱ
	if(*t==24){	//ʱ�ﵽ24
		*t=0;	//ʱ����
	}
}
