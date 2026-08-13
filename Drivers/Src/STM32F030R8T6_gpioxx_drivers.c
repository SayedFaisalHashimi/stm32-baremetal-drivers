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


/**
 * @fn      GPIO_Init
 * @brief   Initializes the given GPIO pin according to the specified parameters
 *
 * @param   pGPIOHandle : Pointer to the GPIO handle structure
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
	uint32_t temp = 0;
    uint8_t pinNumber = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber;

	// Enable clock for the port just in case it wasn't done prior
	GPIO_PeriClockControl(pGPIOHandle->pGPIOx, ENABLE);

	// 1. Configure the mode of the GPIO pin
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2 * pinNumber));
	pGPIOHandle->pGPIOx->MODER &= ~(0x3 << (2 * pinNumber)); // Clearing
	pGPIOHandle->pGPIOx->MODER |= temp; // Setting

	// 2. Configure the speed
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2 * pinNumber));
	pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x3 << (2 * pinNumber));
	pGPIOHandle->pGPIOx->OSPEEDR |= temp;

	// 3. Configure the pull-up/pull-down settings
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl << (2 * pinNumber));
	pGPIOHandle->pGPIOx->PUPDR &= ~(0x3 << (2 * pinNumber));
	pGPIOHandle->pGPIOx->PUPDR |= temp;

	// 4. Configure the output type
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType << pinNumber);
	pGPIOHandle->pGPIOx->OTYPER &= ~(0x1 << pinNumber);
	pGPIOHandle->pGPIOx->OTYPER |= temp;

	// 5. Configure alternate functionality if applicable
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN)
	{
		uint8_t temp1 = pinNumber / 8; // determines AFR[0] (low) or AFR[1] (high)
		uint8_t temp2 = pinNumber % 8; // determines bit position within AFR

		pGPIOHandle->pGPIOx->AFR[temp1] &= ~(0xF << (4 * temp2));
		pGPIOHandle->pGPIOx->AFR[temp1] |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << (4 * temp2));
	}
}



/**
 * @fn      GPIO_DeInit
 * @brief   De-initializes the GPIO port back to reset state
 *
 * @param   pGPIOx : Base address of the GPIO port
 */
void GPIO_DeInit(GPIOx_RegDef_t *pGPIOx)
{
	if(pGPIOx == GPIOA)
	{
		RCC->AHBRSTR |= (1 << 17);
		RCC->AHBRSTR &= ~(1 << 17);
	}
	else if(pGPIOx == GPIOB)
	{
		RCC->AHBRSTR |= (1 << 18);
		RCC->AHBRSTR &= ~(1 << 18);
	}
	else if(pGPIOx == GPIOC)
	{
		RCC->AHBRSTR |= (1 << 19);
		RCC->AHBRSTR &= ~(1 << 19);
	}
	else if(pGPIOx == GPIOD)
	{
		RCC->AHBRSTR |= (1 << 20);
		RCC->AHBRSTR &= ~(1 << 20);
	}
	else if(pGPIOx == GPIOF)
	{
		RCC->AHBRSTR |= (1 << 22);
		RCC->AHBRSTR &= ~(1 << 22);
	}
}


