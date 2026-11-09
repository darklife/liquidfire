/*
 * Copyright (c) 2003, Lucas Mendes <lmendes@netbsd.com.br>
 * Copyright (c) 2003, Marcelo Samsoniuk <marcelos@bsi.com.br>
 *      All rights reserved.
 *
 * By using this file, you agree to the terms and conditions set
 * forth in the LICENSE file which can be found at the top level of
 * the liquidfire distribution.
 */

#include <stdio.h>

#define OK	0

int main(int c,char **p) {

	unsigned char buffer[4096];

	FILE *fi,*fo;

	int i;

	if(c!=3) return -1;

	fi=fopen(p[1],"r");
	fo=fopen(p[2],"w");
	
	fread(buffer,4096,1,fi);

	fclose(fi);

	fprintf(fo,"char font[]={\n\t");
	
	for(i=0;i!=4096;i++) {
	
		fprintf(fo,"0x%02x,",buffer[i]);
		if((i%20)==0&&i) fprintf(fo,"\n\t");
	}

	fprintf(fo,"0 };\n\n");

	fclose(fo);

	return OK;
}
