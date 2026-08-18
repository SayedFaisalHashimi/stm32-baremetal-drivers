/*
 * STM32F0R8T6_SPI.c
 *
 *  Created on: Aug 18, 2026
 *      Author: Sayed Faisal Hashimi
 */

#include "STM32F030R8T6_SPI.h"

void SPI_PeriClockControl(SPI_RegDef_t *pSPIx, uint8_t EnOrDi)
{
    if (EnOrDi == ENABLE)
    {
        if (pSPIx == SPI1) SPI1_PCLK_EN();
        else if (pSPIx == SPI2) SPI2_PCLK_EN();
    }
    else
    {
        if (pSPIx == SPI1) SPI1_PCLK_DI();
        else if (pSPIx == SPI2) SPI2_PCLK_DI();
    }
}



void SPI_Init(SPI_Handle_t *pSPIHandle)
{
    // Enable Peripheral Clock
    SPI_PeriClockControl(pSPIHandle->pSPIx, ENABLE);

    uint32_t tempreg1 = 0;
    uint32_t tempreg2 = 0;

    // 1. Configure Device Mode (Master/Slave)
    tempreg1 |= (pSPIHandle->SPIConfig.SPI_DeviceMode << 2); // MSTR Bit

    // 2. Configure Bus Configuration
    if (pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_FD)
    {
        tempreg1 &= ~(1 << 15); // Clear BIDIMODE
    }
    else if (pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_HD)
    {
        tempreg1 |= (1 << 15);  // Set BIDIMODE
    }
    else if (pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_SIMPLEX_RXONLY)
    {
        tempreg1 &= ~(1 << 15); // Clear BIDIMODE
        tempreg1 |= (1 << 10);  // Set RXONLY
    }

    // 3. Configure Clock Speed (Baud Rate Prescaler)
    tempreg1 |= (pSPIHandle->SPIConfig.SPI_SCLKSpeed << 3);

    // 4. Configure CPOL and CPHA
    tempreg1 |= (pSPIHandle->SPIConfig.SPI_CPOL << 1);
    tempreg1 |= (pSPIHandle->SPIConfig.SPI_CPHA << 0);

    // 5. Configure Software Slave Management (SSM)
    tempreg1 |= (pSPIHandle->SPIConfig.SPI_SSM << 9);

    pSPIHandle->pSPIx->CR1 = tempreg1;

    // 6. Configure Data Size (DS[3:0]) and FRXTH threshold in CR2
    tempreg2 &= ~(0xF << 8); // Clear DS bits
    tempreg2 |= (pSPIHandle->SPIConfig.SPI_DS << 8);

    if (pSPIHandle->SPIConfig.SPI_DS == SPI_DS_8BIT)
    {
        tempreg2 |= (1 << 12); // FRXTH = 1 (8-bit FIFO threshold)
    }

    pSPIHandle->pSPIx->CR2 = tempreg2;
}


uint8_t SPI_GetFlagStatus(SPI_RegDef_t *pSPIx, uint32_t FlagName)
{
    if (pSPIx->SR & FlagName)
    {
        return FLAG_SET;
    }
    return FLAG_RESET;
}
