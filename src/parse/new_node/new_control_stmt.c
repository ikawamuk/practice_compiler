/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_control_stmt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:17:54 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/04 12:23:19 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "arena.h"
#include <stdlib.h>

void	*xaalloc(size_t size);

t_tree	*new_control_stmt(t_nd_type type, t_tree *cond, t_tree *then)
{
	t_tree	*new = xaalloc(sizeof(t_tree));
	new->node_type = type;
	new->cond = cond;
	new->then = then;
	return (new);
}
