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
void		generate_load(FILE *assem_src, const t_tree *node);
void		generate_return(FILE *assem_src, const t_tree *node);
static void	generate_operator(FILE *assem_src, const t_tree *node);


void	print_node_type(t_nd_type type);

void	generate(FILE *assem_src, const t_tree *node)
{
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
		generate_load(assem_src, node);
		return ;
	}
	if (node->type == ND_RETURN)
	{
		generate(assem_src, node);
		generate_return(assem_src, node->child);
		return ;
	}
	if (node->type == ND_EXPR_STMT)
	{
		generate(assem_src, node);
		fprintf(assem_src, "\tadd rsp, 8\n");
		return ;
	}
	if (node->type == ND_NEG)
	{
		generate(assem_src, node->child);

		return ;
	}
	if (node->type == ND_ASSIGN)
	{
		if (node->type != ND_LVAR)
		{
			fprintf(stderr, "left operand of assignment should be left value.\n");
			fclose(assem_src);
			clear_arena();
			exit(EXIT_FAILURE);
		}
		generate_left_value(assem_src, node->lhs);
		generate(assem_src, node->rhs);
		fprintf(assem_src, "\tpop rdi\n");
		fprintf(assem_src, "\tpop rax\n");
		fprintf(assem_src, "\tmov [rax], rdi\n");
		fprintf(assem_src, "\tpush rdi\n");
		return ;
	}
	if (is_operator(node->type))
	{
		generate_operator(assem_src, node);
		return ;
	}
	fprintf(stderr, "unknown node type\n");
	clear_arena();
	exit(EXIT_FAILURE);
	return ;
}



static void	generate_operator(FILE *assem_src, const t_tree *node)
{
	generate(assem_src, node->lhs);
	generate(assem_src, node->rhs);
	fprintf(assem_src, "\tpop rdi\n");
	fprintf(assem_src, "\tpop rax\n");
	get_op_generator(node->type)(assem_src);
	fprintf(assem_src, "\tpush rax\n");
}

static bool	is_operator(t_nd_type type)
{
	return (ND_ADD <= type && type <= ND_LE);
}
