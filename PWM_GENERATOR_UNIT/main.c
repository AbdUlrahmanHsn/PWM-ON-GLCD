#define F_CPU 16000000UL
#include"Service/STD_types.h"
#include"Service/bit_math.h"
#include"MCAl/DIO/DIO_int.h"
#include"MCAl/PORT/PORT_int.h"
#include"MCAl/GIE/GIE_int.h"
#include"MCAl/TIMER0/TIMER0_int.h"
#include "HAL/CLCD/CLCD_int.h"

int main()
{
//	244 hz
u8 Duty = 65 ;
	PORT_voidInit();
	CLCD_voidInit();
	CLCD_voidClearDisplay();
	TIMER0_voidInit();
	TIMER0_voidGenPWM(Duty);

	CLCD_voidSendString("output is :");
	CLCD_voidSendNUmber(Duty);
	CLCD_voidSendString("%");

	while(1)
	{

	}

	return 0 ;
}
