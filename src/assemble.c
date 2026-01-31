/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assemble.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 21:39:32 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/31 21:39:33 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ccc_define.h"
#include <stdlib.h>
#include <stdio.h>

void	assemble(char *asm_file_name)
{
	char cmd[256];

	snprintf(cmd, sizeof(cmd), "cc %s -o c.out", asm_file_name);
	system(cmd);
	snprintf(cmd, sizeof(cmd), "rm %s", asm_file_name);
	system(cmd);
	return ;
}