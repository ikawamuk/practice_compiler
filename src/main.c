/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 21:39:22 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/31 23:02:22 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int		file_to_token_list(char *file_path, t_token *head);
int		compile(t_token *input);
void	clear_token(t_token *cur);

int	main(int argc, char *argv[])
{
	t_token	*token_list;

	(void)argc;
	token_list = NULL;
	if (file_to_token_list(argv[1], token_list) != 0)
		return (EXIT_FAILURE);
	if (compile(token_list) != 0)
	{
		clear_token(token_list);
		return (EXIT_FAILURE);
	}
	clear_token(token_list);
	return (EXIT_SUCCESS);
}
