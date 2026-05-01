/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_operator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 02:32:55 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/05/01 10:08:42 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <stdio.h>

void	generate(FILE *assem_src, const t_tree *node);
void	(*get_op_generator(t_nd_type type))(FILE *, const t_tree *);

void	generate_operator(FILE *assem_src, const t_tree *node)
{
	generate(assem_src, node->lhs);
	generate(assem_src, node->rhs);
	fprintf(assem_src, "\tpop rdi\n");
	fprintf(assem_src, "\tpop rax\n");
	get_op_generator(node->node_type)(assem_src, node);
	fprintf(assem_src, "\tpush rax\n");
}
