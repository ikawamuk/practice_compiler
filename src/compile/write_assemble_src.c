/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_assemble_src.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 21:39:26 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/06/19 00:02:44 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void		generate_function(int assem_src_fd, t_function *func);
static void	write_hedder(int asm_src_fd);
static void	write_body(int asm_src_fd, t_func_list *program);

void	write_assemble_src(int asm_src_fd, t_func_list *program)
{
	write_hedder(asm_src_fd);
	write_body(asm_src_fd, program);
	return ;
}

static void	write_body(int asm_src_fd, t_func_list *program)
{
	for (t_func_list *cur = program; cur; cur = cur->next)
		generate_function(asm_src_fd, cur->func);
}

static void	write_hedder(int asm_src_fd)
{
	dprintf(asm_src_fd, ".intel_syntax noprefix\n");
	return ;
}

