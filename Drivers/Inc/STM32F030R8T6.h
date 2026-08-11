/*
 * STM32F030R8T6.h
 *
 *  Created on: Aug 11, 2026
 *      Author: Sayed Faisal Hashimi
 */

#ifndef INC_STM32F030R8T6_H_
#define INC_STM32F030R8T6_H

#include <stdint.h>

/*
 * Base addresses of Memory
 */
#define FLASH_BASEADDR            0x08000000U
#define SRAM_BASEADDR             0x20000000U
#define SYSTEM_MEMORY_BASEADDR    0x1FFFEC00U

/*
 * Peripheral Bus Base Addresses
 */
#define PERIPH_BASE               0x40000000U
#define APBPERIPH_BASE            PERIPH_BASE
#define AHB1PERIPH_BASE           (PERIPH_BASE + 0x00020000U)
#define AHB2PERIPH_BASE           (PERIPH_BASE + 0x08000000U)

/*
 * AHB2 Peripherals (GPIO Ports)
 */
#define GPIOA_BASE                (AHB2PERIPH_BASE + 0x00000000U)
#define GPIOB_BASE                (AHB2PERIPH_BASE + 0x00000400U)
#define GPIOC_BASE                (AHB2PERIPH_BASE + 0x00000800U)
#define GPIOD_BASE                (AHB2PERIPH_BASE + 0x00000C00U)
#define GPIOF_BASE                (AHB2PERIPH_BASE + 0x00001400U)

/*
 * AHB1 Peripherals
 */
#define RCC_BASE                  (AHB1PERIPH_BASE + 0x00001000U)

/*
 * Base addresses of peripherals hanging on APB bus (PERIPH_BASE = 0x40000000U)
 */

/* Timers */
#define TIM3_BASE                 (APBPERIPH_BASE + 0x00000400U)
#define TIM6_BASE                 (APBPERIPH_BASE + 0x00001000U)
#define TIM7_BASE                 (APBPERIPH_BASE + 0x00001400U)
#define TIM14_BASE                (APBPERIPH_BASE + 0x00002000U)
#define TIM15_BASE                (APBPERIPH_BASE + 0x00014000U)
#define TIM16_BASE                (APBPERIPH_BASE + 0x00014400U)
#define TIM17_BASE                (APBPERIPH_BASE + 0x00014800U)
#define TIM1_BASE                 (APBPERIPH_BASE + 0x00012C00U)

/* Watchdogs & RTC */
#define RTC_BASE                  (APBPERIPH_BASE + 0x00002800U)
#define WWDG_BASE                 (APBPERIPH_BASE + 0x00002C00U)
#define IWDG_BASE                 (APBPERIPH_BASE + 0x00003000U)

/* Communication Interfaces */
#define SPI1_BASE                 (APBPERIPH_BASE + 0x00013000U)
#define SPI2_BASE                 (APBPERIPH_BASE + 0x00003800U)
#define USART1_BASE               (APBPERIPH_BASE + 0x00013800U)
#define USART2_BASE               (APBPERIPH_BASE + 0x00004400U)
#define I2C1_BASE                 (APBPERIPH_BASE + 0x00005400U)
#define I2C2_BASE                 (APBPERIPH_BASE + 0x00005800U)

/* System & Analog */
#define PWR_BASE                  (APBPERIPH_BASE + 0x00007000U)
#define SYSCFG_BASE               (APBPERIPH_BASE + 0x00010000U)
#define EXTI_BASE                 (APBPERIPH_BASE + 0x00010400U)
#define ADC1_BASE                 (APBPERIPH_BASE + 0x00012400U)

#endif /* INC_STM32F030R8T6_H_
