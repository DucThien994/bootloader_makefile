CC        = arm-none-eabi-gcc
CPU       = -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard
LDSCRIPT  = STM32F411VETX_FLASH.ld

CFLAGS    = $(CPU) -std=gnu11 -specs=nano.specs -MMD -MP 
LDFLAGS   = $(CPU) -std=gnu11 -T$(LDSCRIPT) -Wl,-Map=output.map -Wl,--gc-sections --specs=nano.specs --specs=nosys.specs -static

SRCS      = main.c adc.c usart.c timer.c 
OBJS      = $(SRCS:.c=.o) startup.o
DEPS      = $(SRCS:.c=.d) 
TARGET    = firmware.elf 

all: $(TARGET) firmware.bin

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

startup.o: startup_stm32f411vetx.s
	$(CC) $(CPU) -std=gnu11 -x assembler-with-cpp -c $< -o $@

firmware.bin: $(TARGET)
	arm-none-eabi-objcopy -O binary $< $@

-include $(DEPS)

clean: 
	rm -f $(OBJS) $(DEPS) $(TARGET) firmware.bin output.map

.PHONY: all clean