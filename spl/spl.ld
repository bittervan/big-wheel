OUTPUT_ARCH("riscv")
ENTRY(_entry)
SECTIONS {
    . = 0x20000;
    . = ALIGN(4);
    .spl_header: {
        header.o.header
    }
    .text: {
        *(.text.spl_entry)
        *(.text)
    }
    . = ALIGN(16);
    .rodata: {
        *(.rodata)
    }
    . = ALIGN(16);
    .data: {
        *(.data)
    }
    . = ALIGN(4);
    .bss: {
        __bss_start = .;
        *(.bss)
        __bss_end = .;
    }
    .ALIGN(4);
    ASSERT(. <= (0x30000), "spl size exceeded.")
}