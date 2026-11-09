/*
 * Copyright (c) 2003, Lucas Mendes <lmendes@netbsd.com.br>
 * Copyright (c) 2003, Marcelo Samsoniuk <marcelos@bsi.com.br>
 *      All rights reserved.
 *
 * By using this file, you agree to the terms and conditions set
 * forth in the LICENSE file which can be found at the top level of
 * the liquidfire distribution.
 */

SYS_write	= 0x4
stdout		= 1

buffer:		.ascii "this text was wrote by sys_write trap function! :)\n"

.align	4
.globl	syscall_test
syscall_test:

	move.l	#stdout,%d1
	lea	buffer,%a0
	move.l	#51,%d2

	move.l	#SYS_write,%d0

	trap	#1

	rts
