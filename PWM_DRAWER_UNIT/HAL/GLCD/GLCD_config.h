/*
 * GLCD_config.h
 *
 *  Created on: Jan 29, 2025
 *      Author: AbdUlrahman Hassan
 */

#ifndef HAL_GLCD_GLCD_CONFIG_H_
#define HAL_GLCD_GLCD_CONFIG_H_

/************************************************************************/
/*					Graphical LCD Characteristics                       */
/************************************************************************/
#define GLCD_MAX_LINES							8U
#define GLCD_MAX_LINE_PIXEL_WIDTH				128U
#define GLCD_MAX_PAGE_PIXEL_WIDTH				64U
/*************************************************************************
 *                       PORTS Of Commands and Data                       *
 **************************************************************************/

#define PORT_DATA_BUS			DIO_PORTC
#define PORT_COMMAND_BUS 		DIO_PORTD

/*************************************************************************
 *       		          Commonly Used Adresses    					  *
 **************************************************************************/
#define DISPLAY_OFF       0X3E
#define Y_FIRST_ADDRESS   0X40
#define X_FIRST_ADDRESS   0xB8
#define Z_FIRST_ADDRESS   0xC0
#define DISPLAY_ON        0X3F

/*************************************************************************
 *      	 Used To Choose The Page Needed For use on The LCD	         *
 * ************************************************************************/
typedef enum
{
	Left_Page,
	Right_Page,
	both_pages //p1, p0

}Page_Select;

/*************************************************************************
 *              Pins Used For { RS , EN , CS1 , RW , CS2 , RESET }             *
 **************************************************************************/
#define RS_PIN  				DIO_PIN2
#define RW_PIN					DIO_PIN1
#define EN_PIN  				DIO_PIN0
#define LEFT_SEGMENT_PIN 		DIO_PIN4
#define RIGHT_SEGMENT_PIN 		DIO_PIN3
#define RESET_PIN 				DIO_PIN5
#endif /* HAL_GLCD_GLCD_CONFIG_H_ */
