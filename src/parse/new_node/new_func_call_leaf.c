/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_func_call_leaf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 05:11:27 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/15 05:15:56 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "tree.h"
#include "local_variable.h"
#include <stdio.h>
#include <stdlib.h>

t_tree	*new_func_call_leaf(const char *func_name, size_t len)
{
	t_tree	*new = aalloc(sizeof(t_tree));
	if (!new)
	{
		clear_arena();
		exit(EXIT_FAILURE);
	}
	new->type = ND_FUNC_CALL;
	new->func_name = (char *)func_name;
	new->name_len = len;
	return (new);
}
