/*
 * Copyright (c) 2003, Lucas Mendes <lmendes@netbsd.com.br>
 * Copyright (c) 2003, Marcelo Samsoniuk <marcelos@bsi.com.br>
 *      All rights reserved.
 *
 * By using this file, you agree to the terms and conditions set
 * forth in the LICENSE file which can be found at the top level of
 * the liquidfire distribution.
 */

SRAMADDR	= 0
SRAMSIZE	= 0xffff
ROMADDR		= 0x10c00000

	.globl	_start,syscallf,schedf,tracef

	.data

	.long SRAMADDR+SRAMSIZE-1	/* %ssp */
	.long ROMADDR+_start		/* %pc at _start */
	.long 0				/* bus error */
	.long 0				/* address error */
	.long 0				/* illegal instruction */
	.long 0				/* divde-by-zero */
	.long 0				/* CHK instruction */
	.long 0				/* TRAPV instruction */
	.long 0				/* privilege violation */
	.long tracef			/* trace */
	.long 0				/* line 1010 emulator */
	.long 0				/* line 1111 emulator */
	.long 0,0,0
	.long 0				/* unitialized interrupt vector */

	.long 0,0,0,0,0,0,0,0

	.long 0				/* spurious interrupt */
	.long 0				/* level #1 interrupt autovector */
	.long 0				/* level #2 interrupt autovector */
	.long 0				/* level #3 interrupt autovector */
	.long 0				/* level #4 interrupt autovector */
	.long 0				/* level #5 interrupt autovector */
	.long 0				/* level #6 interrupt autovector */
	.long 0				/* level #7 interrupt autovector */

	.long 0				/* trap #0 */
	.long syscallf			/* trap #1 (syscallf) */
	.long 0				/* trap #2 */
	.long 0				/* trap #3 */
	.long 0				/* trap #4 */
	.long 0				/* trap #5 */
	.long 0				/* trap #6 */
	.long 0				/* trap #7 */
	.long 0				/* trap #8 */
	.long 0				/* trap #9 */
	.long 0				/* trap #10 */
	.long 0				/* trap #11 */
	.long 0				/* trap #12 */
	.long 0				/* trap #13 */
	.long 0				/* trap #14 */
	.long 0				/* trap #15 */

	.long 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0

	.long 0				/* Interrupt level #1 */
	.long 0				/* #2 */
	.long 0				/* #3 */
	.long 0				/* #4 */
	.long 0				/* #5 */
	.long schedf			/* #6 */
	.long 0				/* #7 */

	.long 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	.long 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	.long 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	.long 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	.long 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	.long 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
