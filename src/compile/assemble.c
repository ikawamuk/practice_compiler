/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assemble.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 21:39:32 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/08 21:47:53 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ccc_define.h"
#include "arena.h"
#include <stdlib.h>
#include <stdio.h>

void	assemble(const char *asm_file_name)
{
	char	cmd[256];

	snprintf(cmd, sizeof(cmd), "gcc %s -o b.out", asm_file_name);
	if (system(cmd) != 0)
		exit(EXIT_FAILURE);
	// snprintf(cmd, sizeof(cmd), "rm %s", asm_file_name);
	printf("assemblecode generated: %s\n", asm_file_name);
	exit(EXIT_SUCCESS);
}
