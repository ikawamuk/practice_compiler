/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 23:03:43 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/03 18:28:17 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "token.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void			error_at(const char *input_str, const char *location, const char *err_msg);
static t_token	*new_token(t_arena *arena, const char **str_p, const char *head);

t_token *tokenize(t_arena *arena, const char *str)
{
	const char	*head = str;
	t_token		dummy_head = {0};
	t_token		*cur = &dummy_head;

	while (*str)
	{
		while (isspace(*str))
			str++;
		if (!*str)
			break ;
		t_token	*new = new_token(arena, &str, head);
		if (!new)
			return (NULL);
		cur->next = new;
		cur = cur->next;
	}
	t_token *eof = aalloc(arena, sizeof(t_token));
	if (!eof)
		return (NULL);
	eof->next = NULL;
	eof->str = str;
	eof->type = TK_EOF;
	cur->next = eof;
	return (dummy_head.next);
}

static t_token	*new_token(t_arena *arena, const char **str_p, const char *head)
{
	t_token		*new;

	new = aalloc(arena, sizeof(t_token));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->str = *str_p;
	if (!memcmp(*str_p, "==", 2) || !memcmp(*str_p, "!=", 2) ||
		!memcmp(*str_p, "<=", 2) || !memcmp(*str_p, ">=", 2))
	{
		new->val = 0;
		*str_p += 2;
		new->len = 2;
		new->type = TK_RESERVED;
	}
	else if (strchr("+-*/()<>", **str_p))
	{
		new->val = 0;
		*str_p += 1;
		new->len = 1;
		new->type = TK_RESERVED;
	}
	else if (isdigit(**str_p))
	{
		new->val = strtol(*str_p, (char **)str_p, 10);
		new->len = *str_p - new->str;
		new->type = TK_NUM;
	}
	else
	{
		error_at(head, *str_p, "invalid character");
		return (NULL);
	}
	return (new);
}
