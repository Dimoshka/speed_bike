################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
speed_bike.lss \

FLASH_IMAGE += \
speed_bike.hex \

EEPROM_IMAGE += \
speed_bike.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: speed_bike.elf secondary-outputs

# Tool invocations
speed_bike.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,speed_bike.map -mmcu=atmega8 -o "speed_bike.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

speed_bike.lss: speed_bike.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S speed_bike.elf  >"speed_bike.lss"
	@echo 'Finished building: $@'
	@echo ' '

speed_bike.hex: speed_bike.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex speed_bike.elf  "speed_bike.hex"
	@echo 'Finished building: $@'
	@echo ' '

speed_bike.eep: speed_bike.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex speed_bike.elf  "speed_bike.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: speed_bike.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega8 speed_bike.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) speed_bike.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
