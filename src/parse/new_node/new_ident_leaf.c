/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ident_leaf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 21:14:28 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/04 21:34:33 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "tree.h"
#include "local_variable.h"
#include <stdio.h>
#include <stdlib.h>

void		*xaalloc(size_t size);
t_data_type	set_data_type_int(void);

t_tree	*new_ident_leaf(t_var *var)
{
	t_tree	*new = xaalloc(sizeof(t_tree));
	new->node_type = ND_LVAR;
	new->next = NULL;
	new->local_var = var;
	new->data_type = set_data_type_int();
	return (new);
}
