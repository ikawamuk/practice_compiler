/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 02:56:46 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/01 03:32:29 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "token.h"
#include <stddef.h>

t_tree	*new_node_op(t_nd_type type, t_tree *lhs, t_tree *rhs);
t_tree	*new_node_num(int val);
t_tree	*pri(t_token *list);
t_tree	*mul(t_token *list);

t_tree	*expr(t_token *list)
{
	t_tree	*node = mul(list);
	if (!node)
		return (NULL);
	while (1)
	{
		if (list->type != TK_RESERVED)
			return (node);
		if (list->str[0] == '+')
			node = new_node_op(ND_ADD, node, mul(list->next));
		else if (list->str[0] == '-')
			node = new_node_op(ND_SUB, node, mul(list->next));
	}
}

t_tree	*mul(t_token *list)
{
	t_tree	*node = pri(list);
	if (!node)
		return (NULL);
	while (1)
	{
		if (list->type != TK_RESERVED)
			return (node);
		if (list->str[0] == '*')
			node = new_node_op(ND_MUL, node, pri(list->next));
		else if (list->str[0] == '/')
			node = new_node_op(ND_DIV, node, pri(list->next));
	}
}

t_tree	*pri(t_token *list)
{
	t_tree	*node = NULL;

	if (list->type != TK_RESERVED)
		return (new_node_num(list->val));
	if (list->str[0] == '(')
	{
		node = expr(list->next);
		if (list->str[0] == ')')
			list = list->next;
		else
			return (NULL);
	}
	return (node);
}
