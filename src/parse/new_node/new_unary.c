/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_unary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 16:59:29 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/10/08 19:15:14 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "arena.h"
#include "tree.h"
#include <stdlib.h>
#include <assert.h>

void				*xaalloc(size_t size);
static t_data_type	*detect_data_type(t_nd_type type, t_tree *child);
t_data_type			*new_int(void);
t_data_type			*new_ptr_to(t_data_type *ptr_to);

t_tree	*new_unary(t_nd_type type, t_tree *child)
{
	t_tree	*new = xaalloc(sizeof(t_tree));
	new->node_type = type;
	new->child = child;
	new->data_type = detect_data_type(type, child);
	return (new);
}

t_tree	*new_sizeof(t_tree *child)
{
	t_tree	*new = xaalloc(sizeof(t_tree));
	new->node_type = ND_NUM;
	new->value = size_of(child->data_type);
	new->data_type = new_int();
	return (new);
}

static t_data_type	*detect_data_type(t_nd_type type, t_tree *child)
{
	if (type == ND_ADDRESS)
		return (new_ptr_to(child->data_type));
	if (type == ND_DEREFER)
	{
		if (child->data_type->kind == TYPE_PTR)
			return (child->data_type->ptr_to);
		return (new_int());
	}
	return (new_int());
}

static int	size_of(t_data_type *data_type)
{
	if (data_type->kind == TYPE_INT)
		return (4);
	if (data_type->kind == TYPE_PTR)
		return (8);
	assert(0);
	// assert(ty->kind == TY_ARRAY);
	// return size_of(ty->base) * ty->array_size;
}
