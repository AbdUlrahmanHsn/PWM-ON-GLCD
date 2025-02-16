/*
 * ICU_prog.c
 *
 *  Created on: Feb 7, 2025
 *      Author: ⁄»œ«·—Õ„‰Õ”‰⁄»œ«·Õ„Ì
 */
#include "../../Service/STD_types.h"
#include "../../Service/bit_math.h"
#include "ICU_config.h"
#include "ICU_int.h"
#include "ICU_priv.h"

static void (*TIMER1_Callback_NM)() = NULL;
static void (*TIMER1_Callback_ICI)() = NULL;

void TIMER1_voidInit(void)
{
	/*Set Configurable Modes*/

	#if TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_NORMAL_MODE

		/*Set Waveform generation mode as Normal mode */
			CLR_BIT(TIMER1_TCCR1A_REG,TCCR1A_WGM10);
			CLR_BIT(TIMER1_TCCR1A_REG,TCCR1A_WGM11);
			CLR_BIT(TIMER1_TCCR1B_REG,TCCR1B_WGM12);
			CLR_BIT(TIMER1_TCCR1B_REG,TCCR1B_WGM13);

		/*Set the require Preload Value*/
			TIMER1_TCNT1_REG = TIMER1_PRELOAD_VAL ;

		/*Timer1 Overflow Interrupt Enable*/
			SET_BIT(TIMER1_TIMSK_REG , TIMSK_TOIE1) ;

		/*Set the Required Prescaler	*/
			TIMER1_TCCR1B_REG &= TIMER_PRESCALER_MASK ;
			TIMER1_TCCR1B_REG |= TIMER1_PRESCALER ;
	#else
	#error "Wrong TIMER1_OVERFLOW_INTERRUPT Config"
	#endif

}

void TIMER1_voidSetPreload (u16 Copy_u16Preload)
{
	TIMER1_TCNT1_REG = Copy_u16Preload ;
}

void TIMER1_voidSetICR1 (u16 Copy_u16ICR1)
{
	TIMER1_ICR1_REG = Copy_u16ICR1 ;
}

u16 TIMER1_u16GetTimerCounterValue (void)
{
	return TIMER1_TCNT1_REG ;
}

void TIMER_voidICUInitEnable(void)
{
	TIMER1_voidInit();
	/* Set trigger source as rising edge Initially  */
	#if (TIMER_u8_ICP_INIT_STATE == TIMER_u8_ICP_RAISING_EDGE)
		SET_BIT(TIMER1_TCCR1B_REG,TCCR1B_ICES1);
	#elif(TIMER_u8_ICP_INIT_STATE == TIMER_u8_ICP_FALLING_EDGE)
		CLR_BIT(TIMER1_TCCR1B_REG,TCCR1B_ICES1);
	#endif

	/* Enable Interrupt of ICU */
	SET_BIT(TIMER1_TIMSK_REG,TIMSK_TICIE1);
}

void TIMER_voidICUSetTriggerEdge(u8 Copy_u8Edge) //u8 with boolean massage
{
//	BOOL Local_u8ErrorStatus = true ;

	/* Change The trigger source as Rising edge or Falling edge */
if (Copy_u8Edge == TIMER_u8_ICP_RAISING_EDGE)
{
		SET_BIT(TIMER1_TCCR1B_REG,TCCR1B_ICES1);
}
		else if(Copy_u8Edge == TIMER_u8_ICP_FALLING_EDGE)
		{

		CLR_BIT(TIMER1_TCCR1B_REG,TCCR1B_ICES1);
		}

//		Local_u8ErrorStatus = false ;
//	return Local_u8ErrorStatus;

}

//void TIMER_voidICUEnableInterrupt(void)
//{
//	SET_BIT(TIMSK,TIMSK_TICIE1);
//}

void TIMER_voidICUDisableInterrupt(void)
{
	CLR_BIT(TIMER1_TIMSK_REG,TIMSK_TICIE1);
}

u16 TIMER_u16GetICR(void)
{
	return TIMER1_ICR1_REG;
}

void ICU_ClearTimerValue(void)
{
	TIMER1_TCNT1_REG =0;
}

void TIMER1_voidSetCallBack_NM(void (*pf)(void)){
	TIMER1_Callback_NM = pf ;
}

void TIMER1_voidSetCallBack_ICI(void (*pf)(void)){
	TIMER1_Callback_ICI = pf ;
}

/*TIMER1 Normal Mode ISR*/
void __vector_9 (void)		__attribute__((signal)) ;
void __vector_9 (void)
{
	if (TIMER1_Callback_NM != NULL)
	{
		TIMER1_Callback_NM() ;
	}
}


/*TIMER1 ICU ISR*/
void __vector_6 (void)		__attribute__((signal)) ;
void __vector_6 (void){

	if (TIMER1_Callback_ICI != NULL)
		{
			TIMER1_Callback_ICI() ;
		}
}


//void De_Init(void)
//{
//	TCNT1=0;
//	ICR1=0;
//	TCCR1A=0;
//	TCCR1B=0;
//	CLR_BIT(TIMSK,TIMSK_TICIE1);
//
//}
