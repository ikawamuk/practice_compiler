/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 21:39:28 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/14 18:50:22 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include "ccc_define.h"
#include "program.h"
#include "arena.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		assemble(char *asm_file_name);
FILE	*open_asm_file(char *asm_file_name);
void	write_assemble_src(FILE *asm_file, t_program *prog);

void	compile(t_program *prog)
{
	char	asm_file_name[] = ASMFILE_FORMAT;
	FILE	*asm_file = open_asm_file(asm_file_name);
	write_assemble_src(asm_file, prog);
	fclose(asm_file);
	clear_arena();
	assemble(asm_file_name);
}
