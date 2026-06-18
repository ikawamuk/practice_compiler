/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 21:39:28 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/06/18 23:59:44 by ikawamuk         ###   ########.fr       */
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

int		open_assem_fd(char *assem_src_fd_name);
void	write_assemble_src(int asm_src_fd, t_func_list *program);

char		*compile(t_func_list *program)
{
	char	*assem_src_fd_name = strdup(ASMFILE_FORMAT);
	if (!assem_src_fd_name)
		return (perror("malloc"), NULL);
	int	asm_src_fd = open_assem_fd(assem_src_fd_name);
	write_assemble_src(asm_src_fd, program);
	close(asm_src_fd);
	printf("Assemble src generated: %s\n", assem_src_fd_name);
	return (assem_src_fd_name);
}
