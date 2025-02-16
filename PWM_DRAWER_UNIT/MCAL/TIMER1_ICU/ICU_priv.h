/*
 * ICU_priv.h
 *
 *  Created on: Feb 7, 2025
 *      Author: ⁄»œ«·—Õ„‰Õ”‰⁄»œ«·Õ„Ì
 */

#ifndef MCAL_TIMER1_ICU_ICU_PRIV_H_
#define MCAL_TIMER1_ICU_ICU_PRIV_H_

	#define TIMER1_TIMSK_REG			*((volatile u8*)0X59)
		#define TIMSK_TOIE0		0
		#define TIMSK_OCIE0		1
		#define TIMSK_TOIE1		2 //needed for ICU
		#define TIMSK_OCIE1B	3
		#define TIMSK_OCIE1A	4
		#define TIMSK_TICIE1	5 //needed for ICU
		#define TIMSK_TOIE2		6
		#define TIMSK_OCIE2		7

/*		not needed for ICU		*/

	#define TIMER1_TIFR_REG			*((volatile u8*)0X58)
		#define TIFR_TOV0		0
		#define TIFR_OCF0		1
		#define TIFR_TOV1		2
		#define TIFR_OCF1B		3
		#define TIFR_OCF1A		4
		#define TIFR_ICF1		5
		#define TIFR_TOV2		6
		#define TIFR_OCV2		7

	#define TIMER1_TCCR1A_REG				*((volatile u8*)0X4F)
		#define TCCR1A_COM1A1		7
		#define TCCR1A_COM1A0		6
		#define TCCR1A_COM1B1		5
		#define TCCR1A_COM1B0		4
		#define TCCR1A_WGM11		1
		#define TCCR1A_WGM10		0

	#define TIMER1_TCCR1B_REG				*((volatile u8*)0X4E)
		#define TCCR1B_ICNC1		7
		#define TCCR1B_ICES1		6
		#define TCCR1B_WGM13		4
		#define TCCR1B_WGM12		3
		#define TIMER0_TCCR1_CS12   2
		#define TIMER0_TCCR1_CS11   1
		#define TIMER0_TCCR1_CS10   0
				#define TIMER_NO_PRESCALER_FACTOR 	                    1
				#define TIMER_DIVISION_FACTOR_8	 	                    2
				#define TIMER_DIVISION_FACTOR_64	                    3
				#define TIMER_DIVISION_FACTOR_256	                    4
				#define TIMER_DIVISION_FACTOR_1024	                    5

	#define TIMER1_TCNT1_REG				*((volatile u16*)0X4C)
		#define TCNT1L          *((volatile u8*)(0x4C))
		#define TCNT1H          *((volatile u8*)(0x4D))

/* not needed for ICU
	#define OCR1AL          *((volatile u8*)(0x4A))
	#define OCR1AH          *((volatile u8*)(0x4B))
	#define OCR1A			*((volatile u16*)0X4A)
	#define OCR1BL          *((volatile u8*)(0x48))
	#define OCR1BH          *((volatile u8*)(0x49))
	#define OCR1B			*((volatile u16*)0X48)
*/

	#define TIMER1_ICR1_REG				*((volatile u16*)0X46)
		#define ICR1H           *((volatile u8*)(0x47))
		#define ICR1L           *((volatile u8*)(0x46))

	#define TIMER1_NORMAL_MODE   					 0

	#define TIMER_u8_ICP_FALLING_EDGE                   0
	#define TIMER_u8_ICP_RAISING_EDGE                   1

	#define DISABLE				 0
	#define ENABLE				 1
	#define FALLING_EDGE		 0
	#define RISING_EDGE			 1


	#define TIMER_PRESCALER_MASK      				 0b11111000


#endif /* MCAL_TIMER1_ICU_ICU_PRIV_H_ */
