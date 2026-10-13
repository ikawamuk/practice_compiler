/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_assign.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:56:36 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/10/13 12:07:38 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

void	generate_local_var_address(int assem_src_fd, const t_tree *node);
void	generate(int assem_src_fd, const t_tree *node);
void	generate_store(int assem_src_fd, t_data_type *type);

void	generate_assign(int assem_src_fd, const t_tree *node)
{
	generate_local_var_address(assem_src_fd, node->lhs);
	generate(assem_src_fd, node->rhs);
	generate_store(assem_src_fd, node->data_type);
}

void generate_store(int assem_src_fd, t_data_type *type)
{
	dprintf(assem_src_fd, "\tpop rdi\n");
	dprintf(assem_src_fd, "\tpop rax\n");
	if (size_of(type) == 4)
		dprintf(assem_src_fd, "\tmov dword ptr [rax], edi\n");
	else if (size_of(type) == 8)
		dprintf(assem_src_fd, "\tmov [rax], rdi\n");
	dprintf(assem_src_fd, "\tpush rdi\n");
}
