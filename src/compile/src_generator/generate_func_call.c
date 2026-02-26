/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_func_call.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 13:09:09 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/26 22:22:36 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "tree.h"

void	generate(FILE *assem_src, const t_tree *node);

void		generate_func_call(FILE *assem_src, const t_tree *node)
{
	int	argc = 0;
	for (t_tree *arg = node->args; arg; arg = arg->next)
	{
		generate(assem_src, arg);
		argc++;
	}
	static const char	*arg_registers[] = {
		"rdi", "rsi", "rdx", "rcx", "r8", "r9"
	};
	for (int i = argc - 1; i >= 0; i--)
		fprintf(assem_src, "\tpop %s\n", arg_registers[i]);
	fprintf(assem_src, "\tcall %s\n", node->func_name);
	fprintf(assem_src, "\tpush rax\n");
}

// void	generate_16bytes_alinement_to_func_call(FILE *assem_src, const t_tree *node)
// {
	
// }
