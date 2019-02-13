TARGET       = main

MCU          = attiny10
F_CPU        = 8000000

SRC_DIR      = src
INC_DIR      = include

SRC          = $(wildcard $(SRC_DIR)/*.c)
OBJ          = $(SRC:%.c=%.o)
INC          = $(wildcard $(INC_DIR)/*.h)

CC_FLAGS     = -Wall -g -Os -mmcu=$(MCU) -DF_CPU=$(F_CPU) -I include
LD_FLAGS     =

# Default target
all: $(TARGET).hex

%.hex: %.elf
	avr-objcopy -O ihex $< $@

%.elf: $(OBJ)
	avr-g++ $(LD_FLAGS) $(CC_FLAGS) -o $@ $^

%.o: %.c $(INC)
	avr-g++ $(CC_FLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ) $(TARGET).hex

burn: $(TARGET).hex
	avrdude -c usbasp -p t10 -U flash:w:$(TARGET).hex
