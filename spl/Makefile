CC = riscv64-unknown-elf-gcc
LD = riscv64-unknown-elf-ld
PYTHON = python3
OBJCOPY = riscv64-unknown-elf-objcopy
CFLAGS = -O0

C_SRC = $(wildcard *.c)
C_OBJ = $(C_SRC:%.c=%.o)

ASM_SRC = $(wildcard *.S)
ASM_OBJ = $(ASM_SRC:%.S=%.o)

LINKER_SCRIPT = $(wildcard *.ld)

INCLUDE = ./include

all: spl.bin

spl.bin: spl.elf
	$(OBJCOPY) spl.elf -O binary image.raw
	$(PYTHON) ./scripts/gen_checksum.py image.raw spl.bin

spl.elf: $(C_OBJ) $(ASM_OBJ)
	$(LD) $(CFLAGS) -T $(LINKER_SCRIPT) -o spl.elf $(C_OBJ) $(ASM_OBJ)

$(C_OBJ):%.o:%.c
	$(CC) $(CFLAGS) -o $@ -I$(INCLUDE) -c $<

$(ASM_OBJ):%.o:%.S
	$(CC) $(CFLAGS) -o $@ -I$(INCLUDE) -c $<

clean:
	rm -f *.o
	rm -f spl.elf
	rm -f image.raw
	rm -f spl.bin