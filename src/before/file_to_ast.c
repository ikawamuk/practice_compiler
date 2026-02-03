/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_ast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 03:13:16 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/03 13:47:53 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "tree.h"
#include "token.h"
#include <stdlib.h>
#include <stdio.h>

char	*read_in_bulk(const char *file_path);
t_token *tokenize(char *str);
t_tree	*token_list_to_ast(t_token *token_list);
void	clear_token(t_token *cur);

t_tree	*file_to_ast(t_arena *arena, const char *file_path)
{
	char	*input_str;
	t_token	*token_list;
	t_tree	*ast;

	input_str = read_in_bulk(file_path);
	if (!input_str)
		return (NULL);
	token_list = tokenize(input_str);
	if (!token_list)
	{
		free(input_str);
		return (NULL);
	}
	ast = token_list_to_ast(token_list);
	clear_token(token_list);
	return (ast);
}

	// t_token	*cur = token_list;
	// while (cur)
	// {
	// 	printf("str:%s\n", cur->str);
	// 	cur = cur->next;
	// }
