/*
 * HAL_ADC.c
 * �˿�ֻ������Atmega48/88/168/328��Ƭ��
 * ��Ӧ���������ͺ�һЩ�Ĵ�����ֵ��Ҫ�޸�
 * Modified: 2017/10/3
 * Author : geneLocated
 */ 

#include "HAL_ADC.h"

void ADC_Init(void)	//ADC��ʼ��
{
	ADCSRA = 0x00;	//����ADC
	ADMUX = 0x40;	//���òο���ѹΪAVCC���Ҷ���
	ADCSRA = 0x86;	//���÷�Ƶ��Ϊ64��ʹ��ADC
}

unsigned int ADConvert(unsigned char Channel)	//ADת��
{
	unsigned int CData;
	ADMUX = 0x40;	//����
	ADMUX |= (Channel & 0x07);	//ͨ��ֻ��8������λ��
	ADCSRA |= (1<<ADSC);	//����ADת��
	while(ADCSRA & (1<<ADSC));	//�ȴ�ת������
	CData = ADCL;	//��ȡ��8λת������
	CData |= ((unsigned int)(ADCH & 0x03))<<8;	//��ȡ��2λ
	return CData;	//��������
}
