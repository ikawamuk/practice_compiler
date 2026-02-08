/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 17:12:04 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/08 18:32:56 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "token.h"
#include <ctype.h>
#include <stdbool.h>

static t_token	*new_token(const char **str_p, const char *head);
bool			has_filled_token(t_token *new, const char **str_p);
void			error_at(
					const char *input_str,
					const char *location,
					const char *err_msg);
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
		cur->next = new_token(&str, head);
		if (!cur->next)
			return (NULL);
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
	if (!has_filled_token(new, str_p))
	{
		error_at(head, *str_p, "invalid character");
		return (NULL);
	}
	return (new);
}
