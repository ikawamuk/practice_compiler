/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_body.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 03:26:29 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/08 22:29:31 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gen_table.h"
#include <stdio.h>

void		(*get_generator(t_nd_type type))(FILE *);
static void	exec_calculation(FILE *asm_file, t_nd_type type);

int	write_body(FILE *asm_file, t_tree *node)
{
	if (node->type == ND_NUM)
	{
		fprintf(asm_file, "\tpush %d\n", node->val);
		return (0);
	}
	write_body(asm_file, node->lhs);
	write_body(asm_file, node->rhs);
	
	fprintf(asm_file, "\tpop rdi\n");
	fprintf(asm_file, "\tpop rax\n");
	
	exec_calculation(asm_file, node->type);
	
	fprintf(asm_file, "\tpush rax\n");
	return (0);
}

static void	exec_calculation(FILE *asm_file, t_nd_type type)
{
	get_generator(type)(asm_file);
}
