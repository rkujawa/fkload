custombase	EQU	$DFF000
dmacon		EQU	$096
intena		EQU	$09A
intreq		EQU	$09C
bplcon0		EQU	$100
bpldat		EQU	$110
color		EQU	$180

ciaabase	EQU	$BFE001
ciaddra		EQU	$200

	xref	__bss_start
	xref	__bss_end

	code

	dc.w		$1111
start:
;	lea		stack,sp ; $040000,sp ; set stack pointer 
	lea		$040000,sp ; set stack pointer 

	move.l		#$020000,d0		; delay
	subq.l		#1,d0 

	move.b		#3,ciaabase+ciaddra
	move.b		#2,ciaabase		; dim LED

;	lea		__bss_start,a0		; clear bss
;.1:	clr.l		(a0)+
;	cmp.l		#__bss_end,a0
;	blo		.1

	move.l		var1,var2

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
	jmp		$F80000

fk_bankswitch:
	; switch bank
	; do the magic
	jmp		(a5)	; go back

	data

var1:
	dc.l		-1

	bss

var2:
	ds.l		1
	ds.b		1024
stack:

