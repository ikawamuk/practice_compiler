/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_expr_stmt.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 02:42:02 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/15 02:45:05 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <stdio.h>

void	generate(FILE *assem_src, const t_tree *node);

void	generate_expr_stmt(FILE *assem_src, const t_tree *node)
{
	generate(assem_src, node);
	fprintf(assem_src, "\tadd rsp, 8\n");
	return ;
}
