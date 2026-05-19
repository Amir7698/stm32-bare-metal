#include "stm32f446xx.h"

int main(void)
{
    /* 1. Enable clock for GPIOA */
    RCC->AHB1ENR |= (1 << 0);

    /* 2. Set PA5 as general-purpose output (MODER bits 11:10 = 01) */
    GPIOA->MODER &= ~(3 << 10); /* CLEAR both bits → 00 */
    GPIOA->MODER |= (1 << 10);  /* SET bit 10 only → 01 */

    while (1)
    {
        GPIOA->ODR ^= (1 << 5);
        for (volatile uint32_t i = 0; i < 1000000; i++) /* waste ~40 ms: 100000 loops × 6 cycles each, at 16 MHz => 600 000 / 16 000 000 = 40ms */
        {
        }
    }
}