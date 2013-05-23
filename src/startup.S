	xref	__bss_start
	xref	__bss_end

	dc.w		$1111

	code

start:
	nop
	lea     stack,sp ; $040000,SP ; set SP

;	lea     __bss_start,a0
.1:	clr.l   (a0)+
	cmp.l   #__bss_end,a0
	blo     .1

	move.l  var1,var2

	move.l		#$020000,D0		; delay
	subq.l		#1,D0 

	move.b		#3,$BFE201
	move.b		#2,$BFE001		; dim LED

	lea		$DFF000,A4		; load custom chips address
	move.w		#$7FFF,D0
	move.w		D0,$9A(A4)		; disable all interrupts
	move.w		D0,$9C(A4)		; clear all pending interrupts
	move.w		D0,$96(A4)		; disable all DMA

	move.w		#$0200,$0100(A4)	; BPLCON0 = blank screen
	move.w		#0,$0110(A4)		; Bitplane 0 data = all zeros
	move.w		#$0444,$0180(A4)	; Background colour = dark gray

	lea		start_brightled(PC),A5
	bra		fk_bankswitch

start_brightled:
	bchg		#1,$BFE001		; LED light to bright

kickjump:
	; jump to kick
	; end

fk_bankswitch:
	; switch bank
	jmp		(A5)	; go back
;	rts


	data

var1:
	dc.l    -1

	bss

var2:
	ds.l    1
	ds.b    1024
stack:

