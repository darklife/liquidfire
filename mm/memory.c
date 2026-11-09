/*
 * Copyright (c) 2003, Lucas Mendes <lmendes@netbsd.com.br>
 * Copyright (c) 2003, Marcelo Samsoniuk <marcelos@bsi.com.br>
 *      All rights reserved.
 *
 * By using this file, you agree to the terms and conditions set
 * forth in the LICENSE file which can be found at the top level of
 * the liquidfire distribution.
 */

#include <stdlib.h>
#include <mm.h>
#include <sys/types.h>

	extern struct Task *ssp;

	pid_t *tree=(pid_t *)RAMADDR;

	char *ram=(char *)RAMADDR+PAGETREE;

	pid_t pid=1;

void kfreeall(int pid) {

	register int i;

	/* register pid_t pid=ssp->pid; */

	for(i=0;i<PAGESIZE;i++)
		if(tree[i]==pid||tree[i]==-pid) tree[i]=0;
}

void kfree(void *p) {

	int start=(int)p-(int)ram;

	/* pid_t pid=ssp->pid; */

	if(p==ram) start=0;
	else start=(start%PAGESIZE)?start/PAGESIZE+1:start/PAGESIZE;

	while(tree[start]==pid||tree[start]==-pid) tree[start++]=0;
}

void *kmalloc(pid_t pid,int size,long level) {

	int start,end,k;

	/* pid_t pid=ssp->pid; */

	size=(size%PAGESIZE)?size/PAGESIZE+1:size/PAGESIZE;

	for(start=0;start!=PAGETREE;start+=end) {
	
		while(tree[start]) start++;
		
		for(end=0;(start+end)<PAGETREE&&tree[start+end]==0;end++)  {

			if(end==size) {

				for(k=start;end--;k++) tree[k]=pid;

				tree[k]=-pid;

				return (void *)(start*PAGESIZE+ram);
			}
		}
	}
			
	return NULL;
}