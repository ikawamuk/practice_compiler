/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 03:26:29 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/03 18:53:02 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <stdio.h>

int	calc_ast(FILE *asm_file, t_tree *node)
{
	if (node->type == ND_NUM)
	{
		fprintf(asm_file, "\tpush %d\n", node->val);
		return (0);
	}
	calc_ast(asm_file, node->lhs);
	calc_ast(asm_file, node->rhs);
	fprintf(asm_file, "\tpop rdi\n");
	fprintf(asm_file, "\tpop rax\n");
	switch (node->type) {
	case ND_ADD:
		fprintf(asm_file, "\tadd rax, rdi\n");
		break;
	case ND_SUB:
		fprintf(asm_file, "\tsub rax, rdi\n");
		break;
	case ND_MUL:
		fprintf(asm_file, "\timul rax, rdi\n");
		break;
	case ND_DIV:
		fprintf(asm_file, "\tcqo\n");
		fprintf(asm_file, "\tidiv rdi\n");
		break;
	case ND_EQ:
		fprintf(asm_file, "\tpop rdi\n");
		fprintf(asm_file, "\tpop rax\n");
		fprintf(asm_file, "\tcmp rax, rdi\n");
		fprintf(asm_file, "\tsete al\n");
	case ND_NE:
		fprintf(asm_file, "\tpop rdi\n");
		fprintf(asm_file, "\tpop rax\n");
		fprintf(asm_file, "\tcmp rax, rdi\n");
		fprintf(asm_file, "\tsetne al\n");
	case ND_LT:
		fprintf(asm_file, "\tpop rdi\n");
		fprintf(asm_file, "\tpop rax\n");
		fprintf(asm_file, "\tcmp rax, rdi\n");
		fprintf(asm_file, "\tsetl al\n");
	case ND_LE:
		fprintf(asm_file, "\tpop rdi\n");
		fprintf(asm_file, "\tpop rax\n");
		fprintf(asm_file, "\tcmp rax, rdi\n");
		fprintf(asm_file, "\tsetle al\n");
	default:
		return (1);
	}
	fprintf(asm_file, "\tpush rax\n");
	return (0);
}
