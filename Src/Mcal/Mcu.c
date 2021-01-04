/*
 * Mcu.c
 *
 *  Created on: Dec 31, 2020
 *      Author: Ahmed Desawi
 */

#include "stdint.h"
#include "stdio.h"
#include "Mcu.h"
#include "Compiler.h"
#include "Std_Types.h"

Mcu_Driver_StateType Mcu_Driver_State = MCU_DRIVER_UNINITIALIZED;
uint32_t* Mcu_pClkCtrlStReg =(uint32_t*)CLOCK_CONTROL_AND_STATUS_REG;
uint8_t Mcu_ClockSetting;
static Mcu_ConfigType* Mcu_LocConfigPtr;



void Mcu_Init(Mcu_ConfigType* ConfigPtr)
{
	if(NULL_PTR != ConfigPtr)
	{
		Mcu_LocConfigPtr = ConfigPtr;
		Mcu_Driver_State = MCU_DRIVER_INITIALIZED;
		*Mcu_pClkCtrlStReg |= (uint32_t)(1 << REMOVE_RESET_FLAG);
	}
	else
	{
		Mcu_Driver_State = MCU_DRIVER_UNINITIALIZED;
		printf("MCU configuration pointer is null\r\n");
	}
	return ;
}

void Mcu_PerformReset(void)
{
	uint32_t* Mcu_pResetCtrlReg = (uint32_t*)APP_INT_AND_RESET_CTRL_REG;
	if(MCU_DRIVER_UNINITIALIZED != Mcu_Driver_State)
	{
		*Mcu_pResetCtrlReg = VECTKEY | (uint32_t)(1 << SYSTEM_RESET_REQUEST_BIT);
	}
	else
	{
		*Mcu_pClkCtrlStReg |= (uint32_t)(1 << REMOVE_RESET_FLAG);
		*Mcu_pResetCtrlReg = VECTKEY | (uint32_t)(1 << SYSTEM_RESET_REQUEST_BIT);
		printf("MCU driver is not initialized\r\n");
	}
}

Mcu_RawResetType Mcu_GetResetRawValue(void)
{
	Mcu_RawResetType RetValue;
	Mcu_ResetType u8_McuResetFlagStatus = (*Mcu_pClkCtrlStReg >> 25);
	switch(u8_McuResetFlagStatus)
	{
	case BROWN_OUT_DETECTOR_RESET:
	{
		RetValue = BROWN_OUT_DETECTOR_RESET_FLAG;
		break;
	}
	case PIN_RESET:
	{
		RetValue = PIN_RESET_FLAG;
		break;
	}
	case POWER_DOWN_OR_ON_RESET:
	{
		RetValue = POWER_DOWN_OR_ON_RESET_FLAG;
		break;
	}
	case SOFTWARE_RESET:
	{
		RetValue = SOFTWARE_RESET_FLAG;
		break;
	}
	case INDEPENDENT_WATCHDOG_RESET:
	{
		RetValue = INDEPENDENT_WATCHDOG_RESET_FLAG;
		break;
	}
	case WINDOW_WATCHDOG_RESET:
	{
		RetValue = WINDOW_WATCHDOG_RESET_FLAG;
		break;
	}
	case LOW_POWER_RESET:
	{
		RetValue = LOW_POWER_RESET_FLAG;
		break;
	}
	default :
		RetValue = UNDEFINED_RESET;
		break;
	}
	return RetValue;
}

Std_ReturnType Mcu_InitClock(Mcu_ClockGateType ClockSettings)
{
	Std_ReturnType RetValue = E_NOT_OK;
	uint32_t* Pu32_ClockCtrlReg = (uint32_t*)MCU_RESET_CLOCK_CONTROL;
	if(MCU_DRIVER_UNINITIALIZED != Mcu_Driver_State)
	{
		RetValue = E_OK;
		Mcu_ClockSourceType u8_Mcu_ClockSource 	= Mcu_LocConfigPtr->Mcu_ClockConfigPtr[ClockSettings].ClockSource;
		uint8_t u8_Mcu_PLLUseStatus = Mcu_LocConfigPtr -> Mcu_ClockConfigPtr[ClockSettings].PllUse;
		//uint32_t u32_Mcu_Frequence 	= Mcu_ConfigPtr -> Mcu_ClockConfigPtr[ClockSettings].Freq;
		switch(u8_Mcu_ClockSource)
		{
		case HIGH_SPEED_INTERNAL_OSC:
		{
			*Pu32_ClockCtrlReg |= (uint32_t)(HIGH_SPEED_OSC_ON << INTERNAL_HI_SPD_BIT_POSITION);
			if(HSI_OSC_NOT_READY != ((*Pu32_ClockCtrlReg >> INTERNAL_HI_SPD_CLK_RDY_FLAG_POSITION) & 0x1))
			{
				if(PHASE_LOCKED_LOOP_OFF != u8_Mcu_PLLUseStatus)
				{
					//*Pu32_ClockCtrlReg |= (uint32_t)(PHASE_LOCKED_LOOP_ON << MAIN_PLL_ENABLE_BIT_POSITION);
				}
				else
				{
					//*Pu32_ClockCtrlReg |= (uint32_t)(PHASE_LOCKED_LOOP_OFF << MAIN_PLL_ENABLE_BIT_POSITION);
				}
			}
			else
			{
				//Mcu_PerformReset();
			}
			break;
		}
		case HIGH_SPEED_EXTERNAL_OSC:
		{
			break;
		}
		case MAIN_PHASE_LOCKED_LOOP:
		{
			break;
		}
		case LOW_SPEED_INTERNAL_RC:
		{
			break;
		}
		case LOW_SPEED_EXTERNAL_CRYSTAL:
		{
			break;
		}
		}
		if(Mcu_LocConfigPtr -> Mcu_EnabledClockGates[ClockSettings] <= ClockSettings)
		{
			RetValue = E_NOT_OK;
			printf("Clock settings graeter than clock configured\r\n");
		}
	}
	else
	{
		printf("MCU driver is not initialized\r\n");
		RetValue = E_NOT_OK;
	}
	return RetValue;
}
