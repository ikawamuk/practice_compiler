/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:42:16 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/12 16:15:12 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "arena.h"
#include "token.h"
#include <stdbool.h>

t_tree	*pri(t_token **token_p);
bool	is_expected(const char *op, t_token *token);
t_tree	*new_unary(t_nd_type type, t_tree *child);

/*
term	= ("+" | "-")? primary
*/
t_tree	*term(t_token **token_p)
{
	if (is_expected("+", *token_p))
	{
		(*token_p) = (*token_p)->next;
		return (pri(token_p));
	}
	if (is_expected("-", *token_p))
	{
		(*token_p) = (*token_p)->next;
		return (new_unary(ND_NEG, pri(token_p)));
	}
	if (is_expected("&", *token_p))
	{
		(*token_p) = (*token_p)->next;
		return (new_unary(ND_ADDRESS, pri(token_p)));
	}
	if (is_expected("*", *token_p))
	{
		(*token_p) = (*token_p)->next;
		return (new_unary(ND_DEREFER, pri(token_p)));
	}
	return (pri(token_p));
}
