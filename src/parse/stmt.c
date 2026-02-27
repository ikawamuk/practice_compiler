/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stmt.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 20:40:36 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/28 07:27:55 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "token.h"
#include "arena.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool	is_expected(const char *op, t_token *token);
t_tree	*expr(t_token **token_p);
t_tree	*new_unary(t_nd_type type, t_tree *child_node);
t_tree	*new_binary(t_nd_type type, t_tree *lhs, t_tree *rhs);
t_tree	*control_stmt(t_token **token_p);
t_tree	*block(t_token **token_p);
t_tree	*new_control_stmt(t_nd_type type, t_tree *cond, t_tree *then);
t_tree	*condition(t_token **token_p);


void	print_token_type(t_tk_type type);

/*
stmt	= "while" "(" expr ")" stmt
		| "if" "(" expr ")" stmt ("else" stmt)?
		| "return" expr ";"
		| exor ";"
		| block
*/
t_tree	*stmt(t_token **token_p)
{
	t_tree	*node;

	if (is_expected("while", *token_p))
	{
		*token_p = (*token_p)->next;
		node = new_control_stmt(ND_WHILE, condition(token_p), stmt(token_p));
		return (node);
	}
	if (is_expected("if", *token_p))
	{
		*token_p = (*token_p)->next;
		node = new_control_stmt(ND_IF, condition(token_p), stmt(token_p));
		if (is_expected("else", *token_p))
		{
			*token_p = (*token_p)->next;
			node->els = stmt(token_p);
		}
		return (node);
	}
	if (is_expected("{", *token_p))
		return (block(token_p));
	if (is_expected("return", *token_p))
	{
		(*token_p) = (*token_p)->next;
		node = new_unary(ND_RETURN, expr(token_p));
	}
	else
		node = new_unary(ND_EXPR_STMT, expr(token_p));
	if (is_expected(";", *token_p))
	{
		(*token_p) = (*token_p)->next;
		node->next = NULL;
		return (node);
	}
	print_token_type((*token_p)->type);
	printf("str: %s\n", (*token_p)->str);
	fprintf(stderr, "expected \';\'\n");
	clear_arena();
	exit(EXIT_FAILURE);
}
