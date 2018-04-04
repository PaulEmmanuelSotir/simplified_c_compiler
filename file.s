.globl main
main:
	pushq %rbp
	movq %rsp, %rbp
	subq $8, %rsp
	movq $0, !tmp1
	movq !tmp1, -8(%rsp)
	jmp main.while_body
main.while_body:
	movq -8(%rsp), !tmp3
	movq $5, !tmp4
	cmpq $0, !tmp2
	je main.while_end
	movq $86, %rdi
	call putchar
	movq -8(%rsp), !tmp6
	movq $1, !tmp7
	addq !tmp7, !tmp6
	movq !tmp6, !tmp5
	movq !tmp5, -8(%rsp)
	jmp main.while_body
main.while_end:
	movq $110, %rdi
	call putchar
	movq $0, %rax
	addq $8, %rsp
	popq %rbp
	retq
