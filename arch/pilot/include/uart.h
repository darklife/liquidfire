/*
 * Copyright (c) 2003, Lucas Mendes <lmendes@netbsd.com.br>
 * Copyright (c) 2003, Marcelo Samsoniuk <marcelos@bsi.com.br>
 *      All rights reserved.
 *
 * By using this file, you agree to the terms and conditions set
 * forth in the LICENSE file which can be found at the top level of
 * the liquidfire distribution.
 */

#ifndef IRQ_H
#define IRQ_H

#include <sys/types.h>

	struct UX {

		short ctrl:8;

		short data:8;
	};

	struct EZ328UART {

		short USTCNT;
		short UBAUD;

		struct UX URX;
		struct UX UTX;

		short UMISC;
	};

#ifdef KERNEL

#define EZ328UARTADDR 0xfffff900

extern void port_uart_putc(char);
extern void port_uart_write(void *,size_t);

#endif

#endif
