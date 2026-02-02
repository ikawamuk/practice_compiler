/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 21:39:22 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/02 12:24:03 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

t_tree	*file_to_ast(char *file_path);
int		compile(t_tree *ast);
void	clear_ast(t_tree *node);

int	main(int argc, char *argv[])
{
	t_tree	*ast;

	(void)argc;
	ast = file_to_ast(argv[1]);
	if (!ast)
		return (EXIT_FAILURE);
	if (compile(ast) != 0)
	{
		clear_ast(ast);
		return (EXIT_FAILURE);
	}
	clear_ast(ast);
	return (EXIT_SUCCESS);
}
