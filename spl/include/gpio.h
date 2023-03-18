#ifndef _GPIO_H_
#define _GPIO_H_

#include <types.h>

typedef struct __attribute__((__packed__)) {
    i8 port;                /* PA, PB, ..., PN, ...         */
    i8 port_number;         /* PA01, PA02, ...              */
    i8 function_number;     /* input, output, disabled      */
    i8 pull_number;         /* pull up, pull down, no pull  */
    i8 drive_level;         /* current level, 0-3           */
    i8 data;                /* initial value for input/ouput*/
    u16 reserved;
} GpioConfig; // GPIO

#endif