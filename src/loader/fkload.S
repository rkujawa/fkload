custombase	EQU	$DFF000
dmacon		EQU	$096
intena		EQU	$09A
intreq		EQU	$09C
bplcon0		EQU	$100
bpldat		EQU	$110
color		EQU	$180

ciaabase	EQU	$BFE001
ciaddra		EQU	$200

	global start

	code

start:
	lea		$40000,sp ; set stack pointer 

	move.w		#$0200,bplcon0(a4)		; blank screen
	move.w		#0,bpldat(a4)			; zero bitplane data
	move.w		#$0340,color(a4)		; shitty green

	move.l		testdata,testbss
.1:	jmp		.1

	data

testdata:
	dc.l		$12345678	

	bss

testbss:
	ds.l		1

; vim: set ft=asm68k:
