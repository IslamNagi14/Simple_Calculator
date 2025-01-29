/*
 * LCD_private.h
 *
 *  Created on: Aug 31, 2024
 *      Author: Islam Nagi
 */

#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_
static inline void LCD_VidDOPRVTask(u8 Copy_u8Commnd);
#define EIGHT_BIT		8
#define FOUR_BIT		4
#define SETFUN		    0x38
#define DISPON_OFF		0x0f
#define DISP_CLEAR		0x01
#define ENTRYSET		0x06
#define ROW_1			1
#define ROW_2 	 		2
#define COLWN_1 	 	1
#define COLWN_16 	 	16

#endif /* LCD_PRIVATE_H_ */
