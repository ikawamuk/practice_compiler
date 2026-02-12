/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_num_leaf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:37:21 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/12 17:22:27 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "tree.h"
#include <stdlib.h>

t_tree	*new_num_leaf(int val)
{
	t_tree	*new = aalloc(sizeof(t_tree));
	if (!new)
	if (!new)
	{
		clear_arena();
		exit(EXIT_FAILURE);
	}
	new->type = ND_NUM;
	new->val = val;
	new->child[0] = NULL;
	new->child[1] = NULL;
	return (new);
}
