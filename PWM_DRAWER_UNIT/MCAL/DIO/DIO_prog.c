#include"../../Service/STD_types.h"
#include"../../Service/bit_math.h"
#include "DIO_int.h"
#include "DIO_priv.h"

u8 * Global_u8PORT_arr[] = {DIO_PORTA_REG , DIO_PORTB_REG ,  DIO_PORTC_REG,DIO_PORTD_REG};
u8 * Global_u8Pin_arr[] = {DIO_PINA_REG , DIO_PINB_REG ,  DIO_PINC_REG,DIO_PIND_REG};

void DIO_voidSetPinVlaue    (u8 Copy_u8PortID, u8 Copy_u8PinID , u8 Copy_u8Val){

		if(Copy_u8PinID <= DIO_PIN7 && Copy_u8PortID < 5)
		{

			if(Copy_u8Val == DIO_PIN_HIGH)
			{
				SET_BIT(*(Global_u8PORT_arr[Copy_u8PortID]) ,Copy_u8PinID );

			}else if(Copy_u8Val == DIO_PIN_LOW)
			{
				CLR_BIT(*(Global_u8PORT_arr[Copy_u8PortID]) ,Copy_u8PinID );
			}
			else{
			}
		}
}

u8   DIO_u8GetPinValue      (u8 Copy_u8PortID, u8 Copy_u8PinID ){
	u8 Local_u8State = 0xff ;
		if(Copy_u8PinID <= DIO_PIN7 && Copy_u8PortID < 5)
		{
			Local_u8State = GET_BIT(*(Global_u8Pin_arr[Copy_u8PortID]),Copy_u8PinID);
		}else{

		}

	return Local_u8State ;
}
void DIO_voidSetPortVlaue    (u8 Copy_u8PortID, u8 Copy_u8Val){
	if( Copy_u8PortID < 5)
	{
		*(Global_u8PORT_arr[Copy_u8PortID]) = Copy_u8Val;
	}else{

	}

}
u8   DIO_u8GetPortValue (u8 Copy_u8PortID)
{
	return * Global_u8Pin_arr[Copy_u8PortID];
}
