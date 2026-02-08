/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 21:39:22 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/08 16:20:36 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "arena.h"
# include "token.h"
# include "tree.h"
#include <stdlib.h>
#include <stdio.h>

char	*slurp_file(t_arena *arena, const char *file_path);
t_token *tokenize(t_arena *arena, const char *str);
t_tree	*parse(t_arena *arena, t_token *token_list);
int		compile(t_tree *ast);

int	main(int argc, char *argv[])
{
	if (argc < 2)
		return (EXIT_FAILURE);
	t_arena	arena = {0};
	char	*file_content = slurp_file(&arena, argv[1]);
	t_token	*token_list = tokenize(&arena, file_content);
	t_tree	*ast = parse(&arena, token_list);
	compile(ast);
	clear_arena(&arena);
	return (EXIT_SUCCESS);
}
