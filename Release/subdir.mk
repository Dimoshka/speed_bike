################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DS18B20.c \
../OneWire.c \
../ascii.c \
../main.c \
../nokia5110.c \
../spi.c \
../watch.c 

OBJS += \
./DS18B20.o \
./OneWire.o \
./ascii.o \
./main.o \
./nokia5110.o \
./spi.o \
./watch.o 

C_DEPS += \
./DS18B20.d \
./OneWire.d \
./ascii.d \
./main.d \
./nokia5110.d \
./spi.d \
./watch.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega8 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


