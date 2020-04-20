ARMGNU=aarch64-linux-gnu-
CC=$(ARMGNU)gcc
#LDFLAGS=-T linker.ld -nostdlib

# directory architecture
SRC_DIR = src
BUILD_DIR = build
LINKER_FILE = $(SRC_DIR)/link.ld
START_FILE = $(SRC_DIR)/start.S
START_OBJ = $(BUILD_DIR)/start.o

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
CFLAGS = -Wall -I include -O2 -ffreestanding -nostdinc -nostdlib -nostartfiles

all:  kernel8.img
# build boot 
$(START_OBJ): $(START_FILE)
	$(CC) $(CFLAGS) -c $< -o $@
# build kernel
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

kernel8.img: $(START_OBJ) $(OBJS)
	$(ARMGNU)ld -nostdlib -nostartfiles $(START_OBJ) $(OBJS) -T $(LINKER_FILE) -o kernel8.elf
	$(ARMGNU)objcopy -O binary kernel8.elf kernel8.img

clean:
	rm build/* kernel8.*
	#rm kernel8.elf *.o >/dev/null 2>/dev/null || true