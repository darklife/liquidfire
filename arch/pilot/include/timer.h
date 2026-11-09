/*
 * Copyright (c) 2003, Lucas Mendes <lmendes@netbsd.com.br>
 * Copyright (c) 2003, Marcelo Samsoniuk <marcelos@bsi.com.br>
 *      All rights reserved.
 *
 * By using this file, you agree to the terms and conditions set
 * forth in the LICENSE file which can be found at the top level of
 * the liquidfire distribution.
 */

#ifndef TIMER_H
#define TIMER_H

	struct VZ328TIMER {

		unsigned short 	TCTL,
				TPRER,
				TCMP,
				TCP,
				TCN,
				TSTAT;			
	};

#ifdef KERNEL

#define VZ328TIMER1ADDR	0xfffff600
#define VZ328TIMER2ADDR	0xfffff610

extern void timer_init(void);

#endif

#endif
