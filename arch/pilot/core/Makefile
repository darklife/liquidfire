#
# Copyright (c) 2003, Lucas Mendes <lmendes@netbsd.com.br>
# Copyright (c) 2003, Marcelo Samsoniuk <marcelos@bsi.com.br>
#      All rights reserved.
#
# By using this file, you agree to the terms and conditions set
# forth in the LICENSE file which can be found at the top level of
# the liquidfire distribution.
#

include ../../../Rules.make

 CFLAGS+= -ffixed-%a0 -I../../../include

   OBJS = main.o exceptions.o calls.o calls_test.o

all:: $(OBJS)

clean:
	rm -f $(OBJS) *~ core.a
