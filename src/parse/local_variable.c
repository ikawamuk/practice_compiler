/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   local_variable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:26:45 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/28 08:31:54 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "local_variable.h"
#include "arena.h"
#include <string.h>
#include <stdlib.h>

#include <stdio.h>

char	*dup_token_str(t_token *token);

static t_var_list	*local_list = NULL;

t_var	*find_var(const t_token *token)
{
	for (t_var_list *cur = local_list; cur; cur = cur->next)
	{
		if (!strncmp(cur->var->name, token->str, token->len))
			return (cur->var);
	}
	return (NULL);
}

t_var	*push_lval(const t_token *token)
{
	t_var *new = xaalloc(sizeof(t_var));
	new->name = dup_token_str(token);
	new->offset = local_list ? local_list->var->offset + 8 : 8;
	t_var_list	*tmp = xaalloc(sizeof(t_var_list));
	tmp->var = new;
	tmp->next = local_list;
	local_list = tmp;
	return (new);
}

t_var_list	*get_var_list(void)
{
	return (local_list);
}

void	clear_list_stack(void)
{
	local_list = NULL;
}
