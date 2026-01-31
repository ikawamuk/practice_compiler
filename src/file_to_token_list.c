/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_token_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 22:51:24 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/01 01:06:49 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include <stdlib.h>
#include <stdio.h>

char	*read_in_bulk(const char *file_path);
int		tokenize(char *str, t_token **list_p);

int	file_to_token_list(char *file_path, t_token **list_p)
{
	char	*input_str;

	input_str = read_in_bulk(file_path);
	if (tokenize(input_str, list_p) != 0)
	{
		free(input_str);
		return (EXIT_FAILURE);
	}
	free(input_str);
	return (EXIT_SUCCESS);
}
