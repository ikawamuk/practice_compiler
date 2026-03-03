/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_return.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:49:10 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/04 01:56:05 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <stdio.h>

void	generate(FILE *assem_src, const t_tree *node);
char	*get_current_func_name(void);

void	generate_return(FILE *assem_src, const t_tree *node)
{
	generate(assem_src, node->child);
	fprintf(assem_src, "\tpop rax\n");
	fprintf(assem_src, "\tjmp .Lreturn.%s\n", get_current_func_name());
}
