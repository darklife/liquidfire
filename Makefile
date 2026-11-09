#
# Copyright (c) 2003, Lucas Mendes <lmendes@netbsd.com.br>
# Copyright (c) 2003, Marcelo Samsoniuk <marcelos@bsi.com.br>
#      All rights reserved.
#
# By using this file, you agree to the terms and conditions set
# forth in the LICENSE file which can be found at the top level of
# the liquidfire distribution.
#

include Rules.make

   BOOT	= arch/port/boot.o

   OBJS = arch/port/locore.o arch/port/port.a
   OBJS+= libc/libc.a mm/mm.a sys/sys.a syscalls/syscalls.a

all:

	rm -f ./include/port
	ln -sf `pwd`/arch/port/include ./include/port

	cd arch/port && make
#	cd drivers && make
	cd sys && make
	cd syscalls && make
	cd mm && make
	cd libc && make

#	$(LD) -Tdata 0x0 -Ttext 0x4000 -oformat binary -s -Map memory.map -o boot $(BOOT)
#	$(LD) -Tdata 0x8000 -Ttext 0x0 -oformat binary -s -Map memory.map -o liquid --start-group $(OBJS) --end-group

	$(LD) -Tdata 0x0 -Ttext 0x4000 -oformat=binary -s -Map memory.map -o liquid.rom --start-group $(BOOT) $(OBJS) --end-group

	cd arch/port/tools && make

#	make clean

debug:

	$(OBJDUMP) --disassemble-all --target=binary --architecture=m68k  --start-address=0x4000 liquid.rom|less

clean:

	cd arch/port && make clean
#	cd drivers && make clean
	cd sys && make clean
	cd syscalls && make clean
	cd mm && make clean
	cd libc && make clean
	cd arch/port/tools && make clean

	rm -f $(OBJS) *.o *.map *.core *~
