#include <csrs.h>
#include <time.h>

u64 get_time_cycles() {
    return csr_read(time);
}

u64 get_time_us() {
    return get_time_cycles() / 24;
}

u64 get_time_ms() {
    return get_time_cycles() / 24000;
}

void delay_cycles(u64 count) {
    u64 current_cycle = get_time_cycles();
    u64 target_cycle = current_cycle + count;
    
    if (target_cycle < current_cycle) { // Wrapping around
        while (get_time_cycles() > current_cycle || get_time_cycles() < target_cycle);
    } else {
        while (get_time_cycles() < target_cycle);
    }
}

void delay_us(u64 count) {
    delay_cycles(count * 24);
}

void delay_ms(u64 count) {
    delay_cycles(count * 24000);
}