/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_dereference.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 01:34:22 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/06/19 00:02:44 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

void	generate(int assem_src_fd, const t_tree *node);
void	generate_load(int assem_src_fd);

void	generate_dereference(int assem_src_fd, const t_tree *node)
{
	generate(assem_src_fd, node->child);
	generate_load(assem_src_fd);
}
