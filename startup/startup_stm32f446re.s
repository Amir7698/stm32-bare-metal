.syntax unified
.cpu cortex-m4
.fpu softvfp
.thumb

.global vector_table
.global Reset_Handler

/* Symbols from the linker script */
.word _sidata    /* start of .data init values in flash */
.word _sdata     /* start of .data section in RAM */
.word _edata     /* end of .data section in RAM */
.word _sbss      /* start of .bss section */
.word _ebss      /* end of .bss section */

/* ===== Reset Handler ===== */
.section .text.Reset_Handler
.weak Reset_Handler
.type Reset_Handler, %function
Reset_Handler:
    /* Set stack pointer */
    ldr   r0, =_estack
    mov   sp, r0

    /* Copy .data from flash to RAM */
    ldr   r0, =_sdata
    ldr   r1, =_edata
    ldr   r2, =_sidata
    movs  r3, #0
    b     copy_check
copy_loop:
    ldr   r4, [r2, r3]
    str   r4, [r0, r3]
    adds  r3, r3, #4
copy_check:
    adds  r4, r0, r3
    cmp   r4, r1
    bcc   copy_loop

    /* Zero out .bss */
    ldr   r2, =_sbss
    ldr   r4, =_ebss
    movs  r3, #0
    b     zero_check
zero_loop:
    str   r3, [r2]
    adds  r2, r2, #4
zero_check:
    cmp   r2, r4
    bcc   zero_loop

    /* Call main */
    bl    main

    /* If main returns, loop forever */
hang:
    b     hang
.size Reset_Handler, .-Reset_Handler

/* ===== Default Handler ===== */
.section .text.Default_Handler,"ax",%progbits
Default_Handler:
    b     Default_Handler

/* ===== Vector Table ===== */
.section .isr_vector,"a",%progbits
.type vector_table, %object
vector_table:
    .word _estack              /* Initial stack pointer */
    .word Reset_Handler        /* Reset */
    .word Default_Handler      /* NMI */
    .word Default_Handler      /* HardFault */
    .word Default_Handler      /* MemManage */
    .word Default_Handler      /* BusFault */
    .word Default_Handler      /* UsageFault */
    .word 0
    .word 0
    .word 0
    .word 0
    .word Default_Handler      /* SVCall */
    .word Default_Handler      /* DebugMonitor */
    .word 0
    .word Default_Handler      /* PendSV */
    .word Default_Handler      /* SysTick */
.size vector_table, .-vector_table