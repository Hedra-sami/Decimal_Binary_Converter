################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/DIO_V1/subdir.mk
-include HAL/LCD_handler_v1/subdir.mk
-include HAL/KeyPad_Handler_V1/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Decimal_Binary_Converter.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: Decimal_Binary_Converter.elf secondary-outputs

# Tool invocations
Decimal_Binary_Converter.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Decimal_Binary_Converter.map -mmcu=atmega32 -o "Decimal_Binary_Converter.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Decimal_Binary_Converter.lss: Decimal_Binary_Converter.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Decimal_Binary_Converter.elf  >"Decimal_Binary_Converter.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Decimal_Binary_Converter.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Decimal_Binary_Converter.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Decimal_Binary_Converter.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
