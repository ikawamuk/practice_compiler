/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   local_variable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:26:45 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/14 16:01:21 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "local_variable.h"
#include "arena.h"
#include <string.h>
#include <stdlib.h>

#include <stdio.h>

static t_lvar   *local_list = NULL;

t_lvar  *find_lvar(const t_token *token)
{
	for (t_lvar *cur = local_list; cur; cur = cur->next)
	{
		if (cur->len == token->len
		&& !memcmp(cur->name, token->str, cur->len))
			return (cur);
	}
	return (NULL);
}

int push_lval(const t_token *token)
{
	t_lvar  *new = aalloc(sizeof(t_lvar));
	if (!new)
		return (-1);
	new->name = token->str;
	new->len = token->len;
	new->offset = local_list ? local_list->offset + 8 : 8;
	new->next = local_list;
	local_list = new;
	return (new->offset);
}
