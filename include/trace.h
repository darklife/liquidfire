/*
 * Copyright (c) 2003, Lucas Mendes <lmendes@netbsd.com.br>
 * Copyright (c) 2003, Marcelo Samsoniuk <marcelos@bsi.com.br>
 *      All rights reserved.
 *
 * By using this file, you agree to the terms and conditions set
 * forth in the LICENSE file which can be found at the top level of
 * the liquidfire distribution.
 */

#ifndef TRACE_H
#define TRACE_H

#include <sys/types.h>
#include <port/core.h>

#define trace_enter()	TRACE_ENTER
#define trace_leave()	TRACE_LEAVE

inline isr_t tracef(void);

#endif
