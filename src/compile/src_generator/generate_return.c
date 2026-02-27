/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_return.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:49:10 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/28 03:42:48 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <stdio.h>

void	generate(FILE *assem_src, const t_tree *node);

void	generate_return(FILE *assem_src, const t_tree *node)
{
	generate(assem_src, node);
	fprintf(assem_src, "\tpop rax\n");
	fprintf(assem_src, "\tjmp .Lreturn.%s\n", node->func_name);
}
