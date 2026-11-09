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
#include <stdlib.h>
#include <mm.h>
#include <syscall.h>
#include <config.h>
#include <port/core.h>

extern int port_startup(void);
extern void syscall_init(void);
extern void syscall_test(void);

	FILE *stdout;

void __main(void) {

	stdout=fopen();

	fprintf(stdout,"Liquidfire/m68k version %s-%s\n",KERNELNAME,KERNELVERSION);
	fprintf(stdout,"(c) Marcelo Samsoniuk and Lucas Mendes\n\r");
	fprintf(stdout,"All Rights Reserved.\n\n");

	fprintf(stdout,"Running kernel..\n");
}

int main() {

	port_startup();

	fprintf(stdout,"syscalls: initializing the system call index table\n");

	syscall_init();

	fprintf(stdout,"syscalls: max system call functions is %d\n\n",MAXCALLS);

	syscall_test();

	fprintf(stdout,"p: 0x%x\n",(int)kmalloc(1,1,KERNELLEVEL));

	while(1);

	return 0;
}
