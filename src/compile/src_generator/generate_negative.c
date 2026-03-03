/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_negative.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:59:50 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/04 01:56:35 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "tree.h"
#include <stdio.h>

void	generate(FILE *assem_src, const t_tree *node);

void	generate_negative(FILE *assem_src, const t_tree *node)
{
	generate(assem_src, node->child);
	fprintf(assem_src, "\tpop rax\n");
	fprintf(assem_src, "\tneg rax\n");
	fprintf(assem_src, "\tpush rax\n");
}
