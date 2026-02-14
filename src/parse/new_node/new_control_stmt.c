/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_control_stmt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:17:54 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/14 22:26:06 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "arena.h"
#include <stdlib.h>

t_tree	*new_control_stmt(t_nd_type type, t_tree *cond, t_tree *then)
{
	t_tree	*new = aalloc(sizeof(t_tree));
	if (!new)
	{
		clear_arena();
		exit(EXIT_FAILURE);
	}
	new->type = type;
	new->cond = cond;
	new->then = then;
	return (new);
}
