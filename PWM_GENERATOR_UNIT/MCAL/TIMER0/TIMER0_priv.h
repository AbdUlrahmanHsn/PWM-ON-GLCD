/*
 * TIMER0_priv.h
 *
 *  Created on: 20 Sep 2024
 *      Author: AMIT
 */

#ifndef MCAL_TIMER0_TIMER0_PRIV_H_
#define MCAL_TIMER0_TIMER0_PRIV_H_

/*
$3C ($5C) OCR0  Timer/Counter0 Output Compare Register 82
$39 ($59) TIMSK OCIE2 TOIE2 TICIE1 OCIE1A OCIE1B TOIE1 OCIE0 TOIE0 82, 112, 130
$38 ($58) TIFR  OCF2 TOV2 ICF1 OCF1A OCF1B TOV1 OCF0 TOV0 83, 112, 130
$33 ($53) TCCR0 FOC0 WGM00 COM01 COM00 WGM01 CS02 CS01 CS00 80
$32 ($52) TCNT0 Timer/Counter0 (8 Bits) 82
*/

#define TIMER0_OCR0_REG        *((volatile u8 *)(0x5C))
#define TIMER0_TCNT0_REG       *((volatile u8 *)(0x52))
/*timer counter control register */
#define TIMER0_TCCR0_REG       *((volatile u8 *)(0x53))
#define TIMER0_TCCR0_CS00        0
#define TIMER0_TCCR0_CS01        1
#define TIMER0_TCCR0_CS02        2
#define TIMER0_TCCR0_WGM01       3
#define TIMER0_TCCR0_COM00       4
#define TIMER0_TCCR0_COM01       5
#define TIMER0_TCCR0_WGM00       6
#define TIMER0_TCCR0_FOC0        7

#define TIMER0_TIMSK_REG       *((volatile u8 *)(0x59))
#define TIMER0_TIMSK_TOIE0     0
#define TIMER0_TIMSK_OCIE0     1


#define TIMER0_TIFR_REG        *((volatile u8 *)(0x58))

#define TIMER0_TIFR_TOV0       0
#define TIMER0_TIFR_OCF0       1

 #define  TIMER0_NO_CLK_SRC           0
 #define  TIMER0_NO_PRESCALER   	  1
 #define  TIMER0_NO_DIV_8			  2
 #define  TIMER0_NO_DIV_64            3
 #define  TIMER0_NO_DIV_256           4
 #define  TIMER0_NO_DIV_1024          5
 #define  TIMER0_EXT_FALLING          6
 #define  TIMER0_EXT_RISING           7


#define TIMER0_PRESCALER_MASK       0b11111000


#define TIMER0_NORMAL_MODE           0
#define TIMER0_CTC_MODE              1
#define TIMER0_FAST_PWM_MODE        2
#define TIMER0_PC_PWM_MODE          3

#if  TIMER0_MODE    ==   TIMER0_CTC_MODE
#define  TIMER0_OC0_DISCONNECTED     0
#define  TIMER0_OC0_TOGGLE_ON_CM     1
#define  TIMER0_OC0_CLR_ON_CM        2
#define  TIMER0_OC0_SET_ON_CM       3
#endif

#if  TIMER0_MODE    ==   TIMER0_FAST_PWM_MODE
#define TIMER0_DISCONNECTED   0
#define TIMER0_NONINVERTING   1
#define TIMER0_INVERTING      2
#endif


#endif /* MCAL_TIMER0_TIMER0_PRIV_H_ */
