.globl main
toto:
	pushq %rbp
	movq %rsp, %rbp
	subq $16, %rsp
	movq $1, -8(%rsp)
	addq $1, -8(%rsp)
	movq $84, %rdi
	callq putchar
	addq $16, %rsp
	popq %rbp
	retq
main:
	pushq %rbp
	movq %rsp, %rbp
	subq $16, %rsp
	movq $10, -8(%rsp)
	movq $79, %rdi
	callq putchar
	callq toto
	movq $0, %rax
	addq $16, %rsp
	popq %rbp
	retq
