/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 21:39:28 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/01 01:14:15 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include "ccc_define.h"
#include "token.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	assemble(char *);
int	create_assemble_src(int fd, t_token *input);

int	compile(t_token *input)
{
	static char	asm_file_name[] = "./asm/Ccc_XXXXXX.s";
	int			fd;

	fd = mkstemps(asm_file_name, 2);
	if (fd == -1)
		return (EXIT_FAILURE);
	if (create_assemble_src(fd, input) != 0)
	{
		close(fd);
		return (EXIT_FAILURE);
	}
	close(fd);
	return (assemble(asm_file_name));
}
