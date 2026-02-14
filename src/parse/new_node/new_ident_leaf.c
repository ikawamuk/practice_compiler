/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ident_leaf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 21:14:28 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/12 17:19:24 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "tree.h"
#include "local_variable.h"
#include <stdio.h>
#include <stdlib.h>

t_lvar  *find_lvar(const t_token *token);
int 	push_lval(const t_token *token);

t_tree	*new_ident_leaf(const t_token *token)
{
	t_tree	*new = aalloc(sizeof(t_tree));
	if (!new)
	{
		clear_arena();
		exit(EXIT_FAILURE);
	}
	new->type = ND_LVAR;
	t_lvar	*lvar = find_lvar(token);
	if (lvar)
		new->offset = lvar->offset;
	else
		new->offset = push_lval(token);
	return (new);
}
