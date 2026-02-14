/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_local_value_address.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:47:32 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/14 23:00:48 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

/*
@brief push local value's address on stack.
*/
void	generate_local_value_address(FILE *assem_src, const t_tree *node)
{
	fprintf(assem_src, "\tmov rax, rbp\n");
	fprintf(assem_src, "\tsub rax, %d\n", node->local_var->offset);
	fprintf(assem_src, "\tpush rax\n");
}
