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

	struct VZ328INTC {

		unsigned char 	IVR;
		unsigned short	ICR;
		unsigned int	IMR,
				RES,
				ISR,
				IPR;
		unsigned short	ILCR;
	};

#ifdef KERNEL

#define VZ328INTCADDR 0xfffff300

extern void irq_mask(long long);

#endif

#endif
