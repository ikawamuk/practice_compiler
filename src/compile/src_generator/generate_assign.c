/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_assign.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:56:36 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/06/19 00:02:59 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

void	generate_local_var_address(int assem_src_fd, const t_tree *node);
void	generate(int assem_src_fd, const t_tree *node);

void	generate_assign(int assem_src_fd, const t_tree *node)
{
	generate_local_var_address(assem_src_fd, node->lhs);
	generate(assem_src_fd, node->rhs);
	dprintf(assem_src_fd, "\tpop rdi\n");
	dprintf(assem_src_fd, "\tpop rax\n");
	dprintf(assem_src_fd, "\tmov [rax], rdi\n");
	dprintf(assem_src_fd, "\tpush rdi\n");
}
