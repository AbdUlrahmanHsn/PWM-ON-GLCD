
#ifndef MCAL_DIO_DIO_INT_H_
#define MCAL_DIO_DIO_INT_H_

void DIO_voidSetPinVlaue    (u8 Copy_u8PortID, u8 Copy_u8PinID , u8 Copy_u8Val);
u8   DIO_u8GetPinValue      (u8 Copy_u8PortID, u8 Copy_u8PinID );
void DIO_voidSetPortVlaue    (u8 Copy_u8PortID, u8 Copy_u8Val);

#define   DIO_PORTA        0
#define   DIO_PORTB        1
#define   DIO_PORTC        2
#define   DIO_PORTD        3

#define  DIO_PIN0      0
#define  DIO_PIN1      1
#define  DIO_PIN2      2
#define  DIO_PIN3      3
#define  DIO_PIN4      4
#define  DIO_PIN5      5
#define  DIO_PIN6      6
#define  DIO_PIN7      7

#define DIO_PIN_OUTPUT     1
#define DIO_PORT_OUTPUT    0xff
#define DIO_PIN_INPUT     0
#define DIO_PORT_INPUT     0x00

#define DIO_PIN_HIGH     1
#define DIO_PORT_HIGH     0xff
#define DIO_PIN_LOW      0
#define DIO_PORT_LOW     0




#endif /* MCAL_DIO_DIO_INT_H_ */
