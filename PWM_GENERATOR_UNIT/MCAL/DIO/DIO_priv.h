
#ifndef MCAL_DIO_DIO_PRIV_H_
#define MCAL_DIO_DIO_PRIV_H_
/*
$1B ($3B) PORTA
$1A ($3A) DDRA
$19 ($39) PINA
$18 ($38) PORTB
$17 ($37) DDRB
$16 ($36) PINB
$15 ($35) PORTC
$14 ($34) DDRC
$13 ($33) PINC
$12 ($32) PORTD
$11 ($31) DDRD
$10 ($30) PIND
*/

#define DIO_PORTA_REG       ((volatile u8 *)(0x3b))
#define DIO_PINA_REG        ((volatile u8 *)(0x39))

#define DIO_PORTB_REG       ((volatile u8 *)(0x38))
#define DIO_PINB_REG        ((volatile u8 *)(0x36))

#define DIO_PORTC_REG       ((volatile u8 *)(0x35))
#define DIO_PINC_REG        ((volatile u8 *)(0x33))

#define DIO_PORTD_REG       ((volatile u8 *)(0x32))
#define DIO_PIND_REG        ((volatile u8 *)(0x30))




#endif /* MCAL_DIO_DIO_PRIV_H_ */
