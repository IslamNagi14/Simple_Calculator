/*
 * main.c
 *
 *  Created on: Sep 11, 2024
 *      Author: Islam Nagi
 */


#include"../LIB/StdTypes.h"
#include"../LIB/errorStatuse.h"
#include"../MCAL/DIO/DIO_int.h"
#include"../HAL/LCD/LCD_Config.h"
#include"../HAL/LCD/LCD_int.h"
#include"../HAL/KEYPAD/KYPAD_int.h"
#include"../HAL/KEYPAD/KYPAD_Config.h"
#include"CALC_int.h"
#include<util/delay.h>

int main()
{
	LCD_enuINIT();
	KYPAD_enuINIT();
	LCD_enuSetCurser(4,1);
	LCD_enuDispString("Welcome");
	_delay_ms(200);
	LCD_enuDispString(".");
	_delay_ms(200);
	LCD_enuDispString(".");
	_delay_ms(200);
	LCD_enuDispString(".");
	_delay_ms(1000);
	LCD_enuClearLCD();
	LCD_enuSetCurser(1,1);
		u8 infix[100], postfix[100],Char,Local_u8Iterator = 0;

		while(1)
		{



			KYPAD_enuGetChar(&Char);
			if(0xff != Char && '=' != Char && 'O' != Char)
			{

				LCD_enuDispChar(Char);
				infix[Local_u8Iterator++] = Char;
			}
			infix[Local_u8Iterator] ='\0';
			if('=' == Char)
			{
				// Convert infix to postfix
			    CALC_VidInToPost(infix, postfix);
			    f64 result = CALC_f64Evaluation(postfix);
			    if(0xffff != result)
			       Print_vidResult(result);
			   else
			   {
				   LCD_enuClearLCD();
				   LCD_enuSetCurser(1,1);
				   LCD_enuDispString("Math ERROR");
				   while('O'!=Char)
				   {
					   KYPAD_enuGetChar(&Char);
				   }
			   }

			}
			if('O' == Char)
			{
				LCD_enuClearLCD();
				LCD_enuSetCurser(1,1);
				Local_u8Iterator = 0;

			}



		}


    return 0;
}







/*



  u8 c [] = "wlcome";

		 LCD_enuDispINTNumber(95915);
		 _delay_ms(1000);
		 while(1)
		 {
			 LCD_enuClearLCD();
			 LCD_enuSetCurser(5,1);
			 LCD_enuDispString(c);
			 _delay_ms(1000);
		 }


 */

