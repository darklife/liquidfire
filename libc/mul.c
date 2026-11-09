/*
 * Copyright (c) 2003, Lucas Mendes <lmendes@netbsd.com.br>
 * Copyright (c) 2003, Marcelo Samsoniuk <marcelos@bsi.com.br>
 *      All rights reserved.
 *
 * By using this file, you agree to the terms and conditions set
 * forth in the LICENSE file which can be found at the top level of
 * the liquidfire distribution.
 */

unsigned __mulsi3(unsigned a,unsigned b) {

	unsigned d,count;

	if(a<b) { d=a; a=b; b=d; }
	
	for(count=0,d=0;b;a=a<<1,b=b>>1,count++)
		if(b&1) d+=a;

	return d;
}

