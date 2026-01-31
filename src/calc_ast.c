/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 03:26:29 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/01 03:33:39 by ikawamuk         ###   ########.fr       */
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
		printf("\tcqo\n");
		printf("\tidiv rdi\n");
		break;
	default:
		return (1);
	}
	printf("\tpush rax\n");
	return (0);
}
