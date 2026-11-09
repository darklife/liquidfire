/*
 * Copyright (c) 2003, Lucas Mendes <lmendes@netbsd.com.br>
 * Copyright (c) 2003, Marcelo Samsoniuk <marcelos@bsi.com.br>
 *      All rights reserved.
 *
 * By using this file, you agree to the terms and conditions set
 * forth in the LICENSE file which can be found at the top level of
 * the liquidfire distribution.
 */

#include <stdio.h>
#include <port/core.h>
#include <port/timer.h>
#include <port/irq.h>

void timer_init(void) {

/*	struct VZ328TIMER 	*timer0=(struct VZ328TIMER *)VZ328TIMER1ADDR;
	struct VZ328TIMER	*timer1=(struct VZ328TIMER *)VZ328TIMER2ADDR;

	struct VZ328INTC 	*intc=(struct VZ328INTC *)VZ328INTCADDR;
*/
	/* TCTL = 0000 0000 0101 1001 */
/*
	timer0->TCTL=0x0059;
	timer0->TPRER=0;
	timer0->TCMP=32768;
	intc->IMR=0x0;
	intc->IVR=0x40;
*/
	fprintf(stdout,"timer0: timer enable with 100hz pulse (fix me)\n");

/*	asm("move.w #0x2000,%sr"); */

}
