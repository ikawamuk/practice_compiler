/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   local_variable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:26:45 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/10/13 09:13:57 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "local_variable.h"
#include <string.h>
#include <stdlib.h>

#include <stdio.h>

void				*xaalloc(size_t size);
char				*dup_token_str(const t_token *token);
static t_var_list	*create_var_node(const char *name, int current_offset, t_data_type *data_type);
static t_var		*new_var(const char *name, int current_offset, t_data_type *data_type);

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

t_var	*push_lval(const char *name, t_data_type *data_type)
{
	if (!local_list)
	{
		local_list = create_var_node(name, 0, data_type);
		return (local_list->var);
	}
	t_var_list *cur = local_list;
	while (cur->next)
		cur = cur->next;
	cur->next = create_var_node(name, cur->var->offset, data_type);
	return (cur->next->var);
}

static t_var_list	*create_var_node(const char *name, int current_offset, t_data_type *data_type)
{
	t_var_list	*new = xaalloc(sizeof(t_var_list));
	new->var = new_var(name, current_offset, data_type);
	return (new);
}

static t_var	*new_var(const char *name, int current_offset, t_data_type *data_type)
{
	t_var *var = xaalloc(sizeof(t_var));
	var->name = (char *)name;
	var->offset = current_offset + ((size_of(data_type) + 7) & ~7);
	var->dt_type = data_type;
	return (var);
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
