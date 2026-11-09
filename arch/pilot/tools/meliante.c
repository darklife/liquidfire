/*
 * Copyright (c) 2003, Lucas Mendes <lmendes@netbsd.com.br>
 * Copyright (c) 2003, Marcelo Samsoniuk <marcelos@bsi.com.br>
 *      All rights reserved.
 *
 * By using this file, you agree to the terms and conditions set
 * forth in the LICENSE file which can be found at the top level of
 * the liquidfire distribution.
 */

#include	<stdio.h>
#include	<stdlib.h>

#define OK	0
#define TRUE	1

#define SIZE	1048576

int main(int argc,char **argp,char **envp) {

	FILE *fp;

	char *buffer=malloc(SIZE);

	if(argc<2) {

		printf("Usage: %s liquid.rom\n",argp[0]);
		return TRUE;
	}

	fp=fopen(argp[1], "r+");

	fread(buffer,1,SIZE,fp);
	fseek(fp,0,0);
	fwrite(buffer,1,SIZE,fp);

	fclose(fp);

	printf("meliante: %d bytes saved!\n",SIZE);

	return OK;
}
