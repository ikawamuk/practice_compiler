/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_while.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 03:03:40 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/06/19 00:02:59 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <stdio.h>

void	generate(int assem_src_fd, const t_tree *node);

void	generate_while(int assem_src_fd, const t_tree *node)
{
	static size_t	label_idx = 0;

	dprintf(assem_src_fd, "jmp .Lcond%zu\n", label_idx);
	dprintf(assem_src_fd, ".Lthen%zu:\n", label_idx);
	generate(assem_src_fd, node->then);
	dprintf(assem_src_fd, ".Lcond%zu:\n", label_idx);
	generate(assem_src_fd, node->cond);
	dprintf(assem_src_fd, "\tpop rax\n");
	dprintf(assem_src_fd, "\tcmp rax, 0\n");
	dprintf(assem_src_fd, "\tjne .Lthen%zu\n", label_idx);
	label_idx++;
	return ;
}
