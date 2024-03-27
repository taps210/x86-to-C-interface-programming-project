section .text
bits 64
default rel

global asmkernel
extern printf

asmkernel:
	push rbp
	mov rbp, rsp
	add rbp, 16
		
		movss xmm0, 0
		multiply:
			movss xmm6, [rdx]
			movss xmm7, [r8]
			mulss xmm6, xmm7
			addss xmm0, xmm6
			add rdx, 4
			add r8, 4
			loop multiply
			
	pop rbp
	ret