/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 23:03:43 by ikawamuk          #+#    #+#             */                                       
/*   Updated: 2026/02/08 16:22:35 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "arena.h"
#include <stdlib.h>

t_token *create_token_list(const char *str);

t_token	*tokenize(const char *str)
{
	t_token	*token_list = create_token_list(str);
	if (!token_list)
	{
		clear_arena();
		exit(EXIT_FAILURE);
	}
	return (token_list);
}
