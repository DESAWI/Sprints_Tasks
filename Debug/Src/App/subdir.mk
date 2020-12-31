################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/App/main.c 

OBJS += \
./Src/App/main.o 

C_DEPS += \
./Src/App/main.d 


# Each subdirectory must supply rules for building sources it contributes
Src/App/main.o: ../Src/App/main.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F411VETx -DSTM32 -DSTM32F4 -DSTM32F411E_DISCO -DDEBUG -c -I../Inc -I"C:/Users/HP/Desktop/Sprint/ARM_Architecture/Sprints_Repo/Sprints_Tasks/Src/Common" -I"C:/Users/HP/Desktop/Sprint/ARM_Architecture/Sprints_Repo/Sprints_Tasks/Src/Config/Inc" -I"C:/Users/HP/Desktop/Sprint/ARM_Architecture/Sprints_Repo/Sprints_Tasks/Src/Mcal/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/App/main.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

