AS=vasmm68k_mot
LD=vlink
ASFLAGS=-Fvobj -m68020up
LDSCRIPT=vlink.cmd
LDFLAGS=-brawbin1 -T $(LDSCRIPT)
OUTPUT=fkload.rom

$(OUTPUT) : startup.s
	$(AS) $(ASFLAGS) -Fvobj -o startup.o startup.s
	$(LD) $(LDFLAGS) -o fkload.rom startup.o

clean :
	rm -f $(OUTPUT) startup.o
