/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 19:46:35 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/15 21:53:02 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <stdio.h>
/*
typedef enum {
	ND_NUM,
	ND_NEG,
	ND_ADD, // +
	ND_SUB, // -
	ND_MUL, // *
	ND_DIV, // /
	ND_EQ, // ==
	ND_NE, // !=
	ND_LT, // <
	ND_LE, // <=
	ND_ASSIGN, // = 
	ND_LVAR, // local variable
	ND_EXPR_STMT,
	ND_RETURN,
	ND_IF,
	ND_WHILE,
	ND_BLOCK
}	t_nd_type;
*/
void	print_node_type(t_nd_type type)
{
	static const char *table[] = {
		"ND_NUM",
		"ND_NEG",
		"ND_ADD", // +
		"ND_SUB", // -
		"ND_MUL", // *
		"ND_DIV", // /
		"ND_EQ", // ==
		"ND_NE", // !=
		"ND_LT", // <
		"ND_LE", // <=
		"ND_ASSIGN", // = 
		"ND_LVAR", // local variable
		"ND_EXPR_STMT",
		"ND_RETURN",
		"ND_IF",
		"ND_WHILE",
		"ND_BLOCK",
		"ND_FUNC_CALL"
	};
	for (size_t i = 0; i < sizeof(table) / sizeof(*table); i++)
		if (type == i)
			printf("type: %s\n", table[i]);
}

void	print_ast(t_tree *ast)
{
	print_node_type(ast->type);
	if (ast->type == ND_NUM || ast->type == ND_NEG
	|| ast->type == ND_LVAR || ast->type == ND_FUNC_CALL)
		return ;
	if (ast->type == ND_RETURN || ast->type == ND_EXPR_STMT || ast->type == ND_BLOCK)
	{
		print_ast(ast->child);
		if (ast->next)
			print_ast(ast->next);
		return ;
	}
	if (ND_ADD <= ast->type && ast->type <= ND_ASSIGN)
	{
		print_ast(ast->lhs);
		print_ast(ast->rhs);
		return ;
	}
	if (ast->type == ND_IF || ast->type == ND_WHILE)
	{
		print_ast(ast->cond);
		print_ast(ast->then);
		if (ast->els)
			print_ast(ast->els);
	}
	return ;
}
