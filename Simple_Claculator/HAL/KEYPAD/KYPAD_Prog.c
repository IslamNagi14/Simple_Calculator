/*
 * KYPAD_Prog.c
 *
 *  Created on: Sep 11, 2024
 *      Author: Islam Nagi
 */

#include"../../LIB/StdTypes.h"
#include"../../LIB/errorStatuse.h"
#include"../../MCAL/DIO/DIO_int.h"
#include"KYPAD_Config.h"
#include"KYPAD_Prive.h"

u8 KeyPadPINS[4][4] =
{
		{'7','8','9','/'},
		{'4','5','6','*'},
		{'1','2','3','-'},
		{'O','0','=','+'}

};
ES_t KYPAD_enuINIT(void)
{
	ES_t Local_enuErrorState = ES_NOK;

/*#if INPUT_SOURCE == ROWS
	DIO_enuSetPINDir(ROW1_PORTID,ROW1_PINID,DIO_OUTPUT);
	DIO_enuSetPINDir(ROW2_PORTID,ROW2_PINID,DIO_OUTPUT);
	DIO_enuSetPINDir(ROW3_PORTID,ROW3_PINID,DIO_OUTPUT);
	DIO_enuSetPINDir(ROW4_PORTID,ROW4_PINID,DIO_OUTPUT);
	DIO_enuSetPINVAL(ROW1_PORTID,ROW1_PINID,DIO_HIGH);
	DIO_enuSetPINVAL(ROW2_PORTID,ROW2_PINID,DIO_HIGH);
	DIO_enuSetPINVAL(ROW3_PORTID,ROW3_PINID,DIO_HIGH);
	DIO_enuSetPINVAL(ROW4_PORTID,ROW4_PINID,DIO_HIGH);

	DIO_enuSetPINDir(COL1_PORTID,COL1_PINID,DIO_INPUT);
	DIO_enuSetPINDir(COL2_PORTID,COL2_PINID,DIO_INPUT);
	DIO_enuSetPINDir(COL3_PORTID,COL3_PINID,DIO_INPUT);
	DIO_enuSetPINDir(COL4_PORTID,COL4_PINID,DIO_INPUT);
	DIO_enuSetPINVAL(COL1_PORTID,COL1_PINID,DIO_PULLUP);
	DIO_enuSetPINVAL(COL2_PORTID,COL2_PINID,DIO_PULLUP);
	DIO_enuSetPINVAL(COL3_PORTID,COL3_PINID,DIO_PULLUP);
	DIO_enuSetPINVAL(COL4_PORTID,COL4_PINID,DIO_PULLUP);
*/
//#elif	INPUT_SOURCE == COLUMNS
	DIO_enuSetPINDir(COL1_PORTID,COL1_PINID,DIO_OUTPUT);
	DIO_enuSetPINDir(COL2_PORTID,COL2_PINID,DIO_OUTPUT);
	DIO_enuSetPINDir(COL3_PORTID,COL3_PINID,DIO_OUTPUT);
	DIO_enuSetPINDir(COL4_PORTID,COL4_PINID,DIO_OUTPUT);
	DIO_enuSetPINVAL(COL1_PORTID,COL1_PINID,DIO_HIGH);
	DIO_enuSetPINVAL(COL2_PORTID,COL2_PINID,DIO_HIGH);
	DIO_enuSetPINVAL(COL3_PORTID,COL3_PINID,DIO_HIGH);
	DIO_enuSetPINVAL(COL4_PORTID,COL4_PINID,DIO_HIGH);

	DIO_enuSetPINDir(ROW1_PORTID,ROW1_PINID,DIO_INPUT);
	DIO_enuSetPINDir(ROW2_PORTID,ROW2_PINID,DIO_INPUT);
	DIO_enuSetPINDir(ROW3_PORTID,ROW3_PINID,DIO_INPUT);
	DIO_enuSetPINDir(ROW4_PORTID,ROW4_PINID,DIO_INPUT);
	DIO_enuSetPINVAL(ROW1_PORTID,ROW1_PINID,DIO_PULLUP);
	DIO_enuSetPINVAL(ROW2_PORTID,ROW2_PINID,DIO_PULLUP);
	DIO_enuSetPINVAL(ROW3_PORTID,ROW3_PINID,DIO_PULLUP);
	DIO_enuSetPINVAL(ROW4_PORTID,ROW4_PINID,DIO_PULLUP);

/*#endif*/
	 Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

ES_t KYPAD_enuGetChar(u8 * Copy_pu8Char)
{
	ES_t Local_enuErrorState = ES_NOK;

	u8 Rows_pins[] = {ROW1_PINID,ROW2_PINID,ROW3_PINID,ROW4_PINID};
	u8 Rows_ports[] = {ROW1_PORTID,ROW2_PORTID,ROW3_PORTID,ROW4_PORTID};
	u8 Columns_pins[] = {COL1_PINID,COL2_PINID,COL3_PINID,COL4_PINID};
	u8 Columns_ports[] = {COL1_PORTID,COL2_PORTID,COL3_PORTID,COL4_PORTID};
	u8 Local_u8Rows_iterator = 0;
	u8 Local_u8Columns_iterator = 0;
	u8 Local_u8TempVAR = 0;
	*Copy_pu8Char =0xff;
	for(Local_u8Columns_iterator = 0;Local_u8Columns_iterator <4;Local_u8Columns_iterator++)
	{
		DIO_enuSetPINVAL(Columns_ports[Local_u8Columns_iterator],Columns_pins[Local_u8Columns_iterator],DIO_LOW);

		for(Local_u8Rows_iterator = 0;Local_u8Rows_iterator <4;Local_u8Rows_iterator++)
		{
			DIO_enuGetPINVAL(Rows_ports[Local_u8Rows_iterator],Rows_pins[Local_u8Rows_iterator],&Local_u8TempVAR);
			if(Local_u8TempVAR == DIO_LOW)
			{
				//DIO_enuGetPINVAL(Rows_ports[Local_u8Rows_iterator],Rows_pins[Local_u8Rows_iterator],&Local_u8TempVAR);
				*Copy_pu8Char = KeyPadPINS[Local_u8Columns_iterator][Local_u8Rows_iterator];
				while(Local_u8TempVAR == DIO_LOW)
					DIO_enuGetPINVAL(Rows_ports[Local_u8Rows_iterator],Rows_pins[Local_u8Rows_iterator],&Local_u8TempVAR);
				return Local_enuErrorState;
			}
		}
		DIO_enuSetPINVAL(Columns_ports[Local_u8Columns_iterator],Columns_pins[Local_u8Columns_iterator],DIO_HIGH);
	}

	return Local_enuErrorState;
}








