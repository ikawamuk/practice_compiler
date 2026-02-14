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
void		generate_local_value_address(FILE *assem_src, const t_tree *node);
void		generate_load(FILE *assem_src);
void		generate_return(FILE *assem_src);
void		generate_negative(FILE *assem_src);
void		generate_assign(FILE *assem_src);
static bool	is_operator(t_nd_type type);
static void	generate_operator(FILE *assem_src, t_nd_type type);

void	print_node_type(t_nd_type type);

void	generate(FILE *assem_src, const t_tree *node)
{
	static size_t	control_idx = 0;
	if (!node)
		return ;
	if (node->type == ND_NUM)
	{
		fprintf(assem_src, "\tpush %d\n", node->value);
		return ;
	}
	if (node->type == ND_LVAR)
	{
		generate_local_value_address(assem_src, node);
		generate_load(assem_src);
		return ;
	}
	if (node->type == ND_IF)
	{
		size_t	i = control_idx++;
		generate(assem_src, node->cond);
		fprintf(assem_src, "\tpop rax\n");
		fprintf(assem_src, "\tcmp rax, 0\n");
		fprintf(assem_src, "\tje .Lcontrol%zu\n", i);
		generate(assem_src, node->then);
		fprintf(assem_src, ".Lcontrol%zu:\n", i);
		return ;
	}
	if (node->type == ND_WHILE)
	{
		printf("HERE while!\n");
		exit(0);
	}
	if (node->type == ND_RETURN)
	{
		generate(assem_src, node->child);
		generate_return(assem_src);
		return ;
	}
	if (node->type == ND_EXPR_STMT)
	{
		generate(assem_src, node->child);
		fprintf(assem_src, "\tadd rsp, 8\n");
		return ;
	}
	if (node->type == ND_NEG)
	{
		generate(assem_src, node->child);
		generate_negative(assem_src);
		return ;
	}
	if (node->type == ND_ASSIGN)
	{
		if (node->lhs->type != ND_LVAR)
		{
			fprintf(stderr, "left operand of assignment should be left value.\n");
			fclose(assem_src);
			clear_arena();
			exit(EXIT_FAILURE);
		}
		generate_local_value_address(assem_src, node->lhs);
		generate(assem_src, node->rhs);
		generate_assign(assem_src);
		return ;
	}
	if (is_operator(node->type))
	{
		generate(assem_src, node->lhs);
		generate(assem_src, node->rhs);
		generate_operator(assem_src, node->type);
		return ;
	}
	fprintf(stderr, "unknown node type\n");
	clear_arena();
	exit(EXIT_FAILURE);
	return ;
}

static void	generate_operator(FILE *assem_src, t_nd_type type)
{
	fprintf(assem_src, "\tpop rdi\n");
	fprintf(assem_src, "\tpop rax\n");
	get_op_generator(type)(assem_src);
	fprintf(assem_src, "\tpush rax\n");
}

static bool	is_operator(t_nd_type type)
{
	return (ND_ADD <= type && type <= ND_LE);
}
