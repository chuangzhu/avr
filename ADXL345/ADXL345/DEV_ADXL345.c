/*
 * DEV_ADXL345.c
 * ������ADXL345���ٶȴ�����
 * �˿���ܹ���HAL_TWI_MST.h֮��ʹ��
 * Modified: 2017/10/3
 * Author : geneLocated
 */ 

#include "DEV_ADXL345.h"

signed int aC[3];	//�˴��������

void ADXL345_Init(void)
{
	ADXL_Write(0x31,0x0B);	//DATA_FORMAT	�����Բ⣬�жϸߵ�ƽ��Ч��ȫ�ֱ��ʣ��Ҷ��룬��Χ+-16g
	ADXL_Write(0x2C,0x08);	//BW_RATE	�������25Hz������12.5Hz
	ADXL_Write(0x2D,0x08);	//POWER_CTL	�����Զ����ߣ���������ģʽ
	ADXL_Write(0x2E,0x80);	//INT_ENABLE	����DATA_READY�ж�
	ADXL_Write(0x1E,0x00);	//OFSX	X�᲻����ƫ��У׼
	ADXL_Write(0x1F,0x00);	//OFSY	Y�᲻����ƫ��У׼
	ADXL_Write(0x20,0x00);	//OFSZ	Z�᲻����ƫ��У׼
	//ADXL_Write(0x20,0x05);	//OFSZ	Z�����78mgƫ��У׼
}

void ADXL345_GetData(void)
{
	unsigned char aData[6];	//����DATAX0��DATAX1��DATAY0��DATAY1��DATAZ0��DATAZ1������
	ADXL_MultiQuery(0x32, aData, 6);	//��DATAX0��������DATAZ1������aData[]��
	union		//��TWI�������ֽ�ƴ��int�ĺ���
	{
		unsigned char oriData[2];	//ԭ����
		signed int conData;	//ת���������
	} patch ;
	for(unsigned char i=0; i<3; i++)
	{
		patch.oriData[0]=aData[2*i];
		patch.oriData[1]=aData[2*i+1];
		aC[i]=patch.conData * OUTratio;
	}
}
