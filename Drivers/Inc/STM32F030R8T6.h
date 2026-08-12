#ifndef INC_STM32F030R8T6_H_
#define INC_STM32F030R8T6_H_

#include<stdint.h>
#include <stddef.h>
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
#define   USART6_BASE                      (APBPERIPHERAL_BASE_ADDR + 0x00011400UL)
#define   ADC_BASE                         (APBPERIPHERAL_BASE_ADDR + 0x00012400UL)
#define   TIM1_BASE                        (APBPERIPHERAL_BASE_ADDR + 0x00012C00UL)
#define   SPI1_BASE                        (APBPERIPHERAL_BASE_ADDR + 0x00013000UL)
#define   USART1_BASE                      (APBPERIPHERAL_BASE_ADDR + 0x00013800UL)
#define   TIM15_BASE                       (APBPERIPHERAL_BASE_ADDR + 0x00014000UL)
#define   TIM16_BASE                         (APBPERIPHERAL_BASE_ADDR + 0x00014400UL)  //recheck
#define   TIM17_BASE                         (APBPERIPHERAL_BASE_ADDR + 0x00014800UL)  //recheck
#define   DBGMCU_BASE                        (APBPERIPHERAL_BASE_ADDR + 0x00015800UL)

//AHB1 PERIPHERAL
#define   DMA_BASE                          AHB1PERIPHERAL_BASE_ADDR
#define   RCC_BASE                         (AHB1PERIPHERAL_BASE_ADDR + 0x00001000UL)
#define   FLASH_INTERFACE_BASE             (AHB1PERIPHERAL_BASE_ADDR + 0x00002000UL)
#define   CRC_BASE                         (AHB1PERIPHERAL_BASE_ADDR + 0x00003000UL)

// DMA CHANNELS ADRESSES
#define DMA1_BASE              0x40020000UL

#define DMA1_Channel1_BASE     (DMA1_BASE + 0x08UL)
#define DMA1_Channel2_BASE     (DMA1_BASE + 0x1CUL)
#define DMA1_Channel3_BASE     (DMA1_BASE + 0x30UL)
#define DMA1_Channel4_BASE     (DMA1_BASE + 0x44UL)
#define DMA1_Channel5_BASE     (DMA1_BASE + 0x58UL)


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



/*----------------------------- USART ---------------------------------------*/

typedef struct
{
    volatile uint32_t CR1;         /* 0x00 */
    volatile uint32_t CR2;         /* 0x04 */
    volatile uint32_t CR3;         /* 0x08 */
    volatile uint32_t BRR;         /* 0x0C */
    volatile uint32_t RESERVED1;   /* 0x10 */
    volatile uint32_t RTOR;        /* 0x14 */
    volatile uint32_t RQR;         /* 0x18 */
    volatile uint32_t ISR;         /* 0x1C */
    volatile uint32_t ICR;         /* 0x20 */
    volatile uint32_t RDR;         /* 0x24 */
    volatile uint32_t TDR;         /* 0x28 */

} USARTx_RegDef_t;



/*----------------------------- SPI -----------------------------------------*/

typedef struct
{
    volatile uint32_t CR1;         /* 0x00 */
    volatile uint32_t CR2;         /* 0x04 */
    volatile uint32_t SR;          /* 0x08 */
    volatile uint32_t DR;          /* 0x0C */
    volatile uint32_t CRCPR;       /* 0x10 */
    volatile uint32_t RXCRCR;      /* 0x14 */
    volatile uint32_t TXCRCR;      /* 0x18 */
} SPIx_RegDef_t;



/*----------------------------- I2C -----------------------------------------*/

typedef struct
{
    volatile uint32_t CR1;         /* 0x00 */
    volatile uint32_t CR2;         /* 0x04 */
    volatile uint32_t OAR1;        /* 0x08 */
    volatile uint32_t OAR2;        /* 0x0C */
    volatile uint32_t TIMINGR;     /* 0x10 */
    volatile uint32_t TIMEOUTR;    /* 0x14 */
    volatile uint32_t ISR;         /* 0x18 */
    volatile uint32_t ICR;         /* 0x1C */
    volatile uint32_t PECR;        /* 0x20 */
    volatile uint32_t RXDR;        /* 0x24 */
    volatile uint32_t TXDR;        /* 0x28 */
} I2Cx_RegDef_t;


/*----------------------------- ADC -----------------------------------------*/

typedef struct
{
    volatile uint32_t ISR;         /* 0x00 */
    volatile uint32_t IER;         /* 0x04 */
    volatile uint32_t CR;          /* 0x08 */
    volatile uint32_t CFGR1;       /* 0x0C */
    volatile uint32_t CFGR2;       /* 0x10 */
    volatile uint32_t SMPR;        /* 0x14 */

    volatile uint32_t RESERVED1[2];/* 0x18 - 0x1C */

    volatile uint32_t TR;          /* 0x20 */

    volatile uint32_t RESERVED2;   /* 0x24 */

    volatile uint32_t CHSELR;      /* 0x28 */

    volatile uint32_t RESERVED3[5];/* 0x2C - 0x3C */

    volatile uint32_t DR;          /* 0x40 */
    volatile uint32_t RESERVED4[177];/* 0x44 - 0x304 */
     volatile uint32_t CCR;         /* 0x308  */          /*Be careful ADC_CCR is a Common register to all ADCs*/
} ADCx_RegDef_t;



/*===========================================================================*/
/*                              DMA CHANNEL                                  */
/*===========================================================================*/

typedef struct {
    volatile uint32_t ISR;       /* 0x00 */   /* Interrupt status register      */
    volatile uint32_t IFCR;       /* 0x04 */   /* Interrupt flag clear register  */

    /* Channel 1 */
    volatile uint32_t CCR1;         /* Channel 1 configuration        */
    volatile uint32_t CNDTR1;       /* Channel 1 number of data       */
    volatile uint32_t CPAR1;        /* Channel 1 peripheral address   */
    volatile uint32_t CMAR1;        /* Channel 1 memory address       */
    volatile uint32_t RESERVED1;    /* Reserved                      */

    /* Channel 2 */
    volatile uint32_t CCR2;         /* Channel 2 configuration        */
    volatile uint32_t CNDTR2;       /* Channel 2 number of data       */
    volatile uint32_t CPAR2;        /* Channel 2 peripheral address   */
    volatile uint32_t CMAR2;        /* Channel 2 memory address       */
    /* 0x2C */ volatile uint32_t RESERVED2;    /* Reserved                      */

    /* Channel 3 */
    volatile uint32_t CCR3;         /* Channel 3 configuration        */
    volatile uint32_t CNDTR3;       /* Channel 3 number of data       */
    volatile uint32_t CPAR3;        /* Channel 3 peripheral address   */
    volatile uint32_t CMAR3;        /* Channel 3 memory address       */
    /* 0x40 */ volatile uint32_t RESERVED3;    /* Reserved                      */

    /* Channel 4 */
    volatile uint32_t CCR4;         /* Channel 4 configuration        */
    volatile uint32_t CNDTR4;       /* Channel 4 number of data       */
    volatile uint32_t CPAR4;        /* Channel 4 peripheral address   */
    volatile uint32_t CMAR4;        /* Channel 4 memory address       */
    volatile uint32_t RESERVED4;    /* Reserved                      */

    /* Channel 5 */
    volatile uint32_t CCR5;         /* Channel 5 configuration        */
    volatile uint32_t CNDTR5;       /* Channel 5 number of data       */
    volatile uint32_t CPAR5;        /* Channel 5 peripheral address   */
    volatile uint32_t CMAR5;        /* Channel 5 memory address       */

    volatile uint32_t RESERVED5[15];  /* Padding to 0xA8 */
    volatile uint32_t CSELR;        /* Channel selection register     */
} DMA_RegDef_t;



/*----------------------------- FLASH ---------------------------------------*/

typedef struct
{
    volatile uint32_t ACR;         /* 0x00 */
    volatile uint32_t KEYR;        /* 0x04 */
    volatile uint32_t OPTKEYR;     /* 0x08 */
    volatile uint32_t SR;          /* 0x0C */
    volatile uint32_t CR;          /* 0x10 */
    volatile uint32_t AR;          /* 0x14 */
    volatile uint32_t RESERVED;    /* 0x18 */
    volatile uint32_t OBR;         /* 0x1C */
    volatile uint32_t WRPR;        /* 0x20 */
} FLASH_RegDef_t;


/*----------------------------- SYSCFG --------------------------------------*/

typedef struct
{
    volatile uint32_t CFGR1;       /* 0x00 - SYSCFG configuration register 1 */
    volatile uint32_t RESERVED;    /* 0x04 - Reserved                         */
    volatile uint32_t EXTICR[4];  /* 0x08 - 0x14 - External interrupt config  */
    volatile uint32_t CFGR2;       /* 0x18 - SYSCFG configuration register 2 */
} SYSCFG_RegDef_t;


/*----------------------------- RTC -----------------------------------------*/

typedef struct
{
    volatile uint32_t TR;           /* 0x00 - Time register */
    volatile uint32_t DR;           /* 0x04 - Date register */
    volatile uint32_t CR;           /* 0x08 - Control register */
    volatile uint32_t ISR;          /* 0x0C - Initialization and status register */
    volatile uint32_t PRER;         /* 0x10 - Prescaler register */
    volatile uint32_t WUTR;         /* 0x14 - Wakeup timer register */
    volatile uint32_t RESERVED1;    /* 0x18 - Reserved */
    volatile uint32_t ALRMAR;       /* 0x1C - Alarm A register */
    volatile uint32_t RESERVED2;    /* 0x20 - Reserved */
    volatile uint32_t WPR;          /* 0x24 - Write protection register */
    volatile uint32_t SSR;          /* 0x28 - Sub second register */
    volatile uint32_t SHIFTR;       /* 0x2C - Shift control register */
    volatile uint32_t TSTR;         /* 0x30 - Time stamp time register */
    volatile uint32_t TSDR;         /* 0x34 - Time stamp date register */
    volatile uint32_t TSSSR;        /* 0x38 - Time stamp sub second register */
    volatile uint32_t CALR;         /* 0x3C - Calibration register */
    volatile uint32_t TAFCR;        /* 0x40 - Tamper and alternate function config */
    volatile uint32_t ALRMASSR;     /* 0x44 - Alarm A sub second register */
} RTC_RegDef_t;


/*----------------------------- TIM -----------------------------------------*/




//TIM1
typedef struct
{
    volatile uint32_t CR1;        /* 0x00 */
    volatile uint32_t CR2;        /* 0x04 */
    volatile uint32_t SMCR;       /* 0x08 */
    volatile uint32_t DIER;       /* 0x0C */
    volatile uint32_t SR;         /* 0x10 */
    volatile uint32_t EGR;        /* 0x14 */
    volatile uint32_t CCMR1;      /* 0x18 */
    volatile uint32_t CCMR2;      /* 0x1C */
    volatile uint32_t CCER;       /* 0x20 */
    volatile uint32_t CNT;        /* 0x24 */
    volatile uint32_t PSC;        /* 0x28 */
    volatile uint32_t ARR;        /* 0x2C */
    volatile uint32_t RCR;        /* 0x30 */
    volatile uint32_t CCR1;       /* 0x34 */
    volatile uint32_t CCR2;       /* 0x38 */
    volatile uint32_t CCR3;       /* 0x3C */
    volatile uint32_t CCR4;       /* 0x40 */
    volatile uint32_t BDTR;       /* 0x44 */
    volatile uint32_t DCR;        /* 0x48 */
    volatile uint32_t DMAR;       /* 0x4C */

} TIM1_RegDef_t;


/* TIM3*/

typedef struct
{
    volatile uint32_t CR1;        /* 0x00 */
    volatile uint32_t CR2;        /* 0x04 */
    volatile uint32_t SMCR;       /* 0x08 */
    volatile uint32_t DIER;       /* 0x0C */
    volatile uint32_t SR;         /* 0x10 */
    volatile uint32_t EGR;        /* 0x14 */
    volatile uint32_t CCMR1;      /* 0x18 */
    volatile uint32_t CCMR2;      /* 0x1C */
    volatile uint32_t CCER;       /* 0x20 */
    volatile uint32_t CNT;        /* 0x24 */
    volatile uint32_t PSC;        /* 0x28 */
    volatile uint32_t ARR;        /* 0x2C */

    volatile uint32_t RESERVED1;  /* 0x30 */

    volatile uint32_t CCR1;       /* 0x34 */
    volatile uint32_t CCR2;       /* 0x38 */
    volatile uint32_t CCR3;       /* 0x3C */
    volatile uint32_t CCR4;       /* 0x40 */

    volatile uint32_t RESERVED2;  /* 0x44 */

    volatile uint32_t DCR;        /* 0x48 */
    volatile uint32_t DMAR;       /* 0x4C */

} TIM3_RegDef_t;


// TIM6/7

typedef struct
{
    volatile uint32_t CR1;        /* 0x00 */
    volatile uint32_t CR2;        /* 0x04 */

    volatile uint32_t RESERVED1;  /* 0x08 */

    volatile uint32_t DIER;       /* 0x0C */
    volatile uint32_t SR;         /* 0x10 */
    volatile uint32_t EGR;        /* 0x14 */

    volatile uint32_t RESERVED2[3]; /* 0x18 - 0x20 */

    volatile uint32_t CNT;        /* 0x24 */
    volatile uint32_t PSC;        /* 0x28 */
    volatile uint32_t ARR;        /* 0x2C */

} TIM6_RegDef_t;



//TIM14

typedef struct
{
    volatile uint32_t CR1;          /* 0x00 */
    volatile uint32_t RESERVED1[2]; /* 0x04 - 0x08 */
    volatile uint32_t DIER;         /* 0x0C */
    volatile uint32_t SR;           /* 0x10 */
    volatile uint32_t EGR;          /* 0x14 */
    volatile uint32_t CCMR1;        /* 0x18 */
    volatile uint32_t RESERVED2;    /* 0x1C */
    volatile uint32_t CCER;         /* 0x20 */
    volatile uint32_t CNT;          /* 0x24 */
    volatile uint32_t PSC;          /* 0x28 */
    volatile uint32_t ARR;          /* 0x2C */
    volatile uint32_t RESERVED3;    /* 0x30 */
    volatile uint32_t CCR1;         /* 0x34 */
    volatile uint32_t RESERVED4[6]; /* 0x38 - 0x4C */
    volatile uint32_t OR;           /* 0x50 */
} TIM14_RegDef_t;



// TIM15
typedef struct
{
    volatile uint32_t CR1;        /* 0x00 */
    volatile uint32_t CR2;        /* 0x04 */
    volatile uint32_t SMCR;       /* 0x08 */
    volatile uint32_t DIER;       /* 0x0C */
    volatile uint32_t SR;        /* 0x10 */
    volatile uint32_t EGR;        /* 0x14 */
    volatile uint32_t CCMR1;      /* 0x18 */

    volatile uint32_t RESERVED1;  /* 0x1C */

    volatile uint32_t CCER;       /* 0x20 */
    volatile uint32_t CNT;        /* 0x24 */
    volatile uint32_t PSC;        /* 0x28 */
    volatile uint32_t ARR;        /* 0x2C */
    volatile uint32_t RCR;        /* 0x30 */
    volatile uint32_t CCR1;       /* 0x34 */
    volatile uint32_t CCR2;       /* 0x38 */

    volatile uint32_t RESERVED2[2]; /* 0x3C - 0x40 */

    volatile uint32_t BDTR;       /* 0x44 */
    volatile uint32_t DCR;        /* 0x48 */
    volatile uint32_t DMAR;       /* 0x4C */

} TIM15_RegDef_t;



//TIM16/17
typedef struct
{
    volatile uint32_t CR1;        /* 0x00 */
    volatile uint32_t CR2;        /* 0x04 */

    volatile uint32_t RESERVED1;  /* 0x08 */

    volatile uint32_t DIER;       /* 0x0C */
    volatile uint32_t SR;         /* 0x10 */
    volatile uint32_t EGR;        /* 0x14 */
    volatile uint32_t CCMR1;      /* 0x18 */

    volatile uint32_t RESERVED2;  /* 0x1C */

    volatile uint32_t CCER;       /* 0x20 */
    volatile uint32_t CNT;        /* 0x24 */
    volatile uint32_t PSC;        /* 0x28 */
    volatile uint32_t ARR;        /* 0x2C */
    volatile uint32_t RCR;        /* 0x30 */
    volatile uint32_t CCR1;       /* 0x34 */

    volatile uint32_t RESERVED3[3]; /* 0x38 - 0x40 */

    volatile uint32_t BDTR;       /* 0x44 */
    volatile uint32_t DCR;        /* 0x48 */
    volatile uint32_t DMAR;       /* 0x4C */

} TIM16_RegDef_t;



/*----------------------------- PWR -----------------------------------------*/

typedef struct
{
    volatile uint32_t CR;          /* 0x00 */
    volatile uint32_t CSR;         /* 0x04 */
} PWR_RegDef_t;


/*----------------------------- IWDG ----------------------------------------*/

typedef struct
{
    volatile uint32_t KR;          /* 0x00 */
    volatile uint32_t PR;          /* 0x04 */
    volatile uint32_t RLR;         /* 0x08 */
    volatile uint32_t SR;          /* 0x0C */
    volatile uint32_t WINR;        /* 0x10 */
} IWDG_RegDef_t;


/*----------------------------- WWDG ----------------------------------------*/

typedef struct
{
    volatile uint32_t CR;          /* 0x00 */
    volatile uint32_t CFR;         /* 0x04 */
    volatile uint32_t SR;          /* 0x08 */
} WWDG_RegDef_t;


/*----------------------------- DBGMCU --------------------------------------*/

typedef struct
{
    volatile uint32_t IDCODE;      /* 0x00 */
    volatile uint32_t CR;          /* 0x04 */
    volatile uint32_t APB1FZ;      /* 0x08 */
    volatile uint32_t APB2FZ;      /* 0x0C */
} DBGMCU_RegDef_t;


/*----------------------------- EXTI ----------------------------------------*/

typedef struct
{
    volatile uint32_t IMR;         /* 0x00 */
    volatile uint32_t EMR;         /* 0x04 */
    volatile uint32_t RTSR;        /* 0x08 */
    volatile uint32_t FTSR;        /* 0x0C */
    volatile uint32_t SWIER;       /* 0x10 */
    volatile uint32_t PR;          /* 0x14 */
} EXTI_RegDef_t;



#endif /* INC_STM32F030R8T6_H_ */

