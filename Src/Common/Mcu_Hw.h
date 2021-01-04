/*
 * Mcu_Hw.h
 *
 *  Created on: Dec 26, 2020
 *      Author: Ahmed Ibrahim
 */

#ifndef COMMON_MCU_HW_H_
#define COMMON_MCU_HW_H_

#include <stdint.h>

#define INT_PRI_REG_BASE_ADDR						(0xE000E400U)
#define INT_SET_EN_BASE_ADDR						(0xE000E100U)
#define MCU_RESET_CLOCK_CONTROL						(0x40023800U)
#define APP_INT_AND_RESET_CTRL_REG					(0xE000ED0CU)
#define CLOCK_CONTROL_AND_STATUS_REG				(0x40023874U)
#define VECTKEY										(0x5FA0000U)



#endif /* COMMON_MCU_HW_H_ */
