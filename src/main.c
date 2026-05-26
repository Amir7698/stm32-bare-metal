#include "stm32f446xx.h"
#include "systick.h"
#include "timer.h"

int main(void)
{
    systick_init();
    /* 1. Enable clock for GPIOA */
    // RCC->AHB1ENR |= (1 << 0);
    timer_init(TIM2, 1000); /* 1 kHz PWM on PA5 */

    /* 2. Set PA5 as general-purpose output (MODER bits 11:10 = 01) */
    // GPIOA->MODER &= ~(3 << 10); /* CLEAR both bits → 00 */
    // GPIOA->MODER |= (1 << 10);  /* SET bit 10 only → 01 */

    while (1)
    {
        for (uint16_t d = 0; d < 1000; d++)
        {
            timer_set_duty(TIM2, 1, d);
            delay_ms(1);
        }

        for (uint16_t d = 999; d > 0; d--)
        {
            timer_set_duty(TIM2, 1, d);
            delay_ms(1);
        }
    }
}