/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_operator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 02:32:55 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/06/19 00:03:36 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <stdio.h>

void	generate(int assem_src_fd, const t_tree *node);
void	(*get_op_generator(t_nd_type type))(int, const t_tree *);

void	generate_operator(int assem_src_fd, const t_tree *node)
{
	generate(assem_src_fd, node->lhs);
	generate(assem_src_fd, node->rhs);
	dprintf(assem_src_fd, "\tpop rdi\n");
	dprintf(assem_src_fd, "\tpop rax\n");
	get_op_generator(node->node_type)(assem_src_fd, node);
	dprintf(assem_src_fd, "\tpush rax\n");
}
