/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 21:39:22 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/01 01:55:03 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*read_in_bulk(const char *file_path);
t_token *tokenize(char *str);
int		compile(t_token *input);
void	clear_token(t_token *cur);

int	main(int argc, char *argv[])
{
	char	*input_str;
	t_token	*token_list;

	(void)argc;
	input_str = read_in_bulk(argv[1]);
	token_list = tokenize(input_str);
	if (!token_list)
	{
		free(input_str);
		return (EXIT_FAILURE);
	}
	if (compile(token_list) != 0)
	{
		free(input_str);
		clear_token(token_list);
		return (EXIT_FAILURE);
	}
	free(input_str);
	clear_token(token_list);
	return (EXIT_SUCCESS);
}
