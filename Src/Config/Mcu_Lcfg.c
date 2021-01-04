/*
 * Mcu_Lcfg.c
 *
 *  Created on: Jan 2, 2021
 *      Author: Ahmed Desawi
 */
#include "Mcu.h"

Mcu_ConfigType Mcu_Config = {
		{{HIGH_SPEED_INTERNAL_OSC,				ENABLE,						25000	}},
								{
									IO_PORTA_CLOCK_ENABLE,
									IO_PORTB_CLOCK_ENABLE,
									IO_PORTC_CLOCK_ENABLE
								}
};

