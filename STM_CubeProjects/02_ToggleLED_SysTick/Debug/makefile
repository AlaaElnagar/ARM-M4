################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include MCAL/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := 02_ToggleLED_SysTick
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
02_ToggleLED_SysTick.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
02_ToggleLED_SysTick.list \

OBJCOPY_HEX += \
02_ToggleLED_SysTick.hex \

OBJCOPY_BIN += \
02_ToggleLED_SysTick.bin \


# All Target
all: main-build

# Main-build Target
main-build: 02_ToggleLED_SysTick.elf secondary-outputs

# Tool invocations
02_ToggleLED_SysTick.elf: $(OBJS) $(USER_OBJS) C:\Users\Ahmed\ Khaled\ Hammad\Documents\ARM_BlackPill\STM_CubeProjects\02_ToggleLED_SysTick\STM32F401CCUX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "02_ToggleLED_SysTick.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\Ahmed Khaled Hammad\Documents\ARM_BlackPill\STM_CubeProjects\02_ToggleLED_SysTick\STM32F401CCUX_FLASH.ld" --specs=nosys.specs -Wl,-Map="02_ToggleLED_SysTick.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

02_ToggleLED_SysTick.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "02_ToggleLED_SysTick.list"
	@echo 'Finished building: $@'
	@echo ' '

02_ToggleLED_SysTick.hex: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "02_ToggleLED_SysTick.hex"
	@echo 'Finished building: $@'
	@echo ' '

02_ToggleLED_SysTick.bin: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "02_ToggleLED_SysTick.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) 02_ToggleLED_SysTick.bin 02_ToggleLED_SysTick.elf 02_ToggleLED_SysTick.hex 02_ToggleLED_SysTick.list default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
