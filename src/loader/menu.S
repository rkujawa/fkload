	include hardware.i

	global menu 

	code

menu:
	move.w		#$0595,color(a4)	; light green
.1:	jmp		.1

; vim: set ft=asm68k:
