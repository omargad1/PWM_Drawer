 /******************************************************************************
 *
 * Module: GLCD
 *
 * File Name: glcd.h
 *
 * Description: Header file for the GLCD driver
 *
 * Author: OMAR MOHAMED
 *
 *******************************************************************************/

#ifndef GLCD_H_
#define GLCD_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define GLCD_RS_PORT_ID            PORTB_ID
#define GLCD_RS_PIN_ID              PIN6_ID

#define GLCD_RW_PORT_ID            PORTB_ID
#define GLCD_RW_PIN_ID              PIN7_ID

#define GLCD_E_PORT_ID            PORTB_ID
#define GLCD_E_PIN_ID              PIN0_ID

#define GLCD_RST_PORT_ID            PORTB_ID
#define GLCD_RST_PIN_ID              PIN1_ID

#define GLCD_CS1_PORT_ID            PORTB_ID
#define GLCD_CS1_PIN_ID              PIN4_ID

#define GLCD_CS2_PORT_ID            PORTB_ID
#define GLCD_CS2_PIN_ID              PIN5_ID

#define GLCD_DATA_PORT_ID               PORTA_ID







/*******************************************************************************
 *                     GLCD COMMANDS                                   *
 *******************************************************************************/


#define FontWidth                                    5
#define GLCD_MAX_LINES								 8
#define GLCD_MAX_LINE_PIXEL							128
#define GLCD_MAX_PAGE_PIXEL   					     64

#define GLCD_SET_Y_ADDRESS_PREFIX		       		(0x40U)
#define	GLCD_SET_X_ADDRESS_PREFIX					(0xB8U)
#define	GLCD_SET_Z_ADDRESS_PREFIX					(0xC0U)


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void GLCD_sendcommand(uint8 command);
void GLCD_init(void);
void GLCD_senddata(uint8 data);
void GLCD_DisplaySpecialPattern(uint64 Pattern);
void GLCD_select_page(uint8 page);
void GLCD_String(char line_no,char page, char *str);
void GLCD_line(uint8 line);
void GLCD_number(uint8 line_no,uint8 page,uint16 number);
void GLCD_ClearDisplay(void);
void GLCD_Reset(void);





#endif /* GLCD_H_ */
