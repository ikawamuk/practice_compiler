/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_block.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 04:33:53 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/06/19 00:02:44 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "tree.h"
#include <stdio.h>

void	generate(int assem_src_fd, const t_tree *node);

void	generate_block(int assem_src_fd, const t_tree *node)
{
	t_tree	*cur = (t_tree *)node->child;
	while (cur)
	{
		t_tree	*next = cur->next;
		generate(assem_src_fd, cur);
		cur = next;
	}
}
