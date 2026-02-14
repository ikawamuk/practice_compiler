/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_local_variable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:43:39 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/15 02:37:49 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <stdio.h>

void	generate_local_value_address(FILE *assem_src, const t_tree *node);

void		generate_local_variable(FILE *assem_src, const t_tree *node)
{
	generate_local_value_address(assem_src, node);
	fprintf(assem_src, "\tpop rax\n");
	fprintf(assem_src, "\tmov rax, [rax]\n");
	fprintf(assem_src, "\tpush rax\n");
}
