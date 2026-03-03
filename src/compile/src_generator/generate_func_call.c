/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_func_call.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 13:09:09 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/04 03:17:17 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <string.h>
#include <stdio.h>

const char	*arg_registers[] = {
	"rdi", "rsi", "rdx", "rcx", "r8", "r9"
};

void		generate(FILE *assem_src, const t_tree *node);
const char		**get_arg_registers(void);
static void	generate_syscall(FILE *assem_src, const t_tree *node);

void		generate_func_call(FILE *assem_src, const t_tree *node)
{
	if (!strcmp("syscall", node->func_name))
	{
		generate_syscall(assem_src, node);
		return ;
	}
	int	argc = 0;
	for (t_tree *arg = node->args; arg; arg = arg->next)
	{
		generate(assem_src, arg);
		argc++;
	}
	for (int i = argc - 1; i >= 0; i--)
		fprintf(assem_src, "\tpop %s\n", get_arg_registers()[i]);
	// need 16bytes alinement!;
	fprintf(assem_src, "\tcall %s\n", node->func_name);
	fprintf(assem_src, "\tpush rax\n");
}

const char	**get_arg_registers(void)
{
	return (arg_registers);
}

static void	generate_syscall(FILE *assem_src, const t_tree *node)
{
	static const char	*arg_syscall_registers[] = {
		"rax", "rdi", "rsi", "rdx", "r10", "r8", "r9"
	};
	int	argc = 0;
	for (t_tree *arg = node->args; arg; arg = arg->next)
	{
		generate(assem_src, arg);
		argc++;
	}
	for (int i = argc - 1; i >= 0; i--)
		fprintf(assem_src, "\tpop %s\n", arg_syscall_registers[i]);
	fprintf(assem_src, "\tsyscall\n");
	fprintf(assem_src, "\tpush rax\n");
}
