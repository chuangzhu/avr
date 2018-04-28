/*
 * main.c
 * HAL_ADXL345库文件检测程序
 * Created: 2017/10/3 21:36:15
 * Author : geneLocated
 */ 

#include "F_CPU.h"
#include <avr/io.h>
#include <util/delay.h>
#include "../TWI/HAL_TWI_MST.h"
#include "../USART/HAL_USART.h"
#include "DEV_ADXL345.h"

#define set(Reg, Bit)	Reg|=(1<<Bit)	//置位Reg寄存器的Bit位
#define clr(Reg, Bit)	Reg&=~(1<<Bit)	//清零Reg寄存器的Bit位


int main(void)
{
	DDRB=0x3F;	//0011 1111	(XTAL2:0, XTAL1:0, DIS7:1, DIS6:1, DIS5:1, DIS4:1, DIS3:1, DIS2:1)
	DDRD=0xD2;	//1101 0010	(DIS1:1, DIS0:1, BUTTON:0, TRIG:1, INT2:0, INT1:0, TXD:1, RXD:0)
	TWI_Init();
	USART_Begin();
	ADXL345_Init();
	set(DDRB, 5);
	if(ADXL_Query(0x00)==0xE5) set(PORTB, 5);
    while (1) 
    {
		ADXL345_GetData();
		for (unsigned char i=0; i<3; i++)
		{
			USART_Print(aC[i]);
			USART_SendByte('\t');
		}
		USART_SendLine();
		_delay_ms(10);
    }
}

