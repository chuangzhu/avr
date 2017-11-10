/*
 * HAL_USART.c
 * �˿�ֻ������Atmega48/88/168/328��Ƭ��
 * ��Ӧ���������ͺ�һЩ�Ĵ�����ֵ��Ҫ�޸�
 * Modified: 2017/10/3
 * Author : geneLocated
 */ 
#include "F_CPU.h"	/* ����<F_CPU.h>�ж���ʱ��Ƶ�ʺͲ�����*/
#include "HAL_USART.h"

#ifndef F_CPU
# warning "F_CPU not defined for <HAL_USART.c>"
#define F_CPU 8000000
#endif

#ifndef baud
# warning "baud not defined for <HAL_USART.c>"
#define baud 9600
#endif

//��ʼUSARTͨѶ
void USART_Begin(void)
{
	UBRR0H=(F_CPU/16/baud-1)/256;
	UBRR0L=(F_CPU/16/baud-1)%256;
	UCSR0B=(1<<RXEN0)|(1<<TXEN0);	//ʹ�ܷ��ͽ���
	//UCSR0B|=(1<<RXCIE0);	//ʹ�ܽ����ж�
	UCSR0C=(1<<UCSZ01)|(1<<UCSZ00);	//8bit
}

//����һ���ֽ�
void USART_SendByte(unsigned char x)
{
	while(!((UCSR0A)&(1<<UDRE0)));
	UDR0=x;
}

//��USART�����ַ����������У�
void USART_SendData(const char *data, unsigned int leng)
{
	while(leng)
	{
		while(!((UCSR0A)&(1<<UDRE0)));
		UDR0=*data;
		data++;
		leng--;
	}
}

//��USART��ASCII��ʽ����int
void USART_Print(int data)
{
	if(data<0)
	{
		data=~data+1;
		USART_SendByte('-');	//����
	}
	USART_SendByte(data/10000+48);	//��λ
	USART_SendByte(data%10000/1000+48);	//ǧλ
	USART_SendByte(data%1000/100+48);	//��λ
	USART_SendByte(data%100/10+48);	//ʮλ
	USART_SendByte(data%10+48);	//��λ
}

//��USART���ͻس�����
void USART_SendLine(void)
{
	USART_SendByte(0X0D);	//�س�CR(\r)
	USART_SendByte(0X0A);	//����LF(\n)
}

/*
//��USART���͸�������ͨ�������壩
void USART_SendFloat(float data)
{
	union convert	//һ�����������гɿ�ĺ���
	{
		float oriData;	//ԭ��������
		unsigned char conData[4];	//�Ӻ��������ó���������,һ��������Ա��г�4���ֽ�С��
	} convertion ;	//����һ��������С����
	convertion.oriData = data;	//����������븡������
	for(unsigned char count=0; count<4; count++)	//��ȡ����4��С��ִη���
	{
		while(!((UCSR0A)&(1<<UDRE0)));	//�ȴ�
		UDR0=convertion.conData[3-count];	//����
	}
}*/
