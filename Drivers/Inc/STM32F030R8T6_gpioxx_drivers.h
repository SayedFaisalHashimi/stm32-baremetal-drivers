/*
 * STM32F030R8T6_gpioxx_drivers.h
 *
 *  Created on: Aug 13, 2026
 *      Author: DELL
 */

#ifndef INC_STM32F030R8T6_GPIOXX_DRIVERS_H_
#define INC_STM32F030R8T6_GPIOXX_DRIVERS_H_

#include "STM32F030R8T6.h"



/* Generic Macros */
#define ENABLE 				1
#define DISABLE 			0
#define GPIO_PIN_SET        1
#define GPIO_PIN_RESET      0

/*
 * Configuration structure for a GPIO pin
 */
typedef struct
{
	uint8_t GPIO_PinNumber;			/*!< possible values from @GPIO_PIN_NUMBERS >*/
	uint8_t GPIO_PinMode;			/*!< possible values from @GPIO_PIN_MODES >*/
	uint8_t GPIO_PinSpeed;			/*!< possible values from @GPIO_PIN_SPEED >*/
	uint8_t GPIO_PinPuPdControl;	/*!< possible values from @GPIO_PIN_PUPD >*/
	uint8_t GPIO_PinOPType;			/*!< possible values from @GPIO_PIN_OP_TYPES >*/
	uint8_t GPIO_PinAltFunMode;		/*!< possible values from @GPIO_PIN_ALT_FUN >*/
} GPIO_PinConfig_t;

/*
 * Handle structure for a GPIO pin
 */
typedef struct
{
	GPIOx_RegDef_t *pGPIOx;       		/*!< This holds the base address of the GPIO port to which the pin belongs >*/
	GPIO_PinConfig_t GPIO_PinConfig;   /*!< This holds GPIO pin configuration settings >*/
} GPIO_Handle_t;

/*
 * @GPIO_PIN_NUMBERS
 * GPIO pin numbers
 */
#define GPIO_PIN_NO_0  		0
#define GPIO_PIN_NO_1  		1
#define GPIO_PIN_NO_2  		2
#define GPIO_PIN_NO_3  		3
#define GPIO_PIN_NO_4  		4
#define GPIO_PIN_NO_5  		5
#define GPIO_PIN_NO_6  		6
#define GPIO_PIN_NO_7  		7
#define GPIO_PIN_NO_8  		8
#define GPIO_PIN_NO_9  		9
#define GPIO_PIN_NO_10  	10
#define GPIO_PIN_NO_11 		11
#define GPIO_PIN_NO_12  	12
#define GPIO_PIN_NO_13 		13
#define GPIO_PIN_NO_14 		14
#define GPIO_PIN_NO_15 		15

/*
 * @GPIO_PIN_MODES
 * GPIO pin possible modes
 */
#define GPIO_MODE_IN 		0
#define GPIO_MODE_OUT 		1
#define GPIO_MODE_ALTFN 	2
#define GPIO_MODE_ANALOG 	3

/*
 * @GPIO_PIN_OP_TYPES
 * GPIO pin possible output types
 */
#define GPIO_OP_TYPE_PP   	0
#define GPIO_OP_TYPE_OD   	1

/*
 * @GPIO_PIN_SPEED
 * GPIO pin possible output speeds
 */
#define GPIO_SPEED_LOW			0
#define GPIO_SPEED_MEDIUM		1
#define GPIO_SPEED_HIGH			3

/*
 * @GPIO_PIN_PUPD
 * GPIO pin pull-up/pull-down configuration macros
 */
#define GPIO_NO_PUPD   		0
#define GPIO_PIN_PU			1
#define GPIO_PIN_PD			2

/*
 * @GPIO_PIN_ALT_FUN
 * GPIO alternate function modes
 */
#define GPIO_AF0            0
#define GPIO_AF1            1
#define GPIO_AF2            2
#define GPIO_AF3            3
#define GPIO_AF4            4
#define GPIO_AF5            5
#define GPIO_AF6            6
#define GPIO_AF7            7


#endif /* INC_STM32F030R8T6_GPIOXX_DRIVERS_H_ */
