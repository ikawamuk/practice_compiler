/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_num_leaf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:37:21 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/12 18:01:30 by ikawamuk         ###   ########.fr       */
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
	return (new);
}
