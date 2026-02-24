/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 21:39:22 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/24 13:24:07 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "arena.h"
# include "token.h"
# include "function.h"
#include <stdlib.h>
#include <stdio.h>

char	*slurp_file(const char *file_path);
t_token *tokenize(const char *str);
t_function	*parse(t_token *token_list);
void	compile(t_function *ast);

void	print_ast(t_tree *ast);
void	print_token_list(const t_token *token);

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		fprintf(stderr, "no input file");
		return (EXIT_FAILURE);
	}
	char	*file_content = slurp_file(argv[1]);
	t_token	*token_list = tokenize(file_content);
	t_function	*main_function = parse(token_list);
	print_ast(main_function->ast);
	compile(main_function);
}
