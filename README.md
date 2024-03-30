# PWM_Drawer
PWM drawer works as a mini oscilloscope that is responsible for printing the frequency and the waveform of the generated PWM signal using FreeRTOS
## Introduction
PWM drawer works as a mini oscilloscope that is responsible for printing the frequency and the waveform of the generated PWM signal using FreeRTOS.
## Hardware Components
1. ATmega640 Microcontroller
2. graphical lcd

## Software Components
1. FreeRTOS: Real-Time Operating System providing multitasking capabilities.
2. AVR-GCC Compiler: Used for compiling C code for the ATmega640 microcontroller.
3. AVR Libc: C library for AVR microcontrollers, providing essential functions.
4. FreeRTOS AVR Port: Port specific to the ATmega640 microcontroller, facilitating integration with FreeRTOS.
5. PWM Drawer Application: Code for measuring PWM signals and managing tasks using FreeRTOS.

## Project Setup
1. Set up the development environment by installing AVR-GCC compiler and AVR Libc.
2. Download FreeRTOS AVR Port compatible with ATmega640.
3. Configure development environment to include FreeRTOS headers and source files.
4. Write the PWM Drawer application code using FreeRTOS APIs.

## PWM Drawer Application
1. **Initialization:**
   - Initialize hardware peripherals (e.g., GLCD, GPIO,ICU).
   - Initialize FreeRTOS kernel.
   - Create necessary tasks and initialize synchronization primitives (e.g., semaphores).

2. **PWM Measuring Task:**
   - Implement a task responsible for generating PWM signals.
   - - Implement a task responsible for measuring and drawing PWM signals.
   
3. **Resource Management:**
   - Manage system resources efficiently to ensure optimal performance.
   - Implement resource sharing mechanisms (e.g., semaphores) to prevent conflicts.



