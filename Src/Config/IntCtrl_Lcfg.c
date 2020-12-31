/*
 * IntCtrl_Lcfg.c
 *
 *  Created on: Dec 26, 2020
 *      Author: Ahmed Ibrahim
 *
 */

#include "IntCtrl_Cfg.h"
#include "IntCtrl_Lcfg.h"

#define IRQNO_USART1		(37)
#define IRQNO_SPI1			(35)
#define IRQNO_I2C1			(28)

const IntCtrl_CfgType IntCtrl_Cfg[NUM_OF_ACTIVATED_INTERRUPTS] =
{
		/*IntNum		GroupPri	SubGroupPri */
		{IRQNO_USART1,		2,			0},
		{IRQNO_SPI1,		2,			0},
		{IRQNO_I2C1,		2,			0},
};

