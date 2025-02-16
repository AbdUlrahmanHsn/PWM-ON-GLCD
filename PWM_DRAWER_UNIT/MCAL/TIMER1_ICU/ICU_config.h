/*
 * ICU_config.h
 *
 *  Created on: Feb 7, 2025
 *      Author: ⁄»œ«·—Õ„‰Õ”‰⁄»œ«·Õ„Ì
 */

#ifndef MCAL_TIMER1_ICU_ICU_CONFIG_H_
#define MCAL_TIMER1_ICU_ICU_CONFIG_H_

/*Timer1 Config*/

	/*Set Timer1 Waveform Generation Mode (ICU)
	 * Choose between
	 * 1. TIMER1_NORMAL_MODE
	 * 2. TIMER1_PWM_8_BIT_MODE
	 * 3. TIMER1_PWM_9_BIT_MODE
	 * 4. TIMER1_PWM_10_BIT_MODE
	 * 5. TIMER1_CTC_OCR1A_MODE
	 * 6. TIMER1_FAST_PWM_8_BIT_MODE
	 * 7. TIMER1_FAST_PWM_9_BIT_MODE
	 * 8. TIMER1_FAST_PWM_10_BIT_MODE
	 * 9. TIMER1_PWM_PHASE_AND_FREQ_CORRECT_ICR1_MODE
	 * 10.TIMER1_PWM_PHASE_AND_FREQ_CORRECT_OCR1A_MODE
	 * 11.TIMER1_PWM_PHASE_CORRECT_ICR1_MODE
	 * 12.TIMER1_PWM_PHASE_CORRECT_OCR1A_MODE
	 * 13.TIMER1_CTC_ICR1_MODE		<--------------------
	 * 14.TIMER1_FAST_PWM_ICR1_MODE
	 * 15.TIMER1_FAST_PWM_OCR1A_MODE
	 */
	#define TIMER1_WAVEFORM_GENERATION_MODE		TIMER1_NORMAL_MODE

	#define TIMER1_PRELOAD_VAL					0

	/*Set the Required Prescaler
	 * Choose between
	 * - TIMER_NO_PRESCALER_FACTOR
	 * - TIMER_DIVISION_FACTOR_8
	 * - TIMER_DIVISION_FACTOR_64
	 * - TIMER_DIVISION_FACTOR_256
	 * - TIMER_DIVISION_FACTOR_1024

	 */
	#define TIMER1_PRESCALER					TIMER_NO_PRESCALER_FACTOR

	/*Set Input Capture Value*/
	#define TIMER1_ICR1_VAL						0

	//#define TIMER1_OCR1B_MODE					TIMER_CLR_ON_CTC_SET_ON_TOP

	/*Set Timer1 Input Capture Noise Canceler
	 * Choose between
	 * 1. DISABLE
	 * 2. ENABLE
	 */
	#define TIMER1_ICR_NOISE_CANCELER			DISABLE

	/*Set Timer1 Input Capture Edge
	 * Choose between
	 * 1. FALLING_EDGE
	 * 2. RISING_EDGE
	 */
	#define TIMER1_ICR_EDGE				RISING_EDGE

	/*Set Timer1 Overflow Interrupt
	 * Choose between
	 * 1. DISABLE
	 * 2. ENABLE
	 */

	#define TIMER1_OVERFLOW_INTERRUPT			DISABLE


	/*Set Timer1 Input Capture Interrupt
	 * Choose between
	 * 1. DISABLE
	 * 2. ENABLE
	 */
	#define TIMER1_ICR_INTERRUPT			DISABLE
#define TIMER_u8_ICP_INIT_STATE      TIMER_u8_ICP_RAISING_EDGE
/***********************************************************************************************/

#endif /* MCAL_TIMER1_ICU_ICU_CONFIG_H_ */
