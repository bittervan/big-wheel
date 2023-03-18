#include "dram.h"
#include <types.h>
#include <dram.h>

extern i32 raw_initialize_dram(int type, const MemoryParamters *memory_parameters);

i32 initialize_dram(const MemoryParamters *memory_parameters) {
    return raw_initialize_dram(0, memory_parameters);
}