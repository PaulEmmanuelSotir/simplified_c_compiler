.globl toto
toto:
	pushq %rbp
	movq %rsp, %rbp
	subq $32, %rsp
	addq $32, %rsp
	popq %rbp
	retq
