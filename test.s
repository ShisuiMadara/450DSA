	.file	"test.c"
	.text
	.section	.rodata
.LC0:
	.string	"%d and %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$80, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, -76(%rbp)
	jmp	.L2
.L3:
	movl	-76(%rbp), %eax
	cltq
	movl	$1, -64(%rbp,%rax,4)
	addl	$1, -76(%rbp)
.L2:
	cmpl	$4, -76(%rbp)
	jle	.L3
	movl	$0, -72(%rbp)
	jmp	.L4
.L5:
	movl	-72(%rbp), %eax
	cltq
	movl	$1, -32(%rbp,%rax,4)
	addl	$1, -72(%rbp)
.L4:
	cmpl	$4, -72(%rbp)
	jle	.L5
	movl	$0, -68(%rbp)
	jmp	.L6
.L7:
	movl	-68(%rbp), %eax
	cltq
	movl	-32(%rbp,%rax,4), %edx
	movl	-68(%rbp), %eax
	cltq
	movl	-64(%rbp,%rax,4), %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -68(%rbp)
.L6:
	cmpl	$4, -68(%rbp)
	jle	.L7
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L9
	call	__stack_chk_fail@PLT
.L9:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.3.0-1ubuntu1~22.04.1) 11.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
