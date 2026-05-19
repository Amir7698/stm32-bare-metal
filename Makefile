# === Project ===
TARGET = firmware

# === Toolchain ===
CC      = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
SIZE    = arm-none-eabi-size

# === Flags ===
CPU     = -mcpu=cortex-m4 -mthumb -mfloat-abi=soft
CFLAGS  = $(CPU) -Wall -O0 -g -Iinc -ffreestanding
LDFLAGS = $(CPU) -Tlinker/stm32f446re.ld -nostdlib -Wl,--gc-sections

# === Sources ===
C_SRCS   = src/main.c
ASM_SRCS = startup/startup_stm32f446re.s

# === Objects ===
C_OBJS   = $(C_SRCS:.c=.o)
ASM_OBJS = $(ASM_SRCS:.s=.o)
OBJS     = $(C_OBJS) $(ASM_OBJS)

# === Build rules ===
all: $(TARGET).bin

$(TARGET).elf: $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $@

$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) -O binary $< $@
	$(SIZE) $<
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.s
	$(CC) $(CFLAGS) -c $< -o $@

# === Utility rules ===
flash: $(TARGET).bin
	STM32_Programmer_CLI -c port=SWD mode=UR -w $< 0x08000000 -rst
clean:
	rm -f $(OBJS) $(TARGET).elf $(TARGET).bin

.PHONY: all flash clean