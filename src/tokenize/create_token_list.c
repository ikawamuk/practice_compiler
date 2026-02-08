/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 17:12:04 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/08 17:47:38 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "token.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void			error_at(
		const char *input_str,
		const char *location,
		const char *err_msg);
static t_token	*new_token(const char **str_p, const char *head);
static t_token	*new_eof_token(const char *str);

t_token *create_token_list(const char *str)
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
		t_token	*new = new_token(&str, head);
		if (!new)
			return (NULL);
		cur->next = new;
		cur = cur->next;
	}
	cur->next = new_eof_token(str);
	if (!cur->next)
		return (NULL);
	return (dummy_head.next);
}

static t_token	*new_eof_token(const char *str)
{
	t_token *eof = aalloc(sizeof(t_token));
	if (!eof)
		return (NULL);
	eof->next = NULL;
	eof->str = str;
	eof->type = TK_EOF;
	return (eof);
}

static t_token	*new_token(const char **str_p, const char *head)
{
	t_token		*new;

	new = aalloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->str = *str_p;
	if (!memcmp(*str_p, "==", 2) || !memcmp(*str_p, "!=", 2)
	|| !memcmp(*str_p, "<=", 2) || !memcmp(*str_p, ">=", 2))
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
