################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../GCC/AVR32_UC3/port.c 

S_UPPER_SRCS += \
../GCC/AVR32_UC3/exception.S 

OBJS += \
./GCC/AVR32_UC3/exception.o \
./GCC/AVR32_UC3/port.o 

S_UPPER_DEPS += \
./GCC/AVR32_UC3/exception.d 

C_DEPS += \
./GCC/AVR32_UC3/port.d 


# Each subdirectory must supply rules for building sources it contributes
GCC/AVR32_UC3/%.o: ../GCC/AVR32_UC3/%.S GCC/AVR32_UC3/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Assembler'
	avr-gcc -x assembler-with-cpp -g2 -gstabs -mmcu=atmega640 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

GCC/AVR32_UC3/%.o: ../GCC/AVR32_UC3/%.c GCC/AVR32_UC3/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\user\Desktop\practice\PWM_Drawer\PWM_Drawer\GCC\AVR32_UC3" -I"C:\Users\user\Desktop\practice\PWM_Drawer\PWM_Drawer\COMMON" -I"C:\Users\user\Desktop\practice\PWM_Drawer\PWM_Drawer\Source\include" -I"C:\Users\user\Desktop\practice\PWM_Drawer\PWM_Drawer\APP" -I"C:\Users\user\Desktop\practice\PWM_Drawer\PWM_Drawer\HAL" -I"C:\Users\user\Desktop\practice\PWM_Drawer\PWM_Drawer\MCAL" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega640 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


