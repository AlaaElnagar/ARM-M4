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


BUILD_ARTIFACT_NAME := 03_ToggleLEDWithBTN_EXTI
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
03_ToggleLEDWithBTN_EXTI.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
03_ToggleLEDWithBTN_EXTI.list \

OBJCOPY_HEX += \
03_ToggleLEDWithBTN_EXTI.hex \

OBJCOPY_BIN += \
03_ToggleLEDWithBTN_EXTI.bin \


# All Target
all: main-build

# Main-build Target
main-build: 03_ToggleLEDWithBTN_EXTI.elf secondary-outputs

# Tool invocations
03_ToggleLEDWithBTN_EXTI.elf: $(OBJS) $(USER_OBJS) C:\Users\Ahmed\ Khaled\ Hammad\Documents\ARM_BlackPill\STM_CubeProjects\03_ToggleLEDWithBTN_EXTI\STM32F401CCUX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "03_ToggleLEDWithBTN_EXTI.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\Ahmed Khaled Hammad\Documents\ARM_BlackPill\STM_CubeProjects\03_ToggleLEDWithBTN_EXTI\STM32F401CCUX_FLASH.ld" --specs=nosys.specs -Wl,-Map="03_ToggleLEDWithBTN_EXTI.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

03_ToggleLEDWithBTN_EXTI.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "03_ToggleLEDWithBTN_EXTI.list"
	@echo 'Finished building: $@'
	@echo ' '

03_ToggleLEDWithBTN_EXTI.hex: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "03_ToggleLEDWithBTN_EXTI.hex"
	@echo 'Finished building: $@'
	@echo ' '

03_ToggleLEDWithBTN_EXTI.bin: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "03_ToggleLEDWithBTN_EXTI.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) 03_ToggleLEDWithBTN_EXTI.bin 03_ToggleLEDWithBTN_EXTI.elf 03_ToggleLEDWithBTN_EXTI.hex 03_ToggleLEDWithBTN_EXTI.list default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
