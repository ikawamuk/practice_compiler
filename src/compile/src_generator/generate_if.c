/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 02:39:17 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/04 02:35:27 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <stdio.h>

void	generate(FILE *assem_src, const t_tree *node);

void	generate_if(FILE *assem_src, const t_tree *node)
{
	static size_t	label_idx = 0;

	generate(assem_src, node->cond);
	fprintf(assem_src, "\tpop rax\n");
	fprintf(assem_src, "\tcmp rax, 0\n");
	fprintf(assem_src, "\tje .Lelse%zu\n", label_idx);
	generate(assem_src, node->then);
	fprintf(assem_src, "\tjmp .Lend%zu\n", label_idx);
	fprintf(assem_src, ".Lelse%zu:\n", label_idx);
	if (node->els)
		generate(assem_src, node->els);
	fprintf(assem_src, ".Lend%zu:\n", label_idx);
	label_idx++;
	return ;
}
