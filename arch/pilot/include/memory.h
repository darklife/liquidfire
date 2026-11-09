#ifndef MEMORY_H
#define MEMORY_H

#define SRAMADDR	0
#define SRAMSIZE	0xffff

#define ROMADDR		0x10c00000
#define ROMSIZE		0x10400

#define RAMADDR		0x10000000
#define RAMSIZE		0x100000

#define FLASHADDR	0x10c10400
#define FLASHSIZE	0xfec00

#define VRAM		0x9000

/* chip select */

#define CSC		0xfffff114

/* UART */

#define USTCNT		0xfffff900
#define UBAUD		0xfffff902
#define UTX		0xfffff906

/* LCD */

#define LSSA		0xfffffa00
#define LVPW		0xfffffa05
#define LXMAX		0xfffffa08
#define LYMAX		0xfffffa0a
#define LBAR		0xfffffa29
#define LPXCD		0xfffffa25
#define LPICF		0xfffffa20
#define LCKCON		0xfffffa27

/* PLL */

#define PLLCR		0xfffff200
#define PLLFSR		0xfffff202

#endif
