	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.globl	_arith2                 ## -- Begin function arith2
	.p2align	4, 0x90
_arith2:                                ## @arith2
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	orq	%rsi, %rdi
	sarq	$3, %rdi
	notq	%rdi
	subq	%rdi, %rdx
	movq	%rdx, %rax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function

.subsections_via_symbols
