################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Adc.c \
../src/Calculator.c \
../src/DIO.c \
../src/EEPROM.c \
../src/ExtInterrupt.c \
../src/GlobalInterrupt.c \
../src/Gpt.c \
../src/I2C.c \
../src/Keypad.c \
../src/LCD.c \
../src/SPI.c \
../src/SSD.c \
../src/Spt.c \
../src/Time_Table.c \
../src/UART.c \
../src/WDT.c 

OBJS += \
./src/Adc.o \
./src/Calculator.o \
./src/DIO.o \
./src/EEPROM.o \
./src/ExtInterrupt.o \
./src/GlobalInterrupt.o \
./src/Gpt.o \
./src/I2C.o \
./src/Keypad.o \
./src/LCD.o \
./src/SPI.o \
./src/SSD.o \
./src/Spt.o \
./src/Time_Table.o \
./src/UART.o \
./src/WDT.o 

C_DEPS += \
./src/Adc.d \
./src/Calculator.d \
./src/DIO.d \
./src/EEPROM.d \
./src/ExtInterrupt.d \
./src/GlobalInterrupt.d \
./src/Gpt.d \
./src/I2C.d \
./src/Keypad.d \
./src/LCD.d \
./src/SPI.d \
./src/SSD.d \
./src/Spt.d \
./src/Time_Table.d \
./src/UART.d \
./src/WDT.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"E:\CMP2024\cmp2024\embedded2\Smart-Home\inc" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


