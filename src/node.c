/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 02:57:31 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/02 12:29:22 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "tree.h"
#include <stdlib.h>

void	*alloc(t_arena *arena, size_t size);

t_tree	*new_node_op(t_arena *arena, t_nd_type type, t_tree *lhs, t_tree *rhs)
{
	t_tree	*new;

	if (!lhs || !rhs)
		return (NULL);
	new = alloc(arena, sizeof(t_tree));
	if (!new)
		return (NULL);
	new->type = type;
	new->val = 0;
	new->lhs = lhs;
	new->rhs = rhs;
	return (new);
}

t_tree	*new_node_num(t_arena *arena, int val)
{
	t_tree	*new;

	new = alloc(arena, sizeof(t_tree));
	if (!new)
		return (NULL);
	new->type = ND_NUM;
	new->val = val;
	new->lhs = NULL;
	new->rhs = NULL;
	return (new);
}
