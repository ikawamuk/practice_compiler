/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mul.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:36:04 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/08 17:50:48 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "arena.h"
#include "token.h"
#include <stdbool.h>

t_tree	*unary(t_token **token_p);
bool	is_expected_op(const char *op, t_token *token_p);
t_tree	*new_binary(t_nd_type type, t_tree *lhs, t_tree *rhs);

t_tree	*mul(t_token **token_p)
{
	t_tree	*node = unary(token_p);
	while (1)
	{
		if (is_expected_op("*", *token_p))
		{
			*token_p = (*token_p)->next;
			node = new_binary(ND_MUL, node, unary(token_p));
		}
		else if (is_expected_op("/", *token_p))
		{
			*token_p = (*token_p)->next;
			node = new_binary(ND_DIV, node, unary(token_p));
		}
		else
			return (node);
	}
}
