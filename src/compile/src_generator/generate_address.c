/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:47:32 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/06/19 00:04:12 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "arena.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	generate(int assem_src_fd, const t_tree *node);
void	generate_local_var_address(int assem_src_fd, const t_tree *node);

void	print_node_type(t_nd_type type);

void	generate_address(int assem_src_fd, const t_tree *node)
{
	generate_local_var_address(assem_src_fd, node->child);
}

/*
@brief push local value's address on stack.
*/
void	generate_local_var_address(int assem_src_fd, const t_tree *node)
{
	if (node->node_type == ND_LVAR)
	{
		dprintf(assem_src_fd, "\tmov rax, rbp\n");
		dprintf(assem_src_fd, "\tsub rax, %d\n", node->local_var->offset);
		dprintf(assem_src_fd, "\tpush rax\n");
		return ;
	}
	else if (node->node_type == ND_DEREFER)
	{
		generate(assem_src_fd, node->child);
		return ;
	}
	dprintf(1, "It is not a left value.\n");
	print_node_type(node->node_type);
	close(assem_src_fd);
	clear_arena();
	exit(EXIT_FAILURE);
}
