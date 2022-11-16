################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/stm32f723e_discovery.c \
../Drivers/BSP/stm32f723e_discovery_lcd.c 

OBJS += \
./Drivers/BSP/stm32f723e_discovery.o \
./Drivers/BSP/stm32f723e_discovery_lcd.o 

C_DEPS += \
./Drivers/BSP/stm32f723e_discovery.d \
./Drivers/BSP/stm32f723e_discovery_lcd.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/%.o Drivers/BSP/%.su: ../Drivers/BSP/%.c Drivers/BSP/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F723xx -c -I../Core/Inc -I../Drivers/BSP/Components -I../Drivers/BSP/Components/Common -I../Drivers/BSP/Components/st7789h2 -I../Drivers/BSP -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP

clean-Drivers-2f-BSP:
	-$(RM) ./Drivers/BSP/stm32f723e_discovery.d ./Drivers/BSP/stm32f723e_discovery.o ./Drivers/BSP/stm32f723e_discovery.su ./Drivers/BSP/stm32f723e_discovery_lcd.d ./Drivers/BSP/stm32f723e_discovery_lcd.o ./Drivers/BSP/stm32f723e_discovery_lcd.su

.PHONY: clean-Drivers-2f-BSP

