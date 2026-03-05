/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 21:11:41 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/05 19:24:34 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "token.h"
#include "local_variable.h"

t_var			*find_var(const t_token *token);
t_var			*push_lval(const t_token *token);
t_tree			*new_variable_leaf(t_var *var);
static t_var	*fetch_var(t_token *token);

/*
variable
*/
t_tree	*variable(t_token **token_p)
{
	t_var	*var = fetch_var(*token_p);
	t_tree	*node = new_variable_leaf(var);
	*token_p = (*token_p)->next;
	return (node);
}

static t_var	*fetch_var(t_token *token)
{
	t_var	*var = find_var(token);
	if (!var)
		var = push_lval(token);
	return (var);
}
