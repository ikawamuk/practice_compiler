/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 21:39:28 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/03 18:40:10 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include "ccc_define.h"
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		assemble(char *asm_file_name);
FILE    *create_asm_file(char *asm_file_name);
int		write_assemble_src(FILE *asm_file, t_tree *ast);

int	compile(t_tree *ast)
{
	char	asm_file_name[] = ASMFILE_FORMAT;
	FILE	*asm_file;

	asm_file = create_asm_file(asm_file_name);
	if (!asm_file)
		return (EXIT_FAILURE);
	if (write_assemble_src(asm_file, ast) != 0)
	{
		fclose(asm_file);
		return (EXIT_FAILURE);
	}
	fclose(asm_file);
	return (assemble(asm_file_name));
}
