/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_return.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:49:10 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/06/19 00:02:59 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <stdio.h>

void	generate(int assem_src_fd, const t_tree *node);
char	*get_current_func_name(void);

void	generate_return(int assem_src_fd, const t_tree *node)
{
	generate(assem_src_fd, node->child);
	dprintf(assem_src_fd, "\tpop rax\n");
	dprintf(assem_src_fd, "\tjmp .Lreturn.%s\n", get_current_func_name());
}
