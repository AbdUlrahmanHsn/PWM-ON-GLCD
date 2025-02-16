/*
 * GIE_int.h
 *
 *  Created on: 6 Sep 2024
 *      Author: AMIT
 */

#ifndef MCAL_GIE_GIE_INT_H_
#define MCAL_GIE_GIE_INT_H_

#define SREG_REG   *((volatile u8* )(0x5f))
#define GIE_BIT     7
void GIE_voidEnableGlobalInterrupt();
void GIE_voidDisableGlobalInterrupt();

#endif /* MCAL_GIE_GIE_INT_H_ */
