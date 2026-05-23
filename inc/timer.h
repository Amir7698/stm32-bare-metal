#ifndef TIMER_H
#define TIMER_H
#include <stdint.h>
#include "stm32f446xx.h"

void timer_init(TIM_TypeDef *tim, uint32_t fr_hz);
void timer_set_duty(TIM_TypeDef *tim, uint8_t ch, uint16_t duty);

#endif