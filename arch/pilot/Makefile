#
# Copyright (c) 2003, Lucas Mendes <lmendes@netbsd.com.br>
# Copyright (c) 2003, Marcelo Samsoniuk <marcelos@bsi.com.br>
#      All rights reserved.
#
# By using this file, you agree to the terms and conditions set
# forth in the LICENSE file which can be found at the top level of
# the liquidfire distribution.
#

include ../../Rules.make

     CC+= -I../../include

TARGETS = core/main.o core/exceptions.o core/calls.o core/calls_test.o
TARGETS+= drivers/fb/fb.o drivers/timer/timer.o drivers/uart/uart.o

   OBJS = boot.o locore.o

all:: $(OBJS)

	cd core && make
	cd drivers && make

	$(AR) port.a $(TARGETS)
	$(RANLIB) port.a

clean:

	cd core && make clean
	cd drivers && make clean
	rm -f $(OBJS) *~ port.a
