/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   local_variable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:26:45 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/01 19:40:27 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "local_variable.h"
#include <string.h>
#include <stdlib.h>

#include <stdio.h>

void				*xaalloc(size_t size);
char				*dup_token_str(const t_token *token);
static t_var_list	*create_var_node(const t_token *token, int current_offset);

static t_var_list	*local_list = NULL;

t_var	*find_var(const t_token *token)
{
	for (t_var_list *cur = local_list; cur; cur = cur->next)
	{
		if (strlen(cur->var->name) == (size_t)token->len
		&& !strncmp(cur->var->name, token->str, token->len))
			return (cur->var);
	}
	return (NULL);
}

t_var	*push_lval(const t_token *token)
{
	if (!local_list)
	{
		local_list = create_var_node(token, 0);
		return (local_list->var);
	}
	t_var_list *cur = local_list;
	while (cur->next)
		cur = cur->next;
	cur->next = create_var_node(token, cur->var->offset);
	return (cur->next->var);
}

static t_var_list	*create_var_node(const t_token *token, int current_offset)
{
	t_var *var = xaalloc(sizeof(t_var));
	var->name = dup_token_str(token);
	var->offset = current_offset + 8;
	t_var_list	*new = xaalloc(sizeof(t_var_list));
	new->var = var;
	return (new);
}

t_var_list	*get_var_list(void)
{
	return (local_list);
}

int	get_var_list_size(void)
{
	int	cnt = 0;
	for (t_var_list *cur = get_var_list(); cur; cur = cur->next)
		cnt++;
	return (cnt);
}

void	clear_list_stack(void)
{
	local_list = NULL;
}
