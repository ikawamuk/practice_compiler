/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_local_variable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:43:39 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/01 22:00:56 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <stdio.h>

void	generate_local_var_address(FILE *assem_src, const t_tree *node);
void	generate_dereference(FILE *assem_src, const t_tree *node);

void	generate_local_variable(FILE *assem_src, const t_tree *node)
{
	generate_local_var_address(assem_src, node);
	generate_dereference(assem_src, node);
}

void	generate_load(FILE *assem_src)
{
	fprintf(assem_src, "\tpop rax\n");
	fprintf(assem_src, "\tmov rax, [rax]\n");
	fprintf(assem_src, "\tpush rax\n");
}
