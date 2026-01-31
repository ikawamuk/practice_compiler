/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_token_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 02:28:13 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/01 02:34:16 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include <stdio.h>
#include <stdlib.h>

char	*read_in_bulk(const char *file_path);
t_token *tokenize(char *str);

t_token	*file_to_token_list(char *file_path)
{
	t_token	*token_list;
	char	*input_str;

	input_str = read_in_bulk(file_path);
	if (!input_str)
		return (NULL);
	token_list = tokenize(input_str);
	if (!token_list)
	{
		free(input_str);
		return (NULL);
	}
	return (token_list);
}
