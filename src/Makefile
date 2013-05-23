AS=vasmm68k_mot
ASFLASGS=-Fbin -m68020up
OUTPUT=fkload.rom

$(OUTPUT) : startup.s
	$(AS) $(ASFLASGS) -o $(OUTPUT) startup.s 

clean :
	rm -f $(OUTPUT)
