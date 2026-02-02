/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 02:56:46 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/02 12:28:59 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "tree.h"
#include "token.h"
#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>


bool	consume_op(t_token **list_p, char c);
t_tree	*new_node_op(t_arena *arena, t_nd_type type, t_tree *lhs, t_tree *rhs);
t_tree	*new_node_num(t_arena *arena, int val);
t_tree	*pri(t_arena *arena, t_token **list_p);
t_tree	*mul(t_arena *arena, t_token **list_p);
t_tree	*unary(t_arena *arena, t_token **list_p);

t_tree	*expr(t_arena *arena, t_token **list_p)
{
	t_tree	*node = mul(arena, list_p);

	if (!node)
		return (NULL);
	while (1)
	{
		if (consume_op(list_p, '+'))
			node = new_node_op(arena, ND_ADD, node, mul(arena, list_p));
		else if (consume_op(list_p, '-'))
			node = new_node_op(arena, ND_SUB, node, mul(arena, list_p));
		else
			return (node);
	}
}

t_tree	*mul(t_arena *arena, t_token **list_p)
{
	t_tree	*node = unary(arena, list_p);
	if (!node)
		return (NULL);
	while (1)
	{
		if (consume_op(list_p, '*'))
			node = new_node_op(arena, ND_MUL, node, unary(arena, list_p));
		else if (consume_op(list_p, '/'))
			node = new_node_op(arena, ND_DIV, node, unary(arena, list_p));
		else
			return (node);
	}
}

t_tree	*unary(t_arena *arena, t_token **list_p)
{
	if (consume_op(list_p, '+'))
		return (pri(arena, list_p));
	if (consume_op(list_p, '-'))
		return (new_node_op(arena, ND_SUB, new_node_num(arena, 0), pri(arena, list_p)));
	return (pri(arena, list_p));
}

t_tree	*pri(t_arena *arena, t_token **list_p)
{
	t_tree	*node;

	if (consume_op(list_p, '('))
	{
		node = expr(arena, list_p);
		if (consume_op(list_p, ')'))
			return (node);
		return (NULL);
	}
	node = new_node_num(arena, (*list_p)->val);
	*list_p = (*list_p)->next;
	return (node);
}


