#include "state.h"
#include "mm.h"

#define PM_PASSWORD 0x5a000000
#define PM_RSTC ((volatile unsigned int*)(MMIO_BASE+0x0010001c))
#define PM_WDOG ((volatile unsigned int*)(MMIO_BASE+0x00100024))

#define PM_RSTC_FULLRST 0x00000020
#define set(a, b) *a = b
// #define tick 100

void reset(int tick){ // reboot after watchdog timer expire
  set(PM_RSTC, PM_PASSWORD | PM_RSTC_FULLRST); // full reset
  set(PM_WDOG, PM_PASSWORD | tick); // number of watchdog tick
}

void cancel_reset() {
  set(PM_RSTC, PM_PASSWORD | 0); // full reset
  set(PM_WDOG, PM_PASSWORD | 0); // number of watchdog tick
}