################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/ADC_INTERFACE.c \
../MCAL/Dio_INTERFACE.c \
../MCAL/EXTI_INTERACE.c \
../MCAL/GIC.c \
../MCAL/Timer_INTERFACE.c 

OBJS += \
./MCAL/ADC_INTERFACE.o \
./MCAL/Dio_INTERFACE.o \
./MCAL/EXTI_INTERACE.o \
./MCAL/GIC.o \
./MCAL/Timer_INTERFACE.o 

C_DEPS += \
./MCAL/ADC_INTERFACE.d \
./MCAL/Dio_INTERFACE.d \
./MCAL/EXTI_INTERACE.d \
./MCAL/GIC.d \
./MCAL/Timer_INTERFACE.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/%.o: ../MCAL/%.c MCAL/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\NTI\AVR\Nti_R7\HAL\inc" -I"D:\NTI\AVR\Nti_R7\UTILITIES\inc" -I"D:\NTI\AVR\Nti_R7\inc" -I"D:\NTI\AVR\Nti_R7\MCAL\inc" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


