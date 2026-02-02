/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list_to_ast.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 12:19:38 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/02 12:33:39 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "tree.h"
#include "token.h"
#include <stdlib.h>

t_tree			*expr(void *arena, t_token **list_p);
static size_t	count_token_list(t_token *list);

t_tree	*token_list_to_ast(t_token *token_list)
{
	t_arena	arena;

	arena.buffer = malloc(count_token_list(token_list) * sizeof(t_tree));
	if (!arena.buffer)
		return (NULL);
	return (expr(&arena, &token_list));
}

static size_t	count_token_list(t_token *list)
{
	size_t	count;
	t_token	*cur = list;

	count = 0;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return (count);
}
