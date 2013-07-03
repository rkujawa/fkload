; NOTE: must use explicit values for the constants (i.e. "color01 EQU color00 + $02" won't work for some reason)
custombase	EQU	$DFF000

; DMA
dmaconr		EQU	$002
dmacon		EQU	$096

; interrupts
intena		EQU	$09A
intenar     EQU $01C
intreq		EQU	$09C
intreqr     EQU $01E

; bitplanes
bplcon0		EQU	$100
bplcon1     EQU $102

bpl1mod     EQU $108
bpl2mod     EQU $10A

bpldat		EQU	$110
bpl1pth		EQU	$0E0
bpl1ptl		EQU	$0E2
bpl2pth		EQU	$0E4
bpl2ptl		EQU	$0E6

color		EQU	$180

color00		EQU	$180
color01		EQU	$182
color02		EQU	$184  
color03		EQU	$186

diwstrt		EQU	$08E
diwstop		EQU	$090
ddfstrt		EQU	$092
ddfstop		EQU	$094

; Copper
cop1lch		EQU	$080
cop1lcl		EQU	$082
cop2lch		EQU	$084
cop2lcl		EQU	$086
copjmp1		EQU	$088
copjmp2		EQU	$08A


ciaabase	EQU	$BFE001
ciaddra		EQU	$200
ciasdr		EQU	$C00

; vim: set ft=asm68k:
