/*
 * Copyright (c) 2003, Lucas Mendes <lmendes@netbsd.com.br>
 * Copyright (c) 2003, Marcelo Samsoniuk <marcelos@bsi.com.br>
 *      All rights reserved.
 *
 * By using this file, you agree to the terms and conditions set
 * forth in the LICENSE file which can be found at the top level of
 * the liquidfire distribution.
 */

#ifndef FB_H
#define FB_H

#include <port/memory.h>

extern void fbshowraw(int,int,char *,int,int);
extern void fbshow(int,int,char *,int);
extern void fbpixel(int,int,int);
extern void fbxline(int,int,int,int);
extern void fbyline(int,int,int,int);
extern void fbbox(int,int,int,int,int);
extern void fbscroll(int);

#endif
