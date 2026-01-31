/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_assemble_src.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 21:39:26 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/31 21:39:27 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static void	fprint_hedder(FILE *asm_file);
static void	fprint_return(FILE *asm_file, int return_value);

void	create_assemble_src(int fd, const char *input)
{
	FILE	*asm_file;

	asm_file = fdopen(fd, "w");
	if (!asm_file)
		return ;
	fprint_hedder(asm_file);
	fprint_return(asm_file, atoi(input));
	fclose(asm_file);
	return ;
}

static void	fprint_return(FILE *asm_file, int return_value)
{
	fprintf(asm_file, "\tmov rax, %d\n", return_value);
	fprintf(asm_file, "\tret\n");
	return ;
}

static void	fprint_hedder(FILE *asm_file)
{
	fprintf(asm_file, ".intel_syntax noprefix\n.globl main\n");
	fprintf(asm_file, "main:\n");
	return ;
}
