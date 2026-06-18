/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 02:39:17 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/06/19 00:02:59 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <stdio.h>

void	generate(int assem_src_fd, const t_tree *node);

void	generate_if(int assem_src_fd, const t_tree *node)
{
	static size_t	label_idx = 0;

	generate(assem_src_fd, node->cond);
	dprintf(assem_src_fd, "\tpop rax\n");
	dprintf(assem_src_fd, "\tcmp rax, 0\n");
	dprintf(assem_src_fd, "\tje .Lelse%zu\n", label_idx);
	generate(assem_src_fd, node->then);
	dprintf(assem_src_fd, "\tjmp .Lend%zu\n", label_idx);
	dprintf(assem_src_fd, ".Lelse%zu:\n", label_idx);
	if (node->els)
		generate(assem_src_fd, node->els);
	dprintf(assem_src_fd, ".Lend%zu:\n", label_idx);
	label_idx++;
	return ;
}
