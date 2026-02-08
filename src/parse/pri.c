/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:36:55 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/08 21:13:47 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "arena.h"
#include "token.h"
#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>

bool	is_expected_op(const char *op, t_token *token);
t_tree	*new_num_leaf(int val);
t_tree	*expr(t_token **token_p);
t_tree	*num(t_token **token_p);
t_tree	*ident(t_token **token_p);

t_tree	*pri(t_token **token_p)
{
	t_tree	*node;
	if (is_expected_op("(", *token_p))
	{
		*token_p = (*token_p)->next;
		node = expr(token_p);
		if (is_expected_op(")", *token_p))
		{
			*token_p = (*token_p)->next;
			return (node);
		}
		// error_at(head, p, "unclosed parenthesis");
		fprintf(stderr, "unclosed parenthesis");
		return (NULL);
	}
	if ((*token_p)->type == TK_NUM)
		return (num(token_p));
	if ((*token_p)->type == TK_IDENT)
		return (ident(token_p));
	fprintf(stderr, "unexpected token\n");
	return (NULL);
}
