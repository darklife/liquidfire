/*
 * Copyright (c) 2003, Lucas Mendes <lmendes@netbsd.com.br>
 * Copyright (c) 2003, Marcelo Samsoniuk <marcelos@bsi.com.br>
 *      All rights reserved.
 *
 * By using this file, you agree to the terms and conditions set
 * forth in the LICENSE file which can be found at the top level of
 * the liquidfire distribution.
 */

#ifndef CORE_H
#define CORE_H

#include <memory.h>

#define ireturn		asm("rte")

#define SYSCALLreg	asm("%d0")

#define CPUsave()	asm("movem.l %a0-%a6/%d0-%d7,%sp@-")
#define CPUrestore()	asm("movem.l %sp@+,%a0-%a6/%d0-%d7")

#define SCHEDenter()	asm("link %a6,#0")
#define SCHEDleave()	asm("unlk %a6")

#define TRACEenter()	asm("link %a6,#0")
#define TRACEleave()	asm("unlk %a6")

extern void UARTputc(char);

#define CONSOLEputc(c)	UARTputc(c)

#endif
