/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 02:56:46 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/01 04:09:04 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "token.h"
#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>

bool	consume_op(t_token **list_p, char c);
t_tree	*new_node_op(t_nd_type type, t_tree *lhs, t_tree *rhs);
t_tree	*new_node_num(int val);
t_tree	*pri(t_token **list_p);
t_tree	*mul(t_token **list_p);

t_tree	*expr(t_token **list_p)
{
	t_tree	*node = mul(list_p);

	if (!node)
		return (NULL);
	while (1)
	{
		if (consume_op(list_p, '+'))
			node = new_node_op(ND_ADD, node, mul(list_p));
		else if (consume_op(list_p, '-'))
			node = new_node_op(ND_SUB, node, mul(list_p));
		else
			return (node);
	}
}

t_tree	*mul(t_token **list_p)
{
	t_tree	*node = pri(list_p);
	if (!node)
		return (NULL);
	while (1)
	{
		if (consume_op(list_p, '*'))
			node = new_node_op(ND_MUL, node, pri(list_p));
		else if (consume_op(list_p, '/'))
			node = new_node_op(ND_DIV, node, pri(list_p));
		else
			return (node);
	}
}

t_tree	*pri(t_token **list_p)
{
	t_tree	*node;

	if (consume_op(list_p, '('))
	{
		node = expr(list_p);
		if (consume_op(list_p, ')'))
			return (node);
		return (NULL);
	}
	node = new_node_num((*list_p)->val);
	*list_p = (*list_p)->next;
	return (node);
}


