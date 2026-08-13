/*
 * STM32F030R8T6.c
 *
 *  Created on: Aug 13, 2026
 *      Author: DELL
 */

#include "STM32F030R8T6_gpioxx_drivers.h"


/**
 * @fn      GPIO_PeriClockControl
 * @brief   Enables or disables peripheral clock for the given GPIO port
 *
 * @param   pGPIOx : Base address of the GPIO port
 * @param   EnorDi : ENABLE or DISABLE macros
 */
void GPIO_PeriClockControl(GPIOx_RegDef_t *pGPIOx, uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		if(pGPIOx == GPIOA)      { GPIOA_CLK_EN(); }
		else if(pGPIOx == GPIOB) { GPIOB_CLK_EN(); }
		else if(pGPIOx == GPIOC) { GPIOC_CLK_EN(); }
		else if(pGPIOx == GPIOD) { GPIOD_CLK_EN(); }
		else if(pGPIOx == GPIOF) { GPIOF_CLK_EN(); }
	}
	else
	{
		if(pGPIOx == GPIOA)      { GPIOA_CLK_DIS(); }
		else if(pGPIOx == GPIOB) { GPIOB_CLK_DIS(); }
		else if(pGPIOx == GPIOC) { GPIOC_CLK_DIS(); }
		else if(pGPIOx == GPIOD) { GPIOD_CLK_DIS(); }
		else if(pGPIOx == GPIOF) { GPIOF_CLK_DIS(); }
	}
}
