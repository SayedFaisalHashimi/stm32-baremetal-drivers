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

#endif /* INC_STM32F030R8T6_SPI_H_ */
