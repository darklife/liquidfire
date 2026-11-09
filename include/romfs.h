/*
 * Copyright (c) 2003, Lucas Mendes <lmendes@netbsd.com.br>
 * Copyright (c) 2003, Marcelo Samsoniuk <marcelos@bsi.com.br>
 *      All rights reserved.
 *
 * By using this file, you agree to the terms and conditions set
 * forth in the LICENSE file which can be found at the top level of
 * the liquidfire distribution.
 */

#ifndef ROMFS_H
#define ROMFS_H

#include <sys/types.h>

#define ROMFS_MAXFN	128
#define ROMFH_HRD	0
#define ROMFH_DIR	1
#define ROMFH_REG	2
#define ROMFH_LNK	3
#define ROMFH_BLK	4
#define ROMFH_CHR	5
#define ROMFH_SCK	6
#define ROMFH_FIF	7
#define ROMFH_EXEC	8

struct romfh {

	int32_t nextfh;
	int32_t spec;
	int32_t size;
	int32_t checksum;
};

struct filenode {


	struct filenode *next;		/* leave next and previous at front, this is a linked list item */
	struct filenode *prev;

	struct filenode *parent;

	struct filehdr dirlist;

	struct filenode *orig_link;

	char *name;
	char *realname;

	dev_t ondev;
	dev_t devnode;

	ino_t onino;

	mode_t modes;

	unsigned int offset;
	unsigned int size;
	unsigned int pad;
};

struct filehdr {

	struct filenode *head;		/* leave head, tail and tailpred at front, this is a linked list header */
	struct filenode *tail;
	struct filenode *tailpred;

	struct filenode *owner;
};

#endif
