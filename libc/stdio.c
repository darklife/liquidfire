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
#include <port/core.h>

char *itoa(int i) {

	static char tmp[20],*zero="0";

	int j,f=0;

	if(!i) return zero;

	if(i<0) f=1;

	for(tmp[j=19]=0;i;i/=10) tmp[--j]='0'+i%10;

	if(f) tmp[--j]='-';

	return tmp+j;
}

char *itox(unsigned i) {

	static char tmp[20],*zero="0";

	char value[16]="0123456789abcdef";

	int j;

	if(!i) return zero;

	for(tmp[j=19]=0;i;i/=16) tmp[--j]=value[i%16];

	return tmp+j;
}

int read(int fd,void *buffer,int size)  { 

	return 0; 
}

int write(int fd,void *buffer,int size) { 

	char *p=buffer;

	int i=size;

	while(size--) CONSOLEputc(*p++);

	return i;
}

int fputc(FILE *fd,char c) {

	if(fd->fd==EOF) return EOF;
	
	fd->buffer[fd->current++]=c;

	if(fd->current==fd->size||c=='\n') {
	
		write(fd->fd,fd->buffer,fd->current);
		fd->current=0;
	}
	return c;
}

int fputs(FILE *fd,char *buffer) {

	int i,j;

	for(i=0;(j=buffer[i]);i++)
		if((fputc(fd,j))==EOF) break;
	
	return i;
}

int fprintf(FILE *fd,char *fmt, ... ) {

	int i,inside;

	char **p=&fmt;

	for(inside=i=0;fmt[i];i++) {
	
		if(inside) {
		
			if(fmt[i]=='s') fputs(fd,*++p);
			if(fmt[i]=='d') fputs(fd,itoa((int)*++p));
			if(fmt[i]=='x') fputs(fd,itox((int)*++p));
			inside=0;
		
		} else { 
	
			if(fmt[i]=='%') inside=1;
			else fputc(fd,fmt[i]);
		}
	}

	return i;
}

int fgetc(FILE *fd) {

	if(fd->fd==EOF) return EOF;

	if(fd->current==fd->size) {
	
		fd->size=read(fd->fd,fd->buffer,MAXBUFFER);
		if(fd->size<=0) return fd->fd=EOF;
		fd->current=0;
	}

	return fd->buffer[fd->current++];
}

int fgets(char *buffer,int size,FILE *fd) {

	int i,j;

	for(buffer[0]=j=i=0;size-1!=i&&j!='\n';buffer[i++]=j)
		if((j=fgetc(fd))==EOF) break;
	
	buffer[i]=0;
	
	return i;
}

FILE *fopen() {

	static FILE fd;

	fd.fd=0;
	fd.size=MAXBUFFER-1;
	fd.current=0;

	return &fd;
}

/*
	exemplo, com abertura manual dos fps.

int main() {

	char buffer[256];

	FILE fi={ 0,0,0 };
	FILE fo={ 0,0,0 };

	fi.fd=0;
	fo.fd=1;

	while(fgets(buffer,256,&fi)) fputs(&fo,buffer);
}
*/
