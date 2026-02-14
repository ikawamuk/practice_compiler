/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_stmt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 20:44:57 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/14 22:28:03 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "tree.h"
#include <stdlib.h>
#include <stdbool.h>

t_tree	*new_control_stmt(t_nd_type type, t_tree *cond, t_tree *then);
bool	is_expected(const char *op, t_token *token);
t_tree	*condition(t_token **token_p);
t_tree	*stmt(t_token **token_p);

/*
control_stmt	= "while" condition stmt
				| "if" condition stmt ("else" stmt)?
*/
t_tree	*control_stmt(t_token **token_p)
{
	t_tree	*node = NULL;
	if (is_expected("while", *token_p))
	{
		*token_p = (*token_p)->next;
		node = new_control_stmt(ND_WHILE, condition(token_p), stmt(token_p));
	}
	else if (is_expected("if", *token_p))
	{
		*token_p = (*token_p)->next;
		node = new_control_stmt(ND_IF, condition(token_p), stmt(token_p));
		if (is_expected("else", *token_p))
		{
			*token_p = (*token_p)->next;
			node->els = stmt(token_p);
		}
	}
	return (node);
}
