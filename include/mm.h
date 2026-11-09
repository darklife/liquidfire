/*
 * Copyright (c) 2003, Lucas Mendes <lmendes@netbsd.com.br>
 * Copyright (c) 2003, Marcelo Samsoniuk <marcelos@bsi.com.br>
 *      All rights reserved.
 *
 * By using this file, you agree to the terms and conditions set
 * forth in the LICENSE file which can be found at the top level of
 * the liquidfire distribution.
 */

#ifndef MM_H
#define MM_H

#ifdef KERNEL

#include <port/memory.h>
#include <sys/types.h>

#define PAGESIZE	1024
#define PAGETREE	1024

#define KERNELLEVEL	0
#define USERLEVEL	1

extern void kfreeall(int);
extern void kfree(void *);
extern void *kmalloc(pid_t,int,long);

extern void vm_unmap(pid_t);
extern void *vm_map(int);
#endif

struct mPage {

	struct mPage *next,*previous;

	int size;

	char data[0];
};

#endif
