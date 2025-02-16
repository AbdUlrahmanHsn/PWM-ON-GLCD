#define F_CPU 16000000UL
#include "HAL/CLCD/CLCD_int.h"
#include "util/delay.h"
#include"Service/STD_types.h"
#include"Service/bit_math.h"
#include"MCAl/DIO/DIO_int.h"
#include"MCAl/PORT/PORT_int.h"
#include"MCAl/GIE/GIE_int.h"
#include"MCAL/TIMER1_ICU/ICU_int.h"
#include"MCAL/TIMER1_ICU/ICU_priv.h"
#include "HAL/GLCD/GLCD_int.h"

//void PWMDrawer_DrawSignal(u16 Signal_Type, f32 Scale_ms);

	static u16 t1 = 0 ;
	static u16 t2 = 0 ;
	static u16 t3 = 0 ;
	static u8 capture_count = 0 ;



void timer1_ICU()
{
			capture_count++;

		if (capture_count == 1)
		{
			ICU_ClearTimerValue();
	        TIMER_voidICUSetTriggerEdge(TIMER_u8_ICP_FALLING_EDGE);
	    }
	    else if (capture_count == 2)
	    {

	        t1 = TIMER_u16GetICR();
	        TIMER_voidICUSetTriggerEdge(TIMER_u8_ICP_RAISING_EDGE);
	    }

	    else if (capture_count == 3)
	    {
	        t2 = TIMER_u16GetICR();
	        TIMER_voidICUSetTriggerEdge(TIMER_u8_ICP_FALLING_EDGE);


	    }
	    else if (capture_count == 4)
	    {
	    	  t3 = TIMER_u16GetICR();
	    	  TIMER_voidICUSetTriggerEdge(TIMER_u8_ICP_RAISING_EDGE);
	    }
}
int main(void)
{
	        u16 period  = 0 ; // t2 - t1;
	        u8	D_Cycle = 0 ; //t3 /( t2 - t1 );
	        f32 freq    = 0 ;
	        f32 TIME_ms = 0 ;
	        u16 prescaler = 1 ; // select prescaler manually until next edit
PORT_voidInit();
GIE_voidEnableGlobalInterrupt();
GLCD_Init();
GLCD_Reset(); //GLCD_ClearDisplay();
//TIMER1_voidInit();
TIMER_voidICUInitEnable();
//TIMER_voidICUEnableInterrupt();
TIMER1_voidSetCallBack_ICI(timer1_ICU);

		while(1)
		{

if(capture_count == 4)
	{
//		De_Init();
//		CLCD_voidSetCursorPosition(0,0);
		period = (t3-t1) ;
		freq =((16000000/prescaler) / period)/1000.000; // div by 1000 for KHz
		TIME_ms = ((float)prescaler/16000) * period ;
		D_Cycle = ((float)(t3-t2)/(period)*100);
		GLCD_GoToLine(0);
		GLCD_String("Freq= ");
		GLCD_SendFloat(freq);
		GLCD_String("KHz");
		GLCD_GoToLine(1);
		GLCD_String("Duty= ");
		GLCD_DisplayInteger(D_Cycle);
		GLCD_String("%");
		GLCD_GoToLine(4);
		GLCD_String("T=");
		GLCD_SendFloat(TIME_ms);
		GLCD_String("ms");
		GLCD_Draw_Pulse(D_Cycle);
		_delay_ms(2000);
		GLCD_ClearDisplay();

		capture_count = 0 ;
	}

		}
		return 0 ;
//	return 0 ;
}


