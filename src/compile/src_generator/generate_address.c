/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:47:32 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/04 13:54:17 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "arena.h"
#include <stdio.h>
#include <stdlib.h>

void	generate(FILE *assem_src, const t_tree *node);
void	generate_local_var_address(FILE *assem_src, const t_tree *node);

void	print_node_type(t_nd_type type);

void	generate_address(FILE *assem_src, const t_tree *node)
{
	generate_local_var_address(assem_src, node->child);
}

/*
@brief push local value's address on stack.
*/
void	generate_local_var_address(FILE *assem_src, const t_tree *node)
{
	if (node->node_type == ND_LVAR)
	{
		fprintf(assem_src, "\tmov rax, rbp\n");
		fprintf(assem_src, "\tsub rax, %d\n", node->local_var->offset);
		fprintf(assem_src, "\tpush rax\n");
		return ;
	}
	else if (node->node_type == ND_DEREFER)
	{
		generate(assem_src, node->child);
		return ;
	}
	fprintf(stderr, "It is not a left value.\n");
	print_node_type(node->node_type);
	fclose(assem_src);
	clear_arena();
	exit(EXIT_FAILURE);
}
