/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_func_call_leaf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 05:11:27 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/04 12:37:48 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include "arena.h"
#include "tree.h"
#include "local_variable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	*xaalloc(size_t size);

t_tree	*new_func_call_leaf(const char *func_name, t_tree *args)
{
	t_tree	*new = xaalloc(sizeof(t_tree));
	new->node_type = ND_FUNC_CALL;
	new->next = NULL;
	new->func_name = func_name;
	new->args = args;
	return (new);
}
