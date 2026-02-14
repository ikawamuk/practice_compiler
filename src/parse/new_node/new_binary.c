/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_binary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:31:39 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/14 15:04:23 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "tree.h"
#include <stdlib.h>

t_tree	*new_binary(t_nd_type type, t_tree *lhs, t_tree *rhs)
{
	t_tree	*new = aalloc(sizeof(t_tree));
	if (!new)
	{
		clear_arena();
		exit(EXIT_FAILURE);
	}
	new->type = type;
	new->lhs = lhs;
	new->rhs = rhs;
	return (new);
}
