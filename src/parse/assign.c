/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 20:45:07 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/14 15:28:30 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "token.h"
#include <stdbool.h>

bool	is_expected(const char *op, t_token *token);
t_tree	*new_binary(t_nd_type type, t_tree *lhs, t_tree *rhs);
t_tree	*equality(t_token **token_p);

t_tree	*assign(t_token **token_p)
{
	t_tree	*node = equality(token_p);

	if (is_expected("=", *token_p))
	{
		(*token_p) = (*token_p)->next;
		return (new_binary(ND_ASSIGN, node, assign(token_p)));
	}
	return (node);
}
