#ifndef __GPIO_H__
#define __GPIO_H__

#include "mm.h"

//The register’s memory address in reference is bus address, you should translate into physical address.
//GPIO has 41 registers
//GPIO Function Select 0-5
#define GPFSEL0         ((volatile unsigned int*)(MMIO_BASE+0x00200000))
#define GPFSEL1         ((volatile unsigned int*)(MMIO_BASE+0x00200004))
#define GPFSEL2         ((volatile unsigned int*)(MMIO_BASE+0x00200008))
#define GPFSEL3         ((volatile unsigned int*)(MMIO_BASE+0x0020000C))
#define GPFSEL4         ((volatile unsigned int*)(MMIO_BASE+0x00200010))
#define GPFSEL5         ((volatile unsigned int*)(MMIO_BASE+0x00200014))
//GPIO Pin Output Set 0-1
#define GPSET0          ((volatile unsigned int*)(MMIO_BASE+0x0020001C))
#define GPSET1          ((volatile unsigned int*)(MMIO_BASE+0x00200020))
//GPIO Pin Output Clear
#define GPCLR0          ((volatile unsigned int*)(MMIO_BASE+0x00200028))
#define GPCLR1          ((volatile unsigned int*)(MMIO_BASE+0x0020002C))
//GPIO Pin Level 
#define GPLEV0          ((volatile unsigned int*)(MMIO_BASE+0x00200034))
#define GPLEV1          ((volatile unsigned int*)(MMIO_BASE+0x00200038))
//GPIO Pin Event Detect Status 
#define GPEDS0          ((volatile unsigned int*)(MMIO_BASE+0x00200040))
#define GPEDS1          ((volatile unsigned int*)(MMIO_BASE+0x00200044))
//GPIO Pin Rising Edge Detect Enable 
#define GPREN0          ((volatile unsigned int*)(MMIO_BASE+0x0020004C))
#define GPREN1          ((volatile unsigned int*)(MMIO_BASE+0x00200050))
//GPIO Pin Falling Edge Detect Enable
#define GPFEN0          ((volatile unsigned int*)(MMIO_BASE+0x00200058))
#define GPFEN1          ((volatile unsigned int*)(MMIO_BASE+0x0020005C))
//GPIO Pin High Detect Enable
#define GPHEN0          ((volatile unsigned int*)(MMIO_BASE+0x00200064))
#define GPHEN1          ((volatile unsigned int*)(MMIO_BASE+0x00200068))
//GPIO Pin Low Detect Enable
#define GPLEN0          ((volatile unsigned int*)(MMIO_BASE+0x00200070))
#define GPLEN1          ((volatile unsigned int*)(MMIO_BASE+0x00200074))
//GPIO Pin Async. Rising Edge Detect
#define GPAREN0          ((volatile unsigned int*)(MMIO_BASE+0x0020007C))
#define GPAREN1          ((volatile unsigned int*)(MMIO_BASE+0x00200080))
//GPIO Pin Async. Falling Edge Detect 
#define GPAFEN0          ((volatile unsigned int*)(MMIO_BASE+0x00200088))
#define GPAFEN1          ((volatile unsigned int*)(MMIO_BASE+0x0020008C))
//GPIO Pin Pull-up/down Enable  / Clock
#define GPPUD           ((volatile unsigned int*)(MMIO_BASE+0x00200094))
#define GPPUDCLK0       ((volatile unsigned int*)(MMIO_BASE+0x00200098))
#define GPPUDCLK1       ((volatile unsigned int*)(MMIO_BASE+0x0020009C))

#endif // !__GPIO_H__