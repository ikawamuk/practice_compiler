/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 03:32:23 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/28 08:43:07 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"
#include <stdio.h>

void		generate_block(FILE *assem_src, const t_tree *node);
static void	generate_functinon_header(FILE *assem_src, t_function *prog);
static void	generate_functinon_footer(FILE *assem_src);

static char	*current_func_name;

void	generate_function(FILE *assem_src, t_function *func)
{
	current_func_name = (char *)func->name;
	generate_functinon_header(assem_src, func);
	generate_block(assem_src, func->body);
	generate_functinon_footer(assem_src);
}

char	*get_current_func_name(void)
{
	return (current_func_name);
}

static void	generate_functinon_header(FILE *assem_src, t_function *func)
{
	fprintf(assem_src, ".global %s\n", func->name);
	fprintf(assem_src, "%s:\n", func->name);
	fprintf(assem_src, "\tpush rbp\n");
	fprintf(assem_src, "\tmov rbp, rsp\n");
	if (func->locals)
		fprintf(assem_src, "\tsub rsp, %d\n",func->stack_size);
}

static void	generate_functinon_footer(FILE *assem_src)
{
	fprintf(assem_src, ".Lreturn.%s:\n", current_func_name);
	fprintf(assem_src, "\tmov rsp, rbp\n");
	fprintf(assem_src, "\tpop rbp\n");
	fprintf(assem_src, "\tret\n");
	return ;
}