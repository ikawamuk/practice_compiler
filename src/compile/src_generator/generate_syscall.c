/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_syscall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 00:24:18 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/01 00:28:28 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <string.h>
#include <stdio.h>

void	generate(FILE *assem_src, const t_tree *node);

void	generate_syscall(FILE *assem_src, const t_tree *node)
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
