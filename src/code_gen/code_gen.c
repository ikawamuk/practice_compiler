/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code_gen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 21:39:28 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/10/02 02:35:32 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include "compilation.h"
#include "ccc_define.h"
#include "function.h"
#include "arena.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int		open_assem_fd(char *assem_src_fd_name);
void	write_assemble_src(int asm_src_fd, t_func_list *program);

int	code_gen(t_compilation *ctx)
{
	char	*assem_src_fd_name = strdup(ASMFILE_FORMAT);
	if (!assem_src_fd_name)
		return (perror("malloc"), -1);
	int	asm_src_fd = open_assem_fd(assem_src_fd_name);
	write_assemble_src(asm_src_fd, ctx->function_list);
	close(asm_src_fd);
	printf("Assemble src generated: %s\n", assem_src_fd_name);
	ctx->asm_file_name = assem_src_fd_name;
	ctx->phase = ASM_FILE_NAME;
	return (0);
}
