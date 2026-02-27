/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_func_call_leaf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 05:11:27 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/28 07:04:18 by ikawamuk         ###   ########.fr       */
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

t_tree	*new_func_call_leaf(const char *func_name, int len, t_tree *args)
{
	t_tree	*new = xaalloc(sizeof(t_tree));
	new->type = ND_FUNC_CALL;
	new->func_name = xaalloc(len + 1);
	strncpy(new->func_name, func_name, len);
	new->args = args;
	return (new);
}
