.globl main
main:
	pushq %rbp
	movq %rsp, %rbp
	subq $16, %rsp
	movq $3, !tmp1
	movq $2, !tmp3
	movq $1, !tmp4
	addq !tmp4, !tmp3
	movq !tmp3, !tmp2
	subq !tmp2, !tmp1
	movq !tmp1, -8(%rsp)
	movq $0, %rax
	addq $16, %rsp
	popq %rbp
	retq
