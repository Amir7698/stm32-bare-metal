#ifndef STM32F446XX_H
#define STM32F446XX_H
#include <stdint.h>

/* ===== Base addresses ===== */
#define PERIPH_BASE (0x40000000UL)

/* ===== AHB1 addresses ===== */
#define AHB1_OFFSET (0x0020000UL)
#define AHB1_BASE (PERIPH_BASE + AHB1_OFFSET)

/* ===== APB1 addresses ===== */
#define APB1_OFFSET (0x0000)
#define APB1_BASE (PERIPH_BASE + APB1_OFFSET)

/* ===== GPIOA addresses ===== */
#define GPIOA_OFFSET (0x0000UL)
#define GPIOA_BASE (AHB1_BASE + GPIOA_OFFSET)

/* ===== RCC addresses ===== */
#define RCC_OFFSET (0x3800UL)
#define RCC_BASE (AHB1_BASE + RCC_OFFSET)

/* ===== TIM2 addresses ===== */
#define TIM2_OFFSET (0x0000UL)
#define TIM2_BASE (APB1_BASE + TIM2_OFFSET)

/* ===== GPIO Registers Layout ===== */

typedef struct
{
    volatile uint32_t MODER;   /* offset 0x00 */
    volatile uint32_t OTYPER;  /* offset 0x04 */
    volatile uint32_t OSPEEDR; /* offset 0x08 */
    volatile uint32_t PUPDR;   /* offset 0x0C */
    volatile uint32_t IDR;     /* offset 0x10 */
    volatile uint32_t ODR;     /* offset 0x14 */
    volatile uint32_t BSRR;    /* offset 0x18 */
    volatile uint32_t LCKR;    /* offset 0x1C */
    volatile uint32_t AFR[2];  /* offset 0x20 (AFRL) and 0x24 (AFRH) */
} GPIO_TypeDef;

#define GPIOA ((GPIO_TypeDef *)GPIOA_BASE)

/* ===== RCC Registers Layout ===== */
typedef struct
{
    volatile uint32_t CR;       /* offset 0x00 */
    volatile uint32_t PLLCFGR;  /* offset 0x04 */
    volatile uint32_t CFGR;     /* offset 0x08 */
    volatile uint32_t CIR;      /* offset 0x0C */
    volatile uint32_t AHB1RSTR; /* offset 0x10 */
    volatile uint32_t AHB2RSTR; /* offset 0x14 */
    volatile uint32_t AHB3RSTR; /* offset 0x18 */
    uint32_t RESERVED0;         /* offset 0x1C */
    volatile uint32_t APB1RSTR; /* offset 0x20 */
    volatile uint32_t APB2RSTR; /* offset 0x24 */
    uint32_t RESERVED1[2];      /* offset 0x28, 0x2C */
    volatile uint32_t AHB1ENR;  /* offset 0x30 */
    volatile uint32_t AHB2ENR;  /* offset 0x34 */
    volatile uint32_t AHB3ENR;  /* offset 0x38 */
    uint32_t RESERVED2;         /* offset 0x3C */
    volatile uint32_t APB1ENR;  /* offset 0x40 */
    volatile uint32_t APB2ENR;  /* offset 0x44 */
} RCC_TypeDef;

#define RCC ((RCC_TypeDef *)RCC_BASE)

/* ===== SysTick (Cortex-M4 core peripheral) ===== */
#define SYSTICK_BASE (0xE000E010UL)

typedef struct
{
    volatile uint32_t CTRL;
    volatile uint32_t LOAD;
    volatile uint32_t VAL;
    volatile uint32_t CALIB;
} SYSTICK_TypeDef;

#define SYSTICK ((SYSTICK_TypeDef *)SYSTICK_BASE)

/* ===== TIM2 Registers Layout ===== */
typedef struct
{
    volatile uint32_t CR1;   /* 0x00 */
    volatile uint32_t CR2;   /* 0x04 */
    volatile uint32_t SMCR;  /* 0x08 */
    volatile uint32_t DIER;  /* 0x0C */
    volatile uint32_t SR;    /* 0x10 */
    volatile uint32_t EGR;   /* 0x14 */
    volatile uint32_t CCMR1; /* 0x18 */
    volatile uint32_t CCMR2; /* 0x1C */
    volatile uint32_t CCER;  /* 0x20 */
    volatile uint32_t CNT;   /* 0x24 */
    volatile uint32_t PSC;   /* 0x28 */
    volatile uint32_t ARR;   /* 0x2C */
    uint32_t RESERVED0;      /* 0x30 */
    volatile uint32_t CCR1;  /* 0x34 */
    volatile uint32_t CCR2;  /* 0x38 */
    volatile uint32_t CCR3;  /* 0x3C */
    volatile uint32_t CCR4;  /* 0x40 */
} TIM_TypeDef;

#define TIM2 ((TIM_TypeDef *)TIM2_BASE)

#endif