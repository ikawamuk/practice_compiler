/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   postfix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 16:38:20 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/10/12 16:53:54 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "arena.h"
#include "token.h"
#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

t_tree	*pri(t_token **token_p);
t_tree	*expr(t_token **token_p);
bool	is_expected(const char *op, t_token *token);
t_tree	*new_unary(t_nd_type type, t_tree *child);
t_tree	*new_binary(t_nd_type type, t_tree *lhs, t_tree *rhs);
t_tree	*mul(t_token **token_p);
void	error_at(const char *location, const char *err_msg);

/*
postfix	= primary ("[" expr "]")
*/
t_tree	*postfix(t_token **token_p)
{
	t_tree	*node = pri(token_p);
	while (is_expected("[", *token_p))
	{
		*token_p = (*token_p)->next;
		t_tree	*exp = node = new_binary(ND_ADD, node, mul(token_p));
		if (!is_expected("]", *token_p))
		{
			error_at((*token_p)->str, "unclosed parenthesis\n");
			clear_arena();
			exit(EXIT_FAILURE);
			return (NULL);
		}
		*token_p = (*token_p)->next;
		node = new_unary(ND_DEREFER, exp);
	}
	return (node);
}

