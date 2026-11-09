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
#include <sched.h>
#include <port/core.h>

	struct Task idle;

	struct Task *ssp=(struct Task *)&idle;

isr_t schedf(void) {

	static int i=0;

	CPUsave();

	SCHEDenter();

	/* while(ssp->state==SLEEP) ssp=ssp->next; */

	fprintf(stdout,"sched: %d\r",i++);

	SCHEDleave();

	CPUrestore();

	ireturn;
}
