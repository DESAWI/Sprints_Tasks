################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Config/IntCtrl_Lcfg.c 

OBJS += \
./Src/Config/IntCtrl_Lcfg.o 

C_DEPS += \
./Src/Config/IntCtrl_Lcfg.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Config/IntCtrl_Lcfg.o: ../Src/Config/IntCtrl_Lcfg.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F411VETx -DSTM32 -DSTM32F4 -DSTM32F411E_DISCO -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/Config/IntCtrl_Lcfg.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

