/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_dereference.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 01:34:22 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/10/13 12:04:29 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

void	generate(int assem_src_fd, const t_tree *node);
void	generate_load(int assem_src_fd, const t_data_type *type);

void	generate_dereference(int assem_src_fd, const t_tree *node)
{
	generate(assem_src_fd, node->child);
	if (node->data_type->kind != TYPE_ARRAY)
		generate_load(assem_src_fd, node->data_type);
}
