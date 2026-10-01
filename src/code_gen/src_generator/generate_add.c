/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 21:56:30 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/06/19 00:02:59 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <stdio.h>

void	generate_add(int assem_src_fd, const t_tree *node)
{
	if (node->data_type->kind == TYPE_PTR)
	{
		t_data_type*	base_type = node->lhs->data_type->ptr_to;
		dprintf(assem_src_fd, "\timul rdi, %d\n", size_of_kind(base_type->kind));
	}
	dprintf(assem_src_fd, "\tadd rax, rdi\n");
}
