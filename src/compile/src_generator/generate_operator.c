/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_operator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 02:32:55 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/04 13:54:01 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <stdio.h>

void	generate(FILE *assem_src, const t_tree *node);
void	(*get_op_generator(t_nd_type type))(FILE *);

void	generate_operator(FILE *assem_src, const t_tree *node)
{
	generate(assem_src, node->lhs);
	generate(assem_src, node->rhs);
	fprintf(assem_src, "\tpop rdi\n");
	fprintf(assem_src, "\tpop rax\n");
	get_op_generator(node->node_type)(assem_src);
	fprintf(assem_src, "\tpush rax\n");
}
