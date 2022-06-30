################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Src/MEXTI_prog.c \
../MCAL/Src/MFPEC_program.c \
../MCAL/Src/MGPIO_program.c \
../MCAL/Src/MNVIC_program.c \
../MCAL/Src/MRCC_prog.c \
../MCAL/Src/MSYSTICK_Program.c \
../MCAL/Src/MUSART_Program.c \
../MCAL/Src/PARSER_program.c 

OBJS += \
./MCAL/Src/MEXTI_prog.o \
./MCAL/Src/MFPEC_program.o \
./MCAL/Src/MGPIO_program.o \
./MCAL/Src/MNVIC_program.o \
./MCAL/Src/MRCC_prog.o \
./MCAL/Src/MSYSTICK_Program.o \
./MCAL/Src/MUSART_Program.o \
./MCAL/Src/PARSER_program.o 

C_DEPS += \
./MCAL/Src/MEXTI_prog.d \
./MCAL/Src/MFPEC_program.d \
./MCAL/Src/MGPIO_program.d \
./MCAL/Src/MNVIC_program.d \
./MCAL/Src/MRCC_prog.d \
./MCAL/Src/MSYSTICK_Program.d \
./MCAL/Src/MUSART_Program.d \
./MCAL/Src/PARSER_program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Src/%.o: ../MCAL/Src/%.c MCAL/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F401CCUx -DSTM32 -DSTM32F4 -c -I../Inc -I"C:/Users/Ahmed Khaled Hammad/Documents/ARM_BlackPill/STM_CubeProjects/04_BOOTLOADER_BlackPill/LIB" -I"C:/Users/Ahmed Khaled Hammad/Documents/ARM_BlackPill/STM_CubeProjects/04_BOOTLOADER_BlackPill/MCAL/Inc" -I"C:/Users/Ahmed Khaled Hammad/Documents/ARM_BlackPill/STM_CubeProjects/04_BOOTLOADER_BlackPill/HAL" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-MCAL-2f-Src

clean-MCAL-2f-Src:
	-$(RM) ./MCAL/Src/MEXTI_prog.d ./MCAL/Src/MEXTI_prog.o ./MCAL/Src/MFPEC_program.d ./MCAL/Src/MFPEC_program.o ./MCAL/Src/MGPIO_program.d ./MCAL/Src/MGPIO_program.o ./MCAL/Src/MNVIC_program.d ./MCAL/Src/MNVIC_program.o ./MCAL/Src/MRCC_prog.d ./MCAL/Src/MRCC_prog.o ./MCAL/Src/MSYSTICK_Program.d ./MCAL/Src/MSYSTICK_Program.o ./MCAL/Src/MUSART_Program.d ./MCAL/Src/MUSART_Program.o ./MCAL/Src/PARSER_program.d ./MCAL/Src/PARSER_program.o

.PHONY: clean-MCAL-2f-Src

