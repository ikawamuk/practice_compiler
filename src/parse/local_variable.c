/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   local_variable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:26:45 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/28 06:55:59 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "local_variable.h"
#include "arena.h"
#include <string.h>
#include <stdlib.h>

#include <stdio.h>

void	*xaalloc(size_t size);

static t_lvar	*local_list = NULL;

t_lvar	*find_lvar(const t_token *token)
{
	for (t_lvar *cur = local_list; cur; cur = cur->next)
	{
		if (cur->len == token->len
		&& !memcmp(cur->name, token->str, cur->len))
			return (cur);
	}
	return (NULL);
}

t_lvar	*push_lval(const t_token *token)
{
	t_lvar *new = xaalloc(sizeof(t_lvar));
	new->name = token->str;
	new->len = token->len;
	new->offset = local_list ? local_list->offset + 8 : 8;
	new->next = local_list;
	local_list = new;
	return (new);
}

t_lvar	*get_var_list(void)
{
	return (local_list);
}

void	clear_list_stack(void)
{
	local_list = NULL;
}
