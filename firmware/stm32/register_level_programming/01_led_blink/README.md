# 01 - LED Blink

## Objective

Blink the onboard Orange LED (PD13) using direct register programming.

## Hardware

- STM32F407G-DISC1 Discovery Board

## Concepts Covered

- RCC Clock Enable
- GPIO Output Configuration
- GPIO Output Data Register (ODR)
- Bit Masking
- Software Delay

## Registers Used

### RCC_AHB1ENR

Enable clock for GPIOD.

### GPIOD_MODER

Configure PD13 as output.

### GPIOD_ODR

Control LED state.

## LED Information

| LED | Pin |
|------|------|
| Orange | PD13 |

## Working Principle

1. Enable GPIOD clock.
2. Configure PD13 as output.
3. Set PD13 HIGH.
4. Delay.
5. Set PD13 LOW.
6. Delay.
7. Repeat forever.

## Learning Outcome

After completing this project, the following concepts should be understood:

- Memory mapped registers
- Register bit manipulation
- GPIO output configuration
- Embedded delay loops