/*
 * Project: STM32F407 Discovery - Push Button Controlled LED
 * Author : Sandesh Aryal
 *
 * Description:
 * - Configures PA0 (User Push Button) as input.
 * - Configures PD13 (Orange LED) as output.
 * - When the button is pressed, the LED turns ON.
 * - When the button is released, the LED turns OFF.
 *
 * Board: STM32F407 Discovery
 */

#include <stdint.h>

int main(void)
{
    /* =========================================================
     * STEP 1: Enable Peripheral Clocks
     * ---------------------------------------------------------
     * GPIOA -> Push Button (PA0)
     * GPIOD -> Orange LED (PD13)
     * =========================================================
     */
    uint32_t *RCC_GPIOA = (uint32_t *)(0x40023800 + 0x30);
    *RCC_GPIOA |= (0x01 << 0);      // Enable GPIOA clock

    uint32_t *RCC_GPIOD = (uint32_t *)(0x40023800 + 0x30);
    *RCC_GPIOD |= (0x01 << 3);      // Enable GPIOD clock


    /* =========================================================
     * STEP 2: Configure PD13 as General Purpose Output
     * ---------------------------------------------------------
     * MODER13[1:0] = 01
     * =========================================================
     */
    uint32_t *gpiod_moder = (uint32_t *)(0x40020C00);

    *gpiod_moder &= 0xF3FFFFFF;     // Clear bits 27:26
    *gpiod_moder |= (0x01 << 26);   // Set output mode


    /* =========================================================
     * STEP 3: Configure PA0 as Input
     * ---------------------------------------------------------
     * MODER0[1:0] = 00
     * =========================================================
     */
    uint32_t *GPIO_MODER = (uint32_t *)(0x40020000);

    *GPIO_MODER &= ~(0x03);         // Set PA0 as input


    /* =========================================================
     * STEP 4: Create Register Pointers
     * ---------------------------------------------------------
     * ODR -> Output Data Register (LED Control)
     * IDR -> Input Data Register  (Button State)
     * =========================================================
     */
    uint32_t *gpiod_state = (uint32_t *)(0x40020C00 + 0x14);
    uint32_t *BUTTON_IDR = (uint32_t *)(0x40020000 + 0x10);


    /* =========================================================
     * STEP 5: Main Application Loop
     * ---------------------------------------------------------
     * Read button state continuously:
     * - PA0 = 1 -> LED ON
     * - PA0 = 0 -> LED OFF
     * =========================================================
     */
    while (1)
    {
        if ((*BUTTON_IDR & 0x01) == 0x00)
        {
            // Button not pressed -> Turn LED OFF
            *gpiod_state &= ~(0x01 << 13);
        }
        else
        {
            // Button pressed -> Turn LED ON
            *gpiod_state |= (0x01 << 13);
        }
    }

    return 0;
}
