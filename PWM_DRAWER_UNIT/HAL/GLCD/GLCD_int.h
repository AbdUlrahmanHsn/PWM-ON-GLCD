/*
 * GLCD_int.h
 *
 *  Created on: Jan 29, 2025
 *      Author: AbdUlrahman Hassan
 */

#ifndef HAL_GLCD_GLCD_INT_H_
#define HAL_GLCD_GLCD_INT_H_
#include "GLCD_config.h"
#include "../../Service/STD_types.h"

/************************************************************************/
/*			Function Implementation for Graphical LCD Module			*/
/************************************************************************/

void GLCD_Init(void);// >>
void GLCD_Page_Select(Page_Select page); // >>
void GLCD_SendInstruction(u8 Instruction); // >>
void GLCD_SendData(u8 Data); // >>
void GLCD_Draw_Pulse (u8 Duty);
void GLCD_Reset(void); // >>
void GLCD_SendChar(u8 Data ); // >>
void GLCD_String(u8* Data_Ptr); //>>
void GLCD_SendInteger(s32 Data); // >>
void GLCD_SendFloat(f32 Data); // >>
void GLCD_ClearDisplay(void); //>>
void GLCD_GoToLine(u8 Line); // >>
void GLCD_DisplayPulse(u8 Pulse_char);
void GLCD_SendCharacterPixels(u64 Pattern);
//void Set_Cursor(u8 x, u8 y);

#endif /* HAL_GLCD_GLCD_INT_H_ */
