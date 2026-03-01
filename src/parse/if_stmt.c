/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_stmt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 21:17:49 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/01 21:30:06 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "tree.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool	is_expected(const char *op, t_token *token);

/*
if_stmt	= "if" "(" expr ")" stmt ("else" stmt)?
*/
t_tree	*if_stmt(t_token **token_p)
{
	if (!is_expected("if", *token_p))
	{
		fprintf(stderr, "expected \'if\'\n");
		clear_arena();
		exit(EXIT_FAILURE);
	}
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
