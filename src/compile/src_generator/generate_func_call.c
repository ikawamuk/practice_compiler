/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_func_call.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 13:09:09 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/24 13:14:19 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "tree.h"

void		generate_func_call(FILE *assem_src, const t_tree *node)
{
	fprintf(assem_src, "\tcall %s\n", node->func_name);
	fprintf(assem_src, "\tpush rax\n");
}
