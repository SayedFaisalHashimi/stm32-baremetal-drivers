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


/*
 * Peripheral register definition structure for GPIO (STM32F030R8)
 */
typedef struct
{
    volatile uint32_t MODER;    /*!< GPIO port mode register,               Address offset: 0x00 */
    volatile uint32_t OTYPER;   /*!< GPIO port output type register,        Address offset: 0x04 */
    volatile uint32_t OSPEEDR;  /*!< GPIO port output speed register,       Address offset: 0x08 */
    volatile uint32_t PUPDR;    /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C */
    volatile uint32_t IDR;      /*!< GPIO port input data register,         Address offset: 0x10 */
    volatile uint32_t ODR;      /*!< GPIO port output data register,        Address offset: 0x14 */
    volatile uint32_t BSRR;     /*!< GPIO port bit set/reset register,      Address offset: 0x18 */
    volatile uint32_t LCKR;     /*!< GPIO port configuration lock register, Address offset: 0x1C */
    volatile uint32_t AFR[2];   /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 (AFR[0]: AFRL, AFR[1]: AFRH) */
    volatile uint32_t BRR;      /*!< GPIO port bit reset register,          Address offset: 0x28 */
} GPIO_RegDef_t;

/*
 * Peripheral definitions (Peripheral base addresses cast to GPIO_RegDef_t*)
 */
#define GPIOA    ((GPIO_RegDef_t *)GPIOA_BASE)  // GPIOA
#define GPIOB    ((GPIO_RegDef_t *)GPIOB_BASE)  // GPIOB
#define GPIOC    ((GPIO_RegDef_t *)GPIOC_BASE)  //GPIOC
#define GPIOD    ((GPIO_RegDef_t *)GPIOD_BASE)  //GPIOD
#define GPIOF    ((GPIO_RegDef_t *)GPIOF_BASE)  //GPIOF



/******************************************************************************/
/*                                                                            */
/*                          AHB2 PERIPHERAL STRUCTS                           */
/*                                                                            */
/******************************************************************************/

/**


/******************************************************************************/
/*                                                                            */
/*                          AHB1 PERIPHERAL STRUCTS                           */
/*                                                                            */
/******************************************************************************/

/**
  * @brief DMA Channel Sub-structure
  */
typedef struct
{
    volatile uint32_t CCR;      /*!< DMA channel configuration register,    Address offset: 0x00 */
    volatile uint32_t CNDTR;    /*!< DMA channel number of data register,   Address offset: 0x04 */
    volatile uint32_t CPAR;     /*!< DMA channel peripheral address reg,    Address offset: 0x08 */
    volatile uint32_t CMAR;     /*!< DMA channel memory address register,   Address offset: 0x0C */
    volatile uint32_t RESERVED; /*!< Reserved,                              Address offset: 0x10 */
} DMA_Channel_RegDef_t;

/**
  * @brief Direct Memory Access (DMA1)
  */
typedef struct
{
    volatile uint32_t ISR;           /*!< DMA interrupt status register,      Address offset: 0x00 */
    volatile uint32_t IFCR;          /*!< DMA interrupt flag clear register,  Address offset: 0x04 */
    DMA_Channel_RegDef_t Channel[5]; /*!< DMA channels 1 to 5,                  Address offset: 0x08 - 0x6B */
} DMA_RegDef_t;

/**
  * @brief Reset and Clock Control (RCC)
  */
typedef struct
{
    volatile uint32_t CR;       /*!< Clock control register,                Address offset: 0x00 */
    volatile uint32_t CFGR;     /*!< Clock configuration register,          Address offset: 0x04 */
    volatile uint32_t CIR;      /*!< Clock interrupt register,              Address offset: 0x08 */
    volatile uint32_t APB2RSTR; /*!< APB peripheral reset register 2,       Address offset: 0x0C */
    volatile uint32_t APB1RSTR; /*!< APB peripheral reset register 1,       Address offset: 0x10 */
    volatile uint32_t AHBENR;   /*!< AHB peripheral clock enable register,  Address offset: 0x14 */
    volatile uint32_t APB2ENR;  /*!< APB peripheral clock enable reg 2,     Address offset: 0x18 */
    volatile uint32_t APB1ENR;  /*!< APB peripheral clock enable reg 1,     Address offset: 0x1C */
    volatile uint32_t BDCR;     /*!< Backup domain control register,        Address offset: 0x20 */
    volatile uint32_t CSR;      /*!< Control/status register,               Address offset: 0x24 */
    volatile uint32_t AHBRSTR;  /*!< AHB peripheral reset register,         Address offset: 0x28 */
    volatile uint32_t CFGR2;    /*!< Clock configuration register 2,        Address offset: 0x2C */
} RCC_RegDef_t;

/**
  * @brief Flash Interface Control
  */
typedef struct
{
    volatile uint32_t ACR;      /*!< Flash access control register,         Address offset: 0x00 */
    volatile uint32_t KEYR;     /*!< Flash key register,                    Address offset: 0x04 */
    volatile uint32_t OPTKEYR;  /*!< Flash option key register,             Address offset: 0x08 */
    volatile uint32_t SR;       /*!< Flash status register,                 Address offset: 0x0C */
    volatile uint32_t CR;       /*!< Flash control register,                Address offset: 0x10 */
    volatile uint32_t AR;       /*!< Flash address register,                Address offset: 0x14 */
    volatile uint32_t RESERVED; /*!< Reserved,                              Address offset: 0x18 */
    volatile uint32_t OBR;      /*!< Option byte register,                  Address offset: 0x1C */
    volatile uint32_t WRPR;     /*!< Write protection register,             Address offset: 0x20 */
} FLASH_RegDef_t;

/**
  * @brief Cyclic Redundancy Check (CRC)
  */
typedef struct
{
    volatile uint32_t DR;       /*!< CRC Data register,                     Address offset: 0x00 */
    volatile uint32_t IDR;      /*!< CRC Independent data register,         Address offset: 0x04 */
    volatile uint32_t CR;       /*!< CRC Control register,                  Address offset: 0x08 */
    volatile uint32_t RESERVED; /*!< Reserved,                              Address offset: 0x0C */
    volatile uint32_t INIT;     /*!< CRC Initial value register,            Address offset: 0x10 */
    volatile uint32_t POL;      /*!< CRC Polynomial register,               Address offset: 0x14 */
} CRC_RegDef_t;


/******************************************************************************/
/*                                                                            */
/*                          APB PERIPHERAL STRUCTS                            */
/*                                                                            */
/******************************************************************************/

/**
  * @brief Universal Synchronous Asynchronous Receiver Transmitter (USART)
  */
typedef struct
{
    volatile uint32_t CR1;      /*!< USART Control register 1,              Address offset: 0x00 */
    volatile uint32_t CR2;      /*!< USART Control register 2,              Address offset: 0x04 */
    volatile uint32_t CR3;      /*!< USART Control register 3,              Address offset: 0x08 */
    volatile uint32_t BRR;      /*!< USART Baud rate register,              Address offset: 0x0C */
    volatile uint32_t GTPR;     /*!< USART Guard time and prescaler reg,    Address offset: 0x10 */
    volatile uint32_t RTOR;     /*!< USART Receiver timeout register,       Address offset: 0x14 */
    volatile uint32_t RQR;      /*!< USART Request register,                Address offset: 0x18 */
    volatile uint32_t ISR;      /*!< USART Interrupt & status register,     Address offset: 0x1C */
    volatile uint32_t ICR;      /*!< USART Interrupt flag clear register,   Address offset: 0x20 */
    volatile uint32_t RDR;      /*!< USART Receive data register,           Address offset: 0x24 */
    volatile uint32_t TDR;      /*!< USART Transmit data register,          Address offset: 0x28 */
} USART_RegDef_t;

/**
  * @brief Serial Peripheral Interface (SPI)
  */
typedef struct
{
    volatile uint32_t CR1;      /*!< SPI Control register 1,                Address offset: 0x00 */
    volatile uint32_t CR2;      /*!< SPI Control register 2,                Address offset: 0x04 */
    volatile uint32_t SR;       /*!< SPI Status register,                   Address offset: 0x08 */
    volatile uint32_t DR;       /*!< SPI Data register,                     Address offset: 0x0C */
    volatile uint32_t CRCPR;    /*!< SPI CRC polynomial register,           Address offset: 0x10 */
    volatile uint32_t RXCRCR;   /*!< SPI Rx CRC register,                   Address offset: 0x14 */
    volatile uint32_t TXCRCR;   /*!< SPI Tx CRC register,                   Address offset: 0x18 */
} SPI_RegDef_t;

/**
  * @brief Inter-Integrated Circuit (I2C)
  */
typedef struct
{
    volatile uint32_t CR1;      /*!< I2C Control register 1,                Address offset: 0x00 */
    volatile uint32_t CR2;      /*!< I2C Control register 2,                Address offset: 0x04 */
    volatile uint32_t OAR1;     /*!< I2C Own address 1 register,            Address offset: 0x08 */
    volatile uint32_t OAR2;     /*!< I2C Own address 2 register,            Address offset: 0x0C */
    volatile uint32_t TIMINGR;  /*!< I2C Timing register,                   Address offset: 0x10 */
    volatile uint32_t TIMEOUTR; /*!< I2C Timeout register,                  Address offset: 0x14 */
    volatile uint32_t ISR;      /*!< I2C Interrupt and status register,     Address offset: 0x18 */
    volatile uint32_t ICR;      /*!< I2C Interrupt clear register,          Address offset: 0x1C */
    volatile uint32_t PECR;     /*!< I2C PEC register,                      Address offset: 0x20 */
    volatile uint32_t RXDR;     /*!< I2C Receive data register,             Address offset: 0x24 */
    volatile uint32_t TXDR;     /*!< I2C Transmit data register,            Address offset: 0x28 */
} I2C_RegDef_t;

/**
  * @brief Timers (TIM1 Advanced, TIM3, TIM14, TIM15, TIM16, TIM17)
  */
typedef struct
{
    volatile uint32_t CR1;      /*!< TIM control register 1,                Address offset: 0x00 */
    volatile uint32_t CR2;      /*!< TIM control register 2,                Address offset: 0x04 */
    volatile uint32_t SMCR;     /*!< TIM slave mode control register,       Address offset: 0x08 */
    volatile uint32_t DIER;     /*!< TIM DMA/interrupt enable register,     Address offset: 0x0C */
    volatile uint32_t SR;       /*!< TIM status register,                   Address offset: 0x10 */
    volatile uint32_t EGR;      /*!< TIM event generation register,         Address offset: 0x14 */
    volatile uint32_t CCMR1;    /*!< TIM capture/compare mode register 1,   Address offset: 0x18 */
    volatile uint32_t CCMR2;    /*!< TIM capture/compare mode register 2,   Address offset: 0x1C */
    volatile uint32_t CCER;     /*!< TIM capture/compare enable register,   Address offset: 0x20 */
    volatile uint32_t CNT;      /*!< TIM counter register,                  Address offset: 0x24 */
    volatile uint32_t PSC;      /*!< TIM prescaler,                         Address offset: 0x28 */
    volatile uint32_t ARR;      /*!< TIM auto-reload register,              Address offset: 0x2C */
    volatile uint32_t RCR;      /*!< TIM repetition counter register,       Address offset: 0x30 */
    volatile uint32_t CCR[4];   /*!< TIM capture/compare registers 1-4,     Address offset: 0x34-0x40 */
    volatile uint32_t BDTR;     /*!< TIM break and dead-time register,      Address offset: 0x44 */
    volatile uint32_t DCR;      /*!< TIM DMA control register,              Address offset: 0x48 */
    volatile uint32_t DMAR;     /*!< TIM DMA address for full transfer,     Address offset: 0x4C */
} TIM_RegDef_t;

/**
  * @brief External Interrupt/Event Controller (EXTI)
  */
typedef struct
{
    volatile uint32_t IMR;      /*!< Interrupt mask register,               Address offset: 0x00 */
    volatile uint32_t EMR;      /*!< Event mask register,                   Address offset: 0x04 */
    volatile uint32_t RTSR;     /*!< Rising trigger selection register,     Address offset: 0x08 */
    volatile uint32_t FTSR;     /*!< Falling trigger selection register,    Address offset: 0x0C */
    volatile uint32_t SWIER;    /*!< Software interrupt event register,     Address offset: 0x10 */
    volatile uint32_t PR;       /*!< Pending register,                      Address offset: 0x14 */
} EXTI_RegDef_t;

/**
  * @brief System Configuration Controller (SYSCFG)
  */
typedef struct
{
    volatile uint32_t CFGR1;    /*!< SYSCFG configuration register 1,       Address offset: 0x00 */
    volatile uint32_t RESERVED; /*!< Reserved,                              Address offset: 0x04 */
    volatile uint32_t EXTICR[4];/*!< SYSCFG external interrupt config regs, Address offset: 0x08-0x14 */
    volatile uint32_t CFGR2;    /*!< SYSCFG configuration register 2,       Address offset: 0x18 */
} SYSCFG_RegDef_t;

/**
  * @brief Analog-to-Digital Converter (ADC1)
  */
typedef struct
{
    volatile uint32_t ISR;      /*!< ADC interrupt and status register,     Address offset: 0x00 */
    volatile uint32_t IER;      /*!< ADC interrupt enable register,         Address offset: 0x04 */
    volatile uint32_t CR;       /*!< ADC control register,                  Address offset: 0x08 */
    volatile uint32_t CFGR1;    /*!< ADC configuration register 1,          Address offset: 0x0C */
    volatile uint32_t CFGR2;    /*!< ADC configuration register 2,          Address offset: 0x10 */
    volatile uint32_t SMPR;     /*!< ADC sampling time register,            Address offset: 0x14 */
    volatile uint32_t RESERVED1[2]; /*!< Reserved,                          Address offset: 0x18-0x1C */
    volatile uint32_t TR;       /*!< ADC watchdog threshold register,       Address offset: 0x20 */
    volatile uint32_t RESERVED2;/*!< Reserved,                              Address offset: 0x24 */
    volatile uint32_t CHSELR;   /*!< ADC channel selection register,        Address offset: 0x28 */
    volatile uint32_t RESERVED3[5]; /*!< Reserved,                          Address offset: 0x2C-0x3C */
    volatile uint32_t DR;       /*!< ADC data register,                     Address offset: 0x40 */
} ADC_RegDef_t;

/**
  * @brief Power Control (PWR)
  */
typedef struct
{
    volatile uint32_t CR;       /*!< Power control register,                Address offset: 0x00 */
    volatile uint32_t CSR;      /*!< Power control/status register,         Address offset: 0x04 */
} PWR_RegDef_t;

/**
  * @brief Independent Watchdog (IWDG)
  */
typedef struct
{
    volatile uint32_t KR;       /*!< Key register,                          Address offset: 0x00 */
    volatile uint32_t PR;       /*!< Prescaler register,                    Address offset: 0x04 */
    volatile uint32_t RLR;      /*!< Reload register,                       Address offset: 0x08 */
    volatile uint32_t SR;       /*!< Status register,                       Address offset: 0x0C */
    volatile uint32_t WINR;     /*!< Window register,                       Address offset: 0x10 */
} IWDG_RegDef_t;

/**
  * @brief Window Watchdog (WWDG)
  */
typedef struct
{
    volatile uint32_t CR;       /*!< Control register,                      Address offset: 0x00 */
    volatile uint32_t CFR;      /*!< Configuration register,                Address offset: 0x04 */
    volatile uint32_t SR;       /*!< Status register,                       Address offset: 0x0C */
} WWDG_RegDef_t;

#endif /* INC_STM32F030R8T6_H_
