/*
 * Mcu.h
 *
 *  Created on: Dec 31, 2020
 *      Author: Ahmed Desawi
 */
#include "Mcu_Hw.h"
#include "Std_Types.h"

#define SYSTEM_RESET_REQUEST_BIT					(2)
#define REMOVE_RESET_FLAG							(24)

#define HIGH_SPEED_OSC_ON							(1U)
#define HIGH_SPEED_OSC_OFF							(0U)
#define HSI_OSC_NOT_READY							(0U)
#define HSI_OSC_READY								(1U)
#define PHASE_LOCKED_LOOP_OFF						(0U)
#define PHASE_LOCKED_LOOP_ON						(1U)
#define PHASE_LOCKED_LOOP_I2S_OFF					(0U)
#define PHASE_LOCKED_LOOP_I2S_ON					(1U)

#define INTERNAL_HI_SPD_BIT_POSITION				(0U)
#define INTERNAL_HI_SPD_CLK_RDY_FLAG_POSITION		(1U)
#define MAIN_PLL_ENABLE_BIT_POSITION				(24U)
#define MAIN_PLL_I2S_ENABLE_BIT_POSITION			(26U)

#define IO_PORTA_CLOCK_ENABLE						(0U)
#define IO_PORTB_CLOCK_ENABLE						(1U)
#define IO_PORTC_CLOCK_ENABLE						(2U)
#define IO_PORTD_CLOCK_ENABLE						(3U)
#define IO_PORTE_CLOCK_ENABLE						(4U)
#define IO_PORTH_CLOCK_ENABLE						(7U)
#define CRC_CLOCK_ENABLE							(12U)
#define DMA1_CLOCK_ENABLE							(21U)
#define DMA2_CLOCK_ENABLE							(22U)
#define TIM2_CLOCK_ENABLE							(0U)
#define TIM3_CLOCK_ENABLE							(1U)
#define TIM4_CLOCK_ENABLE							(2U)
#define TIM5_CLOCK_ENABLE							(3U)
#define WINDOW_WDT_CLOCK_ENABLE						(11U)
#define SPI2_CLOCK_ENABLE							(14U)
#define SPI3_CLOCK_ENABLE							(15U)
#define USART2_CLOCK_ENABLE							(16U)
#define I2C1_CLOCK_ENABLE							(21U)
#define I2C2_CLOCK_ENABLE							(22U)
#define I2C3_CLOCK_ENABLE							(23U)
#define POWER_INTERFACE_CLOCK_ENABLE				(23U)
#define TIM1_CLOCK_ENABLE							(0U)
#define USART1_CLOCK_ENABLE							(4U)
#define USART6_CLOCK_ENABLE							(5U)
#define ADC1_CLOCK_ENABLE							(8U)
#define SDIO_CLOCK_ENABLE							(11U)
#define SPI1_CLOCK_ENABLE							(12U)
#define SPI4_CLOCK_ENABLE							(13U)
#define SYS_CFG_CTRL_CLOCK_ENABLE					(14U)
#define TIM9_CLOCK_ENABLE							(16U)
#define TIM10_CLOCK_ENABLE							(17U)
#define TIM11_CLOCK_ENABLE							(18U)
#define SPI5_CLOCK_ENABLE							(20U)

typedef enum
{
	HIGH_SPEED_INTERNAL_OSC = 0,
	HIGH_SPEED_EXTERNAL_OSC,
	MAIN_PHASE_LOCKED_LOOP,
	LOW_SPEED_INTERNAL_RC,
	LOW_SPEED_EXTERNAL_CRYSTAL
}Mcu_ClockSourceType;

typedef enum
{
	DISABLE = 0,
	ENABLE
}Mcu_PLLUseType;

typedef struct
{
	Mcu_ClockSourceType ClockSource;
	Mcu_PLLUseType PllUse;
	uint32_t Freq;
}Mcu_ClockSettingsConfigType;

typedef enum
{
	UNDEFINED_RESET = 0,
	LOW_POWER_RESET_FLAG,
	WINDOW_WATCHDOG_RESET_FLAG,
	INDEPENDENT_WATCHDOG_RESET_FLAG,
	SOFTWARE_RESET_FLAG,
	POWER_DOWN_OR_ON_RESET_FLAG,
	PIN_RESET_FLAG,
	BROWN_OUT_DETECTOR_RESET_FLAG,
}Mcu_RawResetType;

typedef enum
{
	BROWN_OUT_DETECTOR_RESET = 0x01,
	PIN_RESET = 0x02,
	POWER_DOWN_OR_ON_RESET = 0x04,
	SOFTWARE_RESET = 0x08,
	INDEPENDENT_WATCHDOG_RESET = 0x10,
	WINDOW_WATCHDOG_RESET = 0x20,
	LOW_POWER_RESET = 0x40,
}Mcu_ResetType;

typedef uint8_t Mcu_ClockType;
typedef uint8_t Mcu_ClockGateType;

#define Mcu_Clock_0				(0U)
#define Mcu_Clock_1				(1U)
#define Mcu_Clock_2				(2U)
#define Mcu_Clock_3				(3U)

typedef enum
{
	MCU_DRIVER_UNINITIALIZED = 0,
	MCU_DRIVER_INITIALIZED
}Mcu_Driver_StateType;

typedef struct
{
	Mcu_ClockSettingsConfigType  Mcu_ClockConfigPtr[1];
	Mcu_ClockGateType			 Mcu_EnabledClockGates[];
}Mcu_ConfigType;

//extern Mcu_ConfigType Mcu_Config;

extern void Mcu_Init(Mcu_ConfigType* ConfigPtr);
extern Std_ReturnType Mcu_InitClock(Mcu_ClockGateType ClockSettings);
extern void Mcu_PerformReset(void);
