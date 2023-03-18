#ifndef _HEADER_H_
#define _HEADER_H_
#include "gpio.h"
#include <dram.h>
#include <types.h>

typedef struct __attribute__((__packed__)) {
    u32 jump_instruction;
    u64 magic_number;
    u32 checksum;
    u32 length;
    u32 public_header_size;   // size of this struct
    u32 public_header_version;
    u32 return_address;
    u32 run_address;
    u32 boot_cpu;
    u64 platform_information;
} PublicHeader;

typedef struct __attribute__((__packed__)) {
    u32 private_header_size;
    u8  debug_mode;
    u8  power_mode;
    u16 reserved;
    MemoryParamters memory_parameters;

    i32 uart_port;
    GpioConfig uart_gpio_config[2];

    i32 enable_jtag;
    GpioConfig jtag_gpio_config[5];

    GpioConfig storage_gpio_config[32];
    i8 storage_data[256]; // Is this also reserved?
} PrivateHeader;

typedef struct __attribute__((__packed__)) {

} BootHeader;

#endif