/*
 * config.h
 *
 *  Created on: Aug 22, 2024
 *      Author: Islam Nagi
 */

#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_

#define PA_PIN0_DIR		OUTPUT
#define PA_PIN1_DIR		OUTPUT
#define PA_PIN2_DIR		OUTPUT
#define PA_PIN3_DIR		OUTPUT
#define PA_PIN4_DIR		OUTPUT
#define PA_PIN5_DIR		OUTPUT
#define PA_PIN6_DIR		OUTPUT
#define PA_PIN7_DIR		OUTPUT

#define PB_PIN0_DIR		INPUT
#define PB_PIN1_DIR		OUTPUT
#define PB_PIN2_DIR		OUTPUT
#define PB_PIN3_DIR		INPUT
#define PB_PIN4_DIR		OUTPUT
#define PB_PIN5_DIR		OUTPUT
#define PB_PIN6_DIR		INPUT
#define PB_PIN7_DIR		OUTPUT

#define PC_PIN0_DIR		INPUT
#define PC_PIN1_DIR		OUTPUT
#define PC_PIN2_DIR		OUTPUT
#define PC_PIN3_DIR		INPUT
#define PC_PIN4_DIR		OUTPUT
#define PC_PIN5_DIR		OUTPUT
#define PC_PIN6_DIR		INPUT
#define PC_PIN7_DIR		OUTPUT

#define PD_PIN0_DIR		INPUT
#define PD_PIN1_DIR		OUTPUT
#define PD_PIN2_DIR		OUTPUT
#define PD_PIN3_DIR		INPUT
#define PD_PIN4_DIR		OUTPUT
#define PD_PIN5_DIR		OUTPUT
#define PD_PIN6_DIR		INPUT
#define PD_PIN7_DIR		OUTPUT

#define PA_PIN0_VAL		LOW
#define PA_PIN1_VAL		LOW
#define PA_PIN2_VAL		LOW
#define PA_PIN3_VAL		LOW
#define PA_PIN4_VAL		LOW
#define PA_PIN5_VAL		LOW
#define PA_PIN6_VAL		LOW
#define PA_PIN7_VAL		LOW
/*00111010*/
#define PB_PIN0_VAL		FLOAT
#define PB_PIN1_VAL		HIGH
#define PB_PIN2_VAL		LOW
#define PB_PIN3_VAL		PULLUP
#define PB_PIN4_VAL		HIGH
#define PB_PIN5_VAL		HIGH
#define PB_PIN6_VAL		FLOAT
#define PB_PIN7_VAL		LOW

#define PC_PIN0_VAL		FLOAT
#define PC_PIN1_VAL		HIGH
#define PC_PIN2_VAL		LOW
#define PC_PIN3_VAL		PULLUP
#define PC_PIN4_VAL		HIGH
#define PC_PIN5_VAL		HIGH
#define PC_PIN6_VAL		FLOAT
#define PC_PIN7_VAL		LOW

#define PD_PIN0_VAL		FLOAT
#define PD_PIN1_VAL		HIGH
#define PD_PIN2_VAL		LOW
#define PD_PIN3_VAL		PULLUP
#define PD_PIN4_VAL		HIGH
#define PD_PIN5_VAL		HIGH
#define PD_PIN6_VAL		FLOAT
#define PD_PIN7_VAL		LOW

#endif /* DIO_CONFIG_H_ */
