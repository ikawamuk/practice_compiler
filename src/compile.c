/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 21:39:28 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/31 21:39:29 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include "ccc_define.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	assemble(char *);
void	create_assemble_src(int fd, const char *input);

int	compile(char *input)
{
	static char	asm_file_name[] = "/tmp/Ccc_XXXXXX.s";
	int			fd;

	fd = mkstemps(asm_file_name, 2);
	if (fd == -1)
		return (-1);
	create_assemble_src(fd, input);
	close(fd);
	assemble(asm_file_name);
	return (0);
}
