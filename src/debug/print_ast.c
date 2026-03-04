/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 19:46:35 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/04 12:45:08 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <stdio.h>

struct s_nd_str {
	t_nd_type	type;
	char		*str;
};

void	print_node_type(t_nd_type type)
{
	static const struct s_nd_str table[] = {
		{ND_NUM, "ND_NUM"},
		{ND_NE, "ND_NEG"},
		{ND_ADDRESS, "ND_ADDRESS"}, // &
		{ND_DEREFER, "ND_DEREFER"}, // *
		{ND_ADD, "ND_ADD"}, // +
		{ND_SUB, "ND_SUB"}, // -
		{ND_MUL, "ND_MUL"}, // *
		{ND_DIV, "ND_DIV"}, // /
		{ND_MOD, "ND_MOD"}, // %
		{ND_EQ, "ND_EQ"}, // ==
		{ND_NE, "ND_NE"}, // !=
		{ND_LT, "ND_LT"}, // <
		{ND_LE, "ND_LE"}, // <=
		{ND_ASSIGN, "ND_ASSIGN"}, // = 
		{ND_LVAR, "ND_LVAR"}, // local variable
		{ND_EXPR_STMT, "ND_EXPR_STMT"},
		{ND_RETURN, "ND_RETURN"},
		{ND_IF, "ND_IF"},
		{ND_WHILE, "ND_WHILE"},
		{ND_BLOCK, "ND_BLOCK"},
		{ND_FUNC_CALL, "ND_FUNC_CALL"}
	};
	for (size_t i = 0; i < sizeof(table) / sizeof(*table); i++)
		if (type == table[i].type)
			printf("type: %s\n", table[i].str);
}

void	print_ast(t_tree *ast)
{
	print_node_type(ast->node_type);
	if (ast->node_type == ND_NUM || ast->node_type == ND_NEG
	|| ast->node_type == ND_LVAR || ast->node_type == ND_FUNC_CALL)
		return ;
	if (ast->node_type == ND_RETURN || ast->node_type == ND_EXPR_STMT
	|| ast->node_type == ND_BLOCK || ast->node_type == ND_ADDRESS || ast->node_type == ND_DEREFER)
	{
		print_ast(ast->child);
		if (ast->next)
			print_ast(ast->next);
		return ;
	}
	if (ND_ADD <= ast->node_type && ast->node_type <= ND_ASSIGN)
	{
		print_ast(ast->lhs);
		print_ast(ast->rhs);
		return ;
	}
	if (ast->node_type == ND_IF || ast->node_type == ND_WHILE)
	{
		print_ast(ast->cond);
		print_ast(ast->then);
		if (ast->els)
			print_ast(ast->els);
		return ;
	}
	return ;
}
