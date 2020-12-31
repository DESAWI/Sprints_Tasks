################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Mcal/IntCtrl.c 

OBJS += \
./Src/Mcal/IntCtrl.o 

C_DEPS += \
./Src/Mcal/IntCtrl.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Mcal/IntCtrl.o: ../Src/Mcal/IntCtrl.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F411VETx -DSTM32 -DSTM32F4 -DSTM32F411E_DISCO -DDEBUG -c -I../Inc -I"C:/Users/HP/Desktop/Sprint/ARM_Architecture/Sprints_Repo/Sprints_Tasks/Src/Mcal/Inc" -I"C:/Users/HP/Desktop/Sprint/ARM_Architecture/Sprints_Repo/Sprints_Tasks/Src/Common" -I"C:/Users/HP/Desktop/Sprint/ARM_Architecture/Sprints_Repo/Sprints_Tasks/Src/Config/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/Mcal/IntCtrl.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

