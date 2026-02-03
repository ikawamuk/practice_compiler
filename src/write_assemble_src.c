/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_assemble_src.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 21:39:26 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/03 18:48:48 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "token.h"
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void	put_hedder(FILE *asm_file);
static void	put_return(FILE *asm_file);
// int			put_operations(FILE *asm_file, t_token *input);
int			put_body(FILE *asm_file, t_tree *ast);

int	write_assemble_src(FILE *asm_file, t_tree *ast)
{
	put_hedder(asm_file);
	if (put_body(asm_file, ast) != 0)
		return (EXIT_FAILURE);
	put_return(asm_file);
	return (EXIT_SUCCESS);
}

static void	put_return(FILE *asm_file)
{
	fprintf(asm_file, "\tpop rax\n");
	fprintf(asm_file, "\tret\n");
	return ;
}

static void	put_hedder(FILE *asm_file)
{
	fprintf(asm_file, ".intel_syntax noprefix\n.globl main\n");
	fprintf(asm_file, "main:\n");
	return ;
}
