/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:51:56 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/08 16:51:38 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "arena.h"
#include "token.h"
#include <stdbool.h>

t_tree	*mul(t_token **token_p);
bool	is_expected_op(const char *op, t_token *token);
t_tree	*new_binary(t_nd_type type, t_tree *lhs, t_tree *rhs);

t_tree	*add(t_token **token_p)
{
	t_tree	*node = mul(token_p);

	while (1)
	{
		if (is_expected_op("+", *token_p))
		{
			*token_p = (*token_p)->next;
			node = new_binary(ND_ADD, node, mul(token_p));
		}
		else if (is_expected_op("-", *token_p))
		{
			*token_p = (*token_p)->next;
			node = new_binary(ND_SUB, node, mul(token_p));
		}
		else
			return (node);
	}
}
