/*
 * HAL_PWM.h
 *
 * Created: 2018/6/3 12:02:35
 *  Author: geneLocated
 */ 


#ifndef HAL_PWM_H_
#define HAL_PWM_H_

#include <avr/io.h>



/* PWM OC0A & OC0B */
#if defined(PWM_0A_ENABLE) && defined(PWM_0B_ENABLE)
	#define _PWM_DDRD_SET ((1<<PORTD6)|(1<<PORTD5))
	#define _PWM_TCCR0A_SET ((1<<COM0A1)|(1<<COM0B1)|(1<<WGM00)|(1<<WGM01))
	#define _PWM_TCCR0A_CLR ((1<<COM0A0)|(1<<COM0B0))
#elif defined(PWM_0A_ENABLE)
	#define _PWM_DDRD_SET ((1<<PORTD6))
	#define _PWM_TCCR0A_SET ((1<<COM0A1)|(1<<WGM00)|(1<<WGM01))
	#define _PWM_TCCR0A_CLR ((1<<COM0A0)|(1<<COM0B0)|(1<<COM0B1))
#elif defined(PWM_0B_ENABLE)
	#define _PWM_DDRD_SET ((1<<PORTD5))
	#define _PWM_TCCR0A_SET ((1<<COM0B1)|(1<<WGM00)|(1<<WGM01))
	#define _PWM_TCCR0A_CLR ((1<<COM0A0)|(1<<COM0B0)|(1<<COM0A1))
#endif

#if defined(PWM_0A_ENABLE) || defined(PWM_0B_ENABLE)
	#define _PWM_0_INIT() {\
		DDRD |= _PWM_DDRD_SET;\
		TCCR0A |= _PWM_TCCR0A_SET;\
		TCCR0A &= ~_PWM_TCCR0A_CLR;\
		TCCR0B |= (1<<CS00);\
		TCCR0B &= ~((1<<CS02)|(1<<CS01));\
	}
#else
	#define _PWM_0_INIT() {}
#endif



#define PWM_Init() {\
	_PWM_0_INIT()\
	_PWM_2_INIT()\
	_PWM_1_INIT()\
}

#define PWM_0A(v) { OCR0A = v; }	/* Write PWM value to OC0A (PD6) */
#define PWM_0B(v) { OCR0B = v; }	/* Write PWM value to OC0B (PD5) */
#define PWM_2A(v) { OCR2A = v; }	/* Write PWM value to OC2A (PB3) */
#define PWM_2B(v) { OCR2B = v; }	/* Write PWM value to OC2B (PD3) */
#define PWM_1A(v) { OCR1A = v; }	/* Write PWM value to OC1A (PB1) */
#define PWM_1B(v) { OCR1B = v; }	/* Write PWM value to OC1B (PB2) */

#endif /* HAL_PWM_H_ */