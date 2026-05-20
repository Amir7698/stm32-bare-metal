#include "stm32f446xx.h"
#include "systick.h"

static volatile uint32_t s_ticks = 0; // milliseconds counter

/* Called automatically every 1 ms by SysTick hardware */
void SysTick_Handler(void) // Because nobody else calls SysTick_Handler. The hardware calls it. .word SysTick_Handler        /* SysTick — slot 15 of vector table */
{
    s_ticks++;
}

void systick_init(void)
{
    SYSTICK->LOAD = 15999; /* Set reload value for 1ms interrupt:
    System clock = 16 MHz
    Each tick = 1 / 16MHz = 62.5 ns
    16,000 cycles = 1 ms
    So we load 15,999 (because counter counts from LOAD to 0) */
    SYSTICK->VAL = 0;      /* Clear current SysTick counter value */
    SYSTICK->CTRL = 7;     /* Enable SysTick:
       bit 0 = ENABLE (turn on timer)
       bit 1 = TICKINT (enable interrupt)
       bit 2 = CLKSOURCE (use processor clock)
       => SysTick runs at CPU clock (16 MHz) */
}

uint32_t millis(void)
{
    return s_ticks;
}

void delay_ms(uint32_t ms)
{
    uint32_t start = s_ticks;
    while (s_ticks - start < ms)
    {
        /* do nothing */
    }
}