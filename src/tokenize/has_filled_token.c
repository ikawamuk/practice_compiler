/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_filled_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:26:45 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/12 16:11:24 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool		is_identifier_char(char c);
bool		consumes_reserved(t_token *new, const char **str_p);
bool		consumes_operator(t_token *new, const char **str_p);
static bool	consumes_digit(t_token *new, const char **str_p);
static bool	consumes_identifer(t_token *new, const char **str_p);

bool	has_filled_token(t_token *new, const char **str_p)
{
	if (consumes_reserved(new, str_p))
		return (true);
	if (consumes_operator(new, str_p))
		return (true);
	if (consumes_digit(new, str_p))
		return (true);
	if (consumes_identifer(new, str_p))
		return (true);
	return (false);
}

static bool	consumes_identifer(t_token *new, const char **str_p)
{
	if (is_identifier_char(**str_p))
	{
		const char	*head = *str_p;
		while (is_identifier_char(**str_p))
			(*str_p)++;
		new->len = *str_p - head;
		new->type = TK_IDENT;
		return (true);
	}
	return (false);
}

static bool	consumes_digit(t_token *new, const char **str_p)
{
	if (isdigit(**str_p))
	{
		new->val = strtol(*str_p, (char **)str_p, 10);
		new->len = *str_p - new->str;
		new->type = TK_NUM;
		return (true);
	}
	return (false);
}
