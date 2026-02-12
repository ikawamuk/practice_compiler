/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_unary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 16:59:29 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/12 18:01:38 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "arena.h"
#include "tree.h"
#include <stdlib.h>

t_tree	*new_unary(t_nd_type type, t_tree *child_node)
{
	t_tree	*new = aalloc(sizeof(t_tree));
	if (!new)
	{
		clear_arena();
		exit(EXIT_FAILURE);
	}
	new->type = type;
	new->val = 0;
	new->child = child_node;
	return (new);
}
