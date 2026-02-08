/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_src.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 21:44:45 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/08 21:46:28 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

int	write_assemble_src(FILE *asm_file, t_tree *ast);

void	generate_src(FILE *asm_file, t_tree *ast)
{
	if (write_assemble_src(asm_file, ast) != 0)
	{
		fclose(asm_file);
		clear_arena();
		exit(EXIT_FAILURE);
	}
}
