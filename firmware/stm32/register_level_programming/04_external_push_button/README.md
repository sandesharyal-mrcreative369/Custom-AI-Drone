/**
 ******************************************************************************
 * @file    : main.c
 * @author  : Sandesh Aryal
 * @brief   : STM32 Push Button Controlled LED (Register-Level Programming)
 ******************************************************************************
 *
 * Description:
 * ---------------------------------------------------------------------------
 * This project demonstrates how to interface a push button with an STM32F407
 * microcontroller using direct register programming.
 *
 * The push button is connected to PC10 and configured as an input with the
 * internal pull-up resistor enabled. An LED is connected to PB1 and configured
 * as a digital output.
 *
 * When the button is pressed:
 *      - PC10 reads LOW (0)
 *      - LED on PB1 turns ON
 *
 * When the button is released:
 *      - PC10 reads HIGH (1)
 *      - LED on PB1 turns OFF
 *
 * No external libraries (HAL/LL) are used. All peripheral configuration is
 * performed through direct register access.
 *
 * Hardware Connections:
 * ---------------------------------------------------------------------------
 *
 * Push Button:
 *
 *      STM32 PC10 ---- Push Button ---- GND
 *
 *      Internal Pull-Up Resistor Enabled
 *      Released -> Logic HIGH
 *      Pressed  -> Logic LOW
 *
 *
 * LED:
 *
 *      STM32 PB1 ---- 330Ω Resistor ---- LED Anode (+)
 *                                         LED Cathode (-)
 *                                                |
 *                                               GND
 *
 *
 * Pin Configuration:
 * ---------------------------------------------------------------------------
 * PB1   -> LED Output
 * PC10  -> Push Button Input (Internal Pull-Up Enabled)
 *
 *
 * Register Configuration:
 * ---------------------------------------------------------------------------
 * RCC_AHB1ENR  -> Enables GPIOB and GPIOC clocks
 * GPIOC_MODER -> Configures PC10 as Input
 * GPIOC_PUPDR -> Enables Internal Pull-Up for PC10
 * GPIOB_MODER -> Configures PB1 as Output
 * GPIOB_ODR   -> Controls LED State
 *
 *
 * Target Board:
 * ---------------------------------------------------------------------------
 * STM32F407G-DISC1 (STM32F407VG)
 *
 ******************************************************************************
 */