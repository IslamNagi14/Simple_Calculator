/*
 * LCD_Config.h
 *
 *  Created on: Aug 31, 2024
 *      Author: Islam Nagi
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_
#include"../../MCAL/DIO/DIO_int.h"

#define RS_Port			DIO_u8PORTA
#define RS_Pin			DIO_u8PIN0

#define RW_Port         DIO_u8PORTA
#define RW_Pin          DIO_u8PIN1

#define EN_Port         DIO_u8PORTA
#define EN_Pin          DIO_u8PIN2

#define DB0_Port        DIO_u8PORTB
#define DB0_Pin         DIO_u8PIN0
#define DB1_Port        DIO_u8PORTB
#define DB1_Pin         DIO_u8PIN1
#define DB2_Port        DIO_u8PORTB
#define DB2_Pin         DIO_u8PIN2
#define DB3_Port        DIO_u8PORTB
#define DB3_Pin         DIO_u8PIN3
#define DB4_Port        DIO_u8PORTB
#define DB4_Pin         DIO_u8PIN4
#define DB5_Port        DIO_u8PORTB
#define DB5_Pin         DIO_u8PIN5
#define DB6_Port        DIO_u8PORTB
#define DB6_Pin         DIO_u8PIN6
#define DB7_Port        DIO_u8PORTB
#define DB7_Pin         DIO_u8PIN7


#define LCDMODE  EIGHTMODE






#endif /* LCD_CONFIG_H_ */
