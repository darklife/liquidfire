/*
 * Copyright (c) 2003, Lucas Mendes <lmendes@netbsd.com.br>
 * Copyright (c) 2003, Marcelo Samsoniuk <marcelos@bsi.com.br>
 *      All rights reserved.
 *
 * By using this file, you agree to the terms and conditions set
 * forth in the LICENSE file which can be found at the top level of
 * the liquidfire distribution.
 */

#include <port/memory.h>

	.globl	main,syscall

	.text

.align	4
.globl	_start
_start:

	move.l	#0x00011f07,CSC		/* chip select A1 mask */

	move.w	#0x2410,PLLCR
	move.w	#0x0123,PLLFSR

	move.w	#0x010b,UBAUD		/* 9600 bps */
	move.w	#0x0800,UTX		/* ignore cts */
	move.w	#0xe100,USTCNT		/* enable UART */

	move.l	#VRAM,LSSA		/* vram address */
	move.b	#0xa,LVPW
	move.w	#159,LXMAX		/* 160 */
	move.w	#159,LYMAX		/* 160 */
	move.b	#9,LBAR
	move.b	#0,LPXCD
	move.b	#0x04,LPICF
	move.b	#0x82,LCKCON

	move.w	#0x2700,%sr		/* 0010 0111 0000 0000 */
	lea	RAMADDR+RAMSIZE-4,%sp

	move.l	#ROMADDR,%a0
	move.l	#RAMADDR,%a1
	move.l	#0xffff,%d0
.L1:	move.b	(%a0)+,(%a1)+
	dbf	%d0,.L1

	bsr	clear
	bsr	main
	bsr	halt
	
.align	4
.globl	halt
halt:

	stop #0
	bra	halt

.align	4
.globl	clear
clear:

	move.l	#VRAM,%a0
	eor.l	%d0,%d0
	not.l	%d0
	move.l	#799,%d1
.L2:	move.l	%d0,(%a0)+
	dbf	%d1,.L2

	rts

.align	4
.globl	oslogo
oslogo:
	
	move.l 	%d0,-(%a7)
	move.l 	%a0,-(%a7)

	move.l  #0x9013,%a0
	move.l	#20,%d0
	move.b  #0,(%a0)
	add.l	%d0,%a0
	move.b 	#0x66,(%a0)
	add.l	%d0,%a0
	move.b	#0,(%a0)
	add.l	%d0,%a0
	move.b	#0x18,(%a0)
	add.l	%d0,%a0
	move.b	#0x42,(%a0)
	add.l	%d0,%a0
	move.b	#0x3c,(%a0)
	add.l	%d0,%a0
	move.b  #0,(%a0)

	move.l	(%a7)+,%a0
	move.l	(%a7)+,%d0

	rts
