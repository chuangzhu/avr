/*
 * APP_Clock.h
 * ʱ��Ӧ�ÿ�
 * ռ��TIMER1
 * �˿�ֻ������Atmega48/88/168��Ƭ��
 * ��Ӧ���������ͺ�һЩ�Ĵ�����ֵ��Ҫ�޸�
 * Created: 2017/10/3 16:35:17
 *  Author: geneLocated
 */ 


#ifndef APP_CLOCK_H_
#define APP_CLOCK_H_

#include <avr/io.h>
#include <avr/interrupt.h>

/* ����<F_CPU.h>�ж���ʱ��Ƶ�ʺͲ�����*/

void Clock_Init(void);

extern unsigned char time[3];
#define	second	time[0]
#define	minute	time[1]
#define	hour	time[2]

#endif /* APP_CLOCK_H_ */