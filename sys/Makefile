#
# Copyright (c) 2003, Lucas Mendes <lmendes@netbsd.com.br>
# Copyright (c) 2003, Marcelo Samsoniuk <marcelos@bsi.com.br>
#      All rights reserved.
#
# By using this file, you agree to the terms and conditions set
# forth in the LICENSE file which can be found at the top level of
# the liquidfire distribution.
#

include ../Rules.make

 CFLAGS+= -I../include

   OBJS = core.o sched.o

all:: $(OBJS)

	$(AR) sys.a $(OBJS)
	$(RANLIB) sys.a

clean:
	rm -f $(OBJS) *~ sys.a
