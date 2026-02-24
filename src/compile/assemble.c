/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assemble.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 21:39:32 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/24 13:51:25 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ccc_define.h"
#include "arena.h"
#include <stdlib.h>
#include <stdio.h>

void	assemble(const char *assem_src_name)
{
	char	cmd[256];

	snprintf(cmd, sizeof(cmd), "gcc -c %s", assem_src_name);
	if (system(cmd) != 0)
		exit(EXIT_FAILURE);
	printf("assemblecode generated: %s\n", assem_src_name);
	// snprintf(cmd, sizeof(cmd), "rm %s", assem_src_name);
}
