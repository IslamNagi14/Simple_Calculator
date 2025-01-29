/*
 * STACK.h
 *
 *  Created on: Jan 26, 2025
 *      Author: Islam Nagi
 */

#ifndef MCAL_STACK_STACK_H_
#define MCAL_STACK_STACK_H_

#include"../../LIB/StdTypes.h"
#include"../../LIB/errorStatuse.h"
#include"../../APP/CALC_Config.h"

struct CharStack
{
    int top;
    char data[MAX_STACK_SIZE];
};


struct DoubleStack
{
    int top;
    double data[MAX_STACK_SIZE];
};


// Function prototypes for character stack
void STACK_VidPushChar(struct CharStack* stack, u8 Copy_u8value);
u8 STACK_VidPopChar(struct CharStack* stack);
u8 STACK_u8PeekChar(struct CharStack* stack);
u32 STACK_u32IsEmptyChar(struct CharStack* stack);






// Function prototypes for double stack
void STACK_VidPushDouble(struct DoubleStack* stack, f64 Copy_f64value);
f64 STACK_f64PopDouble(struct DoubleStack* stack);
#endif /* MCAL_STACK_STACK_H_ */
