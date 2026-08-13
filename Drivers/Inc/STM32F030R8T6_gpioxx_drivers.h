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





#endif /* INC_STM32F030R8T6_GPIOXX_DRIVERS_H_ */
