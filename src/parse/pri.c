/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:36:55 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/04 12:52:04 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "arena.h"
#include "token.h"
#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void	error_at(const char *location, const char *err_msg);
bool	is_expected(const char *op, t_token *token);
t_tree	*expr(t_token **token_p);
t_tree	*value(t_token **token_p);

/*
primary	= value | "(" expr ")"
*/
t_tree	*pri(t_token **token_p)
{
	t_tree	*node;
	if (is_expected("(", *token_p))
	{
		*token_p = (*token_p)->next;
		node = expr(token_p);
		if (is_expected(")", *token_p))
		{
			*token_p = (*token_p)->next;
			return (node);
		}
		error_at((*token_p)->str, "unclosed parenthesis\n");
		clear_arena();
		exit(EXIT_FAILURE);
		return (NULL);
	}
	return (value(token_p));
}
