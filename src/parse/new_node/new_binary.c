/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_binary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:31:39 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/05/01 10:04:54 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "tree.h"
#include <stdlib.h>

void		*xaalloc(size_t size);
t_data_type	*new_int(void);
static t_data_type	*detect_data_type(t_nd_type type, t_tree *lhs, t_tree *rhs);
static t_data_type	*detect_data_type_add(t_tree **lhs, t_tree **rhs);
static t_data_type	*detect_data_type_sub(t_tree *lhs, t_tree *rhs);
static t_data_type	*detect_data_type_assign(t_tree *lhs, t_tree *rhs);
static t_data_type	*detect_data_type_mul(t_tree *lhs, t_tree *rhs);
static t_data_type	*detect_data_type_eq(t_tree *lhs, t_tree *rhs);

t_tree	*new_binary(t_nd_type type, t_tree *lhs, t_tree *rhs)
{
	t_tree	*new = xaalloc(sizeof(t_tree));
	new->node_type = type;
	new->data_type = detect_data_type(type, lhs, rhs);
	new->lhs = lhs;
	new->rhs = rhs;
	return (new);
}

static t_data_type	*detect_data_type(t_nd_type type, t_tree *lhs, t_tree *rhs)
{
	if (type == ND_ADD)
		return (detect_data_type_add(&lhs, &rhs));
	if (type == ND_SUB)
		return (detect_data_type_sub(lhs, rhs));
	if (type == ND_ASSIGN)
		return (detect_data_type_assign(lhs, rhs));
	if (type == ND_MUL || type == ND_DIV || type == ND_MOD)
		return (detect_data_type_mul(lhs, rhs));
	if (type == ND_EQ || type == ND_NE)
		return (detect_data_type_eq(lhs, rhs));
	return (new_int());
}

void	swap_tree(t_tree **a, t_tree **b)
{
	t_tree*	tmp = *a;
	*a = *b;
	*b = tmp;
}

static t_data_type	*detect_data_type_add(t_tree **lhs, t_tree **rhs)
{
	if ((*rhs)->data_type->kind == TYPE_PTR)
		swap_tree(lhs, rhs);
	if ((*rhs)->data_type->kind == TYPE_PTR)
		return (NULL);
	return ((*lhs)->data_type);
}

static t_data_type	*detect_data_type_sub(t_tree *lhs, t_tree *rhs)
{
	if (rhs->data_type->kind == TYPE_PTR)
		return (NULL);
	return (lhs->data_type);
}

static t_data_type	*detect_data_type_assign(t_tree *lhs, t_tree *rhs)
{
	(void)rhs;
	return (lhs->data_type);
}

static t_data_type	*detect_data_type_mul(t_tree *lhs, t_tree *rhs)
{
	if (lhs->data_type->kind == TYPE_PTR || rhs->data_type->kind == TYPE_PTR)
		return (NULL);
	return (lhs->data_type);
}


static t_data_type	*detect_data_type_eq(t_tree *lhs, t_tree *rhs)
{
	if (lhs->data_type->kind != rhs->data_type->kind)
		return (NULL);
	return (lhs->data_type);
}


