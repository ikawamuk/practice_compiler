/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 21:56:30 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/10/12 20:37:03 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <stdio.h>

void	generate_add(int assem_src_fd, const t_tree *node)
{
	if (node->lhs->data_type && node->lhs->data_type->base)
	{
		t_data_type*	base_type = node->lhs->data_type->base;
		dprintf(assem_src_fd, "\timul rdi, %d\n", size_of(base_type));
	}
	dprintf(assem_src_fd, "\tadd rax, rdi\n");
}
