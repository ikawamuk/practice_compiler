/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 21:58:33 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/14 22:32:59 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "arena.h"
#include <stdlib.h>
#include <stdbool.h>

bool	is_expected(const char *op, t_token *token);
t_tree	*expr(t_token **token_p);

/*
condition	= "(" expr ")"
*/
t_tree	*condition(t_token **token_p)
{
	if (!is_expected("(", *token_p))
	{
		clear_arena();
		exit(EXIT_FAILURE);
	}
	*token_p = (*token_p)->next;
	t_tree	*cond = expr(token_p);
	if (!is_expected(")", *token_p))
	{
		clear_arena();
		exit(EXIT_FAILURE);
	}
	*token_p = (*token_p)->next;
	return (cond);
}
