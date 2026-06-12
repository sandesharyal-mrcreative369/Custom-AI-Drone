# STM32 Register Level Programming

This section contains STM32F407G-DISC1 Discovery kit-STM32F407VG projects implemented using direct register access without CMSIS or HAL GPIO APIs.

## Board

- STM32F407G-DISC1

## Learning Objectives

- Memory Mapped Registers
- Pointer Based Register Access
- RCC Clock Configuration
- GPIO Configuration
- Input and Output Control
- Bit Masking
- Embedded C Fundamentals

## Projects

| Project | Description |
|----------|------------|
| 01_led_blink | Blink onboard Orange LED (PD13) |
| 02_button_input | Read USER Button (PA0) |
| 03_uart | UART communication |
| 04_timer | Timer configuration |
| 05_pwm | PWM generation |

## Registers Used

- RCC_AHB1ENR
- GPIOx_MODER
- GPIOx_ODR
- GPIOx_IDR

## Development Method

All projects are implemented using direct memory mapped register programming.
No HAL GPIO functions are used.