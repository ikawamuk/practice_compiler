/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_local_variable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:43:39 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/10/13 12:35:48 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <stdio.h>

void	generate_local_var_address(int assem_src_fd, const t_tree *node);
void	generate_load(int assem_src_fd, t_data_type *type);

void	generate_local_variable(int assem_src_fd, const t_tree *node)
{
	generate_local_var_address(assem_src_fd, node);
	if (node->data_type->kind != TYPE_ARRAY)
		generate_load(assem_src_fd, node->data_type);
}

void	generate_load(int assem_src_fd, t_data_type *type)
{
	dprintf(assem_src_fd, "\tpop rax\n");
	if (size_of(type) == 4)
		dprintf(assem_src_fd, "\tmovsxd rax, dword ptr [rax]\n");
	else if (size_of(type) == 8)
		dprintf(assem_src_fd, "\tmov rax, [rax]\n");
	dprintf(assem_src_fd, "\tpush rax\n");
}
