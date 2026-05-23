# STM32 Bare-Metal PWM Driver

Register-level firmware for STM32F446RE (NUCLEO board) written from scratch — no HAL, no Cube, no CMSIS abstraction. The goal is a working, scope-verified PWM driver that demonstrates direct register manipulation, interrupt-driven timing, and a clean Make-based build pipeline.

> 🚧 **Work in progress** — building incrementally as a portfolio project for embedded firmware roles.

---

## What's working today

- ✅ **Bare-metal GPIO toggle** — PA5 (onboard green LED) driven via direct register writes
- ✅ **Custom build system** — Makefile, linker script, startup file, ARM GCC toolchain (no IDE lock-in)
- ✅ **SysTick timing** — Cortex-M4 SysTick configured for 1 ms interrupts, with `delay_ms()` and `millis()` API
- ✅ **Interrupt-driven** — `SysTick_Handler` hooked into the vector table, increments a millisecond counter
- ✅ **LED blinks at exactly 1 Hz** on hardware, verified visually

---

## Roadmap

| Phase                                                      | Status         |
| ---------------------------------------------------------- | -------------- |
| 0 — Toolchain setup (MSYS2, ARM GCC, STM32_Programmer_CLI) | ✅ Done        |
| 1 — GPIO + bare-metal blink                                | ✅ Done        |
| 2 — SysTick precise timing                                 | ✅ Done        |
| 3 — Timer/PWM driver (multi-channel, runtime config)       | ⏭️ In progress |
| 4 — Scope verification + documentation polish              | ⏭️ Planned     |
| 5 — Host-side unit tests (Unity) **OR** GitHub Actions CI  | ⏭️ Planned     |

---

## Hardware

- **Board:** STM32 NUCLEO-F446RE
- **MCU:** STM32F446RE (ARM Cortex-M4, 180 MHz capable, currently running at 16 MHz HSI)
- **Debugger:** Onboard ST-LINK/V2-1 via SWD

---

## Build & flash

Requires `arm-none-eabi-gcc` and `STM32_Programmer_CLI` in PATH. Tested on Windows + MSYS2 MINGW64.

```bash
make             # build firmware.elf and firmware.bin
make flash       # flash to the board over SWD and reset
make clean       # remove build artifacts
```

Current firmware size: **348 B flash, ~1.5 KB RAM** (mostly reserved stack).

---

## Project structure

stm32-bare-metal/
├── inc/
│ ├── stm32f446xx.h # Register definitions (GPIO, RCC, SysTick)
│ └── systick.h # SysTick driver API
├── src/
│ ├── main.c # Application: 1 Hz LED blink on PA5
│ └── systick.c # SysTick driver implementation
├── startup/
│ └── startup_stm32f446re.s # Reset handler + vector table
├── linker/
│ └── stm32f446re.ld # Memory layout (512 KB flash, 128 KB RAM)
└── Makefile # Build pipeline

---

## Why bare-metal?

Most STM32 tutorials lean on HAL or Cube-generated code, which hides what's actually happening at the register level. This project deliberately writes everything from scratch — reading the STM32F446xx Reference Manual (RM0390) and the ARM Cortex-M4 Generic User Guide directly — to demonstrate:

- Reading a Reference Manual and translating bit definitions into working C
- Deriving timing parameters (PSC, ARR, SysTick reload) from first principles
- Building and linking ARM firmware without IDE-specific glue
- Hooking interrupt handlers into the vector table

---

## Author

Amirhossein Mohtashami — M.Sc. Electronic Engineering, Politecnico di Torino
Embedded Firmware Engineer
