/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_local_variable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:43:39 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/06/19 00:02:59 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <stdio.h>

void	generate_local_var_address(int assem_src_fd, const t_tree *node);
void	generate_load(int assem_src_fd);

void	generate_local_variable(int assem_src_fd, const t_tree *node)
{
	generate_local_var_address(assem_src_fd, node);
	generate_load(assem_src_fd);
}

void	generate_load(int assem_src_fd)
{
	dprintf(assem_src_fd, "\tpop rax\n");
	dprintf(assem_src_fd, "\tmov rax, [rax]\n");
	dprintf(assem_src_fd, "\tpush rax\n");
}
