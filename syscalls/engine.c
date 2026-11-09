/*
 * Copyright (c) 2003, Lucas Mendes <lmendes@netbsd.com.br>
 * Copyright (c) 2003, Marcelo Samsoniuk <marcelos@bsi.com.br>
 *      All rights reserved.
 *
 * By using this file, you agree to the terms and conditions set
 * forth in the LICENSE file which can be found at the top level of
 * the liquidfire distribution.
 */

#include <callnr.h>
#include <errno.h>
#include <syscall.h>
#include <port/core.h>
#include <sys/types.h>

extern long sys_read(int,void *,size_t);
extern long sys_write(int,void *,size_t);

	long (*syscallp[MAXCALLS])();

long sys_null(void) {

	return -ENOSYS;
}

void syscall_init(void) {

	int i;

	for(i=0;i<MAXCALLS;syscallp[i++]=sys_null);

	syscallp[READ]=sys_read;
	syscallp[WRITE]=sys_write;
}

syscall_t syscallf(void) {

	register long r SYSCALLreg=r;

	long l;

	if(r>MAXCALLS) {

		r=(-ENOSYS);
		ireturn;
	}

	CPUsave();

	l=syscallp[r]();

	CPUrestore();

	r=l;

	ireturn;
}
