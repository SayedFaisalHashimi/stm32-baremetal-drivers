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


void SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t Len)
{
    while (Len > 0)
    {
        // Wait until TXE flag is set
        while (SPI_GetFlagStatus(pSPIx, SPI_TXE_FLAG) == FLAG_RESET);

        // Check data frame size
        if ((pSPIx->CR2 & (0xF << 8)) == (SPI_DS_16BIT << 8))
        {
            // 16-bit Data transfer
            pSPIx->DR = *((uint16_t*)pTxBuffer);
            Len -= 2;
            pTxBuffer += 2; // Advance pointer by 2 bytes for 16-bit frame
        }
        else
        {
            // 8-bit Data transfer (Must cast to uint8_t for F0 FIFO handling)
            *(volatile uint8_t*)&pSPIx->DR = *pTxBuffer;
            Len--;
            pTxBuffer++;    // Advance pointer by 1 byte for 8-bit frame
        }
    }
}


void SPI_ReceiveData(SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer, uint32_t Len)
{
    while (Len > 0)
    {
        // Wait until RXNE flag is set
        while (SPI_GetFlagStatus(pSPIx, SPI_RXNE_FLAG) == FLAG_RESET);

        if ((pSPIx->CR2 & (0xF << 8)) == (SPI_DS_16BIT << 8))
        {
            // 16-bit Data transfer
            *((uint16_t*)pRxBuffer) = pSPIx->DR;
            Len -= 2;
            pRxBuffer += 2; // Advance pointer by 2 bytes for 16-bit frame
        }
        else
        {
            // 8-bit Data transfer
            *pRxBuffer = *(volatile uint8_t*)&pSPIx->DR; // Direct uint8_t read pops 1 byte from F0 FIFO
            Len--;
            pRxBuffer++;
        }
    }
}


void SPI_PeripheralControl(SPI_RegDef_t *pSPIx, uint8_t EnOrDi)
{
    if (EnOrDi == ENABLE)
    {
        pSPIx->CR1 |= (1 << 6); // Set SPE Bit
    }
    else
    {
        pSPIx->CR1 &= ~(1 << 6); // Clear SPE Bit
    }
}

