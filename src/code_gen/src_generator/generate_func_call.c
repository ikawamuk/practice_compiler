/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_func_call.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 13:09:09 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/10/13 12:34:20 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <string.h>
#include <stdio.h>

static const char *arg_reg64[] = {"rdi", "rsi", "rdx", "rcx", "r8", "r9"};
static const char *arg_reg32[] = {"edi", "esi", "edx", "ecx", "r8d", "r9d"};

const char *get_arg_registers(int index, t_data_type *type)
{
	if (size_of(type) == 4)
	{
		return arg_reg32[index];
	}
	return arg_reg64[index];
}

void			generate(int assem_src_fd, const t_tree *node);
const char		*get_arg_registers(int index, t_data_type *type);
static void		generate_syscall(int assem_src_fd, const t_tree *node);

void		generate_func_call(int assem_src_fd, const t_tree *node)
{
	if (!strcmp("syscall", node->func_name))
	{
		generate_syscall(assem_src_fd, node);
		return ;
	}
	t_tree *args[6];
	int	argc = 0;
	for (t_tree *arg = node->args; arg; arg = arg->next)
		args[argc++] = arg;
	for (int i = 0; i < argc; ++i)
		generate(assem_src_fd, args[i]);
	for (int i = argc - 1; i >= 0; i--)
		dprintf(assem_src_fd, "\tpop %s\n", arg_reg64[i]);
	// need 16bytes alinement!;
	dprintf(assem_src_fd, "\tcall %s\n", node->func_name);
	dprintf(assem_src_fd, "\tpush rax\n");
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
