/*
 * STM32F030R8T6_gpioxx_drivers.c
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
 * @fn       GPIO_Init
 * @brief    Initializes the given GPIO pin according to the specified parameters
 *
 * @param    pGPIOHandle : Pointer to the GPIO handle structure
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
    uint32_t temp = 0;
    uint8_t pinNumber = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber;

    // Enable clock for the port just in case it wasn't done prior
    GPIO_PeriClockControl(pGPIOHandle->pGPIOx, ENABLE);

    // =========================================================================
    // STEP 1: Configure the Mode (Normal Mode vs. Interrupt Mode)
    // =========================================================================
    if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG)
    {
        // Non-interrupt mode configuration (Input, Output, AltFn, Analog)
        temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2 * pinNumber));
        pGPIOHandle->pGPIOx->MODER &= ~(0x3 << (2 * pinNumber)); // clearing
        pGPIOHandle->pGPIOx->MODER |= temp; // setting
    }
    else
    {
        // Interrupt mode: Configure base pin mode strictly as Input mode (00)
        pGPIOHandle->pGPIOx->MODER &= ~(0x3 << (2 * pinNumber));

        // =====================================================================
        // STEP 2: Configure the Edge Trigger (Falling, Rising, or Both)
        // =====================================================================
        if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_FT)
        {
            // Configure Falling Trigger Register (FTSR)
            EXTI->FTSR |= (1 << pinNumber);
            EXTI->RTSR &= ~(1 << pinNumber);
        }
        else if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_RT)
        {
            // Configure Rising Trigger Register (RTSR)
            EXTI->RTSR |= (1 << pinNumber);
            EXTI->FTSR &= ~(1 << pinNumber);
        }
        else if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_RFT)
        {
            // Configure both FTSR and RTSR
            EXTI->FTSR |= (1 << pinNumber);
            EXTI->RTSR |= (1 << pinNumber);
        }

        // =====================================================================
        // STEP 3: Enable Interrupt Delivery on Peripheral Side
        // =====================================================================
        // 3a. Select the GPIO Port in SYSCFG EXTI Control Register (EXTICR)
        uint8_t temp1 = pinNumber / 4;
        uint8_t temp2 = pinNumber % 4;
        uint8_t portcode = GPIO_BASEADDR_TO_CODE(pGPIOHandle->pGPIOx);

        SYSCFG_PCLK_EN(); // Enable clock for SYSCFG
        SYSCFG->EXTICR[temp1] &= ~(0xF << (temp2 * 4)); // Clear
        SYSCFG->EXTICR[temp1] |= (portcode << (temp2 * 4)); // Set port

        // 3b. Unmask the interrupt in EXTI Interrupt Mask Register (IMR)
        EXTI->IMR |= (1 << pinNumber);
    }

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


/**
 * @fn      GPIO_ReadFromInputPin
 * @brief   Reads the state of a specific pin
 *
 * @param   pGPIOx : Base address of the GPIO port
 * @param   PinNumber : Pin number to read
 * @return  0 or 1 (State of the pin)
 */
uint8_t GPIO_ReadFromInputPin(GPIOx_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	uint8_t value;
	value = (uint8_t)((pGPIOx->IDR >> PinNumber) & 0x00000001);
	return value;
}

/**
 * @fn      GPIO_ReadFromInputPort
 * @brief   Reads the entire 16-bit input port
 *
 * @param   pGPIOx : Base address of the GPIO port
 * @return  16-bit port value
 */
uint16_t GPIO_ReadFromInputPort(GPIOx_RegDef_t *pGPIOx)
{
	uint16_t value;
	value = (uint16_t)pGPIOx->IDR;
	return value;
}

/**
 * @fn      GPIO_WriteToOutputPin
 * @brief   Writes a value to a specific output pin
 *
 * @param   pGPIOx : Base address of the GPIO port
 * @param   PinNumber : Pin number to write to
 * @param   Value : GPIO_PIN_SET or GPIO_PIN_RESET
 */
void GPIO_WriteToOutputPin(GPIOx_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value)
{
	if(Value == GPIO_PIN_SET)
	{
		// Set the corresponding bit in the Bit Set/Reset Register (BSRR)
		pGPIOx->BSRR = (1 << PinNumber);
	}
	else
	{
		// Set the corresponding bit in the Bit Reset Register (BRR)
		pGPIOx->BRR = (1 << PinNumber);
	}
}


/**
 * @fn      GPIO_WriteToOutputPort
 * @brief   Writes a 16-bit value to the entire output port
 *
 * @param   pGPIOx : Base address of the GPIO port
 * @param   Value : 16-bit value to write
 */
void GPIO_WriteToOutputPort(GPIOx_RegDef_t *pGPIOx, uint16_t Value)
{
	pGPIOx->ODR = Value;
}

/**
 * @fn      GPIO_ToggleOutputPin
 * @brief   Toggles the state of a specific output pin
 *
 * @param   pGPIOx : Base address of the GPIO port
 * @param   PinNumber : Pin number to toggle
 */
void GPIO_ToggleOutputPin(GPIOx_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	pGPIOx->ODR ^= (1 << PinNumber);
}


//STEP 6: Enable Interrupt Reception on IRQ Number (Processor Side)
void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi)
{
    if(EnorDi == ENABLE)
    {
        if(IRQNumber <= 31)
        {
            // Program ISER0 register
            *NVIC_ISER0 |= (1 << IRQNumber);
        }
        else if(IRQNumber >= 32 && IRQNumber < 64)
        {
            // Program ISER1 register
            *NVIC_ISER1 |= (1 << (IRQNumber % 32));
        }
    }
    else
    {
        if(IRQNumber <= 31)
        {
            // Program ICER0 register
            *NVIC_ICER0 |= (1 << IRQNumber);
        }
        else if(IRQNumber >= 32 && IRQNumber < 64)
        {
            // Program ICER1 register
            *NVIC_ICER1 |= (1 << (IRQNumber % 32));
        }
    }
}

// STEP 5: Configure IRQ Priority for the identified IRQ Number
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority)
{
    // Find IPR register index
    uint8_t iprx = IRQNumber / 4;
    uint8_t iprx_section = IRQNumber % 4;

    // Calculate shift value based on implemented priority bits (usually top 4 bits)
    uint8_t shift_amount = (8 * iprx_section) + (8 - NO_PR_BITS_IMPLEMENTED);

    *(NVIC_PR_BASE_ADDR + iprx) &= ~(0xFF << (8 * iprx_section)); // Clear
    *(NVIC_PR_BASE_ADDR + iprx) |= (IRQPriority << shift_amount);  // Set priority
}


// Driver API to clear pending bit in EXTI peripheral
void GPIO_IRQHandling(uint8_t PinNumber)
{
    // Clear EXTI PR register bit by writing 1 to it
    if(EXTI->PR & (1 << PinNumber))
    {
        EXTI->PR |= (1 << PinNumber);
    }
}

