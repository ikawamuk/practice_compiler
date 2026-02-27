/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ident_leaf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 21:14:28 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/28 06:55:27 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "tree.h"
#include "local_variable.h"
#include <stdio.h>
#include <stdlib.h>

void	*xaalloc(size_t size);

t_tree	*new_ident_leaf(t_lvar *var)
{
	t_tree	*new = xaalloc(sizeof(t_tree));
	new->type = ND_LVAR;
	new->local_var = var;
	return (new);
}
