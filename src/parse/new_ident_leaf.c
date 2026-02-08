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

t_tree	*new_ident_leaf(const char *str)
{
	t_tree	*new = aalloc(sizeof(t_tree));
	if (!new)
		return (NULL);
	new->type = ND_LVAR;
	new->val = 0;
	new->lhs = NULL;
	new->rhs = NULL;
	new->offset = (str[0] - 'a' + 1) * 8;
	return (new);
}
