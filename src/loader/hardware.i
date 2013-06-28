custombase	EQU	$DFF000

dmaconr     EQU $002
dmacon		EQU	$096
intena		EQU	$09A
intenar     EQU $01C
intreq		EQU	$09C
intreqr     EQU $01E

bplcon0		EQU	$100
bplcon1     EQU $102

bpl1mod     EQU $108
bpl2mod     EQU $10A

bpldat		EQU	$110
bpl1pth     EQU $0E0
bpl1ptl     EQU $0E2
bpl2pth     EQU $0E4
bpl2ptl     EQU $0E6

color		EQU	$180

color00     EQU $180
color01     EQU $182
color02     EQU $184  
color03     EQU $186

diwstrt     EQU $08E
diwstop     EQU $090
ddfstrt     EQU $092
ddfstop     EQU $094

; Copper
cop1lch     EQU $080
cop1lcl     EQU cop1lch + $02
cop2lch     EQU cop1lch + $04
cop2lcl     EQU cop1lch + $06
copjmp1     EQU $088
copjmp2     EQU copjmp1 + $02


ciaabase	EQU	$BFE001
ciaddra		EQU	$200
ciasdr          EQU     $C00

; vim: set ft=asm68k:
