################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Config/IntCtrl_Lcfg.c \
../Src/Config/Mcu_Lcfg.c 

OBJS += \
./Src/Config/IntCtrl_Lcfg.o \
./Src/Config/Mcu_Lcfg.o 

C_DEPS += \
./Src/Config/IntCtrl_Lcfg.d \
./Src/Config/Mcu_Lcfg.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Config/IntCtrl_Lcfg.o: ../Src/Config/IntCtrl_Lcfg.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F411VETx -DSTM32 -DSTM32F4 -DSTM32F411E_DISCO -DDEBUG -c -I../Inc -I"C:/Users/HP/Desktop/Sprint/ARM_Architecture/Sprints_Repo/Sprints_Tasks/Src/Config/Inc" -I"C:/Users/HP/Desktop/Sprint/ARM_Architecture/Sprints_Repo/Sprints_Tasks/Src/Mcal/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/Config/IntCtrl_Lcfg.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/Config/Mcu_Lcfg.o: ../Src/Config/Mcu_Lcfg.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F411VETx -DSTM32 -DSTM32F4 -DSTM32F411E_DISCO -DDEBUG -c -I"C:/Users/HP/Desktop/Sprint/ARM_Architecture/Sprints_Repo/Sprints_Tasks/Src/Mcal/Inc" -I../Inc -I"C:/Users/HP/Desktop/Sprint/ARM_Architecture/Sprints_Repo/Sprints_Tasks/Src/Common" -I"C:/Users/HP/Desktop/Sprint/ARM_Architecture/Sprints_Repo/Sprints_Tasks/Src/Config/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/Config/Mcu_Lcfg.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

