	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.globl	_uremdiv                ## -- Begin function uremdiv
	.p2align	4, 0x90
_uremdiv:                               ## @uremdiv
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdx, %r8
	xorl	%edx, %edx
	movq	%rdi, %rax
	divq	%rsi
	movq	%rax, (%r8)
	movq	%rdx, (%rcx)
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function

.subsections_via_symbols
