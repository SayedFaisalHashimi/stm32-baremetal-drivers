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
