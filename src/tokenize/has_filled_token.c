/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_filled_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:26:45 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/08 21:19:41 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

static bool	consumes_digit(t_token *new, const char **str_p);
static bool	consumes_reserved1(t_token *new, const char **str_p);
static bool	consumes_reserved2(t_token *new, const char **str_p);
static bool	consumes_identifer(t_token *new, const char **str_p);

bool	has_filled_token(t_token *new, const char **str_p)
{
	if (consumes_reserved2(new, str_p))
		return (true);
	if (consumes_reserved1(new, str_p))
		return (true);
	if (consumes_digit(new, str_p))
		return (true);
	if (consumes_identifer(new, str_p))
		return (true);
	return (false);
}

static bool	consumes_identifer(t_token *new, const char **str_p)
{
	if ('a' <= **str_p && **str_p <= 'z')
	{
		new->val = 0;
		*str_p += 1;
		new->len = 1;
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

static bool	consumes_reserved1(t_token *new, const char **str_p)
{
	if (strchr("+-*/()<>;=", **str_p))
	{
		new->val = 0;
		*str_p += 1;
		new->len = 1;
		new->type = TK_RESERVED;
		return (true);
	}
	return (false);
}

static bool	consumes_reserved2(t_token *new, const char **str_p)
{
	if (!memcmp(*str_p, "==", 2) || !memcmp(*str_p, "!=", 2)
	|| !memcmp(*str_p, "<=", 2) || !memcmp(*str_p, ">=", 2))
	{
		new->val = 0;
		*str_p += 2;
		new->len = 2;
		new->type = TK_RESERVED;
		return (true);
	}
	return (false);
}