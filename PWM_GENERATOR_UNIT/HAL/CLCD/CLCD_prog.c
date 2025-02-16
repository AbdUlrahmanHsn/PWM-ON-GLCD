#include "util/delay.h"
#include "../../Service/STD_types.h"
#include "../../Service/bit_math.h"
#include "../../MCAl/DIO/DIO_int.h"
#include "CLCD_priv.h"
#include "CLCD_config.h"
#include "CLCD_int.h"

static void CLCD_SendEnablePulse ()
{
	//	send enable pulse
	DIO_voidSetPinVlaue(CLCD_U8_CTRL_PORT,CLCD_U8_E_PIN , DIO_PIN_HIGH);
	_delay_ms(10);
	DIO_voidSetPinVlaue(CLCD_U8_CTRL_PORT,CLCD_U8_E_PIN , DIO_PIN_LOW);
}
#if CLCD_U8_MODE == CLCD_U8_4_BIT_MODE
static void CLCD_voidSetHalfPort(u8 Copy_data)
{
	DIO_voidSetPinVlaue(CLCD_U8_DATA_PORT,CLCD_U8_DATA_PIN_0,GET_BIT(Copy_data,0));
	DIO_voidSetPinVlaue(CLCD_U8_DATA_PORT,CLCD_U8_DATA_PIN_1,GET_BIT(Copy_data,1));
	DIO_voidSetPinVlaue(CLCD_U8_DATA_PORT,CLCD_U8_DATA_PIN_2,GET_BIT(Copy_data,2));
	DIO_voidSetPinVlaue(CLCD_U8_DATA_PORT,CLCD_U8_DATA_PIN_3,GET_BIT(Copy_data,3));
}
#endif
void CLCD_voidSendData(u8 Copy_u8Data){
	//	clr R/W
	DIO_voidSetPinVlaue(CLCD_U8_CTRL_PORT,CLCD_U8_RW_PIN , DIO_PIN_LOW);
	//	set RS
	DIO_voidSetPinVlaue(CLCD_U8_CTRL_PORT,CLCD_U8_RS_PIN , DIO_PIN_HIGH);
#if CLCD_U8_MODE == CLCD_U8_8_BIT_MODE
	//	data on Data port
	DIO_voidSetPortVlaue(CLCD_U8_DATA_PORT,Copy_u8Data);
	CLCD_SendEnablePulse();
#elif CLCD_U8_MODE == CLCD_U8_4_BIT_MODE
	CLCD_voidSetHalfPort(Copy_u8Data>>4);
	CLCD_SendEnablePulse();
	CLCD_voidSetHalfPort(Copy_u8Data);
	CLCD_SendEnablePulse();
#endif
}
void CLCD_voidSendInstruction(u8 Copy_u8Instruction){

	//	clr R/W
	DIO_voidSetPinVlaue(CLCD_U8_CTRL_PORT,CLCD_U8_RW_PIN , DIO_PIN_LOW);
	//	set RS
	DIO_voidSetPinVlaue(CLCD_U8_CTRL_PORT,CLCD_U8_RS_PIN , DIO_PIN_LOW);

#if CLCD_U8_MODE == CLCD_U8_8_BIT_MODE
	//	data on Data port
	DIO_voidSetPortVlaue(CLCD_U8_DATA_PORT,Copy_u8Instruction);
	CLCD_SendEnablePulse();

#elif CLCD_U8_MODE == CLCD_U8_4_BIT_MODE
	CLCD_voidSetHalfPort(Copy_u8Instruction>>4);
	CLCD_SendEnablePulse();
	CLCD_voidSetHalfPort(Copy_u8Instruction);
	CLCD_SendEnablePulse();
#endif
}

void CLCD_voidInit(void)
{
	//	delay 30 ms
	_delay_ms(40);
#if CLCD_U8_MODE == CLCD_U8_8_BIT_MODE
	//	function set
	CLCD_voidSendInstruction(0b00111000);

#elif CLCD_U8_MODE == CLCD_U8_4_BIT_MODE

	CLCD_voidSetHalfPort(0b0010);
	CLCD_SendEnablePulse();

	CLCD_voidSetHalfPort(0b0010);
	CLCD_SendEnablePulse();

	CLCD_voidSetHalfPort(0b1000);
	CLCD_SendEnablePulse();

#endif
	//	Display on /off
	CLCD_voidSendInstruction(0b00001111);

	//	clear
	CLCD_voidSendInstruction(1);
}



void CLCD_voidSendString(char *str ){
	while(*str != '\0')
		CLCD_voidSendData(*str++);
}
void CLCD_voidSendNUmber(u16 Copy_u16num){
	u16 local_tmp  = 0 ,counter = 0 ;
	if(Copy_u16num == 0 )
	{
		CLCD_voidSendData('0');
		return;
	}else{

		while((Copy_u16num%10) == 0  )
		{
			Copy_u16num/=10;
			counter++;
		}
		while(Copy_u16num>0 )
		{
			local_tmp = local_tmp*10 + Copy_u16num%10;
			Copy_u16num/=10;
		}
		Copy_u16num = local_tmp;
		while(Copy_u16num >0 )
		{
			CLCD_voidSendData(Copy_u16num%10 +'0');
			Copy_u16num/=10;
		}
		for(u8 i = 0 ; i<counter ; i++)
		{
			CLCD_voidSendData('0');

		}
	}
}
void CLCD_voidSetCursorPosition(u8 Copy_u8X , u8 Copy_u8y)
{
	u8 Local_u8address ;

	Local_u8address = Copy_u8X + Copy_u8y * 0x40;
	SET_BIT(Local_u8address,7);
	CLCD_voidSendInstruction(Local_u8address);
}
void CLCD_SendSpecialCharcter(u8 * Copy_buffer , u8 Copy_num , u8  Copy_u8X,u8 Copy_u8y )
{
	u8 Local_u8Address , Local_u8Counter = 0 ;

	Local_u8Address = Copy_num * 8 ;
	SET_BIT(Local_u8Address , 6);
	CLCD_voidSendInstruction(Local_u8Address);

	for(Local_u8Counter = 0 ; Local_u8Counter<8 ; Local_u8Counter++)
	{
		CLCD_voidSendData(Copy_buffer[Local_u8Counter]);
	}

	CLCD_voidSetCursorPosition(Copy_u8X,Copy_u8y);

	CLCD_voidSendData(Copy_num);

}


void CLCD_voidClearDisplay(){
	CLCD_voidSendInstruction(1);
}



