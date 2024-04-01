; Group 4 - Bernardo, Fernandez - S16
section .text
bits 64
default rel

global asmkernel

asmkernel:
	pxor xmm0, xmm0
	multiply:
		movss xmm6, [rdx]
		movss xmm7, [r8]
		mulss xmm6, xmm7
		addss xmm0, xmm6
		add rdx, 4
		add r8, 4
		loop multiply
	ret