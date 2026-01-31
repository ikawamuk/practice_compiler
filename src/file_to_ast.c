/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_ast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 03:13:16 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/01 04:09:47 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "token.h"
#include <stdlib.h>
#include <stdio.h>

t_token	*file_to_token_list(char *file_path);
t_tree	*expr(t_token **list_p);
void	clear_token(t_token *cur);

t_tree	*file_to_ast(char *file_path)
{
	t_tree	*ast;
	t_token	*token_list;

	token_list = file_to_token_list(file_path);
	if (!token_list)
		return (NULL);
	// t_token	*cur = token_list;
	// while (cur)
	// {
	// 	printf("str:%s\n", cur->str);
	// 	cur = cur->next;
	// }
	ast = expr(&token_list);
	clear_token(token_list);
	return (ast);
}
