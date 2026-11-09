/*
 * Copyright (c) 2003, Lucas Mendes <lmendes@netbsd.com.br>
 * Copyright (c) 2003, Marcelo Samsoniuk <marcelos@bsi.com.br>
 *      All rights reserved.
 *
 * By using this file, you agree to the terms and conditions set
 * forth in the LICENSE file which can be found at the top level of
 * the liquidfire distribution.
 */

unsigned __divsi3(unsigned a,unsigned b) {

	unsigned c,d,s1,s2;

	if(!b) return 0;

	s1=b&0x80000000;
	s2=a&0x80000000;

	if(s1) b=-b;
	if(s2) a=-a;

	for(c=1,d=b;d<a;c=c<<1,d=d<<1,b=d);
	for(d=0;a&&c;c=c>>1,b=b>>1) if(b<=a)
		a-=b,d+=c;

	return (s1^s2)?-d:d;
}

unsigned __modsi3(unsigned a,unsigned b) {

	unsigned c,d,s1,s2;

	if(!b) return 0;

	s1=b&0x80000000;
	s2=a&0x80000000;

	if(s1) b=-b;
	if(s2) a=-a;

	for(c=1,d=b;d<a;c=c<<1,d=d<<1,b=d);
	for(d=0;a&&c;c=c>>1,b=b>>1)
		if(b<=a) a-=b,d+=c;

	return a;
}
