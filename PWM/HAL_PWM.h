/*
 * HAL_PWM.h
 * __PLEASE DEFINE THE PINS YOU ARE GOING TO USE BEFORE YOU INCLUDE THIS FILE__
 * Example:
       #define PWM_0A_ENABLE
       #define PWM_1B_ENABLE
       #include "HAL_PWM.h"
       int main() {
           PWM_Init();
		   PWM_0A(0x32);
		   PWM_1B(0x3FFF);
       }
 * Created: 2018/6/3 12:02:35
 *  Author: geneLocated
 */ 


#ifndef HAL_PWM_H_
#define HAL_PWM_H_

#include <avr/io.h>



/* PWM OC0A & OC0B */
#if defined(PWM_0A_ENABLE) && defined(PWM_0B_ENABLE)
	#define _PWM_DDRD_0_SET ((1<<PORTD6)|(1<<PORTD5))
	#define _PWM_TCCR0A_SET ((1<<COM0A1)|(1<<COM0B1)|(1<<WGM00)|(1<<WGM01))
	#define _PWM_TCCR0A_CLR ((1<<COM0A0)|(1<<COM0B0))
#elif defined(PWM_0A_ENABLE)
	#define _PWM_DDRD_0_SET ((1<<PORTD6))	//OC0A
	#define _PWM_TCCR0A_SET ((1<<COM0A1)|(1<<WGM00)|(1<<WGM01))
	#define _PWM_TCCR0A_CLR ((1<<COM0A0)|(1<<COM0B0)|(1<<COM0B1))
#elif defined(PWM_0B_ENABLE)
	#define _PWM_DDRD_0_SET ((1<<PORTD5))	//OC0B
	#define _PWM_TCCR0A_SET ((1<<COM0B1)|(1<<WGM00)|(1<<WGM01))
	#define _PWM_TCCR0A_CLR ((1<<COM0A0)|(1<<COM0B0)|(1<<COM0A1))
#endif

#if defined(PWM_0A_ENABLE) || defined(PWM_0B_ENABLE)
	#define _PWM_0_INIT() {\
		DDRD |= _PWM_DDRD_0_SET;\
		TCCR0A |= _PWM_TCCR0A_SET;\
		TCCR0A &= ~_PWM_TCCR0A_CLR;\
		TCCR0B |= (1<<CS00);\
		TCCR0B &= ~((1<<CS02)|(1<<CS01));\
	}
#else
	#define _PWM_0_INIT() {}
#endif



/* PWM OC2A & OC2B */
#if defined(PWM_2A_ENABLE) && defined(PWM_2B_ENABLE)
	#define _PWM_DDRD_2_SET ((1<<PORTD3))	//OC2B
	#define _PWM_DDRB_2_SET ((1<<PORTB3))	//OC2A
	#define _PWM_TCCR2A_SET ((1<<COM2A1)|(1<<COM2B1)|(1<<WGM20)|(1<<WGM21))
	#define _PWM_TCCR2A_CLR ((1<<COM2A0)|(1<<COM2B0))
#elif defined(PWM_2A_ENABLE)
	#define _PWM_DDRD_2_SET (0)
	#define _PWM_DDRB_2_SET ((1<<PORTB3))	//OC2A
	#define _PWM_TCCR2A_SET ((1<<COM2A1)|(1<<WGM20)|(1<<WGM21))
	#define _PWM_TCCR2A_CLR ((1<<COM2A0)|(1<<COM2B0)|(1<<COM2B1))
#elif defined(PWM_2B_ENABLE)
	#define _PWM_DDRD_2_SET ((1<<PORTD3))	//OC2B
	#define _PWM_DDRB_2_SET (0)
	#define _PWM_TCCR2A_SET ((1<<COM2B1)|(1<<WGM20)|(1<<WGM21))
	#define _PWM_TCCR2A_CLR ((1<<COM2A0)|(1<<COM2B0)|(1<<COM2A1))
#endif

#if defined(PWM_2A_ENABLE) || defined(PWM_2B_ENABLE)
	#define _PWM_2_INIT() {\
		DDRD |= _PWM_DDRD_2_SET;\
		DDRB |= _PWM_DDRB_2_SET;\
		TCCR2A |= _PWM_TCCR2A_SET;\
		TCCR2A &= ~_PWM_TCCR2A_CLR;\
		TCCR2B |= (1<<CS20);\
		TCCR2B &= ~((1<<CS22)|(1<<CS21));\
	}
#else
	#define _PWM_2_INIT() {}
#endif



/* PWM OC1A & OC1B */
#if defined(PWM_1A_ENABLE) && defined(PWM_1B_ENABLE)
	#define _PWM_DDRB_1_SET ((1<<PORTB1)|(1<<PORTB2))
	#define _PWM_TCCR1A_SET ((1<<COM1A1)|(1<<COM1B1)|(1<<WGM10)|(1<<WGM11))
	#define _PWM_TCCR1A_CLR ((1<<COM1A0)|(1<<COM1B0))
#elif defined(PWM_1A_ENABLE)
	#define _PWM_DDRB_1_SET ((1<<PORTB1))	//OC1A
	#define _PWM_TCCR1A_SET ((1<<COM1A1)|(1<<WGM10)|(1<<WGM11))
	#define _PWM_TCCR1A_CLR ((1<<COM1A0)|(1<<COM1B0)|(1<<COM1B1))
#elif defined(PWM_1B_ENABLE)
	#define _PWM_DDRB_1_SET ((1<<PORTB2))	//OC1B
	#define _PWM_TCCR1A_SET ((1<<COM1B1)|(1<<WGM10)|(1<<WGM11))
	#define _PWM_TCCR1A_CLR ((1<<COM1A0)|(1<<COM1B0)|(1<<COM1A1))
#endif

#if defined(PWM_1A_ENABLE) || defined(PWM_1B_ENABLE)
	#define _PWM_1_INIT() {\
		DDRB |= _PWM_DDRB_1_SET;\
		TCCR1A |= _PWM_TCCR1A_SET;\
		TCCR1A &= ~_PWM_TCCR1A_CLR;\
		TCCR1B |= (1<<CS10);\
		TCCR1B &= ~((1<<CS12)|(1<<CS11));\
	}
#else
	#define _PWM_1_INIT() {}
#endif



/*
 * Enable PWM.
 * __PLEASE DEFINE THE PINS YOU ARE GOING TO USE BEFORE YOU INCLUDE THIS FILE__
 * Example:
       #define PWM_0A_ENABLE
       #define PWM_1B_ENABLE
       #include "HAL_PWM.h"
       int main() {
           PWM_Init();
		   PWM_0A(0x32);
		   PWM_1B(0x3FFF);
       }
 */
#define PWM_Init() {\
	_PWM_0_INIT()\
	_PWM_2_INIT()\
	_PWM_1_INIT()\
}

#ifdef PWM_0A_ENABLE
	/* Write PWM value to OC0A (PD6) */
	#define PWM_0A(v) { OCR0A = v; }
#endif
#ifdef PWM_0B_ENABLE
	/* Write PWM value to OC0B (PD5) */
	#define PWM_0B(v) { OCR0B = v; }
#endif
#ifdef PWM_2A_ENABLE
	/* Write PWM value to OC2A (PB3) */
	#define PWM_2A(v) { OCR2A = v; }
#endif
#ifdef PWM_2B_ENABLE
	/* Write PWM value to OC2B (PD3) */
	#define PWM_2B(v) { OCR2B = v; }
#endif
#ifdef PWM_1A_ENABLE
	/* Write PWM value to OC1A (PB1) */
	#define PWM_1A(v) { OCR1A = v; }
#endif
#ifdef PWM_1B_ENABLE
	/* Write PWM value to OC1B (PB2) */
	#define PWM_1B(v) { OCR1B = v; }
#endif

#endif /* HAL_PWM_H_ */