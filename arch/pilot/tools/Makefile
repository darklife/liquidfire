#
# Copyright (c) 2003, Lucas Mendes <lmendes@netbsd.com.br>
# Copyright (c) 2003, Marcelo Samsoniuk <marcelos@bsi.com.br>
#      All rights reserved.
#
# By using this file, you agree to the terms and conditions set
# forth in the LICENSE file which can be found at the top level of
# the liquidfire distribution.
#

     CC = gcc
 CFLAGS = -Wall -O2 -fomit-frame-pointer -funroll-loops

   OBJS = meliante fnt2hex

all:: $(OBJS)

#	cat ../../../boot ../../../liquid > ../../../liquid.rom

	./meliante ../../../liquid.rom

clean:
	rm -f $(OBJS) *~
