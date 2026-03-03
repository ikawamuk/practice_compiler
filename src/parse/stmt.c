/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stmt.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 20:40:36 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/04 04:06:02 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "token.h"
#include "arena.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void	error_at(const char *location, const char *err_msg);
bool	is_expected(const char *op, t_token *token);
t_tree	*expr(t_token **token_p);
t_tree	*new_unary(t_nd_type type, t_tree *child_node);
t_tree	*while_stmt(t_token **token_p);
t_tree	*if_stmt(t_token **token_p);
t_tree	*block(t_token **token_p);


void	print_token_type(t_tk_type type);

/*
stmt	= while_stmt
		| if_stmt
		| "return" expr ";"
		| exor ";"
		| block
*/
t_tree	*stmt(t_token **token_p)
{
	if (is_expected("while", *token_p))
		return (while_stmt(token_p));
	if (is_expected("if", *token_p))
		return (if_stmt(token_p));
	if (is_expected("{", *token_p))
		return (block(token_p));
	t_tree	*node;
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
		return (node);
	}
	error_at((*token_p)->str, "expected \';\'\n");
	clear_arena();
	exit(EXIT_FAILURE);
}
