#ifndef CPU_H
#define CPU_H	1

#include "hal_common_includes.h"
#include <stdint.h>

#define CPU_TICKS_PER_MS	72000

void cpu_init(void); // This function calls all CPU HAL (Hardware Abstraction Layer)-specific functions that initialize the CPU clock, flash and peripherals.
void cpu_sw_delay(uint32_t ms); // A simple busy-loop delay function that blocks until the specified ms number of milliseconds have elapsed.

#endif