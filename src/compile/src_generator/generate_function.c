/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 03:32:23 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/06/19 00:02:59 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"
#include <stdio.h>

void		generate_block(int assem_src_fd, const t_tree *node);
const char	**get_arg_registers(void);
static void	generate_functinon_header(int assem_src_fd, t_function *prog);
static void	generate_function_params(int assem_src_fd, t_function *func);
static void	generate_functinon_footer(int assem_src_fd);

static char	*current_func_name;

void	generate_function(int assem_src_fd, t_function *func)
{
	current_func_name = (char *)func->name;
	generate_functinon_header(assem_src_fd, func);
	generate_function_params(assem_src_fd, func);
	generate_block(assem_src_fd, func->body);
	generate_functinon_footer(assem_src_fd);
}

char	*get_current_func_name(void)
{
	return (current_func_name);
}

static void	generate_functinon_header(int assem_src_fd, t_function *func)
{
	dprintf(assem_src_fd, ".global %s\n", get_current_func_name());
	dprintf(assem_src_fd, "%s:\n", get_current_func_name());
	dprintf(assem_src_fd, "\tpush rbp\n");
	dprintf(assem_src_fd, "\tmov rbp, rsp\n");
	dprintf(assem_src_fd, "\tsub rsp, %d\n",func->stack_size);
}

static void	generate_function_params(int assem_src_fd, t_function *func)
{
	int	i = 0;
	for (t_var_list *cur = func->locals; i < func->argc; cur = cur->next)
		dprintf(assem_src_fd, "\tmov [rbp-%d], %s\n", cur->var->offset, get_arg_registers()[i++]);
}

static void	generate_functinon_footer(int assem_src_fd)
{
	dprintf(assem_src_fd, ".Lreturn.%s:\n", get_current_func_name());
	dprintf(assem_src_fd, "\tmov rsp, rbp\n");
	dprintf(assem_src_fd, "\tpop rbp\n");
	dprintf(assem_src_fd, "\tret\n");
	return ;
}