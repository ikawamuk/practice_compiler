/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_assemble_src.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 21:39:26 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/01 01:46:40 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void	put_hedder(FILE *asm_file);
static void	put_return(FILE *asm_file);
int			put_operations(FILE *asm_file, t_token *input);

int	create_assemble_src(int fd, t_token *input)
{
	FILE	*asm_file;

	asm_file = fdopen(fd, "w");
	if (!asm_file)
	{
		fprintf(stderr, "Ccc: error: failed to open the file\n");
		return (EXIT_FAILURE);
	}
	put_hedder(asm_file);
	if (put_operations(asm_file, input) != 0)
	{
		fclose(asm_file);
		return (EXIT_FAILURE);
	}
	put_return(asm_file);
	fclose(asm_file);
	return (EXIT_SUCCESS);
}

static void	put_return(FILE *asm_file)
{
	fprintf(asm_file, "\tret\n");
	return ;
}

static void	put_hedder(FILE *asm_file)
{
	fprintf(asm_file, ".intel_syntax noprefix\n.globl main\n");
	fprintf(asm_file, "main:\n");
	return ;
}
