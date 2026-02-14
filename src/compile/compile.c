/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 21:39:28 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/15 04:16:32 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include "ccc_define.h"
#include "function.h"
#include "arena.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		assemble(char *assem_src_name);
FILE	*open_assem_src(char *assem_src_name);
void	write_assemble_src(FILE *assem_src, t_function *main_function);

void	compile(t_function *main_function)
{
	char	assem_src_name[] = ASMFILE_FORMAT;
	FILE	*assem_src = open_assem_src(assem_src_name);
	write_assemble_src(assem_src, main_function);
	fclose(assem_src);
	clear_arena();
	assemble(assem_src_name);
}
