/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_func_call.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 13:09:09 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/06/19 00:02:59 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <string.h>
#include <stdio.h>

const char	*arg_registers[] = {
	"rdi", "rsi", "rdx", "rcx", "r8", "r9"
};

void		generate(int assem_src_fd, const t_tree *node);
const char		**get_arg_registers(void);
static void	generate_syscall(int assem_src_fd, const t_tree *node);

void		generate_func_call(int assem_src_fd, const t_tree *node)
{
	if (!strcmp("syscall", node->func_name))
	{
		generate_syscall(assem_src_fd, node);
		return ;
	}
	int	argc = 0;
	for (t_tree *arg = node->args; arg; arg = arg->next)
	{
		generate(assem_src_fd, arg);
		argc++;
	}
	for (int i = argc - 1; i >= 0; i--)
		dprintf(assem_src_fd, "\tpop %s\n", get_arg_registers()[i]);
	// need 16bytes alinement!;
	dprintf(assem_src_fd, "\tcall %s\n", node->func_name);
	dprintf(assem_src_fd, "\tpush rax\n");
}

const char	**get_arg_registers(void)
{
	return (arg_registers);
}

static void	generate_syscall(int assem_src_fd, const t_tree *node)
{
	static const char	*arg_syscall_registers[] = {
		"rax", "rdi", "rsi", "rdx", "r10", "r8", "r9"
	};
	int	argc = 0;
	for (t_tree *arg = node->args; arg; arg = arg->next)
	{
		generate(assem_src_fd, arg);
		argc++;
	}
	for (int i = argc - 1; i >= 0; i--)
		dprintf(assem_src_fd, "\tpop %s\n", arg_syscall_registers[i]);
	dprintf(assem_src_fd, "\tsyscall\n");
	dprintf(assem_src_fd, "\tpush rax\n");
}
