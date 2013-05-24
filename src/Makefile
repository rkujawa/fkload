NATIVE_CC=cc

CROSS_AS=vasmm68k_mot
CROSS_LD=vlink
CROSS_ASFLAGS=-Fvobj #-m68020up
CROSS_LDSCRIPT=vlink.cmd
CROSS_LDFLAGS=-brawbin1 -T $(CROSS_LDSCRIPT)

FKLOAD_IMAGE=fkload.img
FKLOAD_FAKEKICK=kick.rom

MAKEROM=makerom
MAKEROM_OBJS=makerom.o

all: $(MAKEROM) $(FKLOAD_IMAGE)

$(FKLOAD_IMAGE) : startup.s
	$(CROSS_AS) $(CROSS_ASFLAGS) -Fvobj -o startup.o startup.s
	$(CROSS_LD) $(CROSS_LDFLAGS) -o $(FKLOAD_IMAGE) startup.o

$(MAKEROM) : makerom.o
	$(NATIVE_CC) -o $(MAKEROM) $(MAKEROM_OBJS)	

%.o : %.c
	$(NATIVE_CC) -c $<

#$(FAKEKICK) : $(OUTPUT)
#	$(MAKEROM)

clean :
	rm -f $(FKLOAD_IMAGE) $(FKLOAD_FAKEKICK) $(MAKEROM) $(MAKEROM_OBJS) startup.o
