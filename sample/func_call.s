	.text
	.intel_syntax noprefix
	.file	"func_call.c"
	.globl	main                            # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
# %bb.0:
	push	rbp
	mov	rbp, rsp
	mov	edi, 1
	mov	esi, 2
	call	print_ok
	xor	eax, eax
	pop	rbp
	ret
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
                                        # -- End function
	.ident	"Ubuntu clang version 12.0.1-19ubuntu3"
	.section	".note.GNU-stack","",@progbits
	.addrsig
	.addrsig_sym print_ok
