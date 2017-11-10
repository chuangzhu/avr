/*
 * DEV_ADXL345.h
 * ������ADXL345���ٶȴ�����
 * �˿���ܹ���HAL_TWI_MST.h֮��ʹ��
 * Modified: 2017/10/3
 * Author : geneLocated
 */ 

#ifndef _DEV_ADXL345_H_
#define _DEV_ADXL345_H_

#include "HAL_TWI_MST.h"

#define SLAVEaddr	(0x53<<1)	//ADXL345��ַ�����ALT ADDRESS������Ϊ(0x1D<<1)������ӵ���Ϊ(0x53<<1)
#define OUTratio 4	//ȫ�ֱ�����XOUT,YOUT,ZOUT�������ӣ�(mg/LSB)

#define ADXL_Write(RegisterAddress, data)	TWI_Write(SLAVEaddr, RegisterAddress, data)
#define ADXL_Query(RegisterAddress)	TWI_Query(SLAVEaddr, RegisterAddress)
#define ADXL_MultiWrite(RegisterAddress, data, leng)	TWI_MultiWrite(SLAVEaddr, RegisterAddress, data, leng)
#define ADXL_MultiQuery(RegisterAddress, Result, leng)	TWI_MultiQuery(SLAVEaddr, RegisterAddress, Result, leng)

//ȫ�ֱ������滻���ļ��ٶȣ���λmg
extern signed int aC[3];	//�˴������������ⲿ����
#define aX	aC[0]
#define aY	aC[1]
#define aZ	aC[2]

void ADXL345_Init(void);	//��ʼ��������
void ADXL345_GetData(void);	//��ȡ���ٶ����ݣ�������aC��

#endif
