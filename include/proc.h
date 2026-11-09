/*
 * Copyright (c) 2003, Lucas Mendes <lmendes@netbsd.com.br>
 * Copyright (c) 2003, Marcelo Samsoniuk <marcelos@bsi.com.br>
 *      All rights reserved.
 *
 * By using this file, you agree to the terms and conditions set
 * forth in the LICENSE file which can be found at the top level of
 * the liquidfire distribution.
 */

#ifndef PROC_H
#define PROC_H

#ifdef KERNEL
#define STACK_SIZE	2048

#define FIRST_SR	0x0
#endif

struct task_struct {

	struct task_struct *next,*previous;

	uid_t uid;

	gid_t gid;

	pid_t pid;

	unsigned long sp;

	void *vm;
};

#endif
