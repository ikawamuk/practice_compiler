/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_token_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 20:50:35 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/05/01 09:33:20 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include <stdio.h>

/*
typedef enum {
	TK_RESERVED,
	TK_IDENT,
	TK_NUM,
	TK_EOF,
	TK_ERROR
}	t_tk_type;
*/
void	print_token_type(t_tk_type type)
{
	static const char *table[] = {
		"TK_RESERVED",
		"TK_IDENT",
		"TK_NUM",
		"TK_EOF",
		"TK_ERROR"
	};
	for (size_t i = 0; i < sizeof(table) / sizeof(*table); i++)
		if (type == i)
			printf("type: %s ", table[i]);
}

void	print_token_list(const t_token *token)
{
	for (t_token *cur = (t_token *)token; cur; cur = cur->next)
	{
		print_token_type(cur->type);
		printf("token:|%.*s|\n", cur->len, cur->str);
	}
}
