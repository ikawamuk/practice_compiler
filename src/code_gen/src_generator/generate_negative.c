/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_negative.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:59:50 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/06/19 00:02:59 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "tree.h"
#include <stdio.h>

void	generate(int assem_src_fd, const t_tree *node);

void	generate_negative(int assem_src_fd, const t_tree *node)
{
	generate(assem_src_fd, node->child);
	dprintf(assem_src_fd, "\tpop rax\n");
	dprintf(assem_src_fd, "\tneg rax\n");
	dprintf(assem_src_fd, "\tpush rax\n");
}
