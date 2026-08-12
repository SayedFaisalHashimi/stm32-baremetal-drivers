#ifndef INC_STM32F030R8T6_H_
#define INC_STM32F030R8T6_H_

#include<stdint.h>
// MEMORY ADDRESSES
#define   FLASH_BASE_ADDR                    0x08000000UL
#define   SRAM_BASE_ADDR                     0x20000000UL
#define   SYSTEM_BASE_ADDR                   0x1FFFEC00UL


// BUS ADDRESSES
#define   PERIPHERAL_BASE_ADDR               0x40000000UL
#define   APBPERIPHERAL_BASE_ADDR            PERIPHERAL_BASE_ADDR
#define   AHB1PERIPHERAL_BASE_ADDR          (PERIPHERAL_BASE_ADDR + 0x00020000UL)
#define   AHB2PERIPHERAL_BASE_ADDR          (PERIPHERAL_BASE_ADDR + 0x08000000UL)


//AHB2 PERIPHERAL
#define   GPIOA_BASE                         AHB2PERIPHERAL_BASE_ADDR
#define   GPIOB_BASE                        (AHB2PERIPHERAL_BASE_ADDR + 0x00000400UL)
#define   GPIOC_BASE                        (AHB2PERIPHERAL_BASE_ADDR + 0x00000800UL)
#define   GPIOD_BASE                        (AHB2PERIPHERAL_BASE_ADDR + 0x00000C00UL)
#define   GPIOF_BASE                        (AHB2PERIPHERAL_BASE_ADDR + 0x00001400UL)


//APB PERIPHERAL
#define   TIM3_BASE                        (APBPERIPHERAL_BASE_ADDR + 0x00000400UL)
#define   TIM6_BASE                        (APBPERIPHERAL_BASE_ADDR + 0x00001000UL)
#define   TIM7_BASE                        (APBPERIPHERAL_BASE_ADDR + 0x00001400UL)
#define   TIM14_BASE                       (APBPERIPHERAL_BASE_ADDR + 0x00002000UL)
#define   RTC_BASE                         (APBPERIPHERAL_BASE_ADDR + 0x00002800UL)
#define   WWDG_BASE                        (APBPERIPHERAL_BASE_ADDR + 0x00002C00UL)
#define   IWDG_BASE                        (APBPERIPHERAL_BASE_ADDR + 0x00003000UL)
#define   SPI2_BASE                        (APBPERIPHERAL_BASE_ADDR + 0x00003800UL)
#define   USART2_BASE                      (APBPERIPHERAL_BASE_ADDR + 0x00004400UL)
#define   USART3_BASE                      (APBPERIPHERAL_BASE_ADDR + 0x00004800UL)
#define   USART4_BASE                      (APBPERIPHERAL_BASE_ADDR + 0x00004C00UL)
#define   USART5_BASE                      (APBPERIPHERAL_BASE_ADDR + 0x00005000UL)
#define   I2C1_BASE                        (APBPERIPHERAL_BASE_ADDR + 0x00005400UL)
#define   I2C2_BASE                        (APBPERIPHERAL_BASE_ADDR + 0x00005800UL)
#define   USB_BASE                         (APBPERIPHERAL_BASE_ADDR + 0x00005C00UL)
#define   USB_SRAM_BASE                    (APBPERIPHERAL_BASE_ADDR + 0x00006000UL)
#define   PWR_BASE                         (APBPERIPHERAL_BASE_ADDR + 0x00007000UL)
#define   SYSCFG_BASE                      (APBPERIPHERAL_BASE_ADDR + 0x00010000UL)
#define   EXTI_BASE                        (APBPERIPHERAL_BASE_ADDR + 0x00010400UL)
#define   USART6                           (APBPERIPHERAL_BASE_ADDR + 0x00011400UL)
#define   ADC_BASE                         (APBPERIPHERAL_BASE_ADDR + 0x00012400UL)
#define   TIM1_BASE                        (APBPERIPHERAL_BASE_ADDR + 0x00012C00UL)
#define   SPI1_BASE                        (APBPERIPHERAL_BASE_ADDR + 0x00013000UL)
#define   USART1_BASE                      (APBPERIPHERAL_BASE_ADDR + 0x00013800UL)
#define   TIM15_BASE                       (APBPERIPHERAL_BASE_ADDR + 0x00014000UL)
#define DBGMCU_BASE                        (APBPERIPHERAL_BASE_ADDR + 0x00015800UL)

//AHB1 PERIPHERAL
#define   DMA_BASE                          AHB1PERIPHERAL_BASE_ADDR
#define   RCC_BASE                         (AHB1PERIPHERAL_BASE_ADDR + 0x00001000UL)
#define   FLASH_INTERFACE_BASE             (AHB1PERIPHERAL_BASE_ADDR + 0x00002000UL)
#define   CRC_BASE                         (AHB1PERIPHERAL_BASE_ADDR + 0x00003000UL)


/******************************************************************************/
/*                                                                            */
/*                          REGISTER DEFINITIONS                              */
/*                                                                            */
/******************************************************************************/

/*----------------------------- GPIO ----------------------------------------*/

typedef struct
{
    volatile uint32_t MODER;       /* 0x00 */
    volatile uint32_t OTYPER;      /* 0x04 */
    volatile uint32_t OSPEEDR;     /* 0x08 */
    volatile uint32_t PUPDR;       /* 0x0C */
    volatile uint32_t IDR;         /* 0x10 */
    volatile uint32_t ODR;         /* 0x14 */
    volatile uint32_t BSRR;        /* 0x18 */
    volatile uint32_t LCKR;        /* 0x1C */
    volatile uint32_t AFR[2];      /* 0x20, 0x24 */
    volatile uint32_t BRR;         /* 0x28 */
} GPIOx_RegDef_t;


/*----------------------------- RCC -----------------------------------------*/

typedef struct
{
    volatile uint32_t CR;          /* 0x00 */
    volatile uint32_t CFGR;        /* 0x04 */
    volatile uint32_t CIR;         /* 0x08 */

    volatile uint32_t APB2RSTR;    /* 0x0C */
    volatile uint32_t APB1RSTR;    /* 0x10 */

    volatile uint32_t AHBENR;      /* 0x14 */

    volatile uint32_t APB2ENR;     /* 0x18 */
    volatile uint32_t APB1ENR;     /* 0x1C */

    volatile uint32_t BDCR;        /* 0x20 */
    volatile uint32_t CSR;         /* 0x24 */

    volatile uint32_t AHBRSTR;     /* 0x28 */

    volatile uint32_t CFGR2;       /* 0x2C */
    volatile uint32_t CFGR3;       /* 0x30 */
    volatile uint32_t CR2;         /* 0x34 */

} RCCx_RegDef_t;


#endif /* INC_STM32F030R8T6_H_ */
