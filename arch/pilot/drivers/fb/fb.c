/*
 * Copyright (c) 2003, Lucas Mendes <lmendes@netbsd.com.br>
 * Copyright (c) 2003, Marcelo Samsoniuk <marcelos@bsi.com.br>
 *      All rights reserved.
 *
 * By using this file, you agree to the terms and conditions set
 * forth in the LICENSE file which can be found at the top level of
 * the liquidfire distribution.
 */

#include <port/font.h>
#include <port/fb.h>
#include <strings.h>

	unsigned short *fb=(short *)VRAM;

void fbpixel(int x,int y,int color) {

        static short mask[]={

                0x8000,0x4000,0x2000,0x1000,
                0x0800,0x0400,0x0200,0x0100,
                0x0080,0x0040,0x0020,0x0010,
                0x0008,0x0004,0x0002,0x0001,
        };

	if(color) fb[y*10+(x>>4)]|=mask[x&15];
	else fb[y*10+(x>>4)]&=~mask[x&15];
}

void fbxline(int x,int y,int w,int c) {

	int z;

	short *fb0,*fb1;

	static short mask[]={

		0x8000,0xc000,0xe000,0xf000,
		0xf800,0xfc00,0xfe00,0xff00,
		0xff80,0xffc0,0xffe0,0xfff0,
		0xfff8,0xfffc,0xfffe,0xffff
	};

	static short imask[]={

		0xffff,0x7fff,0x3fff,0x1fff,
		0x0fff,0x07ff,0x03ff,0x01ff,
		0x00ff,0x007f,0x003f,0x001f,                            
		0x000f,0x0007,0x0003,0x0001
	};

	z=x+w;

	fb1=fb+y*10;
	fb0=fb1+(x>>4);
	fb1=fb1+(z>>4);

	if(fb1==fb0) {

		if(c) *fb0|=((imask[x&15])&mask[z&15]);
		else *fb0&=~((imask[x&15])&mask[z&15]);
	} else {

		if(c) *fb0|=imask[x&15];
		else *fb0 &=~imask[x&15];

		if(c) for(fb0++;fb0!=fb1;fb0++) *fb0=0xffff;
		else for(fb0++;fb0!=fb1;fb0++) *fb0=0x0000;

		if(c) *fb1|=mask[z&15];
		else *fb1&=~mask[z&15];
	}
}

void fbyline(int x,int y,int w,int c) {

	short z;

	unsigned short *fb0=fb+y*10+(x>>4);
        
	static short mask[]={

		0x8000,0x4000,0x2000,0x1000,
		0x0800,0x0400,0x0200,0x0100,
		0x0080,0x0040,0x0020,0x0010,
		0x0008,0x0004,0x0002,0x0001,
	};

	if(c) for(z=mask[x&15];w--;fb0+=10) *fb0|=z;
	else for(z=~mask[x&15];w--;fb0+=10) *fb0&=z;
}

void fbshowraw(int x,int y,char *c,int f,int s) {

	int a,b;
        
	static unsigned char mask[]={ 0x80,0x40,0x20,0x10,0x8,0x4,0x2,0x1 };

	static unsigned char *p;

	while(s--) {

		p=font+16*(*c++);

		for(b=1;b!=p[0]&&b!=15;b++)
			for(a=0;a!=p[15]&&a!=8;a++)
				if((p[b]&mask[a])) fbpixel((x+a),(b+y),f);

		x+=p[15]+1;
	}
}

void fbshow(int x,int y,char *c,int f) {

	fbshowraw(x,y,c,f,strlen(c));
}

void fbbox(int x,int y,int w,int h,int c) {

	while(h--) fbxline(x,y++,w,c);
}

void fbscroll(int lines) {

	int i;

	static short t[10]={
	
		0xffff,0xffff,0xffff,0xffff,0xffff,
		0xffff,0xffff,0xffff,0xffff,0xffff,
	};

	while(lines--) {

		for(i=0;i<10;i++) {

			memcpy(fb,fb+10,20*160-20);
			memcpy(fb+160*10-10,t,20);
		}
	}
}
