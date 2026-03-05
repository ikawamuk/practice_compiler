/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 07:17:49 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/05 22:07:47 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"
#include "data_type.h"
#include <stdio.h>

void	print_ast(t_tree *ast);
void	print_data_type(t_data_type	*data_type);

void	print_program(t_func_list *program)
{
	for (t_func_list *cur = program; cur; cur = cur->next)
	{
		printf("function\n");
		print_data_type(cur->func->data_type);
		printf("function name: %s\n", cur->func->name);
		print_ast(cur->func->body);
	}
}
