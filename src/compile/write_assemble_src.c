/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_assemble_src.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 21:39:26 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/08 21:51:54 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "token.h"
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void	write_hedder(FILE *asm_file);
static void	write_footer(FILE *asm_file);
static void	write_body(FILE *asm_file,  t_tree *ast);
static void	generate_functinon_header(FILE *asm_file);
void		generate(FILE *asm_file, t_tree *ast);

int	write_assemble_src(FILE *asm_file, t_tree *ast)
{
	write_hedder(asm_file);
	write_body(asm_file, ast);
	write_footer(asm_file);
	return (EXIT_SUCCESS);
}

static void	write_body(FILE *asm_file,  t_tree *ast)
{
	generate_functinon_header(asm_file);
	while (ast)
	{
		t_tree	*next = ast->next;
		generate(asm_file, ast);
		fprintf(asm_file, "\tpop rax\n");
		ast = next;
	}
}

static void	generate_functinon_header(FILE *asm_file)
{
	fprintf(asm_file, "\tpush rbp\n");
	fprintf(asm_file, "\tmov rbp, rsp\n");
	fprintf(asm_file, "\tsub rsp, 208\n");
}

static void	write_footer(FILE *asm_file)
{
	// fprintf(asm_file, "\tpop rax\n");
	fprintf(asm_file, "\tmov rsp, rbp\n");
	fprintf(asm_file, "\tpop rbp\n");
	fprintf(asm_file, "\tmov rax, 0\n");
	fprintf(asm_file, "\tret\n");
	return ;
}

static void	write_hedder(FILE *asm_file)
{
	fprintf(asm_file, ".intel_syntax noprefix\n.globl main\n");
	fprintf(asm_file, "main:\n");
	return ;
}
