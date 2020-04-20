#ifndef __UART_H__
#define __UART_H__

#include "mm.h"

/* Auxilary mini UART registers */
#define AUX_ENABLES             ((volatile unsigned int*)(MMIO_BASE+0x00215004))
#define AUX_MU_IO_REG           ((volatile unsigned int*)(MMIO_BASE+0x00215040))
#define AUX_MU_IER_REG          ((volatile unsigned int*)(MMIO_BASE+0x00215044))
#define AUX_MU_IIR_REG          ((volatile unsigned int*)(MMIO_BASE+0x00215048))
#define AUX_MU_LCR_REG          ((volatile unsigned int*)(MMIO_BASE+0x0021504C))
#define AUX_MU_MCR_REG          ((volatile unsigned int*)(MMIO_BASE+0x00215050))
#define AUX_MU_LSR_REG          ((volatile unsigned int*)(MMIO_BASE+0x00215054))
#define AUX_MU_MSR_REG          ((volatile unsigned int*)(MMIO_BASE+0x00215058))
#define AUX_MU_SCRATCH          ((volatile unsigned int*)(MMIO_BASE+0x0021505C))
#define AUX_MU_CNTL_REG         ((volatile unsigned int*)(MMIO_BASE+0x00215060))
#define AUX_MU_STAT_REG         ((volatile unsigned int*)(MMIO_BASE+0x00215064))
#define AUX_MU_BAUD_REG         ((volatile unsigned int*)(MMIO_BASE+0x00215068))
#define AUX_SPI0_CNTL0_REG      ((volatile unsigned int*)(MMIO_BASE+0x00215080))
#define AUX_SPI0_CNTL1_REG      ((volatile unsigned int*)(MMIO_BASE+0x00215084))
#define AUX_SPI0_STAT_REG       ((volatile unsigned int*)(MMIO_BASE+0x00215088))
#define AUX_SPI0_IO_REG         ((volatile unsigned int*)(MMIO_BASE+0x00215090))
#define AUX_SPI0_PEEK_REG       ((volatile unsigned int*)(MMIO_BASE+0x00215094))
#define AUX_SPI1_CNTL0_REG      ((volatile unsigned int*)(MMIO_BASE+0x002150C0))
#define AUX_SPI1_CNTL1_REG      ((volatile unsigned int*)(MMIO_BASE+0x002150C4))
#define AUX_SPI1_STAT_REG       ((volatile unsigned int*)(MMIO_BASE+0x002150C8))
#define AUX_SPI1_IO_REG         ((volatile unsigned int*)(MMIO_BASE+0x002150D0))
#define AUX_SPI1_PEEK_REG       ((volatile unsigned int*)(MMIO_BASE+0x002150D4))

void uart_init();
void uart_send(unsigned int c);
char uart_getc();
void uart_puts(char *s);
int uart_readline (int size, char *buf);

#endif 