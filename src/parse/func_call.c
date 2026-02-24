/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_call.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 05:34:16 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/24 13:15:48 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "tree.h"
#include "token.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool	is_expected(const char *op, t_token *token);
t_tree	*new_func_call_leaf(const char *func_name, size_t len);

t_tree	*func_call(t_token **token_p)
{
	const char	*func_name = (*token_p)->str;
	size_t		len = (*token_p)->len;
	*token_p = (*token_p)->next->next; // next: "(", next's next: ")"
	if (is_expected(")", *token_p))
	{
		*token_p = (*token_p)->next;
		return (new_func_call_leaf(func_name, len));
	}
	fprintf(stderr, "expected \')\'\n");
	clear_arena();
	exit(EXIT_FAILURE);
}
