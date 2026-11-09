/*
 * Copyright (c) 2003, Lucas Mendes <lmendes@netbsd.com.br>
 * Copyright (c) 2003, Marcelo Samsoniuk <marcelos@bsi.com.br>
 *      All rights reserved.
 *
 * By using this file, you agree to the terms and conditions set
 * forth in the LICENSE file which can be found at the top level of
 * the liquidfire distribution.
 */

#ifndef STDIO_H
#define STDIO_H

#define EOF		-1

#define MAXBUFFER 	1024

typedef struct FILE {

	int fd;

	int size;

	int current;

	char buffer[MAXBUFFER];
} FILE;

extern FILE *stdout;

extern char *itoa(int);
extern char *itox(unsigned);
extern int fputc(FILE *fd,char c);
extern int fputs(FILE *fd,char *buffer);
extern int fgetc(FILE *fd);
extern int fgets(char *buffer,int size,FILE *fd);
extern int fprintf(FILE *fd,char *buffer, ... );
extern FILE *fopen(void);

#endif
