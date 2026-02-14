/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_assemble_src.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 21:39:26 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/15 02:55:23 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void	write_hedder(FILE *assem_src);
static void	write_body(FILE *assem_src, t_program *prog);
static void	generate_functinon_header(FILE *assem_src, t_program *prog);
static void	write_functinon_footer(FILE *assem_src);
void		generate(FILE *assem_src, const t_tree *ast);

void	write_assemble_src(FILE *assem_src, t_program *prog)
{
	write_hedder(assem_src);
	write_body(assem_src, prog);
	return ;
}

void	print_node_type(t_nd_type type);

static void	write_body(FILE *assem_src, t_program *prog)
{
	generate_functinon_header(assem_src, prog);
	t_tree	*ast = prog->ast;
	while (ast)
	{
		t_tree	*next = ast->next;
		generate(assem_src, ast);
		ast = next;
	}
	write_functinon_footer(assem_src);
}

static void	write_hedder(FILE *assem_src)
{
	fprintf(assem_src, ".intel_syntax noprefix\n.globl main\n");
	fprintf(assem_src, "main:\n");
	return ;
}

static void	generate_functinon_header(FILE *assem_src, t_program *prog)
{
	fprintf(assem_src, "\tpush rbp\n");
	fprintf(assem_src, "\tmov rbp, rsp\n");
	if (prog->var_list)
		fprintf(assem_src, "\tsub rsp, %d\n", prog->var_list->offset);
}

static void	write_functinon_footer(FILE *assem_src)
{
	fprintf(assem_src, "\tmov rsp, rbp\n");
	fprintf(assem_src, "\tpop rbp\n");
	fprintf(assem_src, "\tmov rax, 0\n");
	fprintf(assem_src, "\tret\n");
	return ;
}
