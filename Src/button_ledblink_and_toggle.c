/*
 * button_ledblink_and_toggle.c
 *
 *  Created on: Aug 14, 2026
 *      Author: DELL
 *
 * Target: STM32F030R8 NUCLEO Board
 * Description: Onboard LED (PA5) control via User Button (PC13).
 *              - 1st Press: Fast blink for 5 seconds, then wait.
 *              - 2nd Press: Toggle LED every 5 seconds continuously.
 *              - 3rd Press: Cycles back to Mode 1.
 */

#include "STM32F030R8T6_gpioxx_drivers.h"

// Software delay (~1 ms at default 8 MHz HSI clock)
void delay_ms(volatile uint32_t ms)
{
    for (volatile uint32_t i = 0; i < (ms * 800UL); i++);
}

int main(void)
{
    // 1. Initialize Onboard LED (PA5)
    GPIO_Handle_t GpioLed = {0};
    GpioLed.pGPIOx = GPIOA;
    GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
    GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
    GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_HIGH;
    GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
    GPIO_Init(&GpioLed);

    // 2. Initialize Onboard Button (PC13)
    GPIO_Handle_t GpioBtn = {0};
    GpioBtn.pGPIOx = GPIOC;
    GpioBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
    GpioBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
    GpioBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_HIGH;
    GpioBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
    GPIO_Init(&GpioBtn);

    // Ensure LED starts OFF
    GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_5, GPIO_PIN_RESET);

    uint8_t mode = 0; // 0 = Idle/Waiting, 1 = 5s Blink, 2 = 5s Toggle

    while (1)
    {
        // --- Mode 0: Initial Idle (Waiting for 1st Press) ---
        if (mode == 0)
        {
            if (GPIO_ReadFromInputPin(GPIOC, GPIO_PIN_NO_13) == GPIO_PIN_RESET)
            {
                delay_ms(50); // Debounce
                if (GPIO_ReadFromInputPin(GPIOC, GPIO_PIN_NO_13) == GPIO_PIN_RESET)
                {
                    while (GPIO_ReadFromInputPin(GPIOC, GPIO_PIN_NO_13) == GPIO_PIN_RESET); // Wait for release
                    mode = 1;
                }
            }
        }

        // --- Mode 1: Fast Blink for 5 Seconds ---
        if (mode == 1)
        {
            // 20 toggles * 250ms = 5000ms (5 seconds total)
            for (int i = 0; i < 20; i++)
            {
                GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_5);
                delay_ms(250);
            }

            // Turn OFF LED when done
            GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_5, GPIO_PIN_RESET);

            // Wait until 2nd button press
            while (mode == 1)
            {
                if (GPIO_ReadFromInputPin(GPIOC, GPIO_PIN_NO_13) == GPIO_PIN_RESET)
                {
                    delay_ms(50);
                    if (GPIO_ReadFromInputPin(GPIOC, GPIO_PIN_NO_13) == GPIO_PIN_RESET)
                    {
                        while (GPIO_ReadFromInputPin(GPIOC, GPIO_PIN_NO_13) == GPIO_PIN_RESET);
                        mode = 2; // Move to Mode 2
                    }
                }
            }
        }

        // --- Mode 2: Toggle LED every 5 Seconds Continuously ---
        if (mode == 2)
        {
            GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_5);

            // Wait 5 seconds (100 * 50ms) while constantly checking for next press
            for (int i = 0; i < 100; i++)
            {
                delay_ms(50);
                if (GPIO_ReadFromInputPin(GPIOC, GPIO_PIN_NO_13) == GPIO_PIN_RESET)
                {
                    delay_ms(50);
                    if (GPIO_ReadFromInputPin(GPIOC, GPIO_PIN_NO_13) == GPIO_PIN_RESET)
                    {
                        while (GPIO_ReadFromInputPin(GPIOC, GPIO_PIN_NO_13) == GPIO_PIN_RESET);
                        mode = 1; // Cycle back to Mode 1
                        break;
                    }
                }
            }
        }
    }
}
