/*
 * HAL_USART.h
 * �˿�ֻ������Atmega48/88/168/328��Ƭ��
 * ��Ӧ���������ͺ�һЩ�Ĵ�����ֵ��Ҫ�޸�
 * Modified: 2017/10/3
 * Author : geneLocated
 */ 

#ifndef _HAL_USART_H_
#define _HAL_USART_H_

#include <avr/io.h>

/* ����<F_CPU.h>�ж���ʱ��Ƶ�ʺͲ�����*/

void USART_Begin(void);	//��ʼUSARTͨѶ
void USART_SendByte(unsigned char x);	//����һ���ֽ�
void USART_SendData(const char *data, unsigned int leng);	//��USART�����ַ����������У�
void USART_Print(int data);	//��USART��ASCII��ʽ����int
void USART_SendLine(void);	//��USART���ͻس�����
/*
void USART_SendFloat(float data);	//��USART���͸�������ͨ�������壩
*/

#endif
