/*
 * LCD_int.h
 *
 *  Created on: Aug 31, 2024
 *      Author: Islam Nagi
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_


#include "../../LIB/StdTypes.h"
#include "../../LIB/errorStatuse.h"

ES_t LCD_enuINIT(void);
ES_t LCD_enuSndComnd(u8 Copy_u8Commnd);
ES_t LCD_enuDispChar(u8 Copy_u8Char);
ES_t LCD_enuDispString(u8 * Copy_u8String);
ES_t LCD_enuClearLCD(void);
ES_t LCD_enuSetCurser(u8 Copy_u8PosX,u8 Copy_u8PosY);
ES_t LCD_enuCreateLetter(u8 Copy_u8PatternNUM,u8 *Copy_Pu8Character);
ES_t LCD_enuWriteFrmLFTtoRI8(void);
ES_t LCD_enuWriteFrmRI8toLFT(void);
ES_t LCD_enuDispINTNumber(s32  Copy_u8NUM);
ES_t LCD_enuDispFloatNumber(f32  Copy_f32NUM);
#endif /* LCD_INT_H_ */
