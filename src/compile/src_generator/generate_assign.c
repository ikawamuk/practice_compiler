/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_assign.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:56:36 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/01 01:27:00 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

void	generate_local_var_address(FILE *assem_src, const t_tree *node);
void	generate(FILE *assem_src, const t_tree *node);

void	generate_assign(FILE *assem_src, const t_tree *node)
{
	if (node->lhs->type != ND_LVAR)
	{
		fprintf(stderr, "left operand of assignment should be left value.\n");
		fclose(assem_src);
		clear_arena();
		exit(EXIT_FAILURE);
	}
	generate_local_var_address(assem_src, node->lhs);
	generate(assem_src, node->rhs);
	fprintf(assem_src, "\tpop rdi\n");
	fprintf(assem_src, "\tpop rax\n");
	fprintf(assem_src, "\tmov [rax], rdi\n");
	fprintf(assem_src, "\tpush rdi\n");
}