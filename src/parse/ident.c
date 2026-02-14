/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ident.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 21:11:41 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/14 18:54:45 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "token.h"
#include "local_variable.h"

t_lvar	*find_lvar(const t_token *token);
t_lvar	*push_lval(const t_token *token);
t_tree	*new_ident_leaf(t_lvar *var);

t_tree	*ident(t_token **token_p)
{
	t_lvar	*var = find_lvar(*token_p);
	if (!var)
		var = push_lval(*token_p);
	t_tree	*node = new_ident_leaf(var);
	*token_p = (*token_p)->next;
	return (node);
}