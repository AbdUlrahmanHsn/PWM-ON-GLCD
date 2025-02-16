#include "../../Service/STD_types.h"
#include "../../Service/bit_math.h"
#include "PORT_config.h"
#include "PORT_int.h"
#include "PORT_priv.h"


void PORT_voidInit(void)
{
	*(DIO_DDRA_REG) = PORTA_DIR;
	*(DIO_DDRB_REG) = PORTB_DIR;
	*(DIO_DDRC_REG) = PORTC_DIR;
	*(DIO_DDRD_REG) = PORTD_DIR;


	*(DIO_PORTA_REG) = PORTA_INITIAL_VAL;
	*(DIO_PORTB_REG) = PORTB_INITIAL_VAL;
	*(DIO_PORTC_REG) = PORTC_INITIAL_VAL;
	*(DIO_PORTD_REG) = PORTD_INITIAL_VAL;
}
