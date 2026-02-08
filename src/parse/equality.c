/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equality.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:12:29 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/08 16:50:31 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "arena.h"
#include "token.h"
#include <stdbool.h>

t_tree	*relational(t_token **token_p);
bool	is_expected_op(const char *op, t_token *token);
t_tree	*new_binary(t_nd_type type, t_tree *lhs, t_tree *rhs);

t_tree	*equality(t_token **token_p)
{
	t_tree	*node = relational(token_p);

	while (1)
	{
		if (is_expected_op("==", *token_p))
		{
			*token_p = (*token_p)->next;
			node = new_binary(ND_EQ, node, relational(token_p));
		}
		else if (is_expected_op("!=", *token_p))
		{
			*token_p = (*token_p)->next;
			node = new_binary(ND_NE, node, relational(token_p));
		}
		else
			return (node);
	}
}
