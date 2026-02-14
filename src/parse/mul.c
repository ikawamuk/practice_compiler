/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mul.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:36:04 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/14 16:00:52 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "arena.h"
#include "token.h"
#include <stdbool.h>

t_tree	*term(t_token **token_p);
bool	is_expected(const char *op, t_token *token_p);
t_tree	*new_binary(t_nd_type type, t_tree *lhs, t_tree *rhs);

t_tree	*mul(t_token **token_p)
{
	t_tree	*node = term(token_p);
	while (1)
	{
		if (is_expected("*", *token_p))
		{
			*token_p = (*token_p)->next;
			node = new_binary(ND_MUL, node, term(token_p));
		}
		else if (is_expected("/", *token_p))
		{
			*token_p = (*token_p)->next;
			node = new_binary(ND_DIV, node, term(token_p));
		}
		else
			return (node);
	}
}
