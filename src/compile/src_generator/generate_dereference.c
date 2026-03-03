/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_dereference.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 01:34:22 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/04 01:51:59 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

void	generate(FILE *assem_src, const t_tree *node);
void	generate_load(FILE *assem_src);

void	generate_dereference(FILE *assem_src, const t_tree *node)
{
	generate(assem_src, node->child);
	generate_load(assem_src);
}
