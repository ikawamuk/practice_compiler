/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 21:56:30 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/05/01 10:45:40 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <stdio.h>

void	generate_add(FILE *assem_src, const t_tree *node)
{
	if (node->data_type->kind == TYPE_PTR)
	{
		t_data_type*	base_type = node->lhs->data_type->ptr_to;
		fprintf(assem_src, "\timul rdi, %d\n", size_of_kind(base_type->kind));
	}
	fprintf(assem_src, "\tadd rax, rdi\n");
}
