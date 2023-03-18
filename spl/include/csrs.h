#ifndef _CSRS_H_
#define _CSRS_H_

#include <defs.h>
#include <types.h>

#define csr_read(csr)                       \
({                                          \
    register u64 __v;                       \
    __asm__ volatile (                      \
        "csrr %[asm__v], " #csr             \
        : [asm__v] "=r" (__v)               \
        :                                   \
        : "memory"                          \
    );                                      \
    __v;                                    \
})

#define csr_write(csr, val)                         \
({                                                  \
    u64 __v = (u64)(val);                           \
    asm volatile ("csrw " #csr ", %0"               \
                    : : "r" (__v)                   \
                    : "memory");                    \
})

#endif