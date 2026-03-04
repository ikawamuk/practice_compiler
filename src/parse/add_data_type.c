/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_data_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:40:44 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/04 13:52:22 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

t_data_type	set_data_type_int(void);
static void	assign_type_recursive(t_tree *node);

void	assign_type(t_func_list *prog)
{
	for (t_func_list *cur = prog; cur; cur = cur->next)
		for (t_tree *node = cur->func->body; node; node = node->next)
			assign_type_recursive(node);
}

static void	assign_type_recursive(t_tree *node)
{
	if (node->node_type == ND_LVAR)
	{
		// node->data_type = node->local_var.data_type;
		node->data_type = set_data_type_int(); // 一旦int
		return ;
	}
	// calling new_XX_leaf
	if (node->node_type == ND_NUM || node->node_type == ND_LVAR
	|| node->node_type == ND_FUNC_CALL)
	{
		node->data_type = set_data_type_int();
		return ;
	}
	// calling new_unary
	if (node->node_type == ND_BLOCK || node->node_type == ND_EXPR_STMT
	|| node->node_type == ND_RETURN || node->node_type == ND_ADDRESS
	|| node->node_type == ND_DEREFER || ND_NEG)
	{
		assign_type_recursive(node->child);
		node->data_type = set_data_type_int();
		return ;
	}
	// calling new_binary
	if (ND_ADD <= node->node_type && node->node_type <= ND_ASSIGN)
	{
		assign_type_recursive(node->lhs);
		assign_type_recursive(node->rhs);
		node->data_type = set_data_type_int();
		return ;
	}
	if (node->node_type == ND_IF || node->node_type == ND_WHILE)
	{
		assign_type_recursive(node->cond);
		assign_type_recursive(node->then);
		if (node->els)
			assign_type_recursive(node->els);
		node->data_type = set_data_type_int();
		return ;
	}
}
