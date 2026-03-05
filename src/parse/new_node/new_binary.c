/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_binary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:31:39 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/05 21:53:48 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "tree.h"
#include <stdlib.h>

void		*xaalloc(size_t size);
t_data_type	*new_int(void);

t_tree	*new_binary(t_nd_type type, t_tree *lhs, t_tree *rhs)
{
	t_tree	*new = xaalloc(sizeof(t_tree));
	new->node_type = type;
	new->lhs = lhs;
	new->rhs = rhs;
	new->data_type = new_int();
	return (new);
}
