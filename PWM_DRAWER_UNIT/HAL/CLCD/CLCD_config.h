
#ifndef HAL_CLCD_CLCD_CONFIG_H_
#define HAL_CLCD_CLCD_CONFIG_H_

// CLCD_U8_4_BIT_MODE
// CLCD_U8_8_BIT_MODE
#define CLCD_U8_MODE               CLCD_U8_8_BIT_MODE
#define CLCD_U8_DATA_PORT          DIO_PORTC
#if CLCD_U8_MODE == CLCD_U8_4_BIT_MODE
#define CLCD_U8_DATA_PIN_0         DIO_PIN4
#define CLCD_U8_DATA_PIN_1         DIO_PIN5
#define CLCD_U8_DATA_PIN_2         DIO_PIN6
#define CLCD_U8_DATA_PIN_3         DIO_PIN7
#endif


#define CLCD_U8_CTRL_PORT          DIO_PORTB

#define CLCD_U8_RS_PIN    		   DIO_PIN0
#define CLCD_U8_RW_PIN    		   DIO_PIN1
#define CLCD_U8_E_PIN    	 	   DIO_PIN2






#endif /* HAL_CLCD_CLCD_CONFIG_H_ */
