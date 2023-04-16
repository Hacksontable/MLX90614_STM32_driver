################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/IR_THERMOMETER/MLX90614.c 

OBJS += \
./Drivers/IR_THERMOMETER/MLX90614.o 

C_DEPS += \
./Drivers/IR_THERMOMETER/MLX90614.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/IR_THERMOMETER/%.o Drivers/IR_THERMOMETER/%.su: ../Drivers/IR_THERMOMETER/%.c Drivers/IR_THERMOMETER/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I"C:/Users/krisa/Desktop/MLX90614/MLX90614_IR_Temp/Drivers/IR_THERMOMETER" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-IR_THERMOMETER

clean-Drivers-2f-IR_THERMOMETER:
	-$(RM) ./Drivers/IR_THERMOMETER/MLX90614.d ./Drivers/IR_THERMOMETER/MLX90614.o ./Drivers/IR_THERMOMETER/MLX90614.su

.PHONY: clean-Drivers-2f-IR_THERMOMETER

