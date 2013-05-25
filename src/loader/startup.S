custombase	EQU	$DFF000
dmacon		EQU	$096
intena		EQU	$09A
intreq		EQU	$09C
bplcon0		EQU	$100
bpldat		EQU	$110
color		EQU	$180

ciaabase	EQU	$BFE001
ciaddra		EQU	$200

	xref	__prg_start
	xref	__copy_len
	xref	__bss_start
	xref	__bss_end

	section		"init",code

	dc.w		$1111
init:
	; copy code and data to RAM
	lea		__prg_start(pc),a0
	lea		start,a1
	move.l		#__copy_len,d0
.1:	move.b		(a0)+,(a1)+
	subq.l		#2,d0
	bne		.1

	; clear bss
	lea		__bss_start,a0
	move.l		#__bss_len,d0
.2:	clr.w		(a0)+
	subq.l		#2,d0

	jmp		start

	code

start:
;	lea		stack,sp ; $040000,sp ; set stack pointer 
	lea		$040000,sp ; set stack pointer 
	move.l		testdata,testbss
; infinite loop
.1:	jmp		.1

	move.l		#$020000,d0		; delay
	subq.l		#1,d0 

	move.b		#3,ciaabase+ciaddra
	move.b		#2,ciaabase		; dim LED

	lea		custombase,a4		; load custom chips address
	move.w		#$7FFF,d0
	move.w		d0,intena(a4)		; disable all interrupts
	move.w		d0,intreq(a4)		; clear all pending interrupts
	move.w		d0,dmacon(a4)		; disable all DMA

	move.w		#$0200,bplcon0(a4)	; blank screen
	move.w		#0,bpldat(a4)		; zero bitplane data
	move.w		#$0555,color(a4)	; background colour = dark gray

	lea		start_brightled(pc),a5
	bra		fk_bankswitch

start_brightled:
	bchg		#1,ciaabase		; LED light to bright
	; do things

kickjump:
	; jump to kick
	; end
	; rts
	; jmp		$F80000

fk_bankswitch:
	; switch bank
	; do the magic
	jmp		(a5)	; go back

	data

testdata:
	dc.l		$12345678	
end:

	bss

testbss:
	ds.l		1

