/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 02:57:31 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/01 03:00:28 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <stdlib.h>

t_tree	*new_node_op(t_nd_type type, t_tree *lhs, t_tree *rhs)
{
	t_tree	*new;

	new = calloc(1, sizeof(t_tree));
	if (!new)
		return (NULL);
	new->type = type;
	new->lhs = lhs;
	new->rhs = rhs;
	return (new);
}

t_tree	*new_node_num(int val)
{
	t_tree	*new;

	new = calloc(1, sizeof(t_tree));
	if (!new)
		return (NULL);
	new->type = ND_NUM;
	new->val = val;
	return (new);
}
