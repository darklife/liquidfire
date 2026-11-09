/*
 * Copyright (c) 2003, Lucas Mendes <lmendes@netbsd.com.br>
 * Copyright (c) 2003, Marcelo Samsoniuk <marcelos@bsi.com.br>
 *      All rights reserved.
 *
 * By using this file, you agree to the terms and conditions set
 * forth in the LICENSE file which can be found at the top level of
 * the liquidfire distribution.
 */

#include <unistd.h>
#include <sys/types.h>

long sys_read(void) {

	register int d asm("%d1")=d;

	register char *p asm("%a0")=p;

	register size_t n asm("%d2")=n;

	return read(d,p,n);
}

long sys_write(void) {

	register int d asm("%d1")=d;

	register char *p asm("%a0")=p;

	register size_t n asm("%d2")=n;

	return write(d,p,n);
}
