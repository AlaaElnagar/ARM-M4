################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/MEXTI_prog.c \
../src/MGPIO_program.c \
../src/MNVIC_Program.c \
../src/MRCC_prog.c \
../src/MSYSTICK_Program.c \
../src/main.c 

OBJS += \
./src/MEXTI_prog.o \
./src/MGPIO_program.o \
./src/MNVIC_Program.o \
./src/MRCC_prog.o \
./src/MSYSTICK_Program.o \
./src/main.o 

C_DEPS += \
./src/MEXTI_prog.d \
./src/MGPIO_program.d \
./src/MNVIC_Program.d \
./src/MRCC_prog.d \
./src/MSYSTICK_Program.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F401xC -DUSE_HAL_DRIVER -DHSE_VALUE=25000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


