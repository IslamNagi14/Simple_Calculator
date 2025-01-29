/*
 * CALC_Prog.c
 *
 *  Created on: Sep 18, 2024
 *      Author: Islam Nagi
 */

#include"../LIB/StdTypes.h"
#include"../MCAL/DIO/DIO_int.h"
#include"../HAL/KEYPAD/KYPAD_int.h"
#include"../HAL/LCD/LCD_int.h"
#include"../MCAL/STACK/STACK.h"
#include"CALC_Config.h"
#include<util/delay.h>
#include <ctype.h>



u8 CALC_u32precedence(u8 Copy_u8op)
{
	switch (Copy_u8op)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	default:
		return 0;
	}
}


u8 CALC_u32isOperator(u8 Copy_u8char)
{
	return (Copy_u8char == '+' || Copy_u8char == '-' || Copy_u8char == '*' || Copy_u8char == '/');
}

// Convert infix expression to postfix expression
void CALC_VidInToPost(u8* Copy_Pu8Infix,u8* Copy_Pu8Postfix)
{
	struct CharStack stack;
	stack.top = -1;
	int i = 0, j = 0;

	while (Copy_Pu8Infix[i] != '\0')
	{
		char token = Copy_Pu8Infix[i];

		// Handle negative numbers
		if (token == '-' && (i == 0 || CALC_u32isOperator(Copy_Pu8Infix[i - 1])))
		{

			Copy_Pu8Postfix[j++] = token;
			i++;
			// Read the entire negative number
			while (isdigit(Copy_Pu8Infix[i]) || Copy_Pu8Infix[i] == '.')
			{
				Copy_Pu8Postfix[j++] = Copy_Pu8Infix[i++];
			}
			Copy_Pu8Postfix[j++] = ' '; // Add a space to separate operands
			continue;
		}

		if (isdigit(token) || token == '.')
		{

			while (isdigit(Copy_Pu8Infix[i]) || Copy_Pu8Infix[i] == '.')
			{
				Copy_Pu8Postfix[j++] = Copy_Pu8Infix[i++];
			}
			Copy_Pu8Postfix[j++] = ' '; // Add a space to separate operands
			i--;
		}
		else if (CALC_u32isOperator(token)) 
		{

			while (!STACK_u32IsEmptyChar(&stack) && CALC_u32precedence(STACK_u8PeekChar(&stack)) >= CALC_u32precedence(token))
			{
				Copy_Pu8Postfix[j++] = STACK_VidPopChar(&stack);
				Copy_Pu8Postfix[j++] = ' ';
			}
			STACK_VidPushChar(&stack, token);
		}
		i++;
	}


	while (!STACK_u32IsEmptyChar(&stack))
	{
		Copy_Pu8Postfix[j++] = STACK_VidPopChar(&stack);
		Copy_Pu8Postfix[j++] = ' ';
	}
	Copy_Pu8Postfix[j] = '\0';
}

// Evaluate the postfix expression
f64 CALC_f64Evaluation(u8* Copy_Pu8Postfix)
{
	struct DoubleStack stack;
	stack.top = -1;
	int i = 0;

	while (Copy_Pu8Postfix[i] != '\0') {
		if (isdigit(Copy_Pu8Postfix[i]) || Copy_Pu8Postfix[i] == '.')
		{

			double num = 0;
			int decimal = 0;
			double fraction = 1.0;

			while (isdigit(Copy_Pu8Postfix[i]) || Copy_Pu8Postfix[i] == '.')
			{
				if (Copy_Pu8Postfix[i] == '.')
				{
					decimal = 1;
				}
				else if (decimal)
				{
					fraction /= 10.0;
					num += (Copy_Pu8Postfix[i] - '0') * fraction;
				}
				else
				{
					num = num * 10 + (Copy_Pu8Postfix[i] - '0');
				}
				i++;
			}
			STACK_VidPushDouble(&stack, num);
		}
		else if (Copy_Pu8Postfix[i] == '-')
		{
			// Handle negative numbers
			if (isdigit(Copy_Pu8Postfix[i + 1]))
			{

				i++;
				double num = 0;
				int decimal = 0;
				double fraction = 1.0;

				while (isdigit(Copy_Pu8Postfix[i]) || Copy_Pu8Postfix[i] == '.')
				{
					if (Copy_Pu8Postfix[i] == '.')
					{
						decimal = 1;
					}
					else if (decimal)
					{
						fraction /= 10.0;
						num += (Copy_Pu8Postfix[i] - '0') * fraction;
					}
					else
					{
						num = num * 10 + (Copy_Pu8Postfix[i] - '0');
					}
					i++;
				}
				STACK_VidPushDouble(&stack, -num); // Push the negative number
			}
			else
			{

				double op2 = STACK_f64PopDouble(&stack);
				double op1 = STACK_f64PopDouble(&stack);
				STACK_VidPushDouble(&stack, op1 - op2);
				i++;
			}
		}
		else if (Copy_Pu8Postfix[i] == ' ')
		{

			i++;
		}
		else
		{

			double op2 = STACK_f64PopDouble(&stack);
			double op1 = STACK_f64PopDouble(&stack);
			double result;

			switch (Copy_Pu8Postfix[i])
			{
			case '+':
			result = op1 + op2;
			break;
			case '*':
				result = op1 * op2;
				break;
			case '/':
				if(0 != op2)
					result = op1 / op2;
				else
					return 0xffff;// divided by zero exception
				break;

			}
			STACK_VidPushDouble(&stack, result);
			i++;
		}
	}

	return STACK_f64PopDouble(&stack); // The final result is the only element left in the stack
}



void Print_vidResult(f32 Copy_f32Result)
{
	u8 Local_u8count = 0;s32 Copy_s32Temp = (s32)Copy_f32Result;
	u8 nig_flag = 0;
	if(Copy_f32Result < 0)
	{
		nig_flag++;
		Local_u8count++;
		Copy_f32Result *= -1;
	}
	for(;Copy_s32Temp;)
	{
		Copy_s32Temp/=10;
		Local_u8count++;
	}
	if(Copy_f32Result - (s32)Copy_f32Result)
	{
		Local_u8count += 4;
		LCD_enuSetCurser(17-Local_u8count,2);
		if(nig_flag)
			LCD_enuDispChar('-');
		//LCD_enuDispINTNumber((s32)Copy_f32Result);
		LCD_enuDispFloatNumber(Copy_f32Result);
	}
	else
	{
		LCD_enuSetCurser(17-Local_u8count,2);
		if(nig_flag)
			LCD_enuDispChar('-');
		LCD_enuDispINTNumber((s32)Copy_f32Result);
	}
}

