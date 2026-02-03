/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_binary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:31:39 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/03 16:42:01 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "tree.h"

t_tree	*new_binary(t_arena *arena, t_nd_type type, t_tree *lhs, t_tree *rhs)
{
	if (!lhs || !rhs)
		return (NULL);
	t_tree	*new = aalloc(arena, sizeof(t_tree));
	if (!new)
		return (NULL);
	new->type = type;
	new->val = 0;
	new->lhs = lhs;
	new->rhs = rhs;
	return (new);
}
