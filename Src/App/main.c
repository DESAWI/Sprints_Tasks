/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Ahmed Ibrahim
 * @brief          : Main program body
 ******************************************************************************
 **/

#include <stdint.h>
#include "IntCtrl.h"
#include "Mcu.h"

extern Mcu_ConfigType Mcu_Config;

Mcu_ClockGateType Mcu_EnabledClockGates[3] =
{
	IO_PORTA_CLOCK_ENABLE,
	IO_PORTB_CLOCK_ENABLE,
	IO_PORTC_CLOCK_ENABLE
};

Mcu_ClockSettingsConfigType Mcu_ClockConfigPtr[1] =
{
		/* Clock source							PLL Use						Freq(HZ) */
		{HIGH_SPEED_INTERNAL_OSC,				ENABLE,						25000	}
};

int main(void)
{
	//Mcu_PerformReset();
//	Mcu_ConfigPtr->Mcu_ClockConfigPtr[0].ClockSource = (Mcu_ClockConfigPtr[0].ClockSource);
//	Mcu_ConfigPtr->Mcu_ClockConfigPtr[0].PllUse = (Mcu_ClockConfigPtr[0].PllUse);
//	Mcu_ConfigPtr->Mcu_ClockConfigPtr[0].Freq = (Mcu_ClockConfigPtr[0].Freq);
	Mcu_Init(&Mcu_Config);
	Mcu_InitClock(0);
	for(;;)
	{

	}
}
