/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_num_leaf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:37:21 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/03 17:45:49 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "tree.h"

t_tree	*new_num_leaf(t_arena *arena, int val)
{
	t_tree	*new = aalloc(arena, sizeof(t_tree));
	if (!new)
		return (NULL);
	new->type = ND_NUM;
	new->val = val;
	new->lhs = NULL;
	new->rhs = NULL;
	return (new);
}
