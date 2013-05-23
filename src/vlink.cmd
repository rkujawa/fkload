MEMORY {
	ram: org = 0x400, len = 0x3fc00
	rom: org = 0xfc0000, len = 0x80000
}

SECTIONS {
       .text: { *(CODE) } > rom
       __rom_end = ALIGN(2);
       .data: { *(DATA) } > ram AT> rom
       .bss (NOLOAD):  {
               __bss_start = .;
               *(BSS)
               __bss_end = .;
       } > ram
}

