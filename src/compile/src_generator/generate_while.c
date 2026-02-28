/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_while.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 03:03:40 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/28 22:13:47 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <stdio.h>

void	generate(FILE *assem_src, const t_tree *node);

void	generate_while(FILE *assem_src, const t_tree *node, size_t label_idx)
{
	fprintf(assem_src, "jmp .Lcond%zu\n", label_idx);
	fprintf(assem_src, ".Lthen%zu:\n", label_idx);
	generate(assem_src, node->then);
	fprintf(assem_src, ".Lcond%zu:\n", label_idx);
	generate(assem_src, node->cond);
	fprintf(assem_src, "\tpop rax\n");
	fprintf(assem_src, "\tcmp rax, 0\n");
	fprintf(assem_src, "\tjne .Lthen%zu\n", label_idx);
	return ;
}
