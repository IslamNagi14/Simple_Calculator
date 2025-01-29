/*
 * STACK.c
 *
 *  Created on: Jan 26, 2025
 *      Author: Islam Nagi
 */


#include"../../LIB/StdTypes.h"
#include"../../LIB/errorStatuse.h"
#include"STACK.h"



void STACK_VidPushChar(struct CharStack* stack, u8 Copy_u8value)
{
    stack->data[++stack->top] = Copy_u8value;
}


u8 STACK_VidPopChar(struct CharStack* stack)
{
    return stack->data[stack->top--];
}


u8 STACK_u8PeekChar(struct CharStack* stack)
{
    if (stack->top == -1) {
        return '\0';
    }
    return stack->data[stack->top];
}


u32 STACK_u32IsEmptyChar(struct CharStack* stack)
{
    return stack->top == -1;
}





void STACK_VidPushDouble(struct DoubleStack* stack, f64 Copy_f64value)
{
    stack->data[++stack->top] = Copy_f64value;
}


f64 STACK_f64PopDouble(struct DoubleStack* stack)
{
    return stack->data[stack->top--];
}

