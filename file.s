.globl main
main:
	pushq %rbp
	movq %rsp, %rbp
	subq $8, %rsp
	movq $0, -8(%rsp)
	movq -8(%rsp), !tmp2
	movq $1, !tmp3
	subq !tmp3, !tmp2
	sete !tmp1
	cmpq $0, !tmp1
	je main.end_if
	movq $70, %rdi
	callq putchar
	jmp main.end_else
main.end_if:
	movq $70, %rdi
	callq putchar
main.end_else:
	movq $110, %rdi
	callq putchar
	movq $0, %rax
	addq $8, %rsp
	popq %rbp
	retq
