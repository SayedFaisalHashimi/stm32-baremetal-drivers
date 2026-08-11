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

#endif /* INC_STM32F030R8T6_H_
