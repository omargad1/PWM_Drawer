################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/glcd.c 

OBJS += \
./HAL/glcd.o 

C_DEPS += \
./HAL/glcd.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/%.o: ../HAL/%.c HAL/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\user\Desktop\practice\PWM_Drawer\PWM_Drawer\Source\portable\ThirdParty\GCC\ATmega" -I"C:\Users\user\Desktop\practice\PWM_Drawer\PWM_Drawer\COMMON" -I"C:\Users\user\Desktop\practice\PWM_Drawer\PWM_Drawer\Source\include" -I"C:\Users\user\Desktop\practice\PWM_Drawer\PWM_Drawer\APP" -I"C:\Users\user\Desktop\practice\PWM_Drawer\PWM_Drawer\HAL" -I"C:\Users\user\Desktop\practice\PWM_Drawer\PWM_Drawer\MCAL" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega640 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


