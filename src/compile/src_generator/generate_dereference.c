/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_dereference.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 01:34:22 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/01 01:37:21 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

void	generate_local_variable(FILE *assem_src, const t_tree *node);
void	generate_load(FILE *assem_src);;

void	generate_dereference(FILE *assem_src, const t_tree *node)
{
	generate_local_variable(assem_src, node);
	generate_load(assem_src);
}
