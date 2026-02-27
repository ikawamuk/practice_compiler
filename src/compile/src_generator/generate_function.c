/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 03:32:23 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/28 03:52:19 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"
#include <stdio.h>

void		generate_block(FILE *assem_src, const t_tree *node);
static void	generate_functinon_header(FILE *assem_src, t_function *prog);
static void	generate_functinon_footer(FILE *assem_src, const char *func_name);

void	generate_function(FILE *assem_src, t_function *func)
{
	const char	*func_name = func->name;
	generate_functinon_header(assem_src, func);
	generate_block(assem_src, func->node);
	generate_functinon_footer(assem_src, func_name);
}

static void	generate_functinon_header(FILE *assem_src, t_function *func)
{
	fprintf(assem_src, ".global %s\n", func->name);
	fprintf(assem_src, "%s:\n", func->name);
	fprintf(assem_src, "\tpush rbp\n");
	fprintf(assem_src, "\tmov rbp, rsp\n");
	if (func->var_list)
		fprintf(assem_src, "\tsub rsp, %d\n",func->var_list->offset);
}

static void	generate_functinon_footer(FILE *assem_src, const char *func_name)
{
	fprintf(assem_src, ".Lreturn.%s:\n", func_name);
	fprintf(assem_src, "\tmov rsp, rbp\n");
	fprintf(assem_src, "\tpop rbp\n");
	fprintf(assem_src, "\tmov rax, 0\n");
	fprintf(assem_src, "\tret\n");
	return ;
}