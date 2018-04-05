.globl _main
_main:
	pushq %rbp
	movq %rsp, %rbp
	movq $79, %rdi
	callq _putchar
	movq $75, %rdi
	callq _putchar
	movq $32, %rdi
	callq _putchar
	movq $0, %rax
	popq %rbp
	retq
