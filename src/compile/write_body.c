/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 03:26:29 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/08 22:29:31 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gen_table.h"
#include <stdio.h>

void		(*get_op_generator(t_nd_type type))(FILE *);
static void	exec_calculation(FILE *asm_file, t_nd_type type);

void	generate(FILE *asm_file, t_tree *node)
{
	if (node->type == ND_NUM)
	{
		fprintf(asm_file, "\tpush %d\n", node->val);
		return ;
	}
	if (node->type == ND_LVAR)
	{
		fprintf(asm_file, "\tmov rax, rbp\n");
		fprintf(asm_file, "\tsub rax, %d\n", node->offset);
		fprintf(asm_file, "\tpush rax\n");
		return ;
	}
	if (node->type == ND_ASSIGN)
	{
		generate(asm_file, node->lhs);
		generate(asm_file, node->rhs);
		fprintf(asm_file, "\tpop rdi\n");
		fprintf(asm_file, "\tpop rax\n");
		fprintf(asm_file, "\tmov [rax], rdi\n");
		fprintf(asm_file, "\tpush rdi\n");
		return ;
	}
	generate(asm_file, node->lhs);
	generate(asm_file, node->rhs);
	fprintf(asm_file, "\tpop rdi\n");
	fprintf(asm_file, "\tpop rax\n");
	exec_calculation(asm_file, node->type);
	fprintf(asm_file, "\tpush rax\n");
	return ;
}

static void	exec_calculation(FILE *asm_file, t_nd_type type)
{
	void	(*gen)(FILE *) = get_op_generator(type);
	if (gen)
		gen(asm_file);
}
