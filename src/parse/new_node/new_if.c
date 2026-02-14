/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_if.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 20:44:57 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/14 20:57:58 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "tree.h"
#include <stdlib.h>
#include <stdbool.h>

bool	is_expected(const char *op, t_token *token);

t_tree	*new_if(t_tree *cond, t_tree *then, t_tree *els)
{
	t_tree	*new = aalloc(sizeof(t_tree));
	if (!new)
	{
		clear_arena();
		exit(EXIT_FAILURE);
	}
	new->type = ND_IF;
	new->cond = cond;
	new->then = then;
	new->els = els;
	return (new);
}
