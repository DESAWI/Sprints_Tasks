/*
 * IntCtrl.c
 *
 *  Created on: Dec 26, 2020
 *      Author: Ahmed Ibrahim
 */
#include <stdint.h>
#include "IntCtrl.h"
#include "IntCtrl_Cfg.h"
#include "IntCtrl_Lcfg.h"
#include "Mcu_Hw.h"
#include "stdio.h"



void IntCtrl_Init(void)
{
	uint8_t u8_IntIndex = 0;
	uint8_t u8_IntNum = 0;
	uint8_t u8_GroupPri = 0;
	uint8_t u8_IntRegPos = 0;
	uint32_t *Pu32_IntPrioReg 	= (uint32_t*)INT_PRI_REG_BASE_ADDR;
	uint32_t *Pu32_IntEnReg 	= (uint32_t*)INT_SET_EN_BASE_ADDR;

	for(u8_IntIndex = 0; u8_IntIndex < NUM_OF_ACTIVATED_INTERRUPTS; u8_IntIndex++)
	{
		u8_IntNum 	= IntCtrl_Cfg[u8_IntIndex].IntNum;
		u8_GroupPri = IntCtrl_Cfg[u8_IntIndex].GroupPri;
		Pu32_IntPrioReg = (uint32_t*)(INT_PRI_REG_BASE_ADDR + (u8_IntNum / 4));
		u8_IntRegPos = ((u8_IntNum % 4) * 8);
		*Pu32_IntPrioReg &= ~(0xFF << u8_IntRegPos);
		*Pu32_IntPrioReg |= ~(u8_GroupPri << u8_IntRegPos);
	}
	/* just for testing */
	for(u8_IntIndex = 0; u8_IntIndex < NUM_OF_ACTIVATED_INTERRUPTS; u8_IntIndex++)
	{
		Pu32_IntEnReg = (uint32_t*)INT_SET_EN_BASE_ADDR;
		*Pu32_IntEnReg = (1 << IntCtrl_Cfg[u8_IntIndex].IntNum);
	}
}

void I2C1_EV_IRQHandler(void)
{
	printf("I2C handler");
}

void SPI1_IRQHandler(void)
{
	printf("SPI1 handler");
}

void USART1_IRQHandler(void)
{
	printf("USART1 handler");
}
