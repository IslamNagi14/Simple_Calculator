/*
 * CALC_int.h
 *
 *  Created on: Sep 18, 2024
 *      Author: Islam Nagi
 */

#ifndef APP_CALC_INT_H_
#define APP_CALC_INT_H_

#include"../LIB/StdTypes.h"
u8 CALC_u32precedence(u8 Copy_u8op);
u8 CALC_u32isOperator(u8 Copy_u8char);
void CALC_VidInToPost(u8* Copy_Pu8Infix,u8* Copy_Pu8Postfix);
f64 CALC_f64Evaluation(u8* Copy_Pu8Postfix);
void Print_vidResult(f32 Copy_f32Result);

#endif /* APP_CALC_INT_H_ */
