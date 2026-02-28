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
#include <string.h>

const char	*arg_registers[] = {
	"rdi", "rsi", "rdx", "rcx", "r8", "r9"
};

void	generate_num(FILE *assem_src, const t_tree *node);
void	generate_local_variable(FILE *assem_src, const t_tree *node);
void	generate_if(FILE *assem_src, const t_tree *node, size_t label_idx);
void	generate_while(FILE *assem_src, const t_tree *node, size_t label_idx);
void	generate_return(FILE *assem_src, const t_tree *node);
void	generate_expr_stmt(FILE *assem_src, const t_tree *node);
void	generate_negative(FILE *assem_src, const t_tree *node);
void	generate_assign(FILE *assem_src, const t_tree *node);
void	generate_operator(FILE *assem_src, const t_tree *node);
void	generate_block(FILE *assem_src, const t_tree *node);
void	generate_func_call(FILE *assem_src, const t_tree *node);
void	generate_syscall(FILE *assem_src, const t_tree *node);
static bool	is_operator(t_nd_type type);

void	print_node_type(t_nd_type type);

void	generate(FILE *assem_src, const t_tree *node)
{
	static size_t	label_idx = 0;
	if (!node)
		return ;
	if (node->type == ND_NUM)
	{
		generate_num(assem_src, node);
		return ;
	}
	if (node->type == ND_LVAR)
	{
		generate_local_variable(assem_src, node);
		return ;
	}
	if (node->type == ND_FUNC_CALL)
	{
		if (!strcmp(node->func_name, "syscall"))
		{
			generate_syscall(assem_src, node);
			return ;
		}
		generate_func_call(assem_src, node);
		return ;
	}
	if (node->type == ND_IF)
	{
		generate_if(assem_src, node, label_idx++);
		return ;
	}
	if (node->type == ND_WHILE)
	{
		generate_while(assem_src, node, label_idx++);
		return ;
	}
	if (node->type == ND_RETURN)
	{
		generate_return(assem_src, node->child);
		return ;
	}
	if (node->type == ND_BLOCK)
	{
		generate_block(assem_src, node->child);
		return ;
	}
	if (node->type == ND_EXPR_STMT)
	{
		generate_expr_stmt(assem_src, node->child);
		return ;
	}
	if (node->type == ND_NEG)
	{
		generate_negative(assem_src, node->child);
		return ;
	}
	if (node->type == ND_ASSIGN)
	{
		generate_assign(assem_src, node);
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

static bool	is_operator(t_nd_type type)
{
	return (ND_ADD <= type && type <= ND_LE);
}
