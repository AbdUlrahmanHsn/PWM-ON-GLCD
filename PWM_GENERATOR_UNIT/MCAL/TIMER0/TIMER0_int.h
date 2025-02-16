/*
 * TIMER0_int.h
 *
 *  Created on: 20 Sep 2024
 *      Author: AMIT
 */

#ifndef MCAL_TIMER0_TIMER0_INT_H_
#define MCAL_TIMER0_TIMER0_INT_H_

void TIMER0_voidInit();
void TIMER0_voidSetPreloadValue(u8 Copy_u8PreLoad);
void TIMER0_voidSetOCRValue(u8 Copy_u8value);
void TIMER0_voidSetCallBack_COMP(void (*pf)(void));
void TIMER0_voidSetCallBack_OV(void (*pf)(void));
void TIMER0_voidGenPWM(u8 Copy_u8pwm) ;
#endif /* MCAL_TIMER0_TIMER0_INT_H_ */
