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
#include <mm.h>
#include <port/core.h>
#include <port/timer.h>
#include <port/fb.h>

extern void oslogo(void);

int port_startup(void) {

	fprintf(stdout,"fb: 160x160 with #1 bpp with base addr at 0x9000\n");

	fprintf(stdout,"mm: page size %d, page tree size %d\n",PAGESIZE,PAGETREE);
	fprintf(stdout,"mm: alloc memory track 0x%x-0x%x\n",RAMADDR,RAMADDR+RAMSIZE);

	fbshow(1,1,"Liquidfire for m68k",0);
	fbshow(1,11,"(c) by Samsoniuk,Mendes",0);
	fbshow(1,21,"All Rights Reserved.",0);
	
	oslogo();

	timer_init();

	return 0;
}
