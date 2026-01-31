/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assemble.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 21:39:32 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/31 22:33:01 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ccc_define.h"
#include <stdlib.h>
#include <stdio.h>

int	assemble(char *asm_file_name)
{
	char	cmd[256];

	snprintf(cmd, sizeof(cmd), "cc %s -o c.out", asm_file_name);
	if (system(cmd) != 0)
		return (EXIT_FAILURE);
	snprintf(cmd, sizeof(cmd), "rm %s", asm_file_name);
	return (system(cmd));
}
