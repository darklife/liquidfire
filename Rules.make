#
# Copyright (c) 2003, Lucas Mendes <lmendes@netbsd.com.br>
# Copyright (c) 2003, Marcelo Samsoniuk <marcelos@bsi.com.br>
#      All rights reserved.
#
# By using this file, you agree to the terms and conditions set
# forth in the LICENSE file which can be found at the top level of
# the liquidfire distribution.
#

CROSSPATH=m68k-elf-

     CC	= $(CROSSPATH)gcc
     AS	= $(CROSSPATH)as
     LD = $(CROSSPATH)ld
     AR = $(CROSSPATH)ar rcs
 RANLIB = $(CROSSPATH)ranlib
OBJDUMP = $(CROSSPATH)objdump

 CFLAGS = -O3 -Wall -m68000 -ffreestanding -ffixed-%a0 -DKERNEL -I../arch/pilot/include -I../../arch/pilot/include -I../../../arch/pilot/include -I../../../../arch/pilot/include
#CFLAGS = -O3 -Wall -ffreestanding -fomit-frame-pointer -DKERNEL
