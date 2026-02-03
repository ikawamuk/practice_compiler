/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unary.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:42:16 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/03 18:35:52 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "arena.h"
#include "token.h"
#include <stdbool.h>

t_tree	*pri(t_arena *arena, t_token **token_p);
bool	is_expected_op(const char *op, t_token *token);
t_tree	*new_binary(t_arena *arena, t_nd_type type, t_tree *lhs, t_tree *rhs);
t_tree	*new_num_leaf(t_arena *arena, int val);

t_tree	*unary(t_arena *arena, t_token **token_p)
{
	if (is_expected_op("+", *token_p))
	{
		(*token_p) = (*token_p)->next;
		return (pri(arena, token_p));
	}
	if (is_expected_op("-", *token_p))
	{
		(*token_p) = (*token_p)->next;
		return (new_binary(arena, ND_SUB, new_num_leaf(arena, 0), pri(arena, token_p)));
	}
	return (pri(arena, token_p));
}
