/* ============================================================================
 * Project : STM32F407 RGB LED Control (Register-Level Programming)
 * Author  : Sandesh  Aryal
 * ----------------------------------------------------------------------------
 * Description:
 * This program controls a Common Anode RGB LED connected to the STM32F407.
 * GPIOE pins PE2, PE4, and PE6 are configured as outputs and used to drive
 * the Red, Green, and Blue channels respectively.
 *
 * Since a Common Anode RGB LED is used:
 *   - Common Anode  -> Connected to +3.3V / +5V
 *   - GPIO LOW (0)  -> LED ON
 *   - GPIO HIGH (1) -> LED OFF
 *
 * The program continuously cycles through:
 *   1. Red
 *   2. Green
 *   3. Blue
 *   4. White (Red + Green + Blue)
 *
 * Hardware Connections:
 * ---------------------------------------------------------------------------
 * RGB LED Pin      STM32 Pin
 * ---------------------------------------------------------------------------
 * RED             -> PE2 (through 330Ω resistor)
 * GREEN           -> PE4 (through 330Ω resistor)
 * BLUE            -> PE6 (through 330Ω resistor)
 * ANODE           -> +3.3V / +5V
 *
 * Notes:
 * ---------------------------------------------------------------------------
 * - GPIOE clock is enabled using RCC_AHB1ENR.
 * - Direct register access is used (no HAL or LL libraries).
 * - Delay is generated using a simple software loop.
 * - GPIO pins can be changed by modifying the register configuration and
 *   bit positions accordingly.
 *
 * Target Board:
 * STM32F407G-DISC1 (STM32F407VG)
 * ============================================================================
 */