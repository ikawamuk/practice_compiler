/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_local_variable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:43:39 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/10/12 15:40:56 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <stdio.h>

void	generate_local_var_address(int assem_src_fd, const t_tree *node);
void	generate_load(int assem_src_fd);

void	generate_local_variable(int assem_src_fd, const t_tree *node)
{
	generate_local_var_address(assem_src_fd, node);
	if (node->data_type->kind != TYPE_ARRAY)
		generate_load(assem_src_fd);
}

void	generate_load(int assem_src_fd)
{
	dprintf(assem_src_fd, "\tpop rax\n");
	dprintf(assem_src_fd, "\tmov rax, [rax]\n");
	dprintf(assem_src_fd, "\tpush rax\n");
}
