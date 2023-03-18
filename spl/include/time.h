#ifndef _TIME_H_
#define _TIME_H_

#include <csrs.h>
#include <defs.h>
#include <types.h>

u64 get_time_cycles();
u64 get_time_us();
u64 get_time_ms();

void delay_cycles(u64 count);
void delay_us(u64 count);
void delay_ms(u64 count);

#endif