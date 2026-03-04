/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_num_leaf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:37:21 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/04 21:33:22 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "tree.h"
#include <stdlib.h>

void		*xaalloc(size_t size);
t_data_type	set_data_type_int(void);

t_tree	*new_num_leaf(int val)
{
	t_tree	*new = xaalloc(sizeof(t_tree));
	new->node_type = ND_NUM;
	new->next = NULL;
	new->value = val;
	new->data_type = set_data_type_int();
	return (new);
}
