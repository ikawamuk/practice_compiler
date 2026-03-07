/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_declar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 22:39:17 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/08 01:29:31 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "tree.h"
#include "token.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
void		*xaalloc(size_t size);
void		error_at(const char *location, const char *err_msg);
t_data_type	*data_type_kw(t_token **token_p);
t_var		*push_lval(const t_token *token, t_data_type *data_type);
bool		is_expected(const char *op, t_token *token);
t_tree		*new_binary(t_nd_type type, t_tree *lhs, t_tree *rhs);
t_tree		*expr(t_token **token_p);
t_tree		*new_variable_leaf(t_var *var);

t_tree	*var_declar(t_token **token_p)
{
	t_data_type	*dt_type = data_type_kw(token_p);
	t_var *var = push_lval(*token_p, dt_type);
	*token_p = (*token_p)->next;
	t_tree	*new = xaalloc(sizeof(t_tree));
	new->node_type = ND_DECLAR;
	new->next = NULL;
	new->local_var = var;
	new->data_type = var->dt_type;
	return (new);
}

t_tree	*declaration_stmt(t_token **token_p)
{
	t_tree	*new = var_declar(token_p);
	if (is_expected("=", *token_p))
	{
		(*token_p) = (*token_p)->next;
		new = new_binary(ND_ASSIGN, new_variable_leaf(new->local_var), expr(token_p));
	}
	if (is_expected(";", *token_p))
	{
		(*token_p) = (*token_p)->next;
		return (new);
	}
	error_at((*token_p)->str, "expected \';\'\n");
	clear_arena();
	exit(EXIT_FAILURE);
}
