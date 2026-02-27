/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 07:17:49 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/28 07:46:38 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"
#include <stdio.h>

void	print_ast(t_tree *ast);

void	print_program(t_function *program)
{
	for (t_function *cur = program; cur; cur = cur->next)
	{
		printf("function name: %s\n", cur->name);
		print_ast(cur->node);
	}
}
