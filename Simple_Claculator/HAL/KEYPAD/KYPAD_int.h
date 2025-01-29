/*
 * KYPAD_int.h
 *
 *  Created on: Sep 11, 2024
 *      Author: Islam Nagi
 */

#ifndef KYPAD_INT_H_
#define KYPAD_INT_H_


#include"../../LIB/StdTypes.h"
#include"../../LIB/errorStatuse.h"

ES_t KYPAD_enuINIT(void);
ES_t KYPAD_enuGetChar(u8 * Copy_pu8Char);
#define KYPAD_ROWS		45
#define KYPAD_Columns		12

#endif /* KYPAD_INT_H_ */
