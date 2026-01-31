/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_assemble_src.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 21:39:26 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/31 22:35:38 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void	put_hedder(FILE *asm_file);
static void	put_return(FILE *asm_file);
static int	put_operations(FILE *asm_file, char *line);

int	create_assemble_src(int fd, char *input)
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
		fprintf(stderr, "Ccc: error: invalid character\n");
		return (EXIT_FAILURE);
	}
	put_return(asm_file);
	fclose(asm_file);
	return (EXIT_SUCCESS);
}

static int	put_operations(FILE *asm_file, char *line)
{
	fprintf(asm_file, "\tmov rax, %ld\n", strtol(line, &line, 10));
	while (*line && *line != '\n')
	{
		if (*line == '+')
		{
			line++;
			fprintf(asm_file, "\tadd rax, %ld\n", strtol(line, &line, 10));
			continue ;
		}
		if (*line == '-')
		{
			line++;
			fprintf(asm_file, "\tsub rax, %ld\n", strtol(line, &line, 10));
			continue ;
		}
		return (-1);
	}
	return (0);
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
