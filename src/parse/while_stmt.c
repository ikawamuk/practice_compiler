/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   while_stmt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 21:16:23 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/01 21:29:37 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "tree.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool	is_expected(const char *op, t_token *token);

/*
while_stmt	= "while" "(" expr ")" stmt
*/
t_tree	*while_stmt(t_token **token_p)
{
	if (!is_expected("while", *token_p))
	{
		fprintf(stderr, "expected \'while\'\n");
		clear_arena();
		exit(EXIT_FAILURE);
	}
	*token_p = (*token_p)->next;
	t_tree	*cond = condition(token_p);
	t_tree	*then = stmt(token_p);
	t_tree	*node = new_control_stmt(ND_WHILE, cond, then);
	return (node);
}
