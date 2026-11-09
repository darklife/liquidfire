/*
 * Copyright (c) 2003, Lucas Mendes <lmendes@netbsd.com.br>
 * Copyright (c) 2003, Marcelo Samsoniuk <marcelos@bsi.com.br>
 *      All rights reserved.
 *
 * By using this file, you agree to the terms and conditions set
 * forth in the LICENSE file which can be found at the top level of
 * the liquidfire distribution.
 */

#include <strings.h>

int strlen(char *src) {

	int i;

	for(i=0;*src++;i++);

	return i;
}

char *strcpy(char *dst,char *src) {

	char *ret=dst;
	
	while((*dst++=*src++));
	
	return ret;
}

char *strcat(char *dst,char *src) {

	char *ret=dst;
	
	while(*dst++);
	while((*dst++=*src++));

	return ret;
}
