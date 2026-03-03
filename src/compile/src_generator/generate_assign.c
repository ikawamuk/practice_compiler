/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_assign.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:56:36 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/04 02:26:37 by ikawamuk         ###   ########.fr       */
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
	generate_local_var_address(assem_src, node->lhs);
	generate(assem_src, node->rhs);
	fprintf(assem_src, "\tpop rdi\n");
	fprintf(assem_src, "\tpop rax\n");
	fprintf(assem_src, "\tmov [rax], rdi\n");
	fprintf(assem_src, "\tpush rdi\n");
}
