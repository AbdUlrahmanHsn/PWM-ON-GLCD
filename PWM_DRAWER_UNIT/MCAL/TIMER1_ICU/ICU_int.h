/*
 * ICU_int.h
 *
 *  Created on: Feb 7, 2025
 *      Author: ⁄»œ«·—Õ„‰Õ”‰⁄»œ«·Õ„Ì
 */
#include "../../Service/STD_types.h"
#include "../../Service/bit_math.h"

#ifndef MCAL_TIMER1_ICU_ICU_INT_H_
#define MCAL_TIMER1_ICU_ICU_INT_H_

	void TIMER1_voidInit(void) ;
	void TIMER1_voidSetPreload (u16 Copy_u16Preload) ;
	void TIMER1_voidSetICR1 (u16 Copy_u16ICR1) ;
	u16  TIMER1_u16GetTimerCounterValue (void) ;
	void TIMER_voidICUInitEnable(void);
	void   TIMER_voidICUSetTriggerEdge(u8 Copy_u8Edge);
	void TIMER_voidICUEnableInterrupt(void);
	void TIMER_voidICUDisableInterrupt(void);
	u16  TIMER_u16GetICR(void);
	void ICU_ClearTimerValue(void);
	void TIMER1_voidSetCallBack_NM(void (*pf)(void));
	void TIMER1_voidSetCallBack_ICI(void (*pf)(void));
	/******************************************************/
//	void De_Init(void);

#endif /* MCAL_TIMER1_ICU_ICU_INT_H_ */
