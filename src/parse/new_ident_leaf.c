/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ident_leaf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 21:14:28 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/08 21:18:41 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "tree.h"
#include "local_variable.h"
#include <stdio.h>

t_lvar  *find_lvar(const t_token *token);
int 	push_lval(const t_token *token);

t_tree	*new_ident_leaf(const t_token *token)
{
	t_tree	*new = aalloc(sizeof(t_tree));
	if (!new)
		return (NULL);
	new->type = ND_LVAR;
	new->val = 0;
	new->lhs = NULL;
	new->rhs = NULL;
	t_lvar	*lvar = find_lvar(token);
	if (lvar)
		new->offset = lvar->offset;
	else
		new->offset = push_lval(token);
	return (new);
}
