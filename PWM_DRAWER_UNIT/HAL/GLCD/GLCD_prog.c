/*
 * GLCD_prog.c
 *
 *  Created on: Jan 29, 2025
 *      Author: AbdUlrahman Hassan
 */

#include "util/delay.h"
#include "../../Service/STD_types.h"
#include "../../Service/bit_math.h"
#include "../../MCAl/DIO/DIO_int.h"
//#include "../../MCAl/PORT/PORT_int.h"
#include "GLCD_config.h"
#include "GLCD_int.h"
#include "GLCD_ASCII.h"

u8 Current_X_Position = 0;
u8 Current_Y_Position = 0;
u8 Current_Half = 0;


void GLCD_SendInstruction(u8 Instruction)
{
		DIO_voidSetPinVlaue(PORT_COMMAND_BUS,RS_PIN,DIO_PIN_LOW); //COMMAND
		DIO_voidSetPinVlaue(PORT_COMMAND_BUS,RW_PIN,DIO_PIN_LOW); //write operation
		DIO_voidSetPortVlaue(PORT_DATA_BUS, Instruction); //send COMMAND
		_delay_us(5);
		DIO_voidSetPinVlaue(PORT_COMMAND_BUS,EN_PIN,DIO_PIN_HIGH); //EN pulse
		_delay_us(5);
		DIO_voidSetPinVlaue(PORT_COMMAND_BUS,EN_PIN,DIO_PIN_LOW); //EN pulse
		_delay_us(5);
}

void GLCD_SendData(u8 Data)
{
		DIO_voidSetPinVlaue(PORT_COMMAND_BUS,RS_PIN,DIO_PIN_HIGH); //DATA
		DIO_voidSetPinVlaue(PORT_COMMAND_BUS,RW_PIN,DIO_PIN_LOW); //write operation
		DIO_voidSetPortVlaue(PORT_DATA_BUS, Data); //send DATA
		_delay_us(5);
		DIO_voidSetPinVlaue(PORT_COMMAND_BUS,EN_PIN,DIO_PIN_HIGH); //EN pulse
		_delay_us(5);
		DIO_voidSetPinVlaue(PORT_COMMAND_BUS,EN_PIN,DIO_PIN_LOW); //EN pulse
		_delay_us(5);
}

void GLCD_Init(void)
{
	/* direction out put (set manually) */
DIO_voidSetPortVlaue(PORT_COMMAND_BUS,DIO_PORT_OUTPUT );
DIO_voidSetPortVlaue(PORT_DATA_BUS,DIO_PORT_OUTPUT );
	/* reset pin == high (inactive) 	*/
	DIO_voidSetPinVlaue(PORT_COMMAND_BUS, RESET_PIN , DIO_PIN_HIGH);
	_delay_ms(20);
GLCD_Page_Select(LEFT_SEGMENT_PIN);
    _delay_ms(10);
    GLCD_SendInstruction(DISPLAY_OFF);
    _delay_ms(10);
	GLCD_SendInstruction(Y_FIRST_ADDRESS);
    _delay_ms(10);
    GLCD_SendInstruction(X_FIRST_ADDRESS);
    _delay_ms(10);
    GLCD_SendInstruction(Z_FIRST_ADDRESS);
    _delay_ms(10);
    GLCD_SendInstruction(DISPLAY_ON);
    _delay_ms(10);
    GLCD_Page_Select(Left_Page);
    Current_Half = 0 ;
}

void GLCD_Page_Select(Page_Select page)
{
	switch (page)
	{
	case Left_Page:
		DIO_voidSetPinVlaue(PORT_COMMAND_BUS,LEFT_SEGMENT_PIN,DIO_PIN_HIGH);
		DIO_voidSetPinVlaue(PORT_COMMAND_BUS,RIGHT_SEGMENT_PIN,DIO_PIN_LOW);
		break;
	case Right_Page:
		DIO_voidSetPinVlaue(PORT_COMMAND_BUS,LEFT_SEGMENT_PIN,DIO_PIN_LOW);
		DIO_voidSetPinVlaue(PORT_COMMAND_BUS,RIGHT_SEGMENT_PIN,DIO_PIN_HIGH);
		break;
	case both_pages:
		DIO_voidSetPinVlaue(PORT_COMMAND_BUS,LEFT_SEGMENT_PIN,DIO_PIN_HIGH);
		DIO_voidSetPinVlaue(PORT_COMMAND_BUS,RIGHT_SEGMENT_PIN,DIO_PIN_HIGH);
		break;
	default :
		DIO_voidSetPinVlaue(PORT_COMMAND_BUS,LEFT_SEGMENT_PIN,DIO_PIN_LOW);
		DIO_voidSetPinVlaue(PORT_COMMAND_BUS,RIGHT_SEGMENT_PIN,DIO_PIN_LOW);
	}
}

void GLCD_Draw_Pulse (u8 Duty)
{
	GLCD_GoToLine(5);
	//put arrow and period
	GLCD_SendCharacterPixels(PWM_DRAWER_GLCD_LEFT_ARROW_HEAD);
		for (u8 a = 0 ; a < 6; a++)
		{
			GLCD_SendCharacterPixels(PWM_DRAWER_GLCD_ARROW_MIDDLE_BODY);
		}
		GLCD_SendCharacterPixels(PWM_DRAWER_GLCD_RIGHT_ARROW_HEAD);

	u8 Pulse_High_Line = (float)Duty / 2.5 ;
		GLCD_GoToLine(6);
//		GLCD_SendData(0);
	//draw pulse shape
//		GLCD_SendData(PWM_DRAWER_GLCD_EDGE);
	for(u8 n = 0 ; n < 3 ; n++)
	{
		GLCD_DisplayPulse(0x7E);
u8 i = 1 ;
		while(i < Pulse_High_Line && i < 40)
		{
			GLCD_DisplayPulse(0x02);
		i++;
		}
		while(i == Pulse_High_Line || i == 40)
		{
			GLCD_DisplayPulse(0x7E);
		i++;
		}
		while(i > Pulse_High_Line && i < 40)
		{
			GLCD_DisplayPulse(0x40);
		i++;

		}
		while(i > 40)
		{
//			GLCD_DisplayPulse(0x7E);
			i  = 1 ;
		}
	}

}

void GLCD_DisplayPulse(u8 Pulse_char)
{
	if ((Current_Half == 0) | (Current_Y_Position < GLCD_MAX_PAGE_PIXEL_WIDTH )) {
		GLCD_SendInstruction(X_FIRST_ADDRESS + Current_X_Position);
		GLCD_SendInstruction(Y_FIRST_ADDRESS + Current_Y_Position);
		GLCD_SendData(Pulse_char);
		Current_Y_Position++;
		if (Current_Y_Position >= GLCD_MAX_PAGE_PIXEL_WIDTH && Current_Half == 0) {
			GLCD_Page_Select(Right_Page);
			Current_Y_Position = 0;
		}
	}
}

void GLCD_SendCharacterPixels(u64 Pattern) {
	for(u8 i = 0; i < 5; i++) {
		GLCD_SendInstruction(X_FIRST_ADDRESS + Current_X_Position);
		GLCD_SendInstruction(Y_FIRST_ADDRESS + Current_Y_Position);
		GLCD_SendData((Pattern>>(i*8U)) & 0x00000000FFUL);
		Current_Y_Position++;
		if (Current_Y_Position >= GLCD_MAX_PAGE_PIXEL_WIDTH && Current_Half == 0) {
			GLCD_Page_Select(Right_Page);
			Current_Y_Position = 0;
		}
	}
}
void GLCD_SendChar(u8 Data) {
	if ((Current_Half == 0) | (Current_Y_Position < GLCD_MAX_PAGE_PIXEL_WIDTH - 7U)) {
		/* Enough space to write character */
		switch (Data) {
			case 'A': case 'a': GLCD_SendCharacterPixels(GLCD_CHAR_A); break;
			case 'F': case 'f': GLCD_SendCharacterPixels(GLCD_CHAR_F); break;
			case 'R': case 'r': GLCD_SendCharacterPixels(GLCD_CHAR_R); break;
			case 'E': case 'e': GLCD_SendCharacterPixels(GLCD_CHAR_E); break;
			case 'Q': case 'q': GLCD_SendCharacterPixels(GLCD_CHAR_Q); break;
			case 'U': case 'u': GLCD_SendCharacterPixels(GLCD_CHAR_U); break;
			case 'N': case 'n': GLCD_SendCharacterPixels(GLCD_CHAR_N); break;
			case 'C': case 'c': GLCD_SendCharacterPixels(GLCD_CHAR_C); break;
			case 'Y': case 'y': GLCD_SendCharacterPixels(GLCD_CHAR_Y); break;
			case 'D': case 'd': GLCD_SendCharacterPixels(GLCD_CHAR_D); break;
			case 'T': case 't': GLCD_SendCharacterPixels(GLCD_CHAR_T); break;
			case 'K': case 'k': GLCD_SendCharacterPixels(GLCD_CHAR_K); break;
			case 'H': case 'h': GLCD_SendCharacterPixels(GLCD_CHAR_H); break;
			case 'Z': case 'z': GLCD_SendCharacterPixels(GLCD_CHAR_Z); break;
			case 'M': case 'm': GLCD_SendCharacterPixels(GLCD_CHAR_M); break;
			case 'S': case 's': GLCD_SendCharacterPixels(GLCD_CHAR_S); break;
			case 'I': case 'i': GLCD_SendCharacterPixels(GLCD_CHAR_I); break;
			case '%': GLCD_SendCharacterPixels(GLCD_CHAR_PERCENT); break;
			case '=': GLCD_SendCharacterPixels(GLCD_CHAR_EQUAL); break;
			case '.': GLCD_SendCharacterPixels(GLCD_CHAR_POINT); break;
			case ' ': GLCD_SendCharacterPixels(GLCD_CHAR_SPACE); break;
			case '-': GLCD_SendCharacterPixels(GLCD_CHAR_NEGATIVE); break;
			case '0': GLCD_SendCharacterPixels(GLCD_CHAR_0); break;
			case '1': GLCD_SendCharacterPixels(GLCD_CHAR_1); break;
			case '2': GLCD_SendCharacterPixels(GLCD_CHAR_2); break;
			case '3': GLCD_SendCharacterPixels(GLCD_CHAR_3); break;
			case '4': GLCD_SendCharacterPixels(GLCD_CHAR_4); break;
			case '5': GLCD_SendCharacterPixels(GLCD_CHAR_5); break;
			case '6': GLCD_SendCharacterPixels(GLCD_CHAR_6); break;
			case '7': GLCD_SendCharacterPixels(GLCD_CHAR_7); break;
			case '8': GLCD_SendCharacterPixels(GLCD_CHAR_8); break;
			case '9': GLCD_SendCharacterPixels(GLCD_CHAR_9); break;
			default: break;
		}
		GLCD_SendInstruction(X_FIRST_ADDRESS + Current_X_Position);
		GLCD_SendInstruction(Y_FIRST_ADDRESS + Current_Y_Position);
		GLCD_SendData(0);
		Current_Y_Position++;
		if (Current_Y_Position >= GLCD_MAX_PAGE_PIXEL_WIDTH && Current_Half == 0) {
			GLCD_Page_Select(Right_Page);
			Current_Y_Position = 0;
		}
	}
}

void GLCD_String(u8* Data_Ptr) {
	while (*Data_Ptr != '\0') {
		GLCD_SendChar(*Data_Ptr);
		Data_Ptr++;
	}
}

void GLCD_DisplayInteger(s32 Data) {
	if (Data < 0) {
		GLCD_SendChar('-');
		Data = -1 * Data;
	}
	u8 u8Local_Digit = 0U;
	u8 str_reversed[5] = "";
	u8* str_ptr = str_reversed;
	do {
		u8Local_Digit = Data%10;
		*str_ptr = (char)(48 + u8Local_Digit); /* 48 is the ASCII code of '0' */
		Data = Data/10;
		str_ptr++;
	} while (Data > 0);
	do {
		str_ptr--;
		GLCD_SendChar(*str_ptr);
	} while (str_ptr != str_reversed);
}

void GLCD_SendFloat(f32 Data) {
	/* Will display only 3 Decimal Places */
	u16 IntegerPart = (u16)Data;
	GLCD_DisplayInteger(IntegerPart);
	GLCD_SendChar('.');
	f32 DecimalPart = (Data - IntegerPart);
	u8 Digit = 0;
	for (u8 i = 0; i < 3; i++) {
		Digit = (u8)(DecimalPart * 10.0);
		GLCD_SendChar((u8)(48+Digit));
		DecimalPart = ((DecimalPart*10.0) - Digit);
	}
}


//void GLCD_String(u8* Data_Ptr) {
//	while (*Data_Ptr != '\0') {
//		GLCD_SendData(*Data_Ptr);
//		Data_Ptr++;
//	}
//}
//
//void GLCD_SendChar(u8 *str)
//{
//	if ((Current_Half == 0) | (Current_Y_Position < GLCD_MAX_PAGE_PIXEL_WIDTH - 7)) {
//
//	u16 i=0;
//	u16 startfont=0,endfont=0;
//	while (*str)
//	{
//		startfont=(*str-32)*5;
//		endfont=startfont + 5;
//		for (i=startfont;i<endfont;i++)
//		{
//			GLCD_SendData(sys5x7[i]);
//
//		GLCD_SendInstruction(X_FIRST_ADDRESS + Current_X_Position);
//		GLCD_SendInstruction(Y_FIRST_ADDRESS + Current_Y_Position);
//		GLCD_SendData(0);
//			Current_Y_Position++;
//			_delay_ms(1);
//		}
//		if (Current_Y_Position >= GLCD_MAX_PAGE_PIXEL_WIDTH &&  == 0)
//				{
//				GLCD_Page_Select(Right_Page);
//					Current_Y_Position= 0;
//				}
//		str++;
//	}
//}
//}
void GLCD_GoToLine(u8 Line)
{
	if (Line < GLCD_MAX_LINES) {
		GLCD_Page_Select(Left_Page);
		Current_X_Position = Line;
		GLCD_SendInstruction(X_FIRST_ADDRESS + Current_X_Position);
		Current_Y_Position = 0;
		GLCD_SendInstruction(Y_FIRST_ADDRESS + Current_Y_Position);
	}
}
void GLCD_ClearDisplay(void)
{
	for (u8 Line = 0; Line < GLCD_MAX_LINES; Line++) {
		GLCD_GoToLine(Line);
		GLCD_Page_Select(both_pages);
		for (u8 i = 0; i < GLCD_MAX_PAGE_PIXEL_WIDTH; i++) {
			GLCD_SendInstruction(Y_FIRST_ADDRESS + i);
			GLCD_SendData(0);
		}
	}
}

void GLCD_Reset(void)
{
		DIO_voidSetPinVlaue(PORT_COMMAND_BUS, RESET_PIN, DIO_PIN_LOW);
		_delay_us(10);

		DIO_voidSetPinVlaue(PORT_COMMAND_BUS, RESET_PIN, DIO_PIN_HIGH);
}

