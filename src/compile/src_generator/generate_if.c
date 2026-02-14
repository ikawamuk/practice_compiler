/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 02:39:17 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/15 02:44:57 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <stdio.h>

void	generate(FILE *assem_src, const t_tree *node);

void	generate_if(FILE *assem_src, const t_tree *node, size_t label_idx)
{
	size_t	label_else = label_idx++;
	size_t	label_end = label_idx++;

	generate(assem_src, node->cond);
	fprintf(assem_src, "\tpop rax\n");
	fprintf(assem_src, "\tcmp rax, 0\n");
	fprintf(assem_src, "\tje .L%zu\n", label_else);
	generate(assem_src, node->then);
	fprintf(assem_src, "\tjmp .L%zu\n", label_end);
	fprintf(assem_src, ".L%zu:\n", label_else);
	if (node->els)
		generate(assem_src, node->els);
	fprintf(assem_src, ".L%zu:\n", label_end);
	return ;
}
