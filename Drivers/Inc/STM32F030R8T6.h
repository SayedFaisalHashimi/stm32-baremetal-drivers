/*
 * STM32F030R8T6.h
 *
 *  Created on: Aug 11, 2026
 *      Author: Sayed Faisal Hashimi
 */

#ifndef INC_STM32F030R8T6_H_
#define INC_STM32F030R8T6_H_

#include <stdint.h>

/******************************************************************************/
/*                                                                            */
/*                          ARM CORTEX-M0 NVIC EXCEPTION NUMBERS              */
/*                                                                            */
/******************************************************************************/

typedef enum
{
    /* Cortex-M0 Processor Exceptions */
    NonMaskableInt_IRQn    = -14,
    HardFault_IRQn         = -13,
    SVCall_IRQn            = -5,
    PendSV_IRQn            = -2,
    SysTick_IRQn           = -1,

    /* STM32F030R8 Specific Interrupt Vectors */
    WWDG_IRQn              = 0,
    RTC_IRQn               = 2,
    FLASH_IRQn             = 3,
    RCC_IRQn               = 4,
    EXTI0_1_IRQn           = 5,
    EXTI2_3_IRQn           = 6,
    EXTI4_15_IRQn          = 7,
    DMA1_Channel1_IRQn     = 9,
    DMA1_Channel2_3_IRQn   = 10,
    DMA1_Channel4_5_IRQn   = 11,
    ADC1_IRQn              = 12,
    TIM1_BRK_UP_TRG_COM_IRQn = 13,
    TIM1_CC_IRQn           = 14,
    TIM3_IRQn              = 16,
    TIM6_IRQn              = 17,
    TIM7_IRQn              = 18,
    TIM14_IRQn             = 19,
    TIM15_IRQn             = 20,
    TIM16_IRQn             = 21,
    TIM17_IRQn             = 22,
    I2C1_IRQn              = 23,
    I2C2_IRQn              = 24,
    SPI1_IRQn              = 25,
    SPI2_IRQn              = 26,
    USART1_IRQn            = 27,
    USART2_IRQn            = 28
} IRQn_Type;

/******************************************************************************/
/*                                                                            */
/*                          MEMORY BASE ADDRESSES                             */
/*                                                                            */
/******************************************************************************/

#define FLASH_BASEADDR            0x08000000U
#define SRAM_BASEADDR             0x20000000U
#define SYSTEM_MEMORY_BASEADDR    0x1FFFEC00U

/******************************************************************************/
/*                                                                            */
/*                        PERIPHERAL BUS BASE ADDRESSES                       */
/*                                                                            */
/******************************************************************************/

#define PERIPH_BASE               0x40000000U
#define APBPERIPH_BASE            PERIPH_BASE
#define AHB1PERIPH_BASE           (PERIPH_BASE + 0x00020000U)
#define AHB2PERIPH_BASE           (PERIPH_BASE + 0x08000000U)

/******************************************************************************/
/*                                                                            */
/*                    PERIPHERAL BASE ADDRESS DEFINITIONS                     */
/*                                                                            */
/******************************************************************************/

/* AHB2 Peripherals (GPIO Ports) */
#define GPIOA_BASE                (AHB2PERIPH_BASE + 0x00000000U)
#define GPIOB_BASE                (AHB2PERIPH_BASE + 0x00000400U)
#define GPIOC_BASE                (AHB2PERIPH_BASE + 0x00000800U)
#define GPIOD_BASE                (AHB2PERIPH_BASE + 0x00000C00U)
#define GPIOF_BASE                (AHB2PERIPH_BASE + 0x00001400U)

/* AHB1 Peripherals */
#define DMA1_BASE                 (AHB1PERIPH_BASE + 0x00000000U)
#define DMA1_Channel1_BASE        (DMA1_BASE + 0x00000008U)
#define DMA1_Channel2_BASE        (DMA1_BASE + 0x0000001CU)
#define DMA1_Channel3_BASE        (DMA1_BASE + 0x00000030U)
#define DMA1_Channel4_BASE        (DMA1_BASE + 0x00000044U)
#define DMA1_Channel5_BASE        (DMA1_BASE + 0x00000058U)
#define RCC_BASE                  (AHB1PERIPH_BASE + 0x00001000U)
#define FLASH_R_BASE              (AHB1PERIPH_BASE + 0x00002000U)
#define CRC_BASE                  (AHB1PERIPH_BASE + 0x00003000U)

/* APB Peripherals */
#define TIM3_BASE                 (APBPERIPH_BASE + 0x00000400U)
#define TIM6_BASE                 (APBPERIPH_BASE + 0x00001000U)
#define TIM7_BASE                 (APBPERIPH_BASE + 0x00001400U)
#define TIM14_BASE                (APBPERIPH_BASE + 0x00002000U)
#define RTC_BASE                  (APBPERIPH_BASE + 0x00002800U)
#define WWDG_BASE                 (APBPERIPH_BASE + 0x00002C00U)
#define IWDG_BASE                 (APBPERIPH_BASE + 0x00003000U)
#define SPI2_BASE                 (APBPERIPH_BASE + 0x00003800U)
#define USART2_BASE               (APBPERIPH_BASE + 0x00004400U)
#define I2C1_BASE                 (APBPERIPH_BASE + 0x00005400U)
#define I2C2_BASE                 (APBPERIPH_BASE + 0x00005800U)
#define PWR_BASE                  (APBPERIPH_BASE + 0x00007000U)
#define SYSCFG_BASE               (APBPERIPH_BASE + 0x00010000U)
#define EXTI_BASE                 (APBPERIPH_BASE + 0x00010400U)
#define ADC1_BASE                 (APBPERIPH_BASE + 0x00012400U)
#define TIM1_BASE                 (APBPERIPH_BASE + 0x00012C00U)
#define SPI1_BASE                 (APBPERIPH_BASE + 0x00013000U)
#define USART1_BASE               (APBPERIPH_BASE + 0x00013800U)
#define TIM15_BASE                (APBPERIPH_BASE + 0x00014000U)
#define TIM16_BASE                (APBPERIPH_BASE + 0x00014400U)
#define TIM17_BASE                (APBPERIPH_BASE + 0x00014800U)

/******************************************************************************/
/*                                                                            */
/*                          PERIPHERAL STRUCT DEFINITIONS                     */
/*                                                                            */
/******************************************************************************/

typedef struct
{
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
    volatile uint32_t OSPEEDR;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t LCKR;
    volatile uint32_t AFR[2];
    volatile uint32_t BRR;
} GPIO_RegDef_t;

typedef struct
{
    volatile uint32_t CCR;
    volatile uint32_t CNDTR;
    volatile uint32_t CPAR;
    volatile uint32_t CMAR;
    volatile uint32_t RESERVED;
} DMA_Channel_RegDef_t;

typedef struct
{
    volatile uint32_t ISR;
    volatile uint32_t IFCR;
    DMA_Channel_RegDef_t Channel[5];
} DMA_RegDef_t;

typedef struct
{
    volatile uint32_t CR;
    volatile uint32_t CFGR;
    volatile uint32_t CIR;
    volatile uint32_t APB2RSTR;
    volatile uint32_t APB1RSTR;
    volatile uint32_t AHBENR;
    volatile uint32_t APB2ENR;
    volatile uint32_t APB1ENR;
    volatile uint32_t BDCR;
    volatile uint32_t CSR;
    volatile uint32_t AHBRSTR;
    volatile uint32_t CFGR2;
} RCC_RegDef_t;

typedef struct
{
    volatile uint32_t ACR;
    volatile uint32_t KEYR;
    volatile uint32_t OPTKEYR;
    volatile uint32_t SR;
    volatile uint32_t CR;
    volatile uint32_t AR;
    volatile uint32_t RESERVED;
    volatile uint32_t OBR;
    volatile uint32_t WRPR;
} FLASH_RegDef_t;

typedef struct
{
    volatile uint32_t DR;
    volatile uint32_t IDR;
    volatile uint32_t CR;
    volatile uint32_t RESERVED;
    volatile uint32_t INIT;
    volatile uint32_t POL;
} CRC_RegDef_t;

typedef struct
{
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t CR3;
    volatile uint32_t BRR;
    volatile uint32_t GTPR;
    volatile uint32_t RTOR;
    volatile uint32_t RQR;
    volatile uint32_t ISR;
    volatile uint32_t ICR;
    volatile uint32_t RDR;
    volatile uint32_t TDR;
} USART_RegDef_t;

typedef struct
{
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t SR;
    volatile uint32_t DR;
    volatile uint32_t CRCPR;
    volatile uint32_t RXCRCR;
    volatile uint32_t TXCRCR;
} SPI_RegDef_t;

typedef struct
{
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t OAR1;
    volatile uint32_t OAR2;
    volatile uint32_t TIMINGR;
    volatile uint32_t TIMEOUTR;
    volatile uint32_t ISR;
    volatile uint32_t ICR;
    volatile uint32_t PECR;
    volatile uint32_t RXDR;
    volatile uint32_t TXDR;
} I2C_RegDef_t;

typedef struct
{
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t SMCR;
    volatile uint32_t DIER;
    volatile uint32_t SR;
    volatile uint32_t EGR;
    volatile uint32_t CCMR1;
    volatile uint32_t CCMR2;
    volatile uint32_t CCER;
    volatile uint32_t CNT;
    volatile uint32_t PSC;
    volatile uint32_t ARR;
    volatile uint32_t RCR;
    volatile uint32_t CCR[4];
    volatile uint32_t BDTR;
    volatile uint32_t DCR;
    volatile uint32_t DMAR;
} TIM_RegDef_t;

typedef struct
{
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t RESERVED;
    volatile uint32_t DIER;
    volatile uint32_t SR;
    volatile uint32_t EGR;
    volatile uint32_t RESERVED2[3];
    volatile uint32_t CNT;
    volatile uint32_t PSC;
    volatile uint32_t ARR;
} TIM_Basic_RegDef_t;

typedef struct
{
    volatile uint32_t IMR;
    volatile uint32_t EMR;
    volatile uint32_t RTSR;
    volatile uint32_t FTSR;
    volatile uint32_t SWIER;
    volatile uint32_t PR;
} EXTI_RegDef_t;

typedef struct
{
    volatile uint32_t CFGR1;
    volatile uint32_t RESERVED;
    volatile uint32_t EXTICR[4];
    volatile uint32_t CFGR2;
} SYSCFG_RegDef_t;

typedef struct
{
    volatile uint32_t ISR;
    volatile uint32_t IER;
    volatile uint32_t CR;
    volatile uint32_t CFGR1;
    volatile uint32_t CFGR2;
    volatile uint32_t SMPR;
    volatile uint32_t RESERVED1[2];
    volatile uint32_t TR;
    volatile uint32_t RESERVED2;
    volatile uint32_t CHSELR;
    volatile uint32_t RESERVED3[5];
    volatile uint32_t DR;
} ADC_RegDef_t;

typedef struct
{
    volatile uint32_t CR;
    volatile uint32_t CSR;
} PWR_RegDef_t;

typedef struct
{
    volatile uint32_t KR;
    volatile uint32_t PR;
    volatile uint32_t RLR;
    volatile uint32_t SR;
    volatile uint32_t WINR;
} IWDG_RegDef_t;

typedef struct
{
    volatile uint32_t CR;
    volatile uint32_t CFR;
    volatile uint32_t SR;
} WWDG_RegDef_t;

/******************************************************************************/
/*                                                                            */
/*                            PERIPHERAL INSTANCES                            */
/*                                                                            */
/******************************************************************************/

#define GPIOA                     ((GPIO_RegDef_t *)GPIOA_BASE)
#define GPIOB                     ((GPIO_RegDef_t *)GPIOB_BASE)
#define GPIOC                     ((GPIO_RegDef_t *)GPIOC_BASE)
#define GPIOD                     ((GPIO_RegDef_t *)GPIOD_BASE)
#define GPIOF                     ((GPIO_RegDef_t *)GPIOF_BASE)

#define RCC                       ((RCC_RegDef_t *)RCC_BASE)
#define FLASH                     ((FLASH_RegDef_t *)FLASH_R_BASE)
#define CRC                       ((CRC_RegDef_t *)CRC_BASE)

#define DMA1                      ((DMA_RegDef_t *)DMA1_BASE)
#define DMA1_Channel1             ((DMA_Channel_RegDef_t *)DMA1_Channel1_BASE)
#define DMA1_Channel2             ((DMA_Channel_RegDef_t *)DMA1_Channel2_BASE)
#define DMA1_Channel3             ((DMA_Channel_RegDef_t *)DMA1_Channel3_BASE)
#define DMA1_Channel4             ((DMA_Channel_RegDef_t *)DMA1_Channel4_BASE)
#define DMA1_Channel5             ((DMA_Channel_RegDef_t *)DMA1_Channel5_BASE)

#define USART1                    ((USART_RegDef_t *)USART1_BASE)
#define USART2                    ((USART_RegDef_t *)USART2_BASE)
#define SPI1                      ((SPI_RegDef_t *)SPI1_BASE)
#define SPI2                      ((SPI_RegDef_t *)SPI2_BASE)
#define I2C1                      ((I2C_RegDef_t *)I2C1_BASE)
#define I2C2                      ((I2C_RegDef_t *)I2C2_BASE)

#define TIM1                      ((TIM_RegDef_t *)TIM1_BASE)
#define TIM3                      ((TIM_RegDef_t *)TIM3_BASE)
#define TIM6                      ((TIM_Basic_RegDef_t *)TIM6_BASE)
#define TIM7                      ((TIM_Basic_RegDef_t *)TIM7_BASE)
#define TIM14                     ((TIM_RegDef_t *)TIM14_BASE)
#define TIM15                     ((TIM_RegDef_t *)TIM15_BASE)
#define TIM16                     ((TIM_RegDef_t *)TIM16_BASE)
#define TIM17                     ((TIM_RegDef_t *)TIM17_BASE)

#define EXTI                      ((EXTI_RegDef_t *)EXTI_BASE)
#define SYSCFG                    ((SYSCFG_RegDef_t *)SYSCFG_BASE)
#define ADC1                      ((ADC_RegDef_t *)ADC1_BASE)
#define PWR                       ((PWR_RegDef_t *)PWR_BASE)
#define IWDG                      ((IWDG_RegDef_t *)IWDG_BASE)
#define WWDG                      ((WWDG_RegDef_t *)WWDG_BASE)

/******************************************************************************/
/*                                                                            */
/*                          CLOCK ENABLE/DISABLE MACROS                       */
/*                                                                            */
/******************************************************************************/

/* GPIO Clock Enable/Disable */
#define GPIOA_PCLK_EN()           (RCC->AHBENR |= (1U << 17))
#define GPIOB_PCLK_EN()           (RCC->AHBENR |= (1U << 18))
#define GPIOC_PCLK_EN()           (RCC->AHBENR |= (1U << 19))
#define GPIOD_PCLK_EN()           (RCC->AHBENR |= (1U << 20))
#define GPIOF_PCLK_EN()           (RCC->AHBENR |= (1U << 22))

#define GPIOA_PCLK_DIS()          (RCC->AHBENR &= ~(1U << 17))
#define GPIOB_PCLK_DIS()          (RCC->AHBENR &= ~(1U << 18))
#define GPIOC_PCLK_DIS()          (RCC->AHBENR &= ~(1U << 19))
#define GPIOD_PCLK_DIS()          (RCC->AHBENR &= ~(1U << 20))
#define GPIOF_PCLK_DIS()          (RCC->AHBENR &= ~(1U << 22))

/* I2C Clock Enable/Disable */
#define I2C1_PCLK_EN()            (RCC->APB1ENR |= (1U << 21))
#define I2C2_PCLK_EN()            (RCC->APB1ENR |= (1U << 22))
#define I2C1_PCLK_DIS()           (RCC->APB1ENR &= ~(1U << 21))
#define I2C2_PCLK_DIS()           (RCC->APB1ENR &= ~(1U << 22))

/* SPI Clock Enable/Disable */
#define SPI1_PCLK_EN()            (RCC->APB2ENR |= (1U << 12))
#define SPI2_PCLK_EN()            (RCC->APB1ENR |= (1U << 14))
#define SPI1_PCLK_DIS()           (RCC->APB2ENR &= ~(1U << 12))
#define SPI2_PCLK_DIS()           (RCC->APB1ENR &= ~(1U << 14))

/* USART Clock Enable/Disable */
#define USART1_PCLK_EN()          (RCC->APB2ENR |= (1U << 14))
#define USART2_PCLK_EN()          (RCC->APB1ENR |= (1U << 17))
#define USART1_PCLK_DIS()         (RCC->APB2ENR &= ~(1U << 14))
#define USART2_PCLK_DIS()         (RCC->APB1ENR &= ~(1U << 17))

/* SYSCFG Clock Enable/Disable */
#define SYSCFG_PCLK_EN()          (RCC->APB2ENR |= (1U << 0))
#define SYSCFG_PCLK_DIS()         (RCC->APB2ENR &= ~(1U << 0))

/******************************************************************************/
/*                                                                            */
/*                        PERIPHERAL RESET MACROS                             */
/*                                                                            */
/******************************************************************************/

#define GPIOA_REG_RESET()         do { (RCC->AHBRSTR |= (1U << 17)); (RCC->AHBRSTR &= ~(1U << 17)); } while(0)
#define GPIOB_REG_RESET()         do { (RCC->AHBRSTR |= (1U << 18)); (RCC->AHBRSTR &= ~(1U << 18)); } while(0)
#define GPIOC_REG_RESET()         do { (RCC->AHBRSTR |= (1U << 19)); (RCC->AHBRSTR &= ~(1U << 19)); } while(0)
#define GPIOD_REG_RESET()         do { (RCC->AHBRSTR |= (1U << 20)); (RCC->AHBRSTR &= ~(1U << 20)); } while(0)
#define GPIOF_REG_RESET()         do { (RCC->AHBRSTR |= (1U << 22)); (RCC->AHBRSTR &= ~(1U << 22)); } while(0)

/******************************************************************************/
/*                                                                            */
/*                             GENERIC MACROS                                 */
/*                                                                            */
/******************************************************************************/

#define ENABLE                    1
#define DISABLE                   0
#define SET                       ENABLE
#define RESET                     DISABLE
#define GPIO_PIN_SET              SET
#define GPIO_PIN_RESET            RESET
#define FLAG_SET                  SET
#define FLAG_RESET                RESET

#endif /* INC_STM32F030R8T6_H_ */
