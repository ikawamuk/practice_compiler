/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_declar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 22:39:17 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/05 22:55:31 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "token.h"

void		*xaalloc(size_t size);
t_data_type	*data_kw(t_token *token);
t_var		*push_lval(const t_token *token, t_data_type *data_type);

t_tree	*var_declar(t_token **token_p)
{
	t_data_type	*dt_type = data_kw(*token_p);
	*token_p = (*token_p)->next;
	t_var *var = push_lval(*token_p, dt_type);
	*token_p = (*token_p)->next;
	t_tree	*new = xaalloc(sizeof(t_tree));
	new->node_type = ND_DECLAR;
	new->next = NULL;
	new->local_var = var;
	new->data_type = var->dt_type;
	return (new);
}