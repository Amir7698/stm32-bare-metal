#include "stm32f446xx.h"
#include "systick.h"

int main(void)
{
    systick_init();
    /* 1. Enable clock for GPIOA */
    RCC->AHB1ENR |= (1 << 0);

    /* 2. Set PA5 as general-purpose output (MODER bits 11:10 = 01) */
    GPIOA->MODER &= ~(3 << 10); /* CLEAR both bits → 00 */
    GPIOA->MODER |= (1 << 10);  /* SET bit 10 only → 01 */

    while (1)
    {
        GPIOA->ODR ^= (1 << 5);
        delay_ms(1000);
    }
}