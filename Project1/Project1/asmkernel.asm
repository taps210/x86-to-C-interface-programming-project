section .text
bits 64
default rel

global asmkernel
extern printf

asmkernel:
	push rbp
	mov rbp, rsp
	add rbp, 16
		
		xor rax, rax
		;multiply:
			;mov 
			
	pop rbp
	ret