/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_stmt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 21:17:49 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/04 04:05:07 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "token.h"
#include "tree.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void	error_at(const char *location, const char *err_msg);
bool	is_expected(const char *op, t_token *token);
t_tree	*new_control_stmt(t_nd_type type, t_tree *cond, t_tree *then);
t_tree	*condition(t_token **token_p);
t_tree	*stmt(t_token **token_p);

/*
if_stmt	= "if" "(" expr ")" stmt ("else" stmt)?
*/
t_tree	*if_stmt(t_token **token_p)
{
	if (!is_expected("if", *token_p))
	{
		error_at((*token_p)->str, "expected \'if\'\n");
		clear_arena();
		exit(EXIT_FAILURE);
	}
	*token_p = (*token_p)->next;
	t_tree	*cond = condition(token_p);
	t_tree 	*then = stmt(token_p);
	t_tree	*node = new_control_stmt(ND_IF, cond, then);
	if (is_expected("else", *token_p))
	{
		*token_p = (*token_p)->next;
		node->els = stmt(token_p);
	}
	return (node);
}
