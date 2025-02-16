
#ifndef HAL_CLCD_CLCD_INT_H_
#define HAL_CLCD_CLCD_INT_H_
#include"../../Service/STD_types.h"

void CLCD_voidInit(void);
void CLCD_voidSendData(u8 Copy_u8Data);
void CLCD_voidSendInstruction(u8 Copy_u8Instruction);
void CLCD_voidSendString(char *);
void CLCD_voidSendNUmber(u32 Copy_u16num);
void CLCD_SendSpecialCharcter(u8 * Copy_buffer , u8 Copy_num , u8  Copy_u8X,u8 Copy_u8y );
void CLCD_voidSetCursorPosition(u8 Copy_u8X , u8 Copy_u8y);
void CLCD_voidClearDisplay();

#endif /* HAL_CLCD_CLCD_INT_H_ */
