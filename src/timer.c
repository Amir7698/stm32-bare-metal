#include "stm32f446xx.h"
#include "timer.h"

/* ============================================================
 * timer_init
 *   tim    = which timer to configure (e.g. TIM2)
 *   fr_hz  = desired PWM frequency in Hz (e.g. 1000 for 1 kHz) * 1000 = f_timer
 *
 * Sets up the timer to count from 0 to 999, repeatedly,
 * at a rate that produces a PWM cycle every 1/fr_hz seconds.
 * Does NOT yet route the output to any pin (that comes next).
 * ============================================================ */
void timer_init(TIM_TypeDef *tim, uint32_t fr_hz)
{
    RCC->APB1ENR |= (1 << 0);
    tim->PSC = ((16000000 / (fr_hz * 1000)) - 1);
    tim->ARR = 999;
    tim->CR1 |= (1 << 0);
}

/* ============================================================
 * timer_set_duty
 *   tim    = which timer
 *   ch     = which channel (1, 2, 3, or 4)
 *   duty   = duty cycle in raw ticks (0–999)
 *            0   = pin always LOW (LED off)
 *            500 = 50% duty (LED at half brightness)
 *            999 = pin always HIGH (LED full bright)
 *
 * Each channel has its own CCRx register. The hardware
 * compares the counter against CCRx every tick — pin is HIGH
 * when CNT < CCRx, LOW when CNT >= CCRx.
 * ============================================================ */
void timer_set_duty(TIM_TypeDef *tim, uint8_t ch, uint16_t duty)
{

    switch (ch)
    {
    case 1:
        tim->CCR1 = duty;
        break;
    case 2:
        tim->CCR2 = duty;
        break;
    case 3:
        tim->CCR3 = duty;
        break;
    case 4:
        tim->CCR4 = duty;
        break;
    default:
        break;
    }
}