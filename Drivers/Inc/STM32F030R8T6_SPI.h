/*
 * STM32F030R8T6_SPI.h
 *
 *  Created on: Aug 18, 2026
 *      Author: DELL
 */

#ifndef INC_STM32F030R8T6_SPI_H_
#define INC_STM32F030R8T6_SPI_H_

#include "STM32F030R8T6.h"

/*
 * Configuration structure for SPI peripheral
 */
typedef struct
{
    uint8_t SPI_DeviceMode;     /*!< @SPI_DeviceMode >*/
    uint8_t SPI_BusConfig;      /*!< @SPI_BusConfig >*/
    uint8_t SPI_SCLKSpeed;      /*!< @SPI_SCLKSpeed >*/
    uint8_t SPI_DS;             /*!< @SPI_DS (Data Size: 8-bit / 16-bit) >*/
    uint8_t SPI_CPOL;           /*!< @SPI_CPOL >*/
    uint8_t SPI_CPHA;           /*!< @SPI_CPHA >*/
    uint8_t SPI_SSM;            /*!< @SPI_SSM >*/
} SPI_Config_t;


/*
 * Handle structure for SPI peripheral
 */
typedef struct
{
    SPI_RegDef_t *pSPIx;
    SPI_Config_t SPIConfig;
} SPI_Handle_t;

/* @SPI_DeviceMode */


/* @SPI_DeviceMode */
#define SPI_DEVICE_MODE_SLAVE       0
#define SPI_DEVICE_MODE_MASTER      1

/* @SPI_BusConfig */
#define SPI_BUS_CONFIG_FD           1   // Full Duplex
#define SPI_BUS_CONFIG_HD           2   // Half Duplex
#define SPI_BUS_CONFIG_SIMPLEX_RXONLY 3 // Simplex RX Only

/* @SPI_SCLKSpeed (Baud rate prescaler) */
#define SPI_SCLK_SPEED_DIV2         0
#define SPI_SCLK_SPEED_DIV4         1
#define SPI_SCLK_SPEED_DIV8         2
#define SPI_SCLK_SPEED_DIV16        3
#define SPI_SCLK_SPEED_DIV32        4
#define SPI_SCLK_SPEED_DIV64        5
#define SPI_SCLK_SPEED_DIV128       6
#define SPI_SCLK_SPEED_DIV256       7


/* @SPI_DS (Data Size selection for STM32F0) */
#define SPI_DS_8BIT                 7   // DS[3:0] = 0111 (8-bit)
#define SPI_DS_16BIT                15  // DS[3:0] = 1111 (16-bit)

/* @SPI_CPOL */
#define SPI_CPOL_LOW                0
#define SPI_CPOL_HIGH               1

/* @SPI_CPHA */
#define SPI_CPHA_LOW                0
#define SPI_CPHA_HIGH               1

/* @SPI_SSM */
#define SPI_SSM_DI                  0
#define SPI_SSM_EN                  1


/* SPI Status Flags */
#define SPI_TXE_FLAG                (1 << 1)
#define SPI_RXNE_FLAG               (1 << 0)
#define SPI_BUSY_FLAG               (1 << 7)


/*
 * Driver API Prototypes
 */
void SPI_PeriClockControl(SPI_RegDef_t *pSPIx, uint8_t EnOrDi);
void SPI_Init(SPI_Handle_t *pSPIHandle);
void SPI_DeInit(SPI_RegDef_t *pSPIx);

void SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t Len);
void SPI_ReceiveData(SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer, uint32_t Len);

void SPI_PeripheralControl(SPI_RegDef_t *pSPIx, uint8_t EnOrDi);
void SPI_SSIConfig(SPI_RegDef_t *pSPIx, uint8_t EnOrDi);
void SPI_SSOEConfig(SPI_RegDef_t *pSPIx, uint8_t EnOrDi);
uint8_t SPI_GetFlagStatus(SPI_RegDef_t *pSPIx, uint32_t FlagName);



#endif /* INC_STM32F030R8T6_SPI_H_ */
