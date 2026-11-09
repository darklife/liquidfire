/*
 * Copyright (c) 2003, Lucas Mendes <lmendes@netbsd.com.br>
 * Copyright (c) 2003, Marcelo Samsoniuk <marcelos@bsi.com.br>
 *      All rights reserved.
 *
 * By using this file, you agree to the terms and conditions set
 * forth in the LICENSE file which can be found at the top level of
 * the liquidfire distribution.
 */

#ifndef SCHED_H
#define SCHED_H

#include <sys/types.h>

#define WACKUP	0
#define SLEEP	1

#include <port/core.h>

struct Task {

	struct Task *next,*previous;

	uid_t uid;

	gid_t gid;

	pid_t pid;

	u_int8_t state;

	unsigned long sp;

	void *vm;
};

#endif
