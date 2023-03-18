#ifndef _DRAM_H_
#define _DRAM_H_

#include <types.h>

typedef struct __attribute__((__packed__)) {
    u32 dram_clk;
    u32 dram_type;
    u32 dram_zq;
    u32 dram_odt_en;
    u32 dram_para1;
    u32 dram_para2;
    u32 dram_mr0;
    u32 dram_mr1;
    u32 dram_mr2;
    u32 dram_mr3;
    u32 dram_tpr0;
    u32 dram_tpr1;
    u32 dram_tpr2;
    u32 dram_tpr3;
    u32 dram_tpr4;
    u32 dram_tpr5;
    u32 dram_tpr6;
    u32 dram_tpr7;
    u32 dram_tpr8;
    u32 dram_tpr9;
    u32 dram_tpr10;
    u32 dram_tpr11;
    u32 dram_tpr12;
    u32 dram_tpr13;
    u32 reserved[8];
} MemoryParamters;

i32 initialize_dram(const MemoryParamters *memory_parameters); 

#endif