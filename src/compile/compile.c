/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 21:39:28 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/28 08:54:08 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include "ccc_define.h"
#include "function.h"
#include "arena.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

FILE	*open_assem_src(char *assem_src_name);
void	write_assemble_src(FILE *assem_src, t_func_list *program);

char		*compile(t_func_list *program)
{
	char	*assem_src_name = strdup(ASMFILE_FORMAT);
	if (!assem_src_name)
		return (perror("malloc"), NULL);
	FILE	*assem_src = open_assem_src(assem_src_name);
	write_assemble_src(assem_src, program);
	fclose(assem_src);
	clear_arena();
	printf("Assemble src generated: %s\n", assem_src_name);
	return (assem_src_name);
}
