/* ------------
 * NOTE := I am using Anode Based RGB LED so its common anode is connected to +5V/+3V.
 * and for RED, GREEN and BLUE pin it is connected to ground with 330ohm resistor.
 *
 *
 *
 * PIN Connectivity
 * RED = PE2
 * GREEN = PE4
 * BLUE = PE6
 * ANODE(Long leg pin) = 5V/3V
 *
 *
 *
 * Common Anode RGB LED
 *
 * LOW  -> LED ON
 * HIGH -> LED OFF
 *
 *
 * You can connected any GPIO Port like GPIOA , GPIOB , GPIOC and soon....
 * Remember according to your GPIO Port and Pin, you should configure
 * the GPIO port address , bitmasking and bitwise operation.
 *
 *
 */


#include <stdint.h>


int main(void)
{
	// ============= CLOCK CONFIGURATION SECTION ==================
	//CLOCK ENABLE
	uint32_t *RCC_AHB1 = (uint32_t*)(0x40023800 + 0x30);
	*RCC_AHB1 |= (1<<4);


	// ============ MODER CONFIGURATION SECTION ===================

	// RED LED
	uint32_t *GPIOE_R = (uint32_t*)(0x40021000);
	*GPIOE_R &= 0xFFFFFF3F;
	*GPIOE_R |= (1<<4);

	// GREEN LED
	uint32_t *GPIOE_G = (uint32_t*)(0x40021000);
	*GPIOE_G &= 0xFFFFF3FF;
	*GPIOE_G |= (1<<8);


	// BLUE LED
	uint32_t *GPIOE_B = (uint32_t*)(0x40021000);
	*GPIOE_B &= 0xFFFF3FFF;
	*GPIOE_B |= (1<<12);


	// =========== OUTPUT STATE CONFIGURATION SECTION ==============

	// RED LED
	uint32_t *GPIOE_ODR_R = (uint32_t*)(0x40021000 + 0x14);


	// GREEN LED
	uint32_t *GPIOE_ODR_G = (uint32_t*)(0x40021000 + 0x14);


	// BLUE LED
	uint32_t *GPIOE_ODR_B = (uint32_t*)(0x40021000 + 0x14);


	// ========== MAIN LOOP SECTION THAT RUNS FOREVER =================
	for(;;){

		//RED LED ON
		for(volatile uint32_t i = 0; i<1000000;i++){
			*GPIOE_ODR_R &= ~(1<<2);  // RED ON (LOW = ON for common anode)
			*GPIOE_ODR_G |= (1<<4);   // Turns GREEN LED OFF
			*GPIOE_ODR_B |= (1<<6);   // Turns BLUE LED OFF
		}

		// GREEN LED ON
		for(volatile uint32_t i = 0; i<1000000; i++){
			*GPIOE_ODR_R |= (1<<2);   // Turns RED LED OFF
			*GPIOE_ODR_G &= ~(1<<4);  // Turns GREEN LED ON
			*GPIOE_ODR_B |= (1<<6);   // Turns BLUE LED OFF

		}

		// BLUE LED ON
		for(volatile uint32_t i = 0; i<1000000; i++){
			*GPIOE_ODR_R |= (1<<2);    // Turns RED LED OFF
			*GPIOE_ODR_G |= (1<<4);    // Turns GREEN LED OFF
			*GPIOE_ODR_B &= ~(1<<6);   // Turns BLUE LED ON
		}

		// All RGB channels ON -> White
		for(volatile uint32_t i = 0; i<1000000; i++){
			*GPIOE_ODR_R &= ~(1<<2);   // Turns RED LED ON
			*GPIOE_ODR_G &= ~(1<<4);   // Turns GREEN LED ON
			*GPIOE_ODR_B &= ~(1<<6);   // Turns BLUE LED ON
		}
}
}
