/*
 * KYPAD_Config.h
 *
 *  Created on: Sep 11, 2024
 *      Author: Islam Nagi
 */

#ifndef KYPAD_CONFIG_H_
#define KYPAD_CONFIG_H_

#include"../../LIB/StdTypes.h"
#include"../../LIB/errorStatuse.h"
#include"../../MCAL/DIO/DIO_int.h"
#include"KYPAD_int.h"

#define INPUT_SOURCE		KYPAD_Columns

#define COL1_PORTID		    DIO_u8PORTC
#define COL1_PINID			DIO_u8PIN0
#define COL2_PORTID			DIO_u8PORTC
#define COL2_PINID		    DIO_u8PIN1
#define COL3_PORTID		    DIO_u8PORTC
#define COL3_PINID			DIO_u8PIN2
#define COL4_PORTID			DIO_u8PORTC
#define COL4_PINID		    DIO_u8PIN3

#define ROW1_PORTID		    DIO_u8PORTC
#define ROW1_PINID			DIO_u8PIN4
#define ROW2_PORTID			DIO_u8PORTC
#define ROW2_PINID		    DIO_u8PIN5
#define ROW3_PORTID		    DIO_u8PORTC
#define ROW3_PINID			DIO_u8PIN6
#define ROW4_PORTID			DIO_u8PORTC
#define ROW4_PINID		    DIO_u8PIN7
#endif /* KYPAD_CONFIG_H_ */
