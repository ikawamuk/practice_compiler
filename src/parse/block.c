/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 03:44:22 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/04 04:03:10 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "tree.h"
#include "token.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void	error_at(const char *location, const char *err_msg);
bool	is_expected(const char *op, t_token *token);
t_tree	*stmt(t_token **token_p);
t_tree	*new_unary(t_nd_type type, t_tree *child);

/*
block	= "{" stmt* "}"
*/
t_tree	*block(t_token **token_p)
{
	t_tree	dummy_head = {0};
	t_tree	*cur = &dummy_head;

	if (is_expected("{", *token_p))
	{
		(*token_p) = (*token_p)->next;
		while ((*token_p)->type != TK_EOF && !is_expected("}", *token_p))
		{
			cur->next = stmt(token_p);
			cur = cur->next;
		}
		if (is_expected("}", *token_p))
		{
			(*token_p) = (*token_p)->next;
			return (new_unary(ND_BLOCK, dummy_head.next));
		}
		error_at((*token_p)->str, "expected \'}\'\n");
	}
	else
		error_at((*token_p)->str, "expected \'}\'\n");
	clear_arena();
	exit(EXIT_FAILURE);
}
