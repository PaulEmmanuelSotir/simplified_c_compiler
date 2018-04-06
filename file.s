.globl _main
_main:
	pushq %rbp
	subq $8, %rsp
	movq %rsp, %rbp
	movq $79, %rdi
	callq _putchar
	movq $75, %rdi
	callq _putchar
	movq $32, %rdi
	callq _putchar
	movq $0, %rax
	addq $8, %rsp
	popq %rbp
	retq
