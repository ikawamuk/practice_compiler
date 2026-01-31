/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 21:39:22 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/31 22:38:55 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*read_in_bulk(const char *file_path);
int		compile(char *input);

int	main(int argc, char *argv[])
{
	char	*input;

	(void)argc;
	input = read_in_bulk(argv[1]);
	if (compile(input) != 0)
	{
		free(input);
		return (EXIT_FAILURE);
	}
	free(input);
	return (EXIT_SUCCESS);
}
