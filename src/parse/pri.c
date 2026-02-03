/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:36:55 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/03 18:36:33 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "arena.h"
#include "token.h"
#include <stdbool.h>

bool	is_expected_op(const char *op, t_token *token);
t_tree	*new_binary(t_arena *arena, t_nd_type type, t_tree *lhs, t_tree *rhs);
t_tree	*new_num_leaf(t_arena *arena, int val);
t_tree	*expr(t_arena *arena, t_token **token_p);

t_tree	*pri(t_arena *arena, t_token **token_p)
{
	t_tree	*node;

	if (is_expected_op("(", *token_p))
	{
		*token_p = (*token_p)->next;
		node = expr(arena, token_p);
		if (is_expected_op(")", *token_p))
		{
			*token_p = (*token_p)->next;
			return (node);
		}
		// error_at(head, p, "unclosed parenthesis");
		return (NULL);
	}
	node = new_num_leaf(arena, (*token_p)->val);
	*token_p = (*token_p)->next;
	return (node);
}
