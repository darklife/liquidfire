/*
 * Copyright (c) 2003, Lucas Mendes <lmendes@netbsd.com.br>
 * Copyright (c) 2003, Marcelo Samsoniuk <marcelos@bsi.com.br>
 *      All rights reserved.
 *
 * By using this file, you agree to the terms and conditions set
 * forth in the LICENSE file which can be found at the top level of
 * the liquidfire distribution.
 */

#include <mm.h>
#include <sys/types.h>

	extern struct Task *ssp;

void *vm_map(int size) {

	/* pid_t pid=ssp->pid; */
	pid_t pid=1;

	return kmalloc(pid,size,USERLEVEL);
}

void vm_unmap(pid_t pid) {

	kfreeall(pid);
}
