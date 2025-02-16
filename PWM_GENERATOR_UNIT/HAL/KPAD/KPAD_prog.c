#include "../../Service/STD_types.h"
#include "../../Service/bit_math.h"
#include "../../MCAl/DIO/DIO_int.h"
#include "KPAD_config.h"
#include "KPAD_int.h"

u8 KPAD_COL_arr[KPAD_U8_COL_SIZE]= {KPAD_U8_COL_PIN0,KPAD_U8_COL_PIN1,KPAD_U8_COL_PIN2,KPAD_U8_COL_PIN3};
u8 KPAD_ROW_arr[KPAD_U8_ROW_SIZE]= {KPAD_U8_ROW_PIN0,KPAD_U8_ROW_PIN1,KPAD_U8_ROW_PIN2,KPAD_U8_ROW_PIN3};



void KPAD_voidGetKeyPressed(u8 * Copy_u8RowIndex , u8* Copy_u8ColIndex){
	*Copy_u8ColIndex =0xff;
	*Copy_u8RowIndex =0xff;
	u8 Local_u8RowCounter ,Local_u8ColCounter ;
	for(Local_u8ColCounter = 0 ; Local_u8ColCounter< KPAD_U8_COL_SIZE ; Local_u8ColCounter++)
	{
		DIO_voidSetPinVlaue(KPAD_U8_COL_PORT,KPAD_COL_arr[Local_u8ColCounter],DIO_PIN_LOW);
		for(Local_u8RowCounter = 0 ; Local_u8RowCounter < KPAD_U8_ROW_SIZE ; Local_u8RowCounter++){

			if (DIO_u8GetPinValue(KPAD_U8_ROW_PORT,KPAD_ROW_arr[Local_u8RowCounter]) == DIO_PIN_LOW)
			{
				while(DIO_u8GetPinValue(KPAD_U8_ROW_PORT,KPAD_ROW_arr[Local_u8RowCounter]) == DIO_PIN_LOW)
				*Copy_u8ColIndex = Local_u8ColCounter;
				*Copy_u8RowIndex = Local_u8RowCounter;
				return ;
			}
		}
		DIO_voidSetPinVlaue(KPAD_U8_COL_PORT,KPAD_COL_arr[Local_u8ColCounter],DIO_PIN_HIGH);




	}
}
