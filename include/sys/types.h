/*
 * Copyright (c) 2003, Lucas Mendes <lmendes@netbsd.com.br>
 * Copyright (c) 2003, Marcelo Samsoniuk <marcelos@bsi.com.br>
 *      All rights reserved.
 *
 * By using this file, you agree to the terms and conditions set
 * forth in the LICENSE file which can be found at the top level of
 * the liquidfire distribution.
 */

#ifndef TYPES_H
#define TYPES_H

typedef void			syscall_t,trap_t,isr_t;

typedef unsigned char		uid_t,gid_t,pid_t;

typedef signed int		ssize_t;
typedef unsigned int		size_t;

typedef unsigned char		u_int8_t;
typedef unsigned short		u_int16_t;
typedef unsigned long		u_int32_t;
typedef unsigned long long	u_int64_t;

typedef unsigned char		int8_t;
typedef unsigned short		int16_t;
typedef unsigned long		int32_t;
typedef unsigned long long	int64_t;

#endif
