/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_block.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 04:33:53 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/15 04:38:27 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "tree.h"
#include <stdio.h>

void	generate(FILE *assem_src, const t_tree *node);

void	generate_block(FILE *assem_src, const t_tree *node)
{
	t_tree	*cur = (t_tree *)node;
	while (cur)
	{
		t_tree	*next = cur->next;
		generate(assem_src, cur);
		cur = next;
	}
}
