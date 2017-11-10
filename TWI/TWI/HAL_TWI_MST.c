/*
 * HAL_TWI_MST.h
 * TWI/IIC/I2C������
 * �˿�ֻ������Atmega48/88/168/328��Ƭ��
 * ��Ӧ���������ͺ�һЩ�Ĵ�����ֵ��Ҫ�޸�
 * Modified: 2017/10/3
 * Author : geneLocated
 */ 

#include "HAL_TWI_MST.h"

//�ȴ�TWINT��λ��������START/STOP�źŷ�����ɻ���յ��ӻ�ACK�ź�ʱ��λ
#define	TWI_WaitAck()	while(!(TWCR & _BV(TWINT)))

//����ACK�ź�
#define	TWI_RecvAck()	({TWI_WaitAck();	(TW_STATUS);})
//�ȴ��ӻ�����ACK

//����START�ź�
void TWI_Start(void)	{PORTC |= (_BV(SDApin)|_BV(SCLpin));	TWCR = (_BV(TWINT)|_BV(TWSTA)|_BV(TWEN));	TWI_WaitAck();}
//TWI�ӿ������ڲ���������	//����START�ź�	//�ȴ���ʼ�źŷ��ͽ���

//����һ���ֽڣ��Դ�����ACK
#define	TWI_SendByte(data)	({TWDR = data;	TWCR = (_BV(TWINT)|_BV(TWEN));	(TWI_RecvAck());})

//����һ���ֽ�
#define	TWI_RecvByte()	({TWCR = _BV(TWINT)|_BV(TWEA)|_BV(TWEN);	TWI_WaitAck();	(TWDR);})

//����ACK�ź�
#define	TWI_SendAck()	TWCR |= _BV(TWEA)

//����NACK�ź�
#define	TWI_SendNoAck()	{TWCR &= ~(_BV(TWEA));	TWI_WaitAck();}

//����STOP�ź�
#define	TWI_Stop()	TWCR = (_BV(TWINT)|_BV(TWSTO)|_BV(TWEN))



/*����Ϊ�ɵ��õĺ���*/

void TWI_Init(void)
{
	TWBR = TWBR_Init;	//����TWI������
}

void TWI_Write(unsigned char SlaveAddress, unsigned char RegisterAddress, unsigned char data)
{
	unsigned char dataArray[1]={data};
	TWI_MultiWrite(SlaveAddress, RegisterAddress, dataArray, 1);
	/*	����Ϊ�ɰ�����
	TWI_Start();	//����START�ź�
	TWI_SendByte(SlaveAddress|TW_WRITE);	//ָ���ӻ���ַ������д
	TWI_SendByte(RegisterAddress);	//�������ݵ�ַ
	TWI_SendByte(data);	//д������
	TWI_Stop();
	*/
}

void TWI_MultiWrite(unsigned char SlaveAddress, unsigned char RegisterAddress, unsigned char data[], unsigned char leng)
{
	TWI_Start();	//����START�ź�
	TWI_SendByte(SlaveAddress|TW_WRITE);	//ָ���ӻ���ַ������д
	TWI_SendByte(RegisterAddress);	//�������ݵ�ַ
	for(unsigned char i=0; i<leng; i++) TWI_SendByte(data[i]);	//д������
	TWI_Stop();
}

unsigned char TWI_Query(unsigned char SlaveAddress, unsigned char RegisterAddress)
{
	//��ѯ�ӻ���Ҫ���䷵��ָ���ڼĴ�����ֵ
	unsigned char ResultArray[1];
	TWI_MultiQuery(SlaveAddress, RegisterAddress, ResultArray, 1);
	return ResultArray[0];
	/*	����Ϊ�ɰ�����
	unsigned char Result;
	TWI_Start();	//����START�ź�
	TWI_SendByte(SlaveAddress|TW_WRITE);	//ָ���ӻ���ַ������д
	TWI_SendByte(RegisterAddress);	//�������ݵ�ַ
	TWI_Start();	//����RESTART�ź�
	TWI_SendByte(SlaveAddress|TW_READ);	//ָ���ӻ���ַ�������
	Result=TWI_RecvByte();	//�������صĽ��
	TWI_SendNoAck();	//����NACK�ź�
	TWI_Stop();	//����STOP�ź�
	return Result;
	*/
}

void TWI_MultiQuery(unsigned char SlaveAddress, unsigned char RegisterAddress, unsigned char Result[], unsigned char leng)
{
	TWI_Start();	//����START�ź�
	TWI_SendByte(SlaveAddress|TW_WRITE);	//ָ���ӻ���ַ������д
	TWI_SendByte(RegisterAddress);	//�������ݵ�ַ
	TWI_Start();	//����RESTART�ź�
	TWI_SendByte(SlaveAddress|TW_READ);	//ָ���ӻ���ַ�������
	for(unsigned char i=0; i<(leng-1); i++)
	{
		Result[i]=TWI_RecvByte();	//�������صĽ��
		TWI_SendAck();	//����ACK�ź�
	}
	Result[(leng-1)]=TWI_RecvByte();	//�������صĽ��
	TWI_SendNoAck();	//����NACK�ź�
	TWI_Stop();	//����STOP�ź�
}
