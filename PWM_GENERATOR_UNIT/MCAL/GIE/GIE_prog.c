#include "../../Service/STD_types.h"
#include "../../Service/bit_math.h"
#include "GIE_int.h"



void GIE_voidEnableGlobalInterrupt(){
	__asm__("SEI");


//	SET_BIT(SREG_REG,GIE_BIT);
}
void GIE_voidDisableGlobalInterrupt(){
	__asm__("CLI");

//	CLR_BIT(SREG_REG,GIE_BIT);
}
