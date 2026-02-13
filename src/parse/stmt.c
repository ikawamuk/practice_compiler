/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stmt.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 20:40:36 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/12 18:01:50 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "token.h"
#include "arena.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool	is_expected_op(const char *op, t_token *token);
t_tree	*expr(t_token **token_p);
t_tree	*new_unary(t_nd_type type, t_tree *child_node);

t_tree	*stmt(t_token **token_p)
{
	t_tree	*node;

	if ((*token_p)->type == TK_RETURN)
	{
		(*token_p) = (*token_p)->next;
		node = new_unary(ND_RETURN, expr(token_p));
	}
	else
		node = new_unary(ND_EXPR_STMT, expr(token_p));
	if (is_expected_op(";", *token_p))
	{
		(*token_p) = (*token_p)->next;
		node->next = NULL;
		return (node);
	}
	fprintf(stderr, "expected \';\'\n");
	clear_arena();
	exit(EXIT_FAILURE);
}
