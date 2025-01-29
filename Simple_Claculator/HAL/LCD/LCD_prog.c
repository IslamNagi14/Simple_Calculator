/*
 * LCD_prog.c
 *
 *  Created on: Aug 31, 2024
 *      Author: Islam Nagi
 */



#include "../../LIB/StdTypes.h"
#include "../../LIB/errorStatuse.h"


#include"LCD_private.h"
#include"LCD_Config.h"

#include"../../MCAL/DIO/DIO_int.h"

#include<util/delay.h>

static u8 LCD_u8Curser = 0x80;
ES_t LCD_enuINIT(void)
{
	//ES_t Local_enuErrorState = ES_NOK;
	_delay_ms(40);
	DIO_enuSetPINDir(EN_Port,EN_Pin,DIO_OUTPUT);
	DIO_enuSetPINDir(RS_Port,RS_Pin,DIO_OUTPUT);
	DIO_enuSetPINDir(RW_Port,RW_Pin,DIO_OUTPUT);
	DIO_enuSetPINDir(DB4_Port,DB4_Pin,DIO_OUTPUT);
	DIO_enuSetPINDir(DB5_Port,DB5_Pin,DIO_OUTPUT);
	DIO_enuSetPINDir(DB6_Port,DB6_Pin,DIO_OUTPUT);
	DIO_enuSetPINDir(DB7_Port,DB7_Pin,DIO_OUTPUT);

#if LCDMODE == EIGHTMODE
	DIO_enuSetPINDir(DB0_Port,DB0_Pin,DIO_OUTPUT);
	DIO_enuSetPINDir(DB1_Port,DB1_Pin,DIO_OUTPUT);
	DIO_enuSetPINDir(DB2_Port,DB2_Pin,DIO_OUTPUT);
	DIO_enuSetPINDir(DB3_Port,DB3_Pin,DIO_OUTPUT);
#endif
	DIO_enuSetPINVAL(RS_Port,RS_Pin,DIO_LOW);
	LCD_VidDOPRVTask(SETFUN);
	_delay_ms(1);
	LCD_VidDOPRVTask(DISPON_OFF);
		_delay_ms(1);
		LCD_VidDOPRVTask(DISP_CLEAR);
	_delay_ms(1.5);
	LCD_VidDOPRVTask(ENTRYSET);

	return 0;//Local_enuErrorState;
}

static inline void LCD_VidDOPRVTask(u8 Copy_u8Commnd)
{

		DIO_enuSetPINVAL(EN_Port,EN_Pin,DIO_LOW);
		DIO_enuSetPINVAL(RW_Port,RW_Pin,DIO_LOW);
		DIO_enuSetPINVAL(DB4_Port,DB4_Pin,(Copy_u8Commnd>>4)&1);
		DIO_enuSetPINVAL(DB5_Port,DB5_Pin,(Copy_u8Commnd>>5)&1);
		DIO_enuSetPINVAL(DB6_Port,DB6_Pin,(Copy_u8Commnd>>6)&1);
		DIO_enuSetPINVAL(DB7_Port,DB7_Pin,(Copy_u8Commnd>>7)&1);
		DIO_enuSetPINVAL(DB0_Port,DB0_Pin,(Copy_u8Commnd>>0)&1);
		DIO_enuSetPINVAL(DB1_Port,DB1_Pin,(Copy_u8Commnd>>1)&1);
		DIO_enuSetPINVAL(DB2_Port,DB2_Pin,(Copy_u8Commnd>>2)&1);
		DIO_enuSetPINVAL(DB3_Port,DB3_Pin,(Copy_u8Commnd>>3)&1);
		DIO_enuSetPINVAL(EN_Port,EN_Pin,DIO_HIGH);
		_delay_ms(10);
		DIO_enuSetPINVAL(EN_Port,EN_Pin,DIO_LOW);


}


ES_t LCD_enuSndComnd(u8 Copy_u8Commnd)
{
	ES_t Local_enuErrorState = ES_NOK;
	DIO_enuSetPINVAL(EN_Port,EN_Pin,DIO_LOW);
	DIO_enuSetPINVAL(RS_Port,RS_Pin,DIO_LOW);
	DIO_enuSetPINVAL(RW_Port,RW_Pin,DIO_LOW);
	DIO_enuSetPINVAL(DB4_Port,DB4_Pin,(Copy_u8Commnd>>4)&1);
	DIO_enuSetPINVAL(DB5_Port,DB5_Pin,(Copy_u8Commnd>>5)&1);
	DIO_enuSetPINVAL(DB6_Port,DB6_Pin,(Copy_u8Commnd>>6)&1);
	DIO_enuSetPINVAL(DB7_Port,DB7_Pin,(Copy_u8Commnd>>7)&1);
	DIO_enuSetPINVAL(DB0_Port,DB0_Pin,(Copy_u8Commnd>>0)&1);
	DIO_enuSetPINVAL(DB1_Port,DB1_Pin,(Copy_u8Commnd>>1)&1);
	DIO_enuSetPINVAL(DB2_Port,DB2_Pin,(Copy_u8Commnd>>2)&1);
	DIO_enuSetPINVAL(DB3_Port,DB3_Pin,(Copy_u8Commnd>>3)&1);
	DIO_enuSetPINVAL(EN_Port,EN_Pin,DIO_HIGH);
	_delay_ms(10);
	DIO_enuSetPINVAL(EN_Port,EN_Pin,DIO_LOW);


	return Local_enuErrorState;
}

ES_t LCD_enuWriteFrmRI8toLFT(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	DIO_enuSetPINVAL(EN_Port,EN_Pin,DIO_LOW);
	DIO_enuSetPINVAL(RS_Port,RS_Pin,DIO_LOW);
	DIO_enuSetPINVAL(RW_Port,RW_Pin,DIO_LOW);
	DIO_enuSetPINVAL(DB0_Port,DB0_Pin,DIO_LOW);
	DIO_enuSetPINVAL(DB1_Port,DB1_Pin,DIO_LOW);
	DIO_enuSetPINVAL(DB2_Port,DB2_Pin,DIO_HIGH);
	DIO_enuSetPINVAL(DB3_Port,DB3_Pin,DIO_LOW);
	DIO_enuSetPINVAL(DB4_Port,DB4_Pin,DIO_LOW);
	DIO_enuSetPINVAL(DB5_Port,DB5_Pin,DIO_LOW);
	DIO_enuSetPINVAL(DB6_Port,DB6_Pin,DIO_LOW);
	DIO_enuSetPINVAL(DB7_Port,DB7_Pin,DIO_LOW);

	DIO_enuSetPINVAL(EN_Port,EN_Pin,DIO_HIGH);
	_delay_ms(10);
	DIO_enuSetPINVAL(EN_Port,EN_Pin,DIO_LOW);


	return Local_enuErrorState;
}
ES_t LCD_enuWriteFrmLFTtoRI8(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	DIO_enuSetPINVAL(EN_Port,EN_Pin,DIO_LOW);
	DIO_enuSetPINVAL(RS_Port,RS_Pin,DIO_LOW);
	DIO_enuSetPINVAL(RW_Port,RW_Pin,DIO_LOW);
	DIO_enuSetPINVAL(DB0_Port,DB0_Pin,DIO_LOW);
	DIO_enuSetPINVAL(DB1_Port,DB1_Pin,DIO_HIGH);
	DIO_enuSetPINVAL(DB2_Port,DB2_Pin,DIO_HIGH);
	DIO_enuSetPINVAL(DB3_Port,DB3_Pin,DIO_LOW);
	DIO_enuSetPINVAL(DB4_Port,DB4_Pin,DIO_LOW);
	DIO_enuSetPINVAL(DB5_Port,DB5_Pin,DIO_LOW);
	DIO_enuSetPINVAL(DB6_Port,DB6_Pin,DIO_LOW);
	DIO_enuSetPINVAL(DB7_Port,DB7_Pin,DIO_LOW);

	DIO_enuSetPINVAL(EN_Port,EN_Pin,DIO_HIGH);
	_delay_ms(10);
	DIO_enuSetPINVAL(EN_Port,EN_Pin,DIO_LOW);


	return Local_enuErrorState;
}
ES_t LCD_enuCreateLetter(u8 Copy_u8PatternNUM,u8 *Copy_Pu8Character)
{
	ES_t Local_enuErrorState = ES_NOK;
	DIO_enuSetPINVAL(EN_Port,EN_Pin,DIO_LOW);
	DIO_enuSetPINVAL(RS_Port,RS_Pin,DIO_LOW);
	DIO_enuSetPINVAL(RW_Port,RW_Pin,DIO_LOW);
	Copy_u8PatternNUM = 0x40 + 8 * Copy_u8PatternNUM;
	if(Copy_u8PatternNUM > 0x7f)
		Local_enuErrorState = ES_Out_Of_Range;
	DIO_enuSetPINVAL(DB0_Port,DB0_Pin,(Copy_u8PatternNUM>>0)&1);
	DIO_enuSetPINVAL(DB1_Port,DB1_Pin,(Copy_u8PatternNUM>>1)&1);
	DIO_enuSetPINVAL(DB2_Port,DB2_Pin,(Copy_u8PatternNUM>>2)&1);
	DIO_enuSetPINVAL(DB3_Port,DB3_Pin,(Copy_u8PatternNUM>>3)&1);
	DIO_enuSetPINVAL(DB4_Port,DB4_Pin,(Copy_u8PatternNUM>>4)&1);
	DIO_enuSetPINVAL(DB5_Port,DB5_Pin,(Copy_u8PatternNUM>>5)&1);
	DIO_enuSetPINVAL(DB6_Port,DB6_Pin,(Copy_u8PatternNUM>>6)&1);
	DIO_enuSetPINVAL(DB7_Port,DB7_Pin,(Copy_u8PatternNUM>>7)&1);

	DIO_enuSetPINVAL(EN_Port,EN_Pin,DIO_HIGH);
	_delay_ms(10);
	DIO_enuSetPINVAL(EN_Port,EN_Pin,DIO_LOW);
	u8 Local_u8Leteral = 0;
	DIO_enuSetPINVAL(RS_Port,RS_Pin,DIO_HIGH);
	for(Local_u8Leteral = 0; Local_u8Leteral < 8 ;Local_u8Leteral++)
	LCD_VidDOPRVTask(Copy_Pu8Character[Local_u8Leteral]);


	return Local_enuErrorState;
}
ES_t LCD_enuSetCurser(u8 Copy_u8PosX,u8 Copy_u8PosY)
{
	ES_t Local_enuErrorState = ES_NOK;
	DIO_enuSetPINVAL(EN_Port,EN_Pin,DIO_LOW);
	DIO_enuSetPINVAL(RS_Port,RS_Pin,DIO_LOW);
	DIO_enuSetPINVAL(RW_Port,RW_Pin,DIO_LOW);

	if(Copy_u8PosY == ROW_1 && Copy_u8PosX >= COLWN_1 &&Copy_u8PosX <= COLWN_16)
		LCD_u8Curser = 0x80 + Copy_u8PosX - 1;
	else if(Copy_u8PosY == ROW_2 && Copy_u8PosX >= COLWN_1 &&Copy_u8PosX <= COLWN_16)
		LCD_u8Curser = 0xC0 + Copy_u8PosX - 1;
	else
		Local_enuErrorState = ES_Out_Of_Range;
	DIO_enuSetPINVAL(DB0_Port,DB0_Pin,(LCD_u8Curser>>0)&1);
	DIO_enuSetPINVAL(DB1_Port,DB1_Pin,(LCD_u8Curser>>1)&1);
	DIO_enuSetPINVAL(DB2_Port,DB2_Pin,(LCD_u8Curser>>2)&1);
	DIO_enuSetPINVAL(DB3_Port,DB3_Pin,(LCD_u8Curser>>3)&1);
	DIO_enuSetPINVAL(DB4_Port,DB4_Pin,(LCD_u8Curser>>4)&1);
	DIO_enuSetPINVAL(DB5_Port,DB5_Pin,(LCD_u8Curser>>5)&1);
	DIO_enuSetPINVAL(DB6_Port,DB6_Pin,(LCD_u8Curser>>6)&1);
	DIO_enuSetPINVAL(DB7_Port,DB7_Pin,(LCD_u8Curser>>7)&1);

	DIO_enuSetPINVAL(EN_Port,EN_Pin,DIO_HIGH);
	_delay_ms(10);
	DIO_enuSetPINVAL(EN_Port,EN_Pin,DIO_LOW);


	return Local_enuErrorState;
}
ES_t LCD_enuClearLCD(void)
{
	ES_t Local_enuErrorState = ES_NOK;
		DIO_enuSetPINVAL(EN_Port,EN_Pin,DIO_LOW);
		DIO_enuSetPINVAL(RS_Port,RS_Pin,DIO_LOW);
		DIO_enuSetPINVAL(RW_Port,RW_Pin,DIO_LOW);
		DIO_enuSetPINVAL(DB0_Port,DB0_Pin,DIO_HIGH);
		DIO_enuSetPINVAL(DB1_Port,DB1_Pin,DIO_LOW);
		DIO_enuSetPINVAL(DB2_Port,DB2_Pin,DIO_LOW);
		DIO_enuSetPINVAL(DB3_Port,DB3_Pin,DIO_LOW);
		DIO_enuSetPINVAL(DB4_Port,DB4_Pin,DIO_LOW);
		DIO_enuSetPINVAL(DB5_Port,DB5_Pin,DIO_LOW);
		DIO_enuSetPINVAL(DB6_Port,DB6_Pin,DIO_LOW);
		DIO_enuSetPINVAL(DB7_Port,DB7_Pin,DIO_LOW);

		DIO_enuSetPINVAL(EN_Port,EN_Pin,DIO_HIGH);
		_delay_ms(10);
		DIO_enuSetPINVAL(EN_Port,EN_Pin,DIO_LOW);


		return Local_enuErrorState;
}
ES_t LCD_enuDispChar(u8 Copy_u8Char)
{
	ES_t Local_enuErrorState = ES_NOK;

	DIO_enuSetPINVAL(EN_Port,EN_Pin,DIO_LOW);
		DIO_enuSetPINVAL(RS_Port,RS_Pin,DIO_LOW);
		DIO_enuSetPINVAL(RW_Port,RW_Pin,DIO_LOW);


		if(LCD_u8Curser >0x8F && LCD_u8Curser < 0xC0)
			LCD_u8Curser = 0xC0;
		else if(LCD_u8Curser >0xCF && LCD_u8Curser <0x80)
			LCD_u8Curser = 0x80;
		DIO_enuSetPINVAL(DB0_Port,DB0_Pin,(LCD_u8Curser>>0)&1);
		DIO_enuSetPINVAL(DB1_Port,DB1_Pin,(LCD_u8Curser>>1)&1);
		DIO_enuSetPINVAL(DB2_Port,DB2_Pin,(LCD_u8Curser>>2)&1);
		DIO_enuSetPINVAL(DB3_Port,DB3_Pin,(LCD_u8Curser>>3)&1);
		DIO_enuSetPINVAL(DB4_Port,DB4_Pin,(LCD_u8Curser>>4)&1);
		DIO_enuSetPINVAL(DB5_Port,DB5_Pin,(LCD_u8Curser>>5)&1);
		DIO_enuSetPINVAL(DB6_Port,DB6_Pin,(LCD_u8Curser>>6)&1);
		DIO_enuSetPINVAL(DB7_Port,DB7_Pin,(LCD_u8Curser>>7)&1);

		DIO_enuSetPINVAL(EN_Port,EN_Pin,DIO_HIGH);
		_delay_ms(10);
		DIO_enuSetPINVAL(EN_Port,EN_Pin,DIO_LOW);



	DIO_enuSetPINVAL(RS_Port,RS_Pin,DIO_HIGH);
	LCD_VidDOPRVTask(Copy_u8Char);
	LCD_u8Curser++;
	return Local_enuErrorState;
}

ES_t LCD_enuDispString(u8 * Copy_u8String)
{
	ES_t Local_enuErrorState = ES_NOK;

		DIO_enuSetPINVAL(RS_Port,RS_Pin,DIO_HIGH);
		u8 Local_iterator =0;
		for(Local_iterator =0;Copy_u8String[Local_iterator]!='\0';Local_iterator++)
		{
			LCD_VidDOPRVTask(Copy_u8String[Local_iterator]);
		}
	return Local_enuErrorState;
}

ES_t LCD_enuDispINTNumber(s32  Copy_u8NUM)
{
	ES_t Local_enuErrorState = ES_NOK;
	DIO_enuSetPINVAL(RS_Port,RS_Pin,DIO_HIGH);

	s32 Local_s32Tempvar = 0,Local_s32iterator = 0;

	while(Copy_u8NUM)
	{
		Local_s32Tempvar = (Local_s32Tempvar*10)+(Copy_u8NUM%10);
		if(Copy_u8NUM % 10 == 0 && Local_s32Tempvar == 0)
			Local_s32iterator++;
		Copy_u8NUM/=10;
	}
	while(Local_s32Tempvar)
	{
		switch(Local_s32Tempvar % 10)
		{
		case 0:
			LCD_VidDOPRVTask('0');break;
		case 1:
			LCD_VidDOPRVTask('1');break;
		case 2:
			LCD_VidDOPRVTask('2');break;
		case 3:
			LCD_VidDOPRVTask('3');break;
		case 4:
			LCD_VidDOPRVTask('4');break;
		case 5:
			LCD_VidDOPRVTask('5');break;
		case 6:
			LCD_VidDOPRVTask('6');break;
		case 7:
			LCD_VidDOPRVTask('7');break;
		case 8:
			LCD_VidDOPRVTask('8');break;
		case 9:
			LCD_VidDOPRVTask('9');break;
		}
		Local_s32Tempvar/=10;
	}
	while(Local_s32iterator)
	{
		LCD_VidDOPRVTask('0');
		Local_s32iterator--;
	}


	return Local_enuErrorState;
}

ES_t LCD_enuDispFloatNumber(f32  Copy_f32NUM)
{
	ES_t Local_enuErrorState = ES_NOK;
	LCD_enuDispINTNumber((s32)Copy_f32NUM);
	LCD_enuDispString(".");
	LCD_enuDispINTNumber((s32)((Copy_f32NUM - (s32)Copy_f32NUM)*1000));
	return Local_enuErrorState;
}
