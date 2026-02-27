/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_assemble_src.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 21:39:26 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/28 08:54:36 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void		generate_function(FILE *assem_src, t_function *func);
static void	write_hedder(FILE *assem_src);
static void	write_body(FILE *assem_src, t_func_list *program);

void	write_assemble_src(FILE *assem_src, t_func_list *program)
{
	write_hedder(assem_src);
	write_body(assem_src, program);
	return ;
}

static void	write_body(FILE *assem_src, t_func_list *program)
{
	for (t_func_list *cur = program; cur; cur = cur->next)
		generate_function(assem_src, cur->func);
}

static void	write_hedder(FILE *assem_src)
{
	fprintf(assem_src, ".intel_syntax noprefix\n");
	return ;
}

