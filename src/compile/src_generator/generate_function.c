/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 03:32:23 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/04 03:17:23 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"
#include <stdio.h>

void		generate_block(FILE *assem_src, const t_tree *node);
const char	**get_arg_registers(void);
static void	generate_functinon_header(FILE *assem_src, t_function *prog);
static void	generate_function_params(FILE *assem_src, t_function *func);
static void	generate_functinon_footer(FILE *assem_src);

static char	*current_func_name;

void	generate_function(FILE *assem_src, t_function *func)
{
	current_func_name = (char *)func->name;
	generate_functinon_header(assem_src, func);
	generate_function_params(assem_src, func);
	generate_block(assem_src, func->body);
	generate_functinon_footer(assem_src);
}

char	*get_current_func_name(void)
{
	return (current_func_name);
}

static void	generate_functinon_header(FILE *assem_src, t_function *func)
{
	fprintf(assem_src, ".global %s\n", get_current_func_name());
	fprintf(assem_src, "%s:\n", get_current_func_name());
	fprintf(assem_src, "\tpush rbp\n");
	fprintf(assem_src, "\tmov rbp, rsp\n");
	fprintf(assem_src, "\tsub rsp, %d\n",func->stack_size);
}

static void	generate_function_params(FILE *assem_src, t_function *func)
{
	int	i = 0;
	for (t_var_list *cur = func->locals; i < func->argc; cur = cur->next)
		fprintf(assem_src, "\tmov [rbp-%d], %s\n", cur->var->offset, get_arg_registers()[i++]);
}

static void	generate_functinon_footer(FILE *assem_src)
{
	fprintf(assem_src, ".Lreturn.%s:\n", get_current_func_name());
	fprintf(assem_src, "\tmov rsp, rbp\n");
	fprintf(assem_src, "\tpop rbp\n");
	fprintf(assem_src, "\tret\n");
	return ;
}