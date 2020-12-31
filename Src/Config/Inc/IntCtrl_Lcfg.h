/*
 * IntCtrl_Lcfg.h
 *
 *  Created on: Dec 29, 2020
 *      Author: Ahmed Ibrahim
 */

#ifndef CONFIG_INTCTRL_LCFG_H_
#define CONFIG_INTCTRL_LCFG_H_
#include "stdint.h"

typedef struct
{
	uint8_t IntNum;
	uint8_t GroupPri;
	uint8_t SubGroupPri;
}IntCtrl_CfgType;

extern const IntCtrl_CfgType IntCtrl_Cfg[];


#endif /* CONFIG_INTCTRL_LCFG_H_ */
