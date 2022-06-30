################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Src/MGPIO_program.c \
../MCAL/Src/MRCC_prog.c \
../MCAL/Src/MSYSTICK_Program.c 

OBJS += \
./MCAL/Src/MGPIO_program.o \
./MCAL/Src/MRCC_prog.o \
./MCAL/Src/MSYSTICK_Program.o 

C_DEPS += \
./MCAL/Src/MGPIO_program.d \
./MCAL/Src/MRCC_prog.d \
./MCAL/Src/MSYSTICK_Program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Src/%.o: ../MCAL/Src/%.c MCAL/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F401CCUx -DSTM32 -DSTM32F4 -c -I../Inc -I"C:/Users/Ahmed Khaled Hammad/Documents/ARM_BlackPill/STM_CubeProjects/02_ToggleLED_SysTick/MCAL/Inc" -I"C:/Users/Ahmed Khaled Hammad/Documents/ARM_BlackPill/STM_CubeProjects/02_ToggleLED_SysTick/LIB" -I"C:/Users/Ahmed Khaled Hammad/Documents/ARM_BlackPill/STM_CubeProjects/02_ToggleLED_SysTick/HAL/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-MCAL-2f-Src

clean-MCAL-2f-Src:
	-$(RM) ./MCAL/Src/MGPIO_program.d ./MCAL/Src/MGPIO_program.o ./MCAL/Src/MRCC_prog.d ./MCAL/Src/MRCC_prog.o ./MCAL/Src/MSYSTICK_Program.d ./MCAL/Src/MSYSTICK_Program.o

.PHONY: clean-MCAL-2f-Src

