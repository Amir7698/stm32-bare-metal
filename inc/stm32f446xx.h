#ifndef STM32F446XX_H
#define STM32F446XX_H
#include <stdint.h>

/* ===== Base addresses ===== */
#define PERIPH_BASE (0x40000000UL)

/* ===== AHB1 addresses ===== */
#define AHB1_OFFSET (0x0020000UL)
#define AHB1_BASE (PERIPH_BASE + AHB1_OFFSET)

/* ===== GPIOA addresses ===== */
#define GPIOA_OFFSET (0x0000UL)
#define GPIOA_BASE (AHB1_BASE + GPIOA_OFFSET)

/* ===== RCC addresses ===== */
#define RCC_OFFSET (0x3800UL)
#define RCC_BASE (AHB1_BASE + RCC_OFFSET)

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

#endif