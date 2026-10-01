/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 17:12:04 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/10/02 02:38:23 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compilation.h"
#include "arena.h"
#include "token.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

void			error_at(const char *location, const char *err_msg);
void			*xaalloc(size_t size);
static t_token	*new_token(const char **str_p);
bool			has_filled_token(t_token *new, const char **str_p);
static t_token	*new_eof_token(const char *str);

int	tokenize(t_compilation *ctx)
{
	const char	*str = ctx->src_content;
	t_token		dummy_head = {0};
	t_token		*cur = &dummy_head;
	while (*str)
	{
		while (isspace(*str))
			str++;
		if (!*str)
			break ;
		cur->next = new_token(&str);
		if (!cur->next)
			return (-1);
		cur = cur->next;
	}
	cur->next = new_eof_token(str);
	ctx->token_list = dummy_head.next;
	ctx->phase = TOKEN_LIST;
	return (0);
}

static t_token	*new_token(const char **str_p)
{
	t_token		*new;

	new = xaalloc(sizeof(t_token));
	new->next = NULL;
	new->str = *str_p;
	if (!has_filled_token(new, str_p))
	{
		error_at(*str_p, "invalid character\n");
		return (NULL);
	}
	return (new);
}

static t_token	*new_eof_token(const char *str)
{
	t_token *eof = xaalloc(sizeof(t_token));
	eof->next = NULL;
	eof->str = str;
	eof->type = TK_EOF;
	return (eof);
}
