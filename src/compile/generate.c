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
#include "arena.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void		(*get_op_generator(t_nd_type type))(FILE *);
void		generate_local_value_address(FILE *asm_file, const t_tree *node);
static void	generate_operator(FILE *asm_file, const t_tree *node);


void	print_node_type(t_nd_type type);

void	generate(FILE *asm_file, const t_tree *node)
{
	if (!node)
		return ;
	if (node->type == ND_NUM)
	{
		fprintf(asm_file, "\tpush %d\n", node->value);
		return ;
	}
	if (node->type == ND_LVAR)
	{
		generate_left_value(asm_file, node);
		fprintf(asm_file, "\tpop rax\n");
		fprintf(asm_file, "\tmov rax, [rax]\n");
		fprintf(asm_file, "\tpush rax\n");
		return ;
	}
	if (node->type == ND_RETURN)
	{
		generate(asm_file, node->child);
		fprintf(asm_file, "\tpop rax\n");
		fprintf(asm_file, "\tmov rsp, rbp\n");
		fprintf(asm_file, "\tpop rbp\n");
		fprintf(asm_file, "\tret\n");
		return ;
	}
	if (node->type == ND_EXPR_STMT)
	{
		generate(asm_file, node->child);
		fprintf(asm_file, "\tpop rax\n");
		return ;
	}
	if (node->type == ND_EXPR_STMT)
	{
		generate(asm_file, node->child);
		fprintf(asm_file, "\tadd rsp, 8\n");
		return ;
	}
	if (node->type == ND_NEG)
	{
		generate(asm_file, node->child);
		fprintf(asm_file, "\tpop rax\n");
		fprintf(asm_file, "\tneg rax\n");
		fprintf(asm_file, "\tpush rax\n");
		return ;
	}
	if (node->type == ND_ASSIGN)
	{
		generate_left_value(asm_file, node->lhs);
		generate(asm_file, node->rhs);
		fprintf(asm_file, "\tpop rdi\n");
		fprintf(asm_file, "\tpop rax\n");
		fprintf(asm_file, "\tmov [rax], rdi\n");
		fprintf(asm_file, "\tpush rdi\n");
		return ;
	}
	if (is_operator(node->type))
	{
		generate_operator(asm_file, node);
		return ;
	}
	fprintf(stderr, "unknown node type\n");
	clear_arena();
	exit(EXIT_FAILURE);
	return ;
}

/*
@brief push local value's address on stack.
*/
void	generate_local_value_address(FILE *asm_file, const t_tree *node)
{
	if (node->type != ND_LVAR)
	{
		fprintf(stderr, "left operand of assignment should be left value.\n");
		fclose(asm_file);
		clear_arena();
		exit(EXIT_FAILURE);
	}
	fprintf(asm_file, "\tmov rax, rbp\n");
	fprintf(asm_file, "\tsub rax, %d\n", node->local_var->offset);
	fprintf(asm_file, "\tpush rax\n");
}

static void	generate_operator(FILE *asm_file, const t_tree *node)
{
	generate(asm_file, node->lhs);
	generate(asm_file, node->rhs);
	fprintf(asm_file, "\tpop rdi\n");
	fprintf(asm_file, "\tpop rax\n");
	get_op_generator(node->type)(asm_file);
	fprintf(asm_file, "\tpush rax\n");
}

static bool	is_operator(t_nd_type type)
{
	return (ND_ADD <= type && type <= ND_LE);
}
