/*
 * Prog.c
 *
 *  Created on: Aug 22, 2024
 *      Author: Islam Nagi
 */
#include "../../LIB/StdTypes.h"
#include "../../LIB/errorStatuse.h"
#include "DIO_config.h"
#include "DIO_Private.h"


ES_t DIO_enuInit(void)
{
	ES_t Local_enuErrorStates = ES_NOK;

	DDRA = CONC(PA_PIN7_DIR, PA_PIN6_DIR, PA_PIN5_DIR, PA_PIN4_DIR, PA_PIN3_DIR, PA_PIN2_DIR, PA_PIN1_DIR, PA_PIN0_DIR);

	DDRB = CONC(PB_PIN7_DIR, PB_PIN6_DIR, PB_PIN5_DIR, PB_PIN4_DIR, PB_PIN3_DIR, PB_PIN2_DIR, PB_PIN1_DIR, PB_PIN0_DIR);

	DDRC = CONC(PC_PIN7_DIR, PC_PIN6_DIR, PC_PIN5_DIR, PC_PIN4_DIR, PC_PIN3_DIR, PC_PIN2_DIR, PC_PIN1_DIR, PC_PIN0_DIR);

	DDRD = CONC(PD_PIN7_DIR, PD_PIN6_DIR, PD_PIN5_DIR, PD_PIN4_DIR, PD_PIN3_DIR, PD_PIN2_DIR, PD_PIN1_DIR, PD_PIN0_DIR);

	PORTA = CONC(PA_PIN7_VAL, PA_PIN6_VAL, PA_PIN5_VAL, PA_PIN4_VAL, PA_PIN3_VAL, PA_PIN2_VAL, PA_PIN1_VAL, PA_PIN0_VAL);

	PORTB = CONC(PB_PIN7_VAL, PB_PIN6_VAL, PB_PIN5_VAL, PB_PIN4_VAL, PB_PIN3_VAL, PB_PIN2_VAL, PB_PIN1_VAL, PB_PIN0_VAL);

	PORTC = CONC(PC_PIN7_VAL, PC_PIN6_VAL, PC_PIN5_VAL, PC_PIN4_VAL, PC_PIN3_VAL, PC_PIN2_VAL, PC_PIN1_VAL, PC_PIN0_VAL);

	PORTD = CONC(PD_PIN7_VAL, PD_PIN6_VAL, PD_PIN5_VAL, PD_PIN4_VAL, PD_PIN3_VAL, PD_PIN2_VAL, PD_PIN1_VAL, PD_PIN0_VAL);

	Local_enuErrorStates = ES_OK;
	return Local_enuErrorStates;
}





ES_t DIO_enuSetPortDir(u8 Copy_u8PortID ,u8 Copy_u8PortValue)
{
	ES_t Local_enuErrorStates = ES_NOK;

	if(Copy_u8PortID <= DIO_PORTD)
	{
		switch(Copy_u8PortID)
		{
		case DIO_PORTA:
					DDRA = Copy_u8PortValue;break;
		case DIO_PORTB:
					DDRB = Copy_u8PortValue;break;
		case DIO_PORTC:
					DDRC= Copy_u8PortValue;break;
		case DIO_PORTD:
					DDRD = Copy_u8PortValue;break;
		}
		Local_enuErrorStates = ES_OK;
	}
	else
	{
		Local_enuErrorStates = ES_Out_Of_Range;
	}

	return Local_enuErrorStates;
}
ES_t DIO_enuSetPortVAL(u8 Copy_u8PortID ,u8 Copy_u8PortValue)
{
	ES_t Local_enuErrorStates = ES_NOK;

		if(Copy_u8PortID <= DIO_PORTD)
		{
			switch(Copy_u8PortID)
			{
			case DIO_PORTA:
						PORTA = Copy_u8PortValue;break;
			case DIO_PORTB:
						PORTB = Copy_u8PortValue;break;
			case DIO_PORTC:
						PORTC= Copy_u8PortValue;break;
			case DIO_PORTD:
						PORTD = Copy_u8PortValue;break;
			}
			Local_enuErrorStates = ES_OK;
		}
		else
		{
			Local_enuErrorStates = ES_Out_Of_Range;
		}

		return Local_enuErrorStates;
}
ES_t DIO_enuToggelPort(u8 Copy_u8PortID)
{
	ES_t Local_enuErrorStates = ES_NOK;

	if(Copy_u8PortID <= DIO_PORTD)
			{
				switch(Copy_u8PortID)
				{
				case DIO_PORTA:
							PORTA = ~PORTA ;break;
				case DIO_PORTB:
							PORTB = ~PORTB ;break;
				case DIO_PORTC:
							PORTC = ~PORTC ;break;
				case DIO_PORTD:
							PORTD = ~PORTD ;break;
				}
				Local_enuErrorStates = ES_OK;
			}
			else
			{
				Local_enuErrorStates = ES_Out_Of_Range;
			}
	return Local_enuErrorStates;
}
ES_t DIO_enuGetPortVAL(u8 Copy_u8PortID,u8 * Copy_Pu8Value)
{
	ES_t Local_enuErrorStates = ES_NOK;
	if(Copy_Pu8Value)
	{
		if(Copy_u8PortID <= DIO_PORTD)
		{
			switch(Copy_u8PortID)
			{
				case DIO_PORTA:
					*Copy_Pu8Value = PINA ;break;
				case DIO_PORTB:
					*Copy_Pu8Value = PINB ;break;
				case DIO_PORTC:
					*Copy_Pu8Value = PINC ;break;
				case DIO_PORTD:
					*Copy_Pu8Value = PIND ;break;
			}
			Local_enuErrorStates = ES_OK;
		}
		else
		{
			Local_enuErrorStates = ES_Out_Of_Range;
		}

	}
	else
	{
		 Local_enuErrorStates = ES_NULLPOINTER;
	}

	return Local_enuErrorStates;
}









ES_t DIO_enuSetPINDir(u8 Copy_u8PortID ,u8 Copy_u8PINID,u8 Copy_u8PINVAL)
{
	ES_t Local_enuErrorStates = ES_NOK;
	if(Copy_u8PortID <= DIO_PORTD && Copy_u8PINID <= DIO_PIN7 && Copy_u8PINVAL<=OUTPUT)
	{

			switch(Copy_u8PortID)
			{
				case DIO_PORTA:
							DDRA &= ~(DIO_MASK_BIT<<Copy_u8PINID);
							DDRA |= (Copy_u8PINVAL<<Copy_u8PINID) ;
							break;
				case DIO_PORTB:
							DDRB &= ~(DIO_MASK_BIT<<Copy_u8PINID);
							DDRB |= (Copy_u8PINVAL<<Copy_u8PINID) ;
							break;
				case DIO_PORTC:
							DDRC &= ~(DIO_MASK_BIT<<Copy_u8PINID);
							DDRC |= (Copy_u8PINVAL<<Copy_u8PINID) ;
							break;
				case DIO_PORTD:
							DDRD &= ~(DIO_MASK_BIT<<Copy_u8PINID);
							DDRD |= (Copy_u8PINVAL<<Copy_u8PINID) ;
							break;
			}
			Local_enuErrorStates = ES_OK;
	}
	else
	{
		Local_enuErrorStates = ES_Out_Of_Range;
	}

	return Local_enuErrorStates;
}
ES_t DIO_enuSetPINVAL(u8 Copy_u8PortID ,u8 Copy_u8PINID,u8 Copy_u8PINVAL)
{
	ES_t Local_enuErrorStates = ES_NOK;
	if(Copy_u8PortID <= DIO_PORTD && Copy_u8PINID <= DIO_PIN7 && Copy_u8PINVAL<=OUTPUT)
		{

				switch(Copy_u8PortID)
				{
					case DIO_PORTA:
								PORTA &= ~(DIO_MASK_BIT<<Copy_u8PINID);
								PORTA |= (Copy_u8PINVAL<<Copy_u8PINID) ;
								break;
					case DIO_PORTB:
								PORTB &= ~(DIO_MASK_BIT<<Copy_u8PINID);
								PORTB |= (Copy_u8PINVAL<<Copy_u8PINID) ;
								break;
					case DIO_PORTC:
								PORTC &= ~(DIO_MASK_BIT<<Copy_u8PINID);
								PORTC |= (Copy_u8PINVAL<<Copy_u8PINID) ;
								break;
					case DIO_PORTD:
								PORTD &= ~(DIO_MASK_BIT<<Copy_u8PINID);
								PORTD |= (Copy_u8PINVAL<<Copy_u8PINID) ;
								break;
				}
				Local_enuErrorStates = ES_OK;
		}
		else
		{
			Local_enuErrorStates = ES_Out_Of_Range;
		}

	return Local_enuErrorStates;
}
ES_t DIO_enuToggelPIN(u8 Copy_u8PortID,u8 Copy_u8PINID)
{
	ES_t Local_enuErrorStates = ES_NOK;
	if(Copy_u8PortID <= DIO_PORTD && Copy_u8PINID <= DIO_PIN7)
			{

					switch(Copy_u8PortID)
					{
						case DIO_PORTA:
									PORTA ^=(DIO_MASK_BIT<<Copy_u8PINID);
									break;
						case DIO_PORTB:
									PORTB ^=(DIO_MASK_BIT<<Copy_u8PINID);
									break;
						case DIO_PORTC:
									PORTC ^=(DIO_MASK_BIT<<Copy_u8PINID);
									break;
						case DIO_PORTD:
									PORTD ^=(DIO_MASK_BIT<<Copy_u8PINID);
									break;
					}
					Local_enuErrorStates = ES_OK;
			}
			else
			{
				Local_enuErrorStates = ES_Out_Of_Range;
			}

	return Local_enuErrorStates;
}
ES_t DIO_enuGetPINVAL(u8 Copy_u8PortID,u8 Copy_u8PINID,u8 * Copy_Pu8Value)
{
	ES_t Local_enuErrorStates = ES_NOK;
	if(Copy_Pu8Value)
	{
		if(Copy_u8PortID <= DIO_PORTD && Copy_u8PINID <= DIO_PIN7)
		{

				switch(Copy_u8PortID)
				{
					case DIO_PORTA:
						*Copy_Pu8Value = (PINA>>Copy_u8PINID)&DIO_MASK_BIT;
								break;
					case DIO_PORTB:
						*Copy_Pu8Value = (PINB>>Copy_u8PINID)&DIO_MASK_BIT;
								break;
					case DIO_PORTC:
						*Copy_Pu8Value = (PINC>>Copy_u8PINID)&DIO_MASK_BIT;
								break;
					case DIO_PORTD:
						*Copy_Pu8Value = (PIND>>Copy_u8PINID)&DIO_MASK_BIT;
								break;
				}
				Local_enuErrorStates = ES_OK;
		}
		else
		{
			Local_enuErrorStates = ES_Out_Of_Range;
		}
	}
	else
	{
		Local_enuErrorStates = ES_NULLPOINTER;
	}

	return Local_enuErrorStates;
}
