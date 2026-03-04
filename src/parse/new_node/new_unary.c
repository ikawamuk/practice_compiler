/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_unary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 16:59:29 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/04 12:23:37 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "arena.h"
#include "tree.h"
#include <stdlib.h>

void	*xaalloc(size_t size);

t_tree	*new_unary(t_nd_type type, t_tree *child)
{
	t_tree	*new = xaalloc(sizeof(t_tree));
	new->node_type = type;
	new->child = child;
	return (new);
}
